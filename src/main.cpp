#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <string.h>

#include "cp_cchar.h"
#include "cp_unixchar.h"
#include "cp_unixbuf.h"
#include "cp_strategy.h"

// for timer
#include "Timer.h"

using namespace std;

int main(void) {
    string s;
    char * line;
    char ** cmd;
    CPStrategy * cp = NULL;

    // for timer
    Timer t;
    double eTime;

    while (1) {

        cout << "$ ";
        getline(cin, s);

        if (s == "exit")
            break;

        // bad parsing
        line = const_cast<char*>(s.c_str());
        int numTokens = 0;
        for (int i = 0; line[i] != '\0'; ++i)
            if (line[i] == ' ')
                numTokens++;
        cmd = (char**) malloc((numTokens+1) * sizeof(char*));
        int j = 0;
        char token[256];
        int tokenSize = 0;
        for (int i = 0; line[i] != '\0'; ++i) {
            if (line[i] == ' ') {
                token[tokenSize] = '\0';
                cmd[j] = (char*) malloc(tokenSize*sizeof(char));
                strcpy(cmd[j++], token);
                tokenSize = 0;
            } else {
                token[tokenSize++] = line[i];
            }
        }
        // add last argument
        token[tokenSize] = '\0';
        cmd[j] = (char*) malloc(tokenSize*sizeof(char));
        strcpy(cmd[j++], token);
        // null terminate
        cmd[j] = NULL;

        // stat for source
        struct stat sb_src, sb_dst;
        if (cmd[1][0] == '-') {
            stat(cmd[2], &sb_src);
            stat(cmd[3], &sb_dst);
        } else {
            stat(cmd[1], &sb_src);
            stat(cmd[2], &sb_dst);
        }

        if (S_ISDIR(sb_src.st_mode)) {
            cout << "cp: Cannot copy a directory!" << endl;
            continue;
        }
        
        if (S_ISREG(sb_dst.st_mode)) {// || S_ISDIR(sb_dst.st_mode)) {
            cout << "cp: Destination file already exists!" << endl;
            continue;
        }

        if (strcmp(cmd[0], "cp") == 0) {
            if (cmd[1][0] != '-')
                cp = new CPUNIXBuf(cmd);
            else if (cmd[1][1] == 'c')
                cp = new CPCChar(cmd);
            else if (cmd[1][1] == 'u')
                cp = new CPUNIXChar(cmd);
            else if (cmd[1][1] == 'b')
                cp = new CPUNIXBuf(cmd);
            else if (cmd[1][1] == 'v') {
                for (int i = 0; i < 3; ++i) {
                    switch (i) {
                        case 0:
                            cp = new CPCChar(cmd);
                            break;
                        case 1:
                            cp = new CPUNIXChar(cmd);
                            break;
                        case 2:
                            cp = new CPUNIXBuf(cmd);
                            break;
                    }
                    // init timer
                    t.start();
                    
                    // copy file
                    if (cp != NULL)
                        cp->execute();

                    // timer
                    t.elapsedUserTime(eTime);
                    cout << eTime << endl;

                    remove(cmd[3]);

                    // free memory
                    if (cp != NULL) {
                        delete cp;
                        cp = NULL;
                    }
                }
            }
        } else {
            // I don't understand why I can't free this memory
            // explicitly.
            //for (int i = 0; cmd[i] != NULL; ++i)
                //free(cmd[i]);
            //free(cmd);
        }

        if (cmd[1][1] != 'v') {
            // copy file
            if (cp != NULL)
                cp->execute();

            // free memory
            if (cp != NULL) {
                delete cp;
                cp = NULL;
            }
        }
    }
}

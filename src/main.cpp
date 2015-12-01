#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <string.h>

#include "cp_cchar.h"
#include "cp_unixchar.h"
#include "cp_unixbuf.h"
#include "cp_strategy.h"

using namespace std;

int main(void) {
    string s;
    char * line;
    char ** cmd;
    CPStrategy * cp = NULL;

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

        if (strcmp(cmd[0], "ccp") == 0)
            cp = new CPCChar(cmd);
        else if (strcmp(cmd[0], "ucp") == 0)
            cp = new CPUNIXChar(cmd);
        else if (strcmp(cmd[0], "bcp") == 0)
            cp = new CPUNIXBuf(cmd);
        else {
            // I don't understand why I can't free this memory
            // explicitly.
            //for (int i = 0; cmd[i] != NULL; ++i)
                //free(cmd[i]);
            //free(cmd);
        }

        if (cp != NULL)
            cp->execute();

        if (cp != NULL) {
            delete cp;
            cp = NULL;
        }
    }
}

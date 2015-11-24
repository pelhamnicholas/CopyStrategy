#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <string.h>

#include "cp_cchar.h"
#include "cp_strategy.h"

using namespace std;

int main(void) {
    string s;
    const char * line;
    char ** cmd;
    CPStrategy * cp;

    cout << "$ ";
    getline(cin, s);

    // bad parsing
    line = s.c_str();
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

    cp = new CPCChar(cmd);

    cp->execute();

    delete cp;

}

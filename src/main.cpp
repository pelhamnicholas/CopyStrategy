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

int main(int argc, char * argv[]) {
    Timer t;
    double eTime;
    CPStrategy * cp = NULL;

    // stat for source
    struct stat sb_src, sb_dst;
    if (argv[1][0] == '-') {
        stat(argv[2], &sb_src);
        stat(argv[3], &sb_dst);
    } else {
        stat(argv[1], &sb_src);
        stat(argv[2], &sb_dst);
    }

    if (S_ISDIR(sb_src.st_mode)) {
        cout << "cp: Cannot copy a directory!" << endl;
        return 1;
    }
    
    if (S_ISREG(sb_dst.st_mode)) {// || S_ISDIR(sb_dst.st_mode)) {
        cout << "cp: Destination file already exists!" << endl;
        return 1;
    }

    if (argv[1][0] != '-')
        cp = new CPUNIXBuf(argv);
    else if (argv[1][1] == 'c')
        cp = new CPCChar(argv);
    else if (argv[1][1] == 'u')
        cp = new CPUNIXChar(argv);
    else if (argv[1][1] == 'b')
        cp = new CPUNIXBuf(argv);
    else if (argv[1][1] == 'v') {
        for (int i = 0; i < 3; ++i) {
            switch (i) {
                case 0:
                    cp = new CPCChar(argv);
                    break;
                case 1:
                    cp = new CPUNIXChar(argv);
                    break;
                case 2:
                    cp = new CPUNIXBuf(argv);
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

            remove(argv[3]);

            // free memory
            if (cp != NULL) {
                delete cp;
                cp = NULL;
            }
        }
    }

    if (argv[1][0] != '-' || argv[1][1] != 'v') {
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

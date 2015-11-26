/*
 *
 */

#include "cp_cchar.h"

CPCChar::CPCChar(char ** argv) : CPStrategy(argv) {
}

CPCChar::~CPCChar() {
}

int CPCChar::execute() {
    // get size of argv[]
    int argc;
    for (argc = 0; argv[argc] != NULL; ++argc) ;

    int i_src, i_dst;
    if (argc < 2) {
        // not enough arguments
        cout << "Error: Not enough arguments!" << endl;
        return 1;
    } else if (argc == 3) {
        // only filenames passed
        i_src = 1;
        i_dst = 2;
    } else if (argc == 4) {
        // flag passed
        i_src = 2;
        i_dst = 3;
    } else {
        // too many arguments
        cout << "Error: Too many arguments passed!" << endl;
        return 1;
    }

    ifstream src(argv[i_src], ios_base::in);
    ofstream dst(argv[i_dst], ios_base::out);

    char c;
    while (src.get(c))
        dst.put(c);

    src.close();
    dst.close();

    return 0;
}

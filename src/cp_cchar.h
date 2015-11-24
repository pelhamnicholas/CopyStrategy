#ifndef CP_CCHAR_H
#define CP_CCHAR_H

#include"cp_strategy.h"
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>

using std::ifstream;
using std::ofstream;
using std::ios_base;
using std::cout;
using std::endl;

class CPCChar : public CPStrategy {
    private:
    public:
        CPCChar() {};
        CPCChar(char ** argv);
        ~CPCChar();
        virtual int execute();
};

#endif

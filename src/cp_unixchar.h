#ifndef CP_UNIXCHAR_H
#define CP_UNIXCHAR_H

#include "cp_strategy.h"
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <iostream>

using std::cout;
using std::endl;

class CPUNIXChar : public CPStrategy {
    private:
    public:
        CPUNIXChar() {};
        CPUNIXChar(char ** argv) : CPStrategy(argv) {};
        ~CPUNIXChar() {};
        virtual int execute();
};

#endif

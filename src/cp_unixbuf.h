#ifndef CP_UNIXBUF_H
#define CP_UNIXBUF_H

#include "cp_strategy.h"
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <iostream>

using std::cout;
using std::endl;

class CPUNIXBuf : public CPStrategy {
    private:
    public:
        CPUNIXBuf() {};
        CPUNIXBuf(char ** argv) : CPStrategy(argv) {};
        ~CPUNIXBuf() {};
        virtual int execute();
};

#endif

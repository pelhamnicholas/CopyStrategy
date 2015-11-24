#ifndef CP_STRATEGY_H
#define CP_STRATEGY_H

#include <stdio.h>
#include <stdlib.h>

class CPStrategy {
    private:
    protected:
        char ** argv;
    public:
        CPStrategy() { argv = NULL; };
        CPStrategy(char ** argv) { this->argv = argv; };
        virtual ~CPStrategy() { free(argv); };
        virtual int execute() = 0;
};

#endif

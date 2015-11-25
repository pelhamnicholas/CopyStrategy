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
        virtual ~CPStrategy() {};
        virtual int execute() = 0;
};

/*
CPStrategy::~CPStrategy() {
    int i;
    for (i = 0; argv[i] != NULL; ++i) {
        free(argv[i]);
    }
    free(argv[i]);
    free(argv);
}
*/

#endif

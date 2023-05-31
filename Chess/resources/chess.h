#ifndef CHESS_CLASS_H
#define CHESS_CLASS_H
#include"team.h"

class chess {
public:

    chess();
    ~chess();

    void checkForMate();

private:
    team white, black;
};

#endif
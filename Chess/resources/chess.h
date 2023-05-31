#ifndef CHESS_CLASS_H
#define CHESS_CLASS_H
#include"team.h"

class chess {
public:

    chess();
    ~chess();

    void checkForMate();

private:
    // All of the whites
    vector<pawn> pawnsW;
    vector<rook> rooksW;
    vector<knight> knightsW;
    vector<bishop> bishopsW;
    vector<queen> queensW;
    king whiteKing;

    // All of the blacks
    vector<pawn> pawnsB;
    vector<rook> rooksB;
    vector<knight> knightsB;
    vector<bishop> bishopsB;
    vector<queen> queensB;
    king blackKing;

};

#endif
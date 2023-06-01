#include"../resources/chess.h"

// This is the constructor for the chess game, it sets the pieces in the correct places
chess::chess() {
    pawnsW = {
        pos(0, 1),
        pos(1, 1),
        pos(2, 1),
        pos(3, 1),
        pos(4, 1),
        pos(5, 1),
        pos(6, 1),
        pos(7, 1)
    };
    rooksW = {
        pos(0, 0),
        pos(7, 0)
    };
    knightsW = {
        pos(1, 0),
        pos(6, 0)
    };
    bishopsW = {
        pos(2, 0),
        pos(5, 0)
    };
    queensW = {pos(4, 0)};
    king(pos(3, 0));
    pawnsW = {
        pos(0, 6),
        pos(1, 6),
        pos(2, 6),
        pos(3, 6),
        pos(4, 6),
        pos(5, 6),
        pos(6, 6),
        pos(7, 6)
    };
    rooksW = {
        pos(0, 7),
        pos(7, 7)
    };
    knightsW = {
        pos(1, 7),
        pos(6, 7)
    };
    bishopsW = {
        pos(2, 7),
        pos(5, 7)
    };
    queensW = {pos(4, 7)};
    king(pos(3, 7));
}

// This is the destructor for the chess game
chess::~chess() {
    // I'm not sure, but I think that the only thing that needs destucted is the teams,
    // and I believe that gets called when it goes out of scope on its own.
    cout << "";
}

void chess::checkForMate() {
    // This will go through both the white team and black teams pieces and sees if it's
    // possible to get a check
    cout << "";
}
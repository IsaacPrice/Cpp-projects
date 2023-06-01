#include<iostream>
#include<vector>
#include<string>
using namespace std;

// This is to simplify all of the other variables that go into each piece
struct pos {
    int x, y;
    pos(int x, int y) : x(x), y(y) {}
};

// This is the pawn class
class pawn {
public:
    pawn(pos startingLocation);
    ~pawn();

    bool isValid(pos attemptedMove, vector<vector<int>> board, bool isWhite);

private:
    pos* piecePosition;
};

// This is the rook class
class rook {
public:
    rook(pos startingLocation);
    ~rook();

    bool isValid(pos attemptedMove, vector<vector<int>> board, bool isWhite);
private:
    pos* piecePosition;
};

// This is the knight class
class knight {
public:
    knight(pos startingLocation);
    ~knight();

    bool isValid(pos attemptedMove, vector<vector<int>> board, bool isWhite);
private:
    pos* piecePosition;
};

// This is the bishop class
class bishop {
public:
    bishop(pos startingLocation);
    ~bishop();

    bool isValid(pos attemptedMove, vector<vector<int>> board, bool isWhite);
private:
    pos* piecePosition;
};

// This is the queen class
class queen {
public:
    queen(pos startingLocation);
    ~queen();

    bool isValid(pos attemptedMove, vector<vector<int>> board, bool isWhite);
private:
    pos* piecePosition;
};

// This is the king class
class king {
public:

    king();
    king(pos startingLocation);
    ~king();

    bool isValid(pos attemptedMove, vector<vector<int>> board, bool isWhite);
private:
    pos* piecePosition;
};

/*
class team {
public:
    team(bool isWhite);
    ~team();

private:
    vector<pawn> pawns;
    vector<rook> rooks;
    vector<knight> knights;
    vector<bishop> bishops;
    vector<queen> queens;
    king theKing;

    bool white;
};
*/
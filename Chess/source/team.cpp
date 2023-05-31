#include"../resources/team.h"

int isFound(vector<vector<int>> pieces, pos position) {
    int xPos = -1, yPos = -1;

    // This goes through each board piece
    for (auto& xVector : pieces) { 
        xPos += 1;
        for (auto& piece : xVector) { 
            yPos += 1;

            // If it found the piece, it will check if it is white or black and then return the value
            if (xPos == position.x && yPos == position.y) {
                return pieces.at(xPos).at(yPos);
            }
        }
    }
}

#pragma region pawn class

// Setting up the proper constuctors and destructors
pawn::pawn(pos startingLocation) {
    piecePosition = &startingLocation;
}

pawn::~pawn() {
    delete piecePosition;
}

// The function to move the piece if possible, and return false if not
bool pawn::isValid(pos attemptedMove, vector<vector<int>> board, bool isWhite) {
    // If it's forward, it has to make sure that there isn't a piece there
    if (isWhite) {
        if (attemptedMove.y == piecePosition->y + 1) {
            if ((attemptedMove.y - piecePosition->y) == 1 || (attemptedMove.y - piecePosition->y) == -1) {
                if (isFound(board,attemptedMove) == 2) {
                    piecePosition->x = attemptedMove.x;
                    piecePosition->y = attemptedMove.y;
                }
            }
            else if (isFound(board, attemptedMove) == 0) {
                piecePosition->x = attemptedMove.x;
                piecePosition->y = attemptedMove.y;  
            }
        }
    }
    else {
        if (attemptedMove.y == piecePosition->y - 1) {
            if ((attemptedMove.y - piecePosition-> y) == 1 || (attemptedMove.y - piecePosition-> y) == -1) {
                if (isFound(board,attemptedMove) == 2) {
                    piecePosition->x = attemptedMove.x;
                    piecePosition->y = attemptedMove.y;
                }
            }
            else if (isFound(board, attemptedMove) == 0) {
                piecePosition->x = attemptedMove.x;
                piecePosition->y = attemptedMove.y;  
            }
        }
    }
}

#pragma endregion

#pragma region rook class

// Constructors and destructors for the class
rook::rook(pos startingLocation) {
    piecePosition = &startingLocation;
}

rook::~rook() {
    delete piecePosition;
}

// This will check if the rook is able to move in that direction, and return if it isn't
bool rook::isValid(pos attemptedMove, vector<vector<int>> board, bool isWhite) {
    
}

#pragma endregion

// Constructor for making the team class
team::team() {
    // Set up the white pieces
}
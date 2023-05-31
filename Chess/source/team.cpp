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
                return pieces.at(xPos).at(yPos); // WHITE IS GOING TO BE 
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
                    return true;
                }
            }
            else if (isFound(board, attemptedMove) == 0) {
                piecePosition->x = attemptedMove.x;
                piecePosition->y = attemptedMove.y;  
                return true;
            }
        }
    }
    else {
        if (attemptedMove.y == piecePosition->y - 1) {
            if ((attemptedMove.y - piecePosition-> y) == 1 || (attemptedMove.y - piecePosition-> y) == -1) {
                if (isFound(board,attemptedMove) == 2) {
                    piecePosition->x = attemptedMove.x;
                    piecePosition->y = attemptedMove.y;
                    return true;
                }
            }
            else if (isFound(board, attemptedMove) == 0) {
                piecePosition->x = attemptedMove.x;
                piecePosition->y = attemptedMove.y;  
                return true;
            }
        }
    }

    // This means that all of the code above ran and couldn't move
    return 0;
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
    // Checks which direction it has moved based on the coordinate that hasn't changed
    if (attemptedMove.x = piecePosition->x) {
        // Means that it moving up or down
        pos test(0, 0);
        test.x = attemptedMove.x;
        for (int i = 0; i < abs(attemptedMove.y - piecePosition->y) - 1; i++) {
            // Checks every line until it hits the destination, and if it hits something then it is false
            if (isWhite) {
                test.y = piecePosition->y + i;
            }
            else {
                test.y = piecePosition->y - i;
            }
            if (isFound(board, test) != 0) {
                return 0; // Means that it hit something, so it cant move
            }
        }

        // It is now done looking for anything in the way, and will return if it moved or not
        if (isFound(board, attemptedMove) != (isWhite + 1)) {
            return 1; // Means that it didn't hit it's own color
        }
    }
    else if (attemptedMove.y = piecePosition->y) {
        // Means that it is moving left and right
        pos test(0, 0);
        test.y = attemptedMove.y;
        for (int i = 0; i < abs(attemptedMove.x - piecePosition->x); i++) {
            // Checks every line until it hits the destination, and if it hits something then it is false
            if (isWhite) {
                test.x = piecePosition->x + i;
            }
            else {
                test.x = piecePosition->x - i;
            }
            if (isFound(board, test) != 0) {
                return 0; // Means that it hit something, so it cant move
            }
        }

        if (isFound(board, attemptedMove) != (isWhite + 1)) {
            return 1; // Means that it took a black piece
        }
        else {
            return 0;
        }
    }
    else {
        // Means that it isn't making a correct move
        return 0;
    }
}

#pragma endregion

#pragma region knight class

// Constructor and destructor for the knight class
knight::knight(pos startingLocation) {
    piecePosition = &startingLocation;
}

knight::~knight() {
    delete piecePosition;
}

// Checks if the knight is making a valid move based on the only 8 choices it has
bool knight::isValid(pos attemptedMove, vector<vector<int>> board, bool isWhite) {
    vector<pos> possibleMoves = { // These are all of the possible moves for the knight to go
        pos(piecePosition->x += 2, piecePosition->y += 1),
        pos(piecePosition->x += 2, piecePosition->y -= 1),
        pos(piecePosition->x += 1, piecePosition->y -= 2),
        pos(piecePosition->x -= 1, piecePosition->y -= 2),
        pos(piecePosition->x -= 2, piecePosition->y -= 1),
        pos(piecePosition->x -= 2, piecePosition->y += 1),
        pos(piecePosition->x -= 1, piecePosition->y += 2),
        pos(piecePosition->x += 1, piecePosition->y += 2)
    };
    
    // Loops through and checks if any of these are availible to move
    for (auto& possible : possibleMoves) {
        if (possible.x == attemptedMove.x && possible.y == attemptedMove.y) {
            if (isFound(board, attemptedMove)) {
                piecePosition->x = attemptedMove.x;
                piecePosition->y = attemptedMove.y;
                return true;
            }
        }
    }

    return false;
}

#pragma endregion

#pragma region bishop class

// Constructor and destructor for the 
bishop::bishop(pos startingLocation) {
    piecePosition = &startingLocation;
}

bishop::~bishop() {
    delete piecePosition;
}

bool bishop::isValid(pos attemptedMove, vector<vector<int>> board, bool isWhite) {
    if (abs(attemptedMove.x - piecePosition->x) / abs(attemptedMove.y - piecePosition->y) != 1) {
        return false; // This means that it wasn't going in the correct direction
    }

    pos test(piecePosition->x, piecePosition->y);

    // This goes through every tile it moves through to hit to the place
    for (int i = 0; i < abs(attemptedMove.x - piecePosition->x) - 1; i++) {
        if (attemptedMove.x - piecePosition->x  < 0) {
            test.x -= 1;
        }
        else {
            test.x += 1;
        }

        if (attemptedMove.y - piecePosition->y < 0) {
            test.y -= 1;
        }
        else {
            test.y += 1;
        }

        // Checks if it was hit
        if (isFound(board, test) != 0) {
            return false;
        }
    }

    // Checks to see if it overlaps one of the same color
    if (isFound(board, attemptedMove) != (isWhite + 1)) {
        piecePosition->x = attemptedMove.x;
        piecePosition->y = attemptedMove.y;
        return true;
    }
    else {
        return false; // Means that it hit the same color
    }
}

#pragma endregion

#pragma region The Queen

// Constructors and Destructors for the
queen::queen(pos startingLocation) {
    piecePosition = &startingLocation;
}

queen::~queen() {
    delete piecePosition;
}

bool queen::isValid(pos attemptedMove, vector<vector<int>> board, bool isWhite) {
    // Checks That the Queen has moved in a correct way, using the bishops diagonal movement
    // and the rooks horizontal and vertical movement
    if (abs(attemptedMove.x - piecePosition->x) / abs(attemptedMove.y - piecePosition->y) == 1) {
        pos test(piecePosition->x, piecePosition->y);

        // This goes through every tile it moves through to hit to the place
        for (int i = 0; i < abs(attemptedMove.x - piecePosition->x) - 1; i++) {
            if (attemptedMove.x - piecePosition->x  < 0) {
                test.x -= 1;
            }
            else {
                test.x += 1;
            }

            if (attemptedMove.y - piecePosition->y < 0) {
                test.y -= 1;
            }
            else {
                test.y += 1;
            }

            // Checks if it was hit
            if (isFound(board, test) != 0) {
                return false;
            }
        }

        // Checks to see if it overlaps one of the same color
        if (isFound(board, attemptedMove) != (isWhite + 1)) {
            piecePosition->x = attemptedMove.x;
            piecePosition->y = attemptedMove.y;
            return true;
        }
        else {
            return false; // Means that it hit the same color
        }
    }

    // Next checks if it has the movement of a rook
    else if (attemptedMove.x = piecePosition->x) {
        // Means that it moving up or down
        pos test(0, 0);
        test.x = attemptedMove.x;
        for (int i = 0; i < abs(attemptedMove.y - piecePosition->y) - 1; i++) {
            // Checks every line until it hits the destination, and if it hits something then it is false
            if (isWhite) {
                test.y = piecePosition->y + i;
            }
            else {
                test.y = piecePosition->y - i;
            }
            if (isFound(board, test) != 0) {
                return false; // Means that it hit something, so it cant move
            }
        }

        // It is now done looking for anything in the way, and will return if it moved or not
        if (isFound(board, attemptedMove) != (isWhite + 1)) {
            return true; // Means that it didn't hit it's own color
        }
    }
    else if (attemptedMove.y = piecePosition->y) {
        // Means that it is moving left and right
        pos test(0, 0);
        test.y = attemptedMove.y;
        for (int i = 0; i < abs(attemptedMove.x - piecePosition->x); i++) {
            // Checks every line until it hits the destination, and if it hits something then it is false
            if (isWhite) {
                test.x = piecePosition->x + i;
            }
            else {
                test.x = piecePosition->x - i;
            }
            if (isFound(board, test) != 0) {
                return false; // Means that it hit something, so it cant move
            }
        }

        if (isFound(board, attemptedMove) != (isWhite + 1)) {
            return true; // Means that it took a black piece
        }
        else {
            return false;
        }
    }
    else {
        // Means that it isn't making a correct move
        return false;
    }
}

#pragma endregion

#pragma region The King

king::king() { 
    cout << "Stupid Idiot" << endl;
}

king::king(pos startingLocation) {
    piecePosition = &startingLocation;
}

king::~king() {
    delete piecePosition;
}

// Checks if the piece is availible to move, and moves it if so
bool king::isValid(pos attemptedMove, vector<vector<int>> board, bool isWhite) {
    // It checks if the move is only one X and one Y
    if (abs(attemptedMove.x - piecePosition->x) <= 1 && abs(attemptedMove.y - piecePosition->y) <= 1) {
        if (isFound(board, attemptedMove) != (isWhite + 1)) {
            piecePosition->x = attemptedMove.x;
            piecePosition->y = attemptedMove.y;
            return true;
        }
    }

    // If none of those were true, then it's an invalid move
    return false;
}

#pragma endregion

// Constructor for making the team class
/*
team::team(bool isWhite) {
    white = isWhite;
    if (isWhite) {
        pawns = {pawn(0, 1),
            pawn(1, 1),
            pawn(2, 1),
            pawn(3, 1),
            pawn(4, 1),
            pawn(5, 1),
            pawn(6, 1),
            pawn(7, 1);}
    }
    else {
        // Sets up all of the white pieces
        pawns = {pawn(0, 6), 
            pawn(1, 6), 
            pawn(2, 6), 
            pawn(3, 6), 
            pawn(4, 6), 
            pawn(5, 6), 
            pawn(6, 6), 
            pawn(7, 6)};
    }
}
*/
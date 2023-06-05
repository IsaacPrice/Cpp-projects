#include<iostream>
#include<vector>
#include<string>
using namespace std;

// ^ --->
// | --->
// | --->
// | --->
// | --->
struct pos {
    int x;
    int y;
};

class chess {
public:
    chess();
    chess(vector<vector<string>> Board);

    void drawBoard();
    bool movePiece(pos piece, pos location);
    bool verify(string toVerify);
    string getPiece(pos location);

private:
    vector<vector<string>> board;

};

// Default constuctor for the chess class
chess::chess() {
    cout << "Welcome to chess!" << endl;
}

// Constuctor with the board already
chess::chess(vector<vector<string>> Board) {
    board = Board;
}

void chess::drawBoard() {
    cout << "  a b c d e f g h" << endl;
    int number = 0;
    
    for (auto& xVect : board) {
        number++;
        cout <<  number << " ";
        for (auto& piece : xVect) {
            if (piece == "wpawn") {
                cout << "\u265f" << " ";
            }
            else if (piece == "wknight") {
                cout << "\u265e" << " ";
            }
            else if (piece == "wrook") {
                cout << "\u265c" << " ";
            }
            else if (piece == "wbishop") {
                cout << "\u265d" << " ";
            }
            else if (piece == "wqueen") {
                cout << "\u265b" << " ";
            }
            else if (piece == "wking") {
                cout << "\u265a" << " ";
            }
            else if (piece == "bpawn") {
                cout << "\u2659" << " ";
            }
            else if (piece == "bknight") {
                cout << "\u2658" << " ";
            }
            else if (piece == "brook") {
                cout << "\u2657" << " ";
            }
            else if (piece == "bbishop") {
                cout << "\u2656" << " ";
            }
            else if (piece == "bqueen") {
                cout << "\u2655" << " ";
            }
            else if (piece == "bking") {
                cout << "\u2654" << " ";
            }
            else {
                cout << ". ";
            }
        }
        cout << endl;
    }
}

// Moves the piece to the desired location
bool chess::movePiece(pos piece, pos location) {
    string pieceName;

    // Gets the name of the desired piece
    pieceName = getPiece(piece);

    // Checks the movement if it is a pawn
    if (pieceName == "wpawn") {
        // Means that is is going forward
        if (location.y == piece.y - 1) {
            // Means that it's trying to go straight forward
            if (location.x == piece.x) {
                // Means that it's trying to go to a place where the white already is
                if (getPiece(location)[0] != 'w') {
                    // all good
                }
                else {
                    return false;
                }
            }
            else if (abs(location.x - piece.x) == 1) {
                // Means that it's tryin to capture a black piece
                if (getPiece(location)[0] == 'b') {
                    // all good
                }
                else {
                    return false;
                }
            }
            else {
                return false;
            }
        }
        else if (location.x == piece.x && piece.y - location.y == 2) {
            // This means that it went 2 forward, so it's a valid move
        }
        else {
            // Means that it's trying to go backward, which the pawn cannot do
            return false;
        }
    }
    if (pieceName == "bpawn") {
        // Means that is is going forward
        if (location.y == piece.y + 1) {
            // Means that it's trying to go straight forward
            if (location.x == piece.x) {
                // Means that it's trying to go to a place where the white already is
                if (getPiece(location)[0] != 'b') {
                    // all good
                }
                else {
                    return false;
                }
            }
            else if (abs(location.x - piece.x) == 1) {
                // Means that it's tryin to capture a black piece
                if (getPiece(location)[0] == 'w') {
                    // all good
                }
                else {
                    return false;
                }
            }
            else {
                return false;
            }
        }
        else if (location.x == piece.x && location.y - piece.y == 2) {
            // This means that it went 2 forward, so it's a valid move
        }
        else {
            // Means that it's trying to go backward, which the pawn cannot do
            return false;
        }
    }
    // Checks the movment if it is a rook
    if (pieceName == "wrook" || pieceName == "brook") {
        pos test;
        // Makes sure that is only going in one direction
        if (piece.x == location.x) {
            // means that it's going in the y direction
            test.x = piece.x;
            test.y = piece.y;
            for (int i = 0; i < abs(piece.y - location.y) - 1; i++) {
                if (piece.y - location.y > 0) {
                    test.y--;
                }
                else {
                    test.y++;
                }

                // This means that it hit a piece on the path, whcih isn's allowed
                if (getPiece(test) != "") {
                    return false;
                }
            }
            
            if (getPiece(location) != "") {
                if (getPiece(location)[0] == pieceName[0]) {
                    // This means that it hit the same piece, which isnt allowed
                    return false;
                }
            }
        }
        else if (piece.y == location.y) {
            // Means that it's going in the x direction
            test.y = piece.y;
            test.x = piece.x;
            for (int i = 0; i < abs(piece.x - location.x) - 1; i++) {
                if (piece.x - location.x > 0) {
                    test.x--;
                }
                else {
                    test.x++;
                }

                // This means that it hit a piece on the path, whcih isn's allowed
                if (getPiece(test) != "") {
                    return false;
                }
            }
            
            if (getPiece(location) != "") {
                if (getPiece(location)[0] == pieceName[0]) {
                    // This means that it hit the same piece, which isnt allowed
                    return false;
                }
            }
        }
        else {
            // means that its going in an invalid direction
            return false;
        }
    }


    board.at(piece.y - 1).at(piece.x - 1) = "";

    board.at(location.y - 1).at(location.x - 1) = pieceName;
    return true;
}

// This makes sure that the string is valid
bool chess::verify(string toVerify) {
    if (int(toupper(toVerify[0])) - 64 < 9 && int(toVerify[1]) - 48 < 9) {
        return true;
    }
    else {
        return false;
    }
}

// Looks through the board and returns the string
string chess::getPiece(pos location) {
    return board.at(location.y - 1).at(location.x - 1);
}

// This gets the users input and formats it to a position
pos decipher(string something) {
    pos toSend;
    toSend.y = int(something[1]) - 48;
    toSend.x = int(toupper(something[0])) - 64;
    return toSend;
}

int main() {
    string userInput;
    pos selected, destination;
    bool isGoing = true;
    vector<vector<string>> board = {
        {"brook","bknight","bbishop","bqueen","bking","bbishop","bknight","brook"},
        {"bpawn","bpawn","bpawn","bpawn","bpawn","bpawn","bpawn","bpawn"},
        {"","","","","","","",""},
        {"","","","","","","",""},
        {"","","","","","","",""},
        {"","","","","","","",""},
        {"wpawn","wpawn","wpawn","wpawn","wpawn","wpawn","wpawn","wpawn"},
        {"wrook","wknight","wbishop","wking","wqueen","wbishop","wknight","wrook"}
    };
    chess game(board);

    // This will get all of the movements of the pieces
    while (isGoing) {
        game.drawBoard();

        // This makes sure that the user enters a valid string
        cout << "Enter the piece you would like to move: ";
        cin >> userInput;  
        while (!game.verify(userInput)) {
            cout << "Entered an Invalid place" << endl;
            cout << "Enter the piece you would like to move: ";
            cin >> userInput;  
        } 
        selected = decipher(userInput);

        cout << "Enter the place you would like to move: ";
        cin >> userInput;  
        while (!game.verify(userInput)) {
            cout << "Entered an Invalid place" << endl;
            cout << "Enter the place you would like to move: ";
            cin >> userInput;  
        } 
        destination = decipher(userInput);

        if (!game.movePiece(selected, destination)) {
            cout << "invalid move" << endl;
        }
    }

    return 0;
}
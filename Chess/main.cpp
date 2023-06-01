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
        cout << number << " ";
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

    pieceName = board.at(piece.y - 1).at(piece.x - 1);
    board.at(piece.y - 1).at(piece.x - 1) = "";

    board.at(location.y - 1).at(location.x - 1) = pieceName;
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

        game.movePiece(selected, destination);
    }

    return 0;
}
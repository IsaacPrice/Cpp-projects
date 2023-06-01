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

void drawBoard(vector<vector<string>> Board) {
    cout << "  a b c d e f g h" << endl;
    int number = 0;
    for (auto& xVect : Board) {
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
bool movePiece(vector<vector<string>> Board, pos piece, pos location) {
    string pieceName;

    // Verifying that all of the positions are legal
    if (!(piece.x < 9 && piece.y < 9 && location.x < 9 && location.y < 9)) {
        cout << "Invalid Move." << endl;
        return false;
    }

    pieceName = Board.at(piece.y - 1).at(piece.x - 1);

    Board.at(location.y - 1).at(location.x - 1) = pieceName;
}

pos decipher(string something) {
    pos toSend;
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

    while (isGoing) {
        drawBoard(board);
        cout << "Enter the piece you would like to move: ";
        cin >> userInput;
    }

    return 0;
}
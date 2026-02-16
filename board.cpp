#include "Board.hpp"
#include <iostream>
#include <algorithm>

// Constructor
Board::Board() {
    reset();
}

void Board::show() const {
    std::cout << "—————————————\n";
    for (int i = 0; i < 3; i++) {
        std::cout << "| ";
        for (int j = 0; j < 3; j++) {
            std::cout << board[i][j] << " | ";
        }
        std::cout << "\n—————————————\n";
    }
}

bool Board::validTurn(int row, int col) const {
    if ((row > 3 || row < 1) || (col > 3 || col < 1))
        return false;

    if (board[row - 1][col - 1] != ' ')
        return false;

    return true;
}

bool Board::checkWin() const {
    // Rows
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] &&
            board[i][1] == board[i][2] &&
            board[i][0] != ' ')
            return true;
    }

    // Columns
    for (int i = 0; i < 3; i++) {
        if (board[0][i] == board[1][i] &&
            board[1][i] == board[2][i] &&
            board[0][i] != ' ')
            return true;
    }

    // Diagonals
    if (board[0][0] == board[1][1] &&
        board[1][1] == board[2][2] &&
        board[0][0] != ' ')
        return true;

    if (board[0][2] == board[1][1] &&
        board[1][1] == board[2][0] &&
        board[0][2] != ' ')
        return true;

    return false;
}

bool Board::isDraw() const {
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (board[i][j] == ' ')
                return false;

    return true;
}

void Board::reset() {
    std::fill(&board[0][0], &board[0][0] + 9, ' ');
}

void Board::update_move(int row, int col, char x_or_o) {
    board[row - 1][col - 1] = x_or_o;
}

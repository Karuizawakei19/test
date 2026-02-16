#include "Game.hpp"
#include <iostream>

Game::Game() : playerTurn(1), x_or_o('X') {}

void Game::updateTurn() {
    if (playerTurn == 1) {
        playerTurn = 2;
        x_or_o = 'O';
    } else {
        playerTurn = 1;
        x_or_o = 'X';
    }
}

void Game::showPlayerTurn() const {
    std::cout << "Player Turn: " << playerTurn << "\n";
}

std::pair<int, int> Game::askForMove() const {
    std::cout << "What is your move (row col): ";
    int row, col;
    std::cin >> row >> col;
    return {row, col};
}

int Game::assignWinner() const {
    return (playerTurn == 2) ? 1 : 2;
}

void Game::showDraw() const {
    std::cout << "GAME OVER!!!\nDraw, No one wins!\n";
}

void Game::showWin() const {
    std::cout << "GAME OVER!!!\nPlayer "
              << assignWinner()
              << " Wins!\n";
}

bool Game::handleGameOver(Board& board) {
    char decision;
    std::cout << "Do you want to play again? (y/n): ";
    std::cin >> decision;

    if (decision == 'n') {
        std::cout << "Thank you for Playing! Bye!\n";
        return true;
    }

    board.reset();
    playerTurn = 1;
    x_or_o = 'X';
    return false;
}

void Game::start() {
    Board board;
    bool isGameOver = false;

    while (!isGameOver) {
        board.show();
        showPlayerTurn();

        auto move = askForMove();

        if (board.validTurn(move.first, move.second)) {
            board.update_move(move.first, move.second, x_or_o);
            updateTurn();

            if (board.checkWin()) {
                board.show();
                showWin();
                isGameOver = handleGameOver(board);
            }
            else if (board.isDraw()) {
                board.show();
                showDraw();
                isGameOver = handleGameOver(board);
            }
        }
        else {
            std::cout << "INVALID MOVE, TRY AGAIN!\n";
        }
    }
}

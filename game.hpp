#ifndef GAME_HPP
#define GAME_HPP

#include "Board.hpp"
#include <utility>

class Game {
private:
    int playerTurn;
    char x_or_o;

    void updateTurn();
    void showPlayerTurn() const;
    std::pair<int, int> askForMove() const;
    int assignWinner() const;
    void showDraw() const;
    void showWin() const;
    bool handleGameOver(Board& board);

public:
    Game();
    void start();
};

#endif

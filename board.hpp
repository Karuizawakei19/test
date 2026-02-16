#ifndef BOARD_HPP
#define BOARD_HPP

class Board {
private:
    char board[3][3];

public:
    Board(); // Constructor

    void show() const;
    bool validTurn(int row, int col) const;
    bool checkWin() const;
    bool isDraw() const;
    void reset();
    void update_move(int row, int col, char x_or_o);
};

#endif

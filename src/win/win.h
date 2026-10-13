#ifndef WIN_H
#define WIN_H

#include "../board/board.h"
#include <stdbool.h>

bool validateWin(int board[ROWS][COLS], int r, int c);

#endif

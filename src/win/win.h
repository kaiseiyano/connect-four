#ifndef WIN_H
#define WIN_H

#include "../board/board.h"
#include <stdbool.h>

bool validateWin(const struct Board *board, int r, int c);

#endif

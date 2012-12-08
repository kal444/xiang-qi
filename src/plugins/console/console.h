#ifndef CONSOLE_H
#define CONSOLE_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <ctype.h>
#include <curses.h>

#include "constants.h"
#include "plugin.h"

static int text_mode = PLAIN_TEXT;

bool console_init(void);
bool console_exit(void);

int console_draw_empty_board(int);

#endif /* CONSOLE_H */

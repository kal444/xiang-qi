#ifndef BOARD_H
#define BOARD_H

#define BOARD_HEIGHT 19
#define BOARD_WIDTH  33

char *board[] =
{
    /*          33                   */
    "+---+---+---+---+---+---+---+---+", /* 1 */
    "|   |   |   | \\ | / |   |   |   |", /* 2 */
    "|---+---+---+---*---+---+---+---|", /* 3 */
    "|   |   |   | / | \\ |   |   |   |", /* 4 */
    "|---#---+---+---+---+---+---#---|", /* 5 */
    "|   |   |   |   |   |   |   |   |", /* 6 */
    "#---+---#---+---#---+---#---+---#", /* 7 */
    "|   |   |   |   |   |   |   |   |", /* 8 */
    "|---+---+---+---+---+---+---+---|", /* 9 */
    "|                               |", /* 10 */
    "|---+---+---+---+---+---+---+---|", /* 11 */
    "|   |   |   |   |   |   |   |   |", /* 12 */
    "#---+---#---+---#---+---#---+---#", /* 13 */
    "|   |   |   |   |   |   |   |   |", /* 14 */
    "|---#---+---+---+---+---+---#---|", /* 15 */
    "|   |   |   | \\ | / |   |   |   |", /* 16 */
    "|---+---+---+---*---+---+---+---|", /* 17 */
    "|   |   |   | / | \\ |   |   |   |", /* 18 */
    "+---+---+---+---+---+---+---+---+", /* 19 */
};

#define PLAIN_TEXT  0
#define CURSES_TEXT 1
#define VGA_TEXT    2

/* to draw a top tee, or a bottom tee */
#define UPPER_RIVERBANK   9 -1
#define LOWER_RIVERBANK   11 -1

/* to draw a vertical line or a tee */
#define IS_VLINE(row)     row%2
#define IS_TEE(row)       !(row%2)

/* VGA line drawing characters */
#define VGA_ULCORNER 0xDA
#define VGA_URCORNER 0xBF
#define VGA_LLCORNER 0xC0
#define VGA_LRCORNER 0xD9
#define VGA_HLINE    0xC4
#define VGA_VLINE    0xB3
#define VGA_TTEE     0xC2
#define VGA_BTEE     0xC1
#define VGA_LTEE     0xC3
#define VGA_RTEE     0xB4
#define VGA_PLUS     0xC5
#define VGA_DLTEE    0xCC
#define VGA_DRTEE    0xB9
#define VGA_DPLUS    0xCE

#endif /* BOARD_H */

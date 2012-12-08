#include "console.h"

const char *
CCP_name(void)
{
    static const char plugin_name[] = "Console Xiang Qi";
    return plugin_name;
}

const char *
CCP_version(void)
{
    static const char plugin_version[] = "0.1";
    return plugin_version;
}

void
CCP_usage(void)
{
    fprintf(stderr, "Xiang Qi Plugin: %s %s\n", CCP_name(), CCP_version());
    fprintf(stderr, "Usage:  xiangqi [options] -p console -- [-h] -m text_mode\n");
    fprintf(stderr, " -h : this help screen\n");
    fprintf(stderr, " -m : text mode to use: plain (default), curses, or vga.\n");
    fprintf(stderr, "\n");
    CCP_exit(HELP_EXIT);
}

bool
CCP_init(int argc, char **argv)
{
    int c;
    
    while( (c = getopt(argc, argv, "hm:")) > 0)
    {
        switch (c)
        {
        case 'h':  /* help */
            CCP_usage();
            break;
        case 'm':
            switch(toupper(optarg[0]))
            {
            case 'C':
                text_mode = CURSES_TEXT;
                break;
            case 'V':
                text_mode = VGA_TEXT;
                break;
            case 'P':
            default:
                text_mode = PLAIN_TEXT;
            }
        }
    }

    return console_init();
}

int
CCP_run(void)
{
    console_draw_empty_board(text_mode);
    console_exit();
    CCP_exit(NORMAL_EXIT);
    return 0;
}

bool
console_init(void)
{
    initscr();
    if(has_colors()) 
    {
        start_color();
#ifdef NCURSES_VERSION
        if(use_default_colors() == OK)
        {
            /* let bg = -1 for default; */
        }
#endif
        /* init color for pieces, and board */
    }
    cbreak();
    noecho();
    nonl();
/*
    intrflush(stdscr, FALSE);
    keypad(stdscr, TRUE);
*/
    timeout(0);

    return TRUE;
}

bool
console_exit(void)
{
    endwin();
    return TRUE;
}

int
console_draw_empty_board(int type)
{
    register int i,j;
    
    for(i = 0; i < BOARD_HEIGHT; i++)
    {
        for(j = 0; j < BOARD_WIDTH; j++)
        {
            switch(type)
            {
            case PLAIN_TEXT:
                addch(board[i][j]);
                break;
            case CURSES_TEXT:
                switch(board[i][j])
                {
                case '-':
                    addch(ACS_HLINE);
                    break;
                case '+':
                    if (i == 0)
                        if (j == 0)
                            addch(ACS_ULCORNER);
                        else if (j == BOARD_WIDTH - 1)
                            addch(ACS_URCORNER);
                        else
                            addch(ACS_TTEE);
                    else if (i == BOARD_HEIGHT - 1)
                        if (j == 0)
                            addch(ACS_LLCORNER);
                        else if (j == BOARD_WIDTH - 1)
                            addch(ACS_LRCORNER);
                        else
                            addch(ACS_BTEE);
                    else if (i == UPPER_RIVERBANK)
                        addch(ACS_BTEE);
                    else if (i == LOWER_RIVERBANK)
                        addch(ACS_TTEE);
                    else
                        addch(ACS_PLUS);
                    break;
                case '|':
                    if (IS_VLINE(i))
                        addch(ACS_VLINE);
                    else if (IS_TEE(i))
                        if (j == 0)
                            addch(ACS_LTEE);
                        else if (j == BOARD_WIDTH - 1)
                            addch(ACS_RTEE);
                        else
                            addch(ACS_VLINE);
                    else
                        addch(ACS_VLINE);
                    break;
                default:
                    addch(board[i][j]);
                }
                break;
            case VGA_TEXT:
                switch(board[i][j])
                {
                case '-':
                    addch(VGA_HLINE);
                    break;
                case '+':
                    if (i == 0)
                        if (j == 0)
                            addch(VGA_ULCORNER);
                        else if (j == BOARD_WIDTH - 1)
                            addch(VGA_URCORNER);
                        else
                            addch(VGA_TTEE);
                    else if (i == BOARD_HEIGHT - 1)
                        if (j == 0)
                            addch(VGA_LLCORNER);
                        else if (j == BOARD_WIDTH - 1)
                            addch(VGA_LRCORNER);
                        else
                            addch(VGA_BTEE);
                    else if (i == UPPER_RIVERBANK)
                        addch(VGA_BTEE);
                    else if (i == LOWER_RIVERBANK)
                        addch(VGA_TTEE);
                    else
                        addch(VGA_PLUS);
                    break;
                case '|':
                    if (IS_VLINE(i))
                        addch(VGA_VLINE);
                    else if (IS_TEE(i))
                        if (j == 0)
                            addch(VGA_LTEE);
                        else if (j == BOARD_WIDTH - 1)
                            addch(VGA_RTEE);
                        else
                            addch(VGA_VLINE);
                    else
                        addch(VGA_VLINE);
                    break;
                case '#':
                    if (j == 0)
                        addch(VGA_DLTEE);
                    else if (j == BOARD_WIDTH - 1)
                        addch(VGA_DRTEE);
                    else
                        addch(VGA_DPLUS);
                    break;
                default:
                    addch(board[i][j]);
                }
                break;
            default:
                break;
            }
        }
        addch('\n');
    }
    refresh();
    return 0;
}

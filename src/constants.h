#ifndef CONSTANTS_H
#define CONSTANTS_H

#ifndef CURSES
 typedef char bool;
 #define TRUE    ((bool)1)
 #define FALSE   ((bool)0)
#endif

#define MAX_FILENAME_LEN 255

#define NORMAL_EXIT 0
#define HELP_EXIT   1

#endif /* CONSTANTS_H */

#ifndef PLUGIN_H
#define PLUGIN_H

#include "constants.h"
#include "board.h"

/*
  CCP_* functions are interface used by each plugin,
  They will be used by the main xiangqi loader, so
  they must be defined by plugin writers.

  The architecture here is the result of studying
  the plugin systerm of licq
*/

/* name returns name of plugin using static char [] */
const char *CCP_name(void);

/* version returns plugin version using static char [] */
const char *CCP_version(void);

/* usage prints usage information on this plugins */
void CCP_usage(void);

/* init initializes the plugin, it will be givern argc,
   and argv. It should always return */
bool CCP_init(int, char**);

/* run enters and starts to run the plugin */
int CCP_run(void);

/* exit will allow the plugin to exit */
void CCP_exit(int);

/* id is a unique number for this plugin */
unsigned int CCP_id;

/*
  =======================================================
  exit function for plugins
  =======================================================
*/

void
CCP_exit(int status)
{
    exit(status);
}

#endif /* PLUGIN_H */

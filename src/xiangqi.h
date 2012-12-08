#ifndef XIANGQI_H
#define XIANGQI_H

#include <stdio.h>
#include <string.h>

#include <unistd.h>
#include <stdlib.h>

#include <getopt.h>

#include <limits.h>

#include <dlfcn.h>

#include "constants.h"
#include "genlist.h"

struct CC_Plugin
{
    const char *(*name)(void);
    const char *(*version)(void);
    void (*usage)(void);
    bool (*init)(int, char**);
    void (*exit)(int);
    int (*run)(void);

    unsigned int *id;

    void *dl_handle;
};

typedef struct CC_Plugin CCPlugin_t;

const char *package(void);
const char *version(void);
bool load_plugin(const char *, CCPlugin_t *, int, char **);
void print_usage(void);

#endif /* XIANGQI_H */

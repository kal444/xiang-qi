/*
  Xiangqi (Chinese Chess)
  
  Copyrighted by Ke Huang. All rights reserved
  GPL to be inserted
*/

#include "xiangqi.h"

genlist *plugins = NULL;
unsigned int next_id = 1;

int
main(int argc, char **argv)
{
    int c;
    genlist *plugin_filenames = NULL;
    CCPlugin_t *temp;
    
    while( (c = getopt(argc, argv, "hp:")) > 0)
    {
        switch (c)
        {
        case 'h':  /* help */
            print_usage();
            break;
        case 'p':  /* new plugin */
            plugin_filenames = genlist_append(plugin_filenames, strdup(optarg));
            fprintf(stderr, "plugin: %s\n", optarg);
            break;
        }
    }

    plugin_filenames = genlist_first(plugin_filenames);
    while(plugin_filenames)
    {
        temp = (CCPlugin_t *)malloc(sizeof(CCPlugin_t));
        load_plugin((char *)plugin_filenames->data, temp, argc, argv);
        plugins = genlist_append(plugins, temp);

        plugin_filenames = plugin_filenames->next;
    }

    plugins = genlist_first(plugins);
    while(plugins)
    {
        /* eventually the following funcion call will be multi-threaded */
        (*((CCPlugin_t *)plugins->data)->run)();
        plugins = plugins->next;
    }
    
    exit(0);
}

bool
load_plugin(const char *libname, CCPlugin_t *prec, int argc, char **argv)
{
    void *handle;
    char *error;
    char plugfile[MAX_FILENAME_LEN];

    strcpy(plugfile, libname);

    handle = dlopen(plugfile, RTLD_NOW);
    if(!handle)
    {
        fprintf(stderr, "Error loading plugin (%s): %s.\n", plugfile, dlerror());
        return FALSE;
    }

    prec->name = (const char * (*)(void))dlsym(handle, "CCP_name");
    if((error = dlerror()))
    {
        fprintf(stderr, "Need CCP_name function in plugin (%s): %s.\n", plugfile, error);
        return FALSE;
    }

    prec->version = (const char* (*)(void))dlsym(handle, "CCP_version");
    if((error = dlerror()))
    {
        fprintf(stderr, "Need CCP_version function in plugin (%s): %s.\n", plugfile, error);
        return FALSE;
    }

    prec->usage = (void (*)(void))dlsym(handle, "CCP_usage");
    if((error = dlerror()))
    {
        fprintf(stderr, "Need CCP_usage function in plugin (%s): %s.\n", plugfile, error);
        return FALSE;
    }

    prec->init = (bool (*)(int, char**))dlsym(handle, "CCP_init");
    if((error = dlerror()))
    {
        fprintf(stderr, "Need CCP_init function in plugin (%s): %s.\n", plugfile, error);
        return FALSE;
    }

    prec->run = (int (*)(void))dlsym(handle, "CCP_run");
    if((error = dlerror()))
    {
        fprintf(stderr, "Need CCP_run function in plugin (%s): %s.\n", plugfile, error);
        return FALSE;
    }

    prec->exit = (void (*)(int))dlsym(handle, "CCP_exit");
    if((error = dlerror()))
    {
        fprintf(stderr, "Need CCP_exit function in plugin (%s): %s.\n", plugfile, error);
        return FALSE;
    }

    prec->id = (unsigned int *)dlsym(handle, "CCP_id");
    if((error = dlerror()))
    {
        fprintf(stderr, "Need CCP_id variable in plugin (%s): %s.\n", plugfile, error);
        return FALSE;
    }

    if(!(*prec->init)(argc, argv))
    {
        fprintf(stderr, "Cannot init plugin (%s).", plugfile);
        return FALSE;
    }
    
    *(prec->id) = next_id++;
    prec->dl_handle = handle;

    return TRUE;
}


void
print_usage(void)
{
    fprintf(stderr, "%s %s\n", package(), version());
    fprintf(stderr, "Usage: xiangqi [-h] [-p plugin] [-p plugin] \
-- <plugin #1 parameters> -- <plugin #2 paramemters>\n\n");
    fprintf(stderr, " -h: this help screen\n");
    fprintf(stderr, " -p: load the given plugin\n");
    fprintf(stderr, "\n");
    exit(HELP_EXIT);
}

const char *
package(void)
{
    static const char package[] = "Xiang Qi";
    return package;
}

const char *
version(void)
{
    static const char version[] = "0.1";
    return version;
}

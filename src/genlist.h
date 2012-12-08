#ifndef GENLIST_H
#define GENLIST_H

/* Doubly linked lists

   NULL is the empty list, so to get a new list:
   genlist_append(NULL, data)
 */
#include <stdlib.h>

struct _genlist;
typedef struct _genlist genlist;

struct _genlist
{
    void * data;
    genlist *next;
    genlist *prev;
};

#define genlist_previous(list)   ((list) ? (((genlist *)(list))->prev) : NULL)
#define genlist_next(list)       ((list) ? (((genlist *)(list))->next) : NULL)

genlist* genlist_alloc             (void);
void     genlist_free_1            (genlist          *list);
void     genlist_free              (genlist          *list);

genlist* genlist_first             (genlist          *list);
genlist* genlist_last              (genlist          *list);
int      genlist_length            (genlist          *list);
genlist* genlist_insert            (genlist          *list,
                                    void *            data,
                                    int               position);

genlist* genlist_append            (genlist          *list,
                                    void *            data);

genlist* genlist_prepend           (genlist          *list,
                                    void *            data);

genlist* genlist_remove            (genlist          *list,
                                    void *            data);


#endif /* GENLIST_H */

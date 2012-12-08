#include "genlist.h"

genlist *
genlist_alloc(void)
{
    return (genlist *)malloc(sizeof(genlist));
}

void
genlist_free_1(genlist *list)
{
    if(list)
    {
        free((void *)list);
    }
}

void
genlist_free(genlist *list)
{
    genlist *nextp;
    genlist *h = genlist_first(list);
    genlist *t = genlist_last(list);
    if(!h) /* h == t == NULL, empty list */
    {
        return;
    }
    while(h != t)
    {
        nextp = h->next;
        h = nextp;
        genlist_free_1(h);
    }
    genlist_free_1(nextp);
}

genlist *
genlist_first(genlist *list)
{
    genlist *p = list;
    if(p)
    {
        while(p->prev)
        {
            p = p->prev;
        }
    }
    return p;
}

genlist *
genlist_last(genlist *list)
{
    genlist *p = list;
    if(p)
    {
        while(p->next)
        {
            p = p->next;
        }
    }
    return p;
}

int
genlist_length(genlist *list)
{
    int count = 0;
    
    genlist *h = genlist_first(list);
    genlist *t = genlist_last(list);
    if(!h) /* h == t == NULL, empty list */
    {
        return count;
    }
    count++;
    while(h != t)
    {
        h = h->next;
        count++;
    }
    return count;
}

genlist *
genlist_insert(genlist *list, void *data, int position)
{
    genlist *p;
    genlist *h = genlist_first(list);
    
    /* assume the length was checked by user.
       0 is prepend, length is append */
    while(position--)
    {
        h = h->next;
    }

    if(!h)
    {
        return genlist_append(list, data);
    }

    if(!h->prev)
    {
        return genlist_prepend(list, data);
    }
    
    p = genlist_alloc();
    p->data = data;

    p->prev = h->prev;
    p->next = h;

    h->prev->next = p;
    h->prev = p;

    return p;
}

genlist *
genlist_append(genlist *list, void *data)
{
    genlist *p;
    genlist *t = genlist_last(list);

    p = genlist_alloc();
    p->data = data;

    if(t)
    {
        p->next = t->next;
        t->next = p;
    } else {
        p->next = NULL;
    }    
    p->prev = t;

    return p;
}

genlist *
genlist_prepend(genlist *list, void* data)
{
    genlist *p;
    genlist *h = genlist_first(list);
    
    p = genlist_alloc();
    p->data = data;

    if(h)
    {
        p->prev = h->prev;
        h->prev = p;
    } else {
        p->prev = NULL;
    }
    p->next = h;

    return p;
}

genlist *
genlist_remove(genlist *list, void *data)
{
    genlist *h = genlist_first(list);

    while(h && (h->data !=data))
    {
        h = h->next;
    }

    h->prev->next = h->next->prev = NULL;
    
    if(h->prev)
    {
        h->prev->next = h->next;
    }
    
    if(h->next)
    {
        h->next->prev = h->prev;
    }

    genlist_free_1(h);
    
    return NULL;
}

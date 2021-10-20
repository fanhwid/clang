/* populator.c */
#include <string.h>
#include "populator.h"

void set_unit(unit_t *p)
{
    if (p == NULL)
        return;
    p->number = 3;
    // p->msg = "Hello Worle!";
    strcpy(p->msg, "Hello World!");
}
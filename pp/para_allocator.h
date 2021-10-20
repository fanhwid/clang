/* para_allocator.h */
#ifndef PARA_ALLOCATOR_H
#define PARA_ALLOCATOR_H

typedef struct {
    int number;
    char *msg;
} unit_t;

void alloc_unit(unit_t **);
void free_unit(unit_t *);

#endif

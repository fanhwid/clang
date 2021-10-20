/* linkedlist.h */
#ifndef LINKEDLIST_H
#define LINKEDLIST_H

typedef struct node *link;
struct node {
    unsigned char elem;
    link next;
};

link make_node(unsigned char elem);
void free_node(link p);
link search(unsigned char elem);
void insert(link p);
void delet(link p);
void traverse(void (*visit)(link));
void destroy(void);
void push(link p);
link pop(void);

#endif
#ifndef __LINKEDLIST_H__
#define __LINKEDLIST_H__

#define QSIZE   50000000
#ifndef THNUM
#define THNUM   2
#endif
#define QUOTA   (QSIZE / THNUM)


// Queue Data Structure
typedef struct __node_t {
    int key;
    long tid;
    struct __node_t *next;
} node_t;
typedef struct __list_t {
    node_t *head;
    node_t *tail;
#ifdef MUTEX
    pthread_mutex_t lock;
#endif
} list_t;

// Queue functions
void list_add(int, long);
node_t* list_del();

// Global count functions
int inc_gcnt();
void dec_gcnt();

// Globals
extern int gcnt;
extern list_t *L;

#endif

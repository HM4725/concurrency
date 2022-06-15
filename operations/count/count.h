typedef struct __counter_t counter_t;
typedef long word_t;

counter_t* init(void*);
void   increment(counter_t*, void*);
void   decrement(counter_t*, void*);
word_t get(counter_t*);
void   destroy(counter_t*);


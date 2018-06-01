// LINKED LISTS //
// Header points to start and end. All lists are null terminated.

// CLIENT //
typedef void *elem;

typedef void elem_free(elem x);

// LIB //
typedef struct list_header *list_t;

list_t list_new();

unsigned int list_len(list_t L);

void list_append(list_t L, elem e);

void list_set(list_t L, elem e);

elem list_get(list_t L, unsigned int i);

void list_rem(list_t L, unsigned int i);

void list_free(list_t L, elem_free *F);

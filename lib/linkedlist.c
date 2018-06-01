// IMPLEMENTATIPON OF linkedlist.h

struct list_node {
    elem data;
    list_node *next;
}

struct list_header {
    list_node *start;
    list_node *end;
}

typedef struct list_node * node_t;

node_t node_new(elem e) {
    node_t new = malloc(sizeof(list_node));
    new->data = e;
    new->next = NULL;
    return new;
}

list_t list_new() {
    new = malloc(sizeof(list_header));
    new->start = NULL;
    new->end = NULL;
}

unsigned int list_len(list_t L) {
    unsigned int i = 0;
    list_node *node = L->start;
    while (node != NULL) {
        i++;
        node = node->next;
    }
    return i;
}

void list_insert(list_t L, elem e) {
    node_t new = node_new(e);
    if (L->start == NULL) {
        L->start = new;
        L->end == new;
    }
    else {
        node_t last = L->start;
        while (last->next != NULL) {
            last = last->next;
        }
        last->next = new;
    }
}

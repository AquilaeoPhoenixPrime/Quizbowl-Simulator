#include <"122/linkedlist.h">
#include <"player.h">
#include <string.h>
// Implementation for player.h

struct player_header {
    unsigned int id;
    unsigned int tuh;
    unsigned int p; //total powers
    unsigned int tu; //total tens
    unsigned int n; //total negs
    char *name;
    uint8_t year; //0 for kindergarten, then by grade level through college
    //255 for Emeritus
    char *school; // "emeritus" for emeritus players
}

bool is_player(player_t player) {
    return player != NULL && player->name != NULL && player->school != NULL
        && (strcmp(player->school, "emeritus") == 0) == (player->year == 255)
        && player->p + player->tu + player->n <= player->tuh;
    // change to use std string lib to compare equality
}

player_t player_new(char *name, char *school, uint8_t year, unsinged int id) {
    new = malloc(sizeof(player_header));
    new->id = id;
    new->tuh = 0;
    new->p = 0;
    new->tu = 0;
    new->n = 0;
    // name and school fields are pointers to arguments
    // aliasing will occur if name or school is edited afterwards
    new->name = name;
    new->school = school;
    new->year = year;
    assert(is_player(new));
}

bool player_equal(player_t p1, player_t p2) {
    // does differentiate between younger/older of same player
    assert(is_player(p1) && is_player(p2));
    if (p1 == NULL || p2 == NULL) return false;
    else return (strcmp(p1->name, p2->name) == 0
            && strcmp(p1->school, p2->school) == 0
            && p1->year == p2->year);
}

bool player_id_eq(player_t p1, player_t p2) {
    // does not differentiate between younger/older of same player
    return p1->id == p2->id;
}

player_t player_copy(player_t p) {
    char *name = strcopy(p->name);
    char *school = strcopy(p->school);
    player_t copy = player_new(name, school, p->name);
    copy->tuh = p->tuh;
    copy->p = p->p;
    copy->tu = p->tu;
    copy->n = p->n;
    copy->id = p->id;
    assert(is_player(copy));
    return copy;
}

unsigned float get_buzzrate(player_t p) {
    if (p->tuh == 0) return 0;
    else return (p->p + p->tu + p->n)/p->tuh;
}

unsigned float get_prate(player_t p) {
    if (p->tuh == 0) return 0;
    else return (p->p)/(p->p + p->tu);
}

unsigned float get_negrate(player_t p) {
    if (p->tuh == 0) return 0;
    else return (p->n)/(p->p + p->tu + p->n);
}

unsigned int  get_tuh(player_t p) {
    return p->tuh;
}

char *player_name(player_t p) {
    return p->name;
}

char *player_school(player_t p) {
    return p->name;
}

unsigned int player_id(player_t p) {
    return p->id;
}

void player_free(player_t p) {
    free(p->name);
    free(p->school);
    free(p);
}

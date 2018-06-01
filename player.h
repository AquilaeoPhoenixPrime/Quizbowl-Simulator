// INTERFACE FOR PLAYER OPERATIONS //
// Sebastien La Duca 5-31-2018 //
//

struct player_header;

typedef struct *player_header player_t;

bool is_player(player_t player);
// data structure invariant //

player_t player_new(char *name, char *school, uint8_t year);
// ENSURES(is_player(\result));
// name and school are passed and set by reference

bool player_equal(player_t p1, player_t p2);
// return true if p1 and p2 are instances of the same player

bool player_id_eq(player_t p1, player_t p2);
// return true if p1 and p2 have same id

player_t player_copy(player_t p);
// copy player

unsigned float get_buzzrate(player_t p);
// calculate buzz rate = (Powers + gets + negs)/tuh
// 0 if tuh is 0

unsigned float get_prate(player_t p);
// calculate prate; prate is 0 if player heard no tossups

unsigned float get_negrate(player_t p);
// calculate negrate; negrate is 0 if player heard no tossups

char *player_name(player_t p);
// return player name
// returns address
// DO NOT MODIFY RETURNED VALUE

unsigned int get_tuh(player_t p) {
    return p->tuh;
}

char *player_school(player_t p);
// return player's school
// returns address
// DO NOT MODIFY RETURNED VALUE

unsigned int player_id(player_t p);
// return player's ID

void player_free(player_t p);
// free memory

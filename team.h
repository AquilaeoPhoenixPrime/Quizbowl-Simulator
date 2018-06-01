// INTERFACE FOR TEAMS
#include <"player.h">

struct team_header;

typedef struct team_header* team_t;

bool is_team(team_t t);

team_t team_new(char* name, player_t* players);

bool on_team(team_t t, player_t p);

player_t get_player(team_t t, uint8_t i);

unsigned float get_ppb(team_t t);

//
// Created by JAD on 06/09/2023.
//

#ifndef EFREI2023_24_LLC_TEAM_H
#define EFREI2023_24_LLC_TEAM_H

#include "character.h"

typedef struct Teammate {
    Character *value;
    struct Teammate *next;
} Teammate;

typedef struct Team {
    char name[100];
    Teammate *head;
} Team;

Team *createTeam(char *name);

void addToTeam(Team *team, Character *character);

void addFirstToTeam(Team *team, Character *character);

void displayTeam(Team *team);

void recursiveDisplayTeam(Team *team);

void deleteCharacterFromTeam(Team *team, Character *character);

void recursiveDeleteCharacterFromTeam(Team *team, Character *character);

#endif //EFREI2023_24_LLC_TEAM_H

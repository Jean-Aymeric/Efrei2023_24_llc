//
// Created by JAD on 06/09/2023.
//

#include "team.h"

Team *createTeam(char *name) {
    Team *team = (Team *) malloc(sizeof(Team));
    strcpy(team->name, name);
    team->head = NULL;
    return team;
}

Teammate *createTeammate(Character *character) {
    Teammate *teammate = (Teammate *) malloc(sizeof(Teammate));
    teammate->value = character;
    teammate->next = NULL;
    return teammate;
}

void addToTeam(Team *team, Character *character) {
    Teammate *teammate = createTeammate(character);
    if (team->head == NULL) {
        team->head = teammate;
    } else {
        Teammate *temp = team->head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = teammate;
    }
}

void displayTeammate(Teammate* teammate){
    displayCharacter(teammate->value);
}


void displayTeam(Team *team) {
    printf("Team : %s\n", team->name);
    Teammate *temp = team->head;
    while (temp != NULL) {
        displayTeammate(temp);
        temp = temp->next;
    }
}
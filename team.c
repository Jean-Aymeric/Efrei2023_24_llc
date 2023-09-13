//
// Created by JAD on 06/09/2023.
//

#include "team.h"

void recursiveDisplayTeammate(Teammate *pTeammate);

Team *createTeam(char *name) {
    Team *team = (Team *) malloc(sizeof(Team));
    strcpy(team->name, name);
    team->head = NULL;
    return team;
}

void deleteTeammate(Teammate *teammate) {
    free(teammate);
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

void addFirstToTeam(Team *team, Character *character) {
    Teammate *teammate = createTeammate(character);
    teammate->next = team->head;
    team->head = teammate;
}

void displayTeammate(Teammate *teammate) {
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

void recursiveDisplayTeammate(Teammate *teammate) {
    if (teammate != NULL) {
        displayCharacter(teammate->value);
        recursiveDisplayTeammate(teammate->next);
    }
}

void recursiveDisplayTeam(Team *team) {
    printf("Team : %s\n", team->name);
    recursiveDisplayTeammate(team->head);
}

void deleteCharacterFromTeam(Team *team, Character *character) {
    Teammate *temp = team->head;
    Teammate *ptemp = NULL;
    if ((team->head != NULL) && (team->head->value == character)) {
        ptemp = team->head;
        team->head = team->head->next;
        deleteTeammate(ptemp);
    } else {
        while (temp->next != NULL) {
            if (temp->next->value == character) {
                ptemp = temp->next;
                temp->next = temp->next->next;
                deleteTeammate(ptemp);
            }
            temp = temp->next;
        }
    }
}

Teammate *recursiveDeleteCharacterFromTeamByTeammate(Teammate *teammate, Character *character) {
    if (teammate != NULL) {
        if (teammate->value == character) {
            Teammate *temp = teammate->next;
            deleteTeammate(teammate);
            return temp;
        } else {
            teammate->next = recursiveDeleteCharacterFromTeamByTeammate(teammate->next, character);
            return teammate;
        }
    } else {
        return NULL;
    }
}

void recursiveDeleteCharacterFromTeam(Team *team, Character *character) {
    team->head = recursiveDeleteCharacterFromTeamByTeammate(team->head, character);
}



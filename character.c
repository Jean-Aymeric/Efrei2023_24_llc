//
// Created by JAD on 06/09/2023.
//

#include "character.h"



Character *createCharacter(char *name, int lifePoints, int level){
    Character *character = (Character*)malloc (sizeof(Character));
    strcpy(character->name,name);
    character->lifePoints = lifePoints;
    character->level = level;
    return character;
}

void deleteCharacter(Character *character){
    if(character != NULL){
        free(character);
    }
}

void displayCharacter(Character *character){
    printf("Name : %s \tLife Points : %d \tLevel : %d\n",character->name, character->lifePoints,character->level);
}
//
// Created by JAD on 06/09/2023.
//

#ifndef EFREI2023_24_LLC_CHARACTER_H
#define EFREI2023_24_LLC_CHARACTER_H
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct Character {
    char name[100];
    int lifePoints;
    int level;
} Character;

Character *createCharacter(char *name, int lifePoints, int level);

void deleteCharacter(Character *character);

void displayCharacter(Character *character);

#endif //EFREI2023_24_LLC_CHARACTER_H

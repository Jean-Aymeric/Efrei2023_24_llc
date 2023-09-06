#include <stdio.h>
#include "team.h"

int main() {
    Team *team = createTeam("L2");
    addToTeam(team, createCharacter("Valentin", 20, 10));
    addToTeam(team, createCharacter("Samy", 20, 10));
    addToTeam(team, createCharacter("Jayan", 20, 10));
    addToTeam(team, createCharacter("Hugo", 20, 10));
    displayTeam(team);
    return 0;
}

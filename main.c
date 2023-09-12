#include <stdio.h>
#include "team.h"

int main() {
    Team *team = createTeam("L2");
    addToTeam(team, createCharacter("Valentin", 20, 10));
    Character *jayan = createCharacter("Jayan", 20, 10);
    addToTeam(team, jayan);
    addToTeam(team, createCharacter("Samy", 20, 10));

    Character *hugo = createCharacter("Hugo", 20, 10);
    addFirstToTeam(team, hugo);

    displayTeam(team);
    deleteCharacterFromTeam(team, hugo);
    deleteCharacterFromTeam(team, jayan);
    recursiveDisplayTeam(team);
    return 0;
}

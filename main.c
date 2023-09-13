#include <stdio.h>
#include "team.h"
#include "product.h"

int main() {
    Team *team = createTeam("L2");
    addToTeam(team, createCharacter("Valentin", 20, 10));
    Character *jayan = createCharacter("Jayan", 20, 10);
    addToTeam(team, jayan);
    addToTeam(team, createCharacter("Samy", 20, 10));

    Character *hugo = createCharacter("Hugo", 20, 10);
    addFirstToTeam(team, hugo);

    displayTeam(team);
    recursiveDeleteCharacterFromTeam(team, hugo);
    recursiveDeleteCharacterFromTeam(team, jayan);
    recursiveDisplayTeam(team);

    ProductList productList;


    addProductInProductList(&productList, createProduct("Smartphone 2", 400, 0.2));
    addProductInProductList(&productList, createProduct("Smartphone 3", 300, 0.2));
    addProductInProductList(&productList, createProduct("Smartphone 1", 200, 0.2));
    displayProductList(productList);

    printf("Nb éléments : %d\n", countProductsInList(productList));
    printf("Tri croissant : %d\n", isProductListOrderedByPrice(productList));
    return 0;
}

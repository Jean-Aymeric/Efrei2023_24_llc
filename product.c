//
// Created by JAD on 13/09/2023.
//

#include "product.h"

void displayAllProductCells(ProductCell *productCell);

void deleteAllProductCells(ProductCell *productCell);

int countAllProductCells(ProductCell *pCell);

int isProductInProductCells(ProductCell *productCell, Product *product);

int isAllProductCellsOrderedByPrice(ProductCell *productCell);

ProductCell *removeProductCellFromProductCells(ProductCell *productCell, Product *product);

Product *createProduct(char name[30], float basePrice, float VATRate) {
    Product *newProduct = (Product *) malloc(sizeof(Product));
    strcpy(newProduct->name, name);
    newProduct->basePrice = basePrice;
    newProduct->VATRate = VATRate;
    return newProduct;
}

void deleteProduct(Product *product) {
    if (product != NULL) {
        free(product);
    }
}

void displayProduct(Product product) {
    printf("Produit : %s\n\tPrix : %0.2f\n", product.name, product.basePrice * (1 + product.VATRate));
}

ProductCell *createProductCell(Product *product) {
    ProductCell *newProductCell = (ProductCell *) malloc(sizeof(ProductCell));
    newProductCell->product = product;
}

void deleteProductCell(ProductCell *productCell) {
    if (productCell != NULL) {
        free(productCell);
    }
}

void deleteAllProductCells(ProductCell *productCell) {
    if (productCell != NULL) {
        deleteAllProductCells(productCell->next);
        deleteProductCell(productCell);
    }
}

void displayProductList(ProductList productList) {
    displayAllProductCells(productList.head);
}

void displayAllProductCells(ProductCell *productCell) {
    if (productCell != NULL) {
        displayProduct(*(productCell->product));
        displayAllProductCells(productCell->next);
    }
}

void removeProductFromList(ProductList *productList, Product *product) {
    productList->head = removeProductCellFromProductCells(productList->head, product);
}

ProductCell *removeProductCellFromProductCells(ProductCell *productCell, Product *product) {
    if (productCell != NULL) {
        if (productCell->product == product) {
            ProductCell *temp = productCell->next;
            deleteProductCell(productCell);
            return temp;
        } else {
            productCell->next = removeProductCellFromProductCells(productCell->next, product);
            return productCell;
        }
    } else {
        return NULL;
    }
}

void removeAllProductsFromList(ProductList *productList) {
    deleteAllProductCells(productList->head);
    productList->head = NULL;
}

int countProductsInList(ProductList productList) {
    return countAllProductCells(productList.head);
}

int countAllProductCells(ProductCell *productCell) {
    if (productCell == NULL) {
        return 0;
    } else {
        return 1 + countAllProductCells(productCell->next);
    }
}

int isProductInList(ProductList *productList, Product *product) {
    return isProductInProductCells(productList->head, product);
}

int isProductInProductCells(ProductCell *productCell, Product *product) {
    if (productCell == NULL) {
        return 0;
    } else if (productCell->product == product) {
        return 1;
    } else {
        return isProductInProductCells(productCell->next, product);
    }
}

int isProductListOrderedByPrice(ProductList productList) {
    return isAllProductCellsOrderedByPrice(productList.head);
}

int isAllProductCellsOrderedByPrice(ProductCell *productCell) {
    if ((productCell == NULL) || (productCell->next == NULL)) {
        return 1;
    } else if (productCell->product->basePrice <= productCell->next->product->basePrice) {
        return isAllProductCellsOrderedByPrice(productCell->next);
    } else {
        return 0;
    }
}

void addProductInProductList(ProductList *productList, Product *product) {
    ProductCell *newproductCell = createProductCell(product);
    newproductCell->next = productList->head;
    productList->head = newproductCell;
}
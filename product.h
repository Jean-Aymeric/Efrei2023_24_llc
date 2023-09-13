//
// Created by JAD on 13/09/2023.
//
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#ifndef EFREI2023_24_LLC_PRODUCT_H
#define EFREI2023_24_LLC_PRODUCT_H

typedef struct Product {
    char name[30];
    float basePrice;
    float VATRate;
} Product;

typedef struct ProductCell {
    Product *product;
    struct ProductCell *next;
} ProductCell;

typedef struct ProductList {
    ProductCell *head;
} ProductList;

Product *createProduct(char name[30], float basePrice, float VATRate);

void deleteProduct(Product *product);

void displayProduct(Product product);

ProductCell *createProductCell(Product *product);

void deleteProductCell(ProductCell *productCell);

void deleteProductList(ProductList *productList);

void removeProductFromList(ProductList *productList, Product *product);

void removeAllProductsFromList(ProductList *productList);

void addProductInProductList(ProductList *productList, Product *product);

int countProductsInList(ProductList productList);

int isProductInList(ProductList *productList, Product *product);

int isProductListOrderedByPrice(ProductList productList);

void displayProductList(ProductList productList);

#endif //EFREI2023_24_LLC_PRODUCT_H

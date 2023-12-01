#ifndef FUNC_H
#define FUNC_H

#define MAX_PRODUCTS 100
#define MAX_CARACTERS 50

extern int numProducts;
extern int products[MAX_PRODUCTS][4]; //son varibles globales es decir se pueden usar en todo el programa.

void createProduct();
void updateProduct();
void deleteProduct();
void readProducts();

#endif /// Esto evita la inclusión de este archivo dos veces o mas.
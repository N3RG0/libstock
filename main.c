#include <stdio.h>
#include "lectu.h"
#include "menu.h"
#include "func.h"
#define MAX_PRODUCTS 100
//  By N3RG0 
int main(){
    int opt;
    do
    {
        opt=menuOpcion();
        switch (opt)
        {
            //vamos a simular un CRUD de una base de datos.
            case 1:
                createProduct();
                break;
            case 2:
                updateProduct();
                break;
            case 3:
                deleteProduct();
                break;
            case 4:
                readProducts();
                break;
            case 5:
                printf("Hasta luego !!\n");
                break;
            default:
                printf("Opcion no valida. Por favor, ingrese una opcion correcta.\n");
                break;
        }
    } while (opt != 5);
    
    return 0;
}
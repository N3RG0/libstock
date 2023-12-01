#include <stdio.h>
#include <string.h>
#include "func.h"
#include "lectu.h"
#include "menu.h"

#define MAX_PRODUCTS 100
#define MAX_NAME_LENGTH 50

char productos[MAX_PRODUCTS][4][MAX_NAME_LENGTH];
int numProductos = 0;

void createProduct() {
    static int id = 1;
    if (numProductos < MAX_PRODUCTS) {
        sprintf(productos[numProductos][0], "%d", id);

        printf("Ingrese el nombre del producto: ");
        getchar(); 
        fgets(productos[numProductos][1], sizeof(productos[numProductos][1]), stdin);
        productos[numProductos][1][strcspn(productos[numProductos][1], "\n")] = '\0';

        printf("Ingrese la cantidad del producto: ");
        scanf("%s", productos[numProductos][2]);

        printf("Ingrese el precio del producto: ");
        scanf("%s", productos[numProductos][3]);
        id++;
        numProductos++;
        printf("Producto agregado correctamente.\n");
    } else {
        printf("No se pueden agregar más productos, límite alcanzado.\n");
    }
}

void readProducts() {
    if (numProductos == 0) {
        printf("No hay productos para mostrar.\n");
    } else {
        printf("     Listado de productos:\n");
        printf("ID\tNombre\t\t\tCantidad\tPrecio\n");
        for (int i = 0; i < numProductos; i++) {
            printf("%s\t%-20s\t%s\t\t$%s\n", productos[i][0], productos[i][1], productos[i][2], productos[i][3]);
        }
    }
}

void updateProduct() {
    char id[MAX_NAME_LENGTH];
    printf("Ingrese el ID del producto a editar: ");
    scanf("%s", id);

    int indice = -1;
    for (int i = 0; i < numProductos; i++) {
        if (strcmp(productos[i][0], id) == 0) {
            int opcion;
            opcion = menuEdit();
            switch (opcion) {
                case 1:
                    printf("Ingrese el nuevo nombre del producto: ");
                    getchar(); // Limpiar el buffer
                    fgets(productos[i][1], sizeof(productos[i][1]), stdin);
                    productos[i][1][strcspn(productos[i][1], "\n")] = '\0'; // Eliminar el salto de línea
                    printf("Nombre actualizado correctamente.\n");
                    break;
                case 2:
                    printf("Ingrese la nueva cantidad del producto: ");
                    scanf("%s", productos[i][2]);
                    printf("Cantidad actualizada correctamente.\n");
                    break;
                case 3:
                    printf("Ingrese el nuevo precio del producto: ");
                    scanf("%s", productos[i][3]);
                    printf("Precio actualizado correctamente.\n");
                    break;
                default:
                    printf("Opción no válida.\n");
                    break;
            }
            return;
        }
    }
    printf("Producto no encontrado.\n");
}

void deleteProduct() {
    char id[MAX_NAME_LENGTH];
    printf("Ingrese el ID del producto a eliminar: ");
    scanf("%s", id);

    int indice = -1;
    for (int i = 0; i < numProductos; i++) {
        if (strcmp(productos[i][0], id) == 0) {
            indice = i;
            break;
        }
    }

    if (indice != -1) {
        for (int i = indice; i < numProductos - 1; i++) {
            strcpy(productos[i][0], productos[i + 1][0]);
            strcpy(productos[i][1], productos[i + 1][1]);
            strcpy(productos[i][2], productos[i + 1][2]);
            strcpy(productos[i][3], productos[i + 1][3]);
        }
        numProductos--;
        printf("Producto eliminado correctamente.\n");
    } else {
        printf("Producto no encontrado.\n");
    }
}
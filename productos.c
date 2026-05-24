#include "productos.h"
#include "utilidades.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void inicializar_inventario(Inventario *inv) {
    inv->total_productos = 0;
}

void agregar_producto(Inventario *inv) {
    if (inv->total_productos >= MAX_PRODUCTOS) {
        printf("❌ Inventario lleno. No se pueden agregar más productos.\n");
        pausa();
        return;
    }

    limpiar_pantalla();
    mostrar_encabezado("AGREGAR NUEVO PRODUCTO");

    Producto p;
    p.id = inv->total_productos + 1;

    printf("SKU: ");
    leer_cadena(p.sku, MAX_SKU);

    if (buscar_producto_por_sku(inv, p.sku) != -1) {
        printf("❌ El SKU ya existe.\n");
        pausa();
        return;
    }

    printf("Descripción: ");
    leer_cadena(p.descripcion, MAX_DESCRIPCION);

    printf("Precio unitario: $");
    p.precio_unitario = leer_flotante();

    printf("Cantidad en stock: ");
    p.cantidad_stock = leer_entero();

    printf("Cantidad mínima para alerta: ");
    p.cantidad_minima = leer_entero();

    inv->productos[inv->total_productos] = p;
    inv->total_productos++;

    printf("\n✅ Producto agregado exitosamente.\n");
    printf("ID del producto: %d\n", p.id);
    pausa();
}

void modificar_producto(Inventario *inv) {
    limpiar_pantalla();
    mostrar_encabezado("MODIFICAR PRODUCTO");

    printf("Ingrese el ID del producto a modificar: ");
    int id = leer_entero();

    int indice = buscar_producto_por_id(inv, id);
    if (indice == -1) {
        printf("❌ Producto no encontrado.\n");
        pausa();
        return;
    }

    Producto *p = &inv->productos[indice];

    printf("\nProducto encontrado:\n");
    printf("SKU: %s\n", p->sku);
    printf("Descripción: %s\n", p->descripcion);
    printf("Precio: $%.2f\n", p->precio_unitario);
    printf("Stock: %d\n", p->cantidad_stock);

    printf("\n¿Qué desea modificar?\n");
    printf("1. Descripción\n");
    printf("2. Precio\n");
    printf("3. Stock\n");
    printf("4. Cantidad mínima\n");
    printf("Seleccione opción: ");
    int opcion = leer_entero();

    switch (opcion) {
        case 1:
            printf("Nueva descripción: ");
            leer_cadena(p->descripcion, MAX_DESCRIPCION);
            printf("✅ Descripción actualizada.\n");
            break;
        case 2:
            printf("Nuevo precio: $");
            p->precio_unitario = leer_flotante();
            printf("✅ Precio actualizado.\n");
            break;
        case 3:
            printf("Nuevo stock: ");
            p->cantidad_stock = leer_entero();
            printf("✅ Stock actualizado.\n");
            break;
        case 4:
            printf("Nueva cantidad mínima: ");
            p->cantidad_minima = leer_entero();
            printf("✅ Cantidad mínima actualizada.\n");
            break;
        default:
            printf("❌ Opción no válida.\n");
    }

    pausa();
}

void visualizar_productos(Inventario *inv) {
    limpiar_pantalla();
    mostrar_encabezado("INVENTARIO DE PRODUCTOS");

    if (inv->total_productos == 0) {
        printf("No hay productos registrados.\n");
        pausa();
        return;
    }

    printf("%-5s %-10s %-30s %-12s %-10s\n", "ID", "SKU", "Descripción", "Precio", "Stock");
    mostrar_linea_separadora();

    for (int i = 0; i < inv->total_productos; i++) {
        Producto *p = &inv->productos[i];
        printf("%-5d %-10s %-30s $%-11.2f %-10d", p->id, p->sku, p->descripcion, 
               p->precio_unitario, p->cantidad_stock);
        
        if (p->cantidad_stock < p->cantidad_minima) {
            printf(" ⚠️ STOCK BAJO");
        }
        printf("\n");
    }

    pausa();
}

int buscar_producto_por_id(Inventario *inv, int id) {
    for (int i = 0; i < inv->total_productos; i++) {
        if (inv->productos[i].id == id) {
            return i;
        }
    }
    return -1;
}

int buscar_producto_por_sku(Inventario *inv, const char *sku) {
    for (int i = 0; i < inv->total_productos; i++) {
        if (strcmp(inv->productos[i].sku, sku) == 0) {
            return i;
        }
    }
    return -1;
}

void eliminar_producto(Inventario *inv) {
    limpiar_pantalla();
    mostrar_encabezado("ELIMINAR PRODUCTO");

    printf("Ingrese el ID del producto a eliminar: ");
    int id = leer_entero();

    int indice = buscar_producto_por_id(inv, id);
    if (indice == -1) {
        printf("❌ Producto no encontrado.\n");
        pausa();
        return;
    }

    printf("Producto: %s\n", inv->productos[indice].descripcion);
    printf("¿Confirma la eliminación? (1=Sí, 0=No): ");
    int confirmacion = leer_entero();

    if (confirmacion == 1) {
        for (int i = indice; i < inv->total_productos - 1; i++) {
            inv->productos[i] = inv->productos[i + 1];
        }
        inv->total_productos--;
        printf("✅ Producto eliminado.\n");
    }

    pausa();
}

void verificar_stock_bajo(Inventario *inv) {
    limpiar_pantalla();
    mostrar_encabezado("PRODUCTOS CON STOCK BAJO");

    int encontrados = 0;
    printf("%-5s %-10s %-30s %-10s %-10s\n", "ID", "SKU", "Descripción", "Stock", "Mínimo");
    mostrar_linea_separadora();

    for (int i = 0; i < inv->total_productos; i++) {
        if (inv->productos[i].cantidad_stock < inv->productos[i].cantidad_minima) {
            Producto *p = &inv->productos[i];
            printf("%-5d %-10s %-30s %-10d %-10d\n", p->id, p->sku, p->descripcion,
                   p->cantidad_stock, p->cantidad_minima);
            encontrados++;
        }
    }

    if (encontrados == 0) {
        printf("No hay productos con stock bajo.\n");
    } else {
        printf("\nTotal de productos con stock bajo: %d\n", encontrados);
    }

    pausa();
}

void guardar_productos(Inventario *inv) {
    FILE *archivo = fopen("datos/productos.dat", "wb");
    if (!archivo) {
        printf("Error al guardar productos.\n");
        return;
    }

    fwrite(&inv->total_productos, sizeof(int), 1, archivo);
    fwrite(inv->productos, sizeof(Producto), inv->total_productos, archivo);
    fclose(archivo);
}

void cargar_productos(Inventario *inv) {
    FILE *archivo = fopen("datos/productos.dat", "rb");
    if (!archivo) {
        inv->total_productos = 0;
        return;
    }

    fread(&inv->total_productos, sizeof(int), 1, archivo);
    fread(inv->productos, sizeof(Producto), inv->total_productos, archivo);
    fclose(archivo);
}

#ifndef PRODUCTOS_H
#define PRODUCTOS_H

#define MAX_PRODUCTOS 1000
#define MAX_DESCRIPCION 100
#define MAX_SKU 20

typedef struct {
    int id;
    char sku[MAX_SKU];
    char descripcion[MAX_DESCRIPCION];
    float precio_unitario;
    int cantidad_stock;
    int cantidad_minima;
} Producto;

typedef struct {
    Producto productos[MAX_PRODUCTOS];
    int total_productos;
} Inventario;

// Funciones de productos
void inicializar_inventario(Inventario *inv);
void agregar_producto(Inventario *inv);
void modificar_producto(Inventario *inv);
void visualizar_productos(Inventario *inv);
void guardar_productos(Inventario *inv);
void cargar_productos(Inventario *inv);
int buscar_producto_por_id(Inventario *inv, int id);
int buscar_producto_por_sku(Inventario *inv, const char *sku);
void eliminar_producto(Inventario *inv);
void verificar_stock_bajo(Inventario *inv);

#endif

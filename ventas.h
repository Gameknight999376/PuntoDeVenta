#ifndef VENTAS_H
#define VENTAS_H

#include "productos.h"
#include "clientes.h"
#include <time.h>

#define MAX_ITEMS_VENTA 50
#define MAX_VENTAS 10000

typedef struct {
    int id_producto;
    int cantidad;
    float precio_unitario;
    float subtotal;
} ItemVenta;

typedef struct {
    int numero_venta;
    time_t fecha;
    int id_cliente;
    ItemVenta items[MAX_ITEMS_VENTA];
    int total_items;
    float subtotal;
    float descuento;
    float impuesto;
    float total;
    char metodo_pago[20];
} NotaVenta;

typedef struct {
    NotaVenta ventas[MAX_VENTAS];
    int total_ventas;
    int proximo_numero_venta;
} RegistroVentas;

// Funciones de ventas
void inicializar_ventas(RegistroVentas *rv);
void crear_nota_venta(RegistroVentas *rv, Inventario *inv, BaseDatos *db);
void agregar_item_venta(NotaVenta *nv, ItemVenta item);
void calcular_total_venta(NotaVenta *nv, float descuento_cliente);
void visualizar_nota_venta(NotaVenta *nv, BaseDatos *db, Inventario *inv);
void generar_comprobante(NotaVenta *nv, BaseDatos *db, Inventario *inv);
void guardar_ventas(RegistroVentas *rv);
void cargar_ventas(RegistroVentas *rv);
void mostrar_historial_ventas(RegistroVentas *rv, BaseDatos *db, Inventario *inv);
float calcular_impuesto(float subtotal);
NotaVenta* buscar_venta(RegistroVentas *rv, int numero_venta);

#endif

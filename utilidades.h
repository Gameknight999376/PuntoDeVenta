#ifndef UTILIDADES_H
#define UTILIDADES_H

#include <stdio.h>

// Funciones de entrada/salida
void limpiar_pantalla();
void pausa();
void limpiar_buffer();
int leer_entero();
float leer_flotante();
void leer_cadena(char *cadena, int max_caracteres);
int menu_principal();
int menu_productos();
int menu_clientes();
int menu_ventas();

// Funciones de validación
int validar_entero_positivo(int valor);
int validar_flotante_positivo(float valor);
int validar_rfc_formato(const char *rfc);

// Funciones de formato
void mostrar_encabezado(const char *titulo);
void mostrar_linea_separadora();
void formato_moneda(float cantidad);
void formato_fecha(time_t fecha);

#endif

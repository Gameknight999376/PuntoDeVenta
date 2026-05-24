#ifndef CLIENTES_H
#define CLIENTES_H

#define MAX_CLIENTES 500
#define MAX_NOMBRE 50
#define MAX_RFC 13
#define MAX_TELEFONO 15
#define MAX_EMAIL 50
#define MAX_DIRECCION 100

typedef struct {
    int id;
    char nombre[MAX_NOMBRE];
    char rfc[MAX_RFC];
    char telefono[MAX_TELEFONO];
    char email[MAX_EMAIL];
    char direccion[MAX_DIRECCION];
    float descuento_porcentaje;
    float credito_disponible;
} Cliente;

typedef struct {
    Cliente clientes[MAX_CLIENTES];
    int total_clientes;
} BaseDatos;

// Funciones de clientes
void inicializar_base_datos(BaseDatos *db);
void agregar_cliente(BaseDatos *db);
void modificar_cliente(BaseDatos *db);
void visualizar_clientes(BaseDatos *db);
void guardar_clientes(BaseDatos *db);
void cargar_clientes(BaseDatos *db);
int buscar_cliente_por_id(BaseDatos *db, int id);
int buscar_cliente_por_rfc(BaseDatos *db, const char *rfc);
void eliminar_cliente(BaseDatos *db);
float obtener_descuento_cliente(BaseDatos *db, int id_cliente);
void validar_rfc(char *rfc);

#endif

# Sistema Punto de Venta en C

## Descripción
Sistema completo de Punto de Venta desarrollado en C que permite:
- Gestión de inventario de productos
- Administración de clientes con RFC
- Generación de notas de venta con descuentos
- Visualización de reportes

## Características

✅ **Control de Inventario**
- Dar de alta productos
- Modificar productos existentes
- Controlar stock

✅ **Gestión de Clientes**
- Registrar clientes
- Modificar datos de clientes
- Validar RFC
- Aplicar descuentos según cliente

✅ **Sistema de Ventas**
- Crear notas de venta
- Aplicar descuentos automáticos
- Generar comprobantes

✅ **Reportes**
- Visualizar notas de venta
- Consultar inventario
- Historial de clientes

## Compilación

```bash
gcc -o pdv *.c -lm
```

## Ejecución

```bash
./pdv
```

## Estructura de Archivos

- `main.c` - Programa principal y menú
- `productos.c/h` - Gestión de productos
- `clientes.c/h` - Gestión de clientes
- `ventas.c/h` - Sistema de ventas
- `utilidades.c/h` - Funciones auxiliares
- `datos/` - Directorio para almacenamiento de datos

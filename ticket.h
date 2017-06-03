#include <stdio.h>
#include "lldblc.h"
#include "productos.h"

/**
 * [Genera un ticket en pantalla]
 * @param this [Es la dirección de la lista enlazada]
 * @param pago [Es el pago que se hace después de la compra]
 */
void GeneraTicket(LinkedList* this, float pago);
/**
 * [Agrega un producto al ticket]
 * @param ticket [Es la dirección de la lista enlazada]
 */
void agregaProductoTicket(LinkedList* ticket);
/**
 * [Calcula el cambio]
 * @param  precio [Es el precio total]
 * @param  pago   [Cuanto pago el cliente]
 * @return        [Regresa el cambio]
 */
float cambio(float precio, float pago);
/**
 * [Inicia una nueva venta]
 * @return [Determina si se regresa al menu anterior o si termina el programa]
 */
int nuevaVenta();
/**
 * [Muestra la venta actual]
 * @param this [Es la dirección de la lista enlazada]
 */
void muestraVenta(LinkedList* this);
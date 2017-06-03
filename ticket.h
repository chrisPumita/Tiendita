#include <stdio.h>
#include "lldblc.h"
#include "productos.h"

/**
 * [GeneraTicket description]
 * @param this [description]
 * @param pago [description]
 */
void GeneraTicket(LinkedList* this, float pago);
/**
 * [agregaProductoTicket description]
 * @param ticket [description]
 */
Bool agregaProductoTicket(LinkedList* ticket, char codigoBarra[]);
/**
 * [cambio description]
 * @param  precio [description]
 * @param  pago   [description]
 * @return        [description]
 */
float cambio(float precio, float pago);
/**
 * [nuevaVenta description]
 * @return [description]
 */
int nuevaVenta();
/**
 * [muestraVenta description]
 * @param this [description]
 */
void muestraVenta(LinkedList* this);
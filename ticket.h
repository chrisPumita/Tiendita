#include <stdio.h>
#include "lldblc.h"
#include "productos.h"

void GeneraTicket(LinkedList* this, float pago);

void agregaProductoTicket(LinkedList* ticket);
float cambio(float precio, float pago);
int nuevaVenta();

void muestraVenta(LinkedList* this);
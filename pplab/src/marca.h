/*
 * marca.h
 *
 *  Created on: 15 may. 2020
 *      Author: reyna
 */

#ifndef MARCA_H_
#define MARCA_H_

typedef struct
{
	int id;
	char descripcion[20];
}eMarca;

#endif /* MARCA_H_ */

void listarMarca(eMarca mar[], int tam);
int cargarDescMarca(char descripcion[], int id, eMarca marca[], int tam);

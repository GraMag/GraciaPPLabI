#include "marca.h"
#include "color.h"

#ifndef AUTO_H_
#define AUTO_H_

typedef struct
{
	int id;
	int patente;
	int idMarca;
	int idColor;
	int modelo;
	int isEmpty;
}eAuto;

#endif /* AUTO_H_ */

void initAuto (eAuto tutu[], int tam);
int noAuto (int ready);
int buscarLibreAuto(eAuto tutu[], int tam);
int buscarAuto(int patente, eAuto tutu[], int tam);
int altaAuto(eAuto tutu[], int tam, eMarca marca[], int tamM, eColor color[], int tamC);
void bajaAuto(eAuto tutu[], int tam);
void modificarAuto(eAuto tutu[], int tam, eColor color[], int tamC);
void mostrarAuto(eAuto tutu, eColor color[], int tamC, eMarca marca[], int tamM);
void listarAutos(eAuto tutu[], int tam, eColor color[], int tamC, eMarca marca[], int tamM);

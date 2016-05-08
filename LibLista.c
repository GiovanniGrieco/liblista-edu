/*
 * LibLista.c - NULL terminated single linked list
 * This edition is for educational purposes and is written mainly for Italian
 * 	students.
 *
 * Copyright (C) 2016  Giovanni Grieco <giovanni.grc96@gmail.com>
 *
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 * I left here my email address. Feel free to contact me in case something is
 * wrong or just to give me a symbolic "f___ you" if you think my coding skills
 * are terrible. I'm working hard on improving myself, so critiques are welcomed
 *
 * La documentazione delle funzioni è disponibile nel file header.
 */

#include <stdlib.h>	// malloc, free
#include <stdarg.h>	// variadic functions
#include <string.h>	// strcmp

#include "LibLista.h"

List lista_aggiungiElemento(List lista, NodeData contenuto)
{
	// creo il nuovo elemento ed associo un proprio spazio nella memoria
	List el_da_aggiungere = malloc(sizeof(ListNode));

	// memorizzo i dati relativi all'elemento della lista nel nuovo spazio
	// di memoria allocato
	el_da_aggiungere->contenuto 		= contenuto;
	el_da_aggiungere->prossimoElemento 	= lista;

	// ritorno la nuova testa di lista
	return el_da_aggiungere;
}

List lista_aggiungiElementi(List lista, int nElementi, ...)
{
	va_list elementi;

	va_start(elementi, nElementi);
	while (nElementi--) {
		lista = lista_aggiungiElemento(lista,
						va_arg(elementi, NodeData));
	}
	va_end(elementi);

	return lista;
}

List lista_inserisciElementoInX(List lista, unsigned int X, NodeData contenuto)
{
	List 	el_index		= lista,
		elemento_precedente	= NULL;

	unsigned int i = 1, lunghezza_lista = lista_lunghezza(lista);
	while (lunghezza_lista--) {
		if (i == X) {
			List inserimento = malloc(sizeof(ListNode));
			inserimento->contenuto = contenuto;
			inserimento->prossimoElemento = el_index;

			elemento_precedente->prossimoElemento = inserimento;

			return lista;
		}

		elemento_precedente = el_index;
		el_index = el_index->prossimoElemento;
		i++;
	}

	X = X - i;
	while (X--) {
		lista = lista_aggiungiElemento(lista, (NodeData) {
			.etichetta = (char*) NULL,
			.valore = 0
		});
	}

	lista = lista_aggiungiElemento(lista, contenuto);

	// non è possibile andare oltre il primo elemento della lista
	return lista;
}

int lista_rimuoviElementoNesimo(List lista, int n)
{
	List 	elem_precedente  = NULL,
		elem_daEliminare = lista;

	// cerco l'n-esimo nodo nella lista
	int i = 1;
	while (i < n && elem_daEliminare != NULL) {
		elem_precedente = elem_daEliminare;
		elem_daEliminare = elem_daEliminare->prossimoElemento;
		i++;
	}

	if (elem_daEliminare == NULL)
		return ENOTFOUND;

	elem_precedente->prossimoElemento = elem_daEliminare->prossimoElemento;
	free(elem_daEliminare);

	return SUCCESS;
}

int lista_modificaElementoNesimo(List lista, unsigned int X,
				 NodeData nuovo_contenuto)
{
	unsigned int nElementi = lista_lunghezza (lista);

	for (unsigned int i = 1; i <= nElementi; i++) {
		if (i == X) {
			lista->contenuto = nuovo_contenuto;
			return SUCCESS;
		}

		lista = lista->prossimoElemento;
	}

	return ENOTFOUND;
}

void lista_distruggi(List lista)
{
	// uso 2 puntatori a causa della deinizializzazione di ogni elemento
	List i = lista;

	// ciclo per neutralizzare gli elementi
	while (lista != NULL) {
		i = lista->prossimoElemento;
		free(lista);
		lista = i;
	}
}

unsigned int lista_lunghezza(List lista)
{
	int i = 0;
	while (lista != NULL) {
		i++;
		lista = lista->prossimoElemento;
	}
	return i;
}

List lista_capovolgi(List lista)
{
	List listaCapovolta = NULL, vecchiaLista = lista;

	do {
		listaCapovolta = lista_aggiungiElemento(listaCapovolta,
							lista->contenuto);
	} while ((lista = lista->prossimoElemento) != NULL);

	// svuota la memoria allocata alla vecchia lista
	lista_distruggi(vecchiaLista);

	return listaCapovolta;
}

int lista_scambiaElementiXY(List lista, unsigned int X, unsigned int Y)
{
	NodeData *elemento_precedente = NULL;
	unsigned int	nElementi = lista_lunghezza(lista),
			i = 1;


		if (i == X || i == Y) {
		}

		lista = lista->prossimoElemento;
	}

	// il ciclo è terminato senza scambi
	return ENOTFOUND;
}

unsigned int lista_cercaPerContenuto(List lista, int mode, NodeData contenuto)
{
	List i = lista;
	int	pos = 1,
		verif_etichetta = (!mode || mode == 1) ? 1 : 0,
		verif_valore 	= (!mode || mode == 2) ? 1 : 0;

	do {
		if ((!strcmp(contenuto.etichetta, i->contenuto.etichetta) ||
		     !verif_etichetta) &&
		    (contenuto.valore == i->contenuto.valore || !verif_valore))
			return pos;
		pos++;
	} while((i = i->prossimoElemento) != NULL);

	return 0; // elemento non trovato
}

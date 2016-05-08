/*
 * esempi.c - [part of] NULL terminated single linked list
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
 */

#include <stdio.h>

#include "LibLista.h"

void __stampaLista(List lista)
{
	// ciclo di iterazione per stampare ogni elemento. i fa da indice
	puts("Elementi:");
	List i = lista;
	do {
		printf("\t> %s, %d\n", i->contenuto.etichetta,
			i->contenuto.valore);
	} while ((i = i->prossimoElemento) != NULL);
}

List __inizializzaListaEsempio()
{
	return lista_aggiungiElementi(NULL, 3,
		(NodeData) {
			.etichetta 	= "Esempio1",
			.valore 	= 333
		},
		(NodeData) {
			.etichetta 	= "Esempio2",
			.valore 	= 444
		},
		(NodeData) {
			.etichetta 	= "Esempio3",
			.valore 	= 999
		}
	);
}

void esempio_stampaElementi(int ordInverso)
{
	List listesempio = __inizializzaListaEsempio();

	if (!ordInverso)
		listesempio = lista_capovolgi(listesempio);

	__stampaLista(listesempio);

	// distruggi la lista e libera la memoria heap occupata
	lista_distruggi(listesempio);
}

void esempio_generaTreElementiEdEliminaneUno()
{
	List listesempio = __inizializzaListaEsempio();

	// rimuovo il secondo elemento dalla lista
	lista_rimuoviElementoNesimo(listesempio, 2);

	__stampaLista(listesempio);

	// distruggi la lista e libera la memoria heap occupata
	lista_distruggi(listesempio);
}

void esempio_scambiaSecondoConTerzoElemento()
{
	List listesempio = __inizializzaListaEsempio();

	int retC = 0;
	if(!(retC = lista_scambiaElementiXY(listesempio, 2, 3))) {
		__stampaLista(listesempio);
	} else {
		puts("*** Errore durante lo scambio degli elementi");
		switch (retC) {
			case 404:
				puts("\tElemento non trovato");
		}
	}

	// distruggi la lista e libera la memoria heap occupata
	lista_distruggi (listesempio);
}

void esempio_modificaSecondoElemento()
{
	List listesempio = __inizializzaListaEsempio ();

	NodeData modifica = {
		.etichetta 	= "EsempioModifica",
		.valore 	= 101
	};

	int retC = 0;
	if(!(retC = lista_modificaElementoNesimo (listesempio, 2, modifica))) {
		__stampaLista (listesempio);
	} else {
		puts("*** Errore durante la modifica dell'elemento");
		switch (retC) {
			case 404:
				puts("\tElemento non trovato");
		}
	}

	// distruggi la lista e libera la memoria heap occupata
	lista_distruggi(listesempio);
}

void esempio_inserisciElementoInX(int posizione)
{
	List listesempio = __inizializzaListaEsempio();

	NodeData dati_da_inserire = {
		.etichetta 	= "Here I am!",
		.valore 	= 111
	};

	listesempio = lista_inserisciElementoInX(listesempio, posizione,
						 dati_da_inserire);

	__stampaLista(listesempio);

	// distruggi la lista e libera la memoria heap occupata
	lista_distruggi(listesempio);
}

void esempio_capovolgiLista()
{
	List listesempio = __inizializzaListaEsempio();

	listesempio = lista_capovolgi(listesempio);

	__stampaLista(listesempio);

	// distruggi la lista e libera la memoria heap occupata
	lista_distruggi(listesempio);
}

void esempio_cercaElemento()
{
	List listesempio = __inizializzaListaEsempio();

	int pos = lista_cercaPerContenuto(listesempio, 0, (NodeData) {
		.etichetta = "Esempio2",
		.valore = 999
	});

	printf("Posizione dell'elemento: %d\n", pos);

	lista_distruggi(listesempio);
}

// inserire qui solo i metodi che si vogliono utilizzare per la sperimentazione
int main()
{
	esempio_stampaElementi(0);
	//esempio_generaTreElementiEdEliminaneUno();
	//esempio_scambiaSecondoConTerzoElemento();
	//esempio_modificaSecondoElemento();
	//esempio_inserisciElementoInX(10);
	//esempio_capovolgiLista();
	//esempio_cercaElemento();

	return 0;
}

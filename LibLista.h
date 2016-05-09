/*
 * LibLista.h - NULL terminated single linked list
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
#pragma once

#define SUCCESS 	0
#define ENOTFOUND 	404

/*
 * NOTE:
 * Struttura della lista:
 *  - Partire SEMPRE a contare da 1, non da zero, a meno che si è sicuri che
 * 	l'end-user non abbia a che fare con ciò;
 *  - Per la numerazione, preferire il metodo di ordinamento in ordine
 *	cronologico crescente;
 *  - La libreria è type-agnostic, quindi si può cambiare la struttura dati di
 *	nodeContent. Così facendo non si potrà più fare riferimento agli esempi;
 *
 * Utilizzo del typedef:
 *  I typedef qui sono inutili. Questa lieve opacità di dato rende la
 *  lista più semplice da utilizzare, senza scrivere keywords aggiuntive e dover
 *  sempre ricordarsi il puntatore a node* per riferirsi alla lista o ad un nodo
 */

struct esempio__nodeContent {
	char	*etichetta;
	int 	valore;
};
typedef struct esempio__nodeContent NodeData;

struct node {
	NodeData contenuto;
	struct node *prossimoElemento;
};
typedef struct node  ListNode;
typedef struct node* List;

/*
 * Aggiunge un nodo alla lista
 * PARAMETRI:
 * 	- Lista da espandere
 * 	- Dati da associare al nodo da aggiungere
 * OUTPUT:
 *	- Lista col nuovo nodo in testa
 */
List lista_aggiungiElemento(List lista, NodeData contenuto);

/* Aggiunge più nodi alla lista. Il numero degli argomenti è variabile
 * PARAMETRI:
 *	- 	Lista da espandere
 *	- 	Numero dei nodi da aggiungere
 *	... Strutture contenenti i dati da associare ai nuovi nodi
 * OUTPUT:
 * 	- Lista con i nuovi nodi in testa
 */
List lista_aggiungiElementi(List lista, int nElementi, ...);

/* Inserisce un nodo in posizione X della lista
 * In caso di una X che supera la lunghezza della lista, ci saranno degli
 * elementi (null) che riempiranno gli elementi intermedi della lista
 * PARAMETRI:
 *	- Lista da espandere
 *	- Posizione di inserimento del nodo
 *	- Contenuto da associare al nodo
 * OUTPUT:
 *	- Lista aggiornata
 */
List lista_inserisciElementoInX(List lista, unsigned int X, NodeData contenuto);

/* Rimuove l'N-esimo nodo
 * PARAMETRI:
 * 	- Lista interessata
 * 	- Indice del nodo da rimuovere (si conta partendo da 1)
 * OUTPUT:
 * 	- SUCCESS | (Codice di errore)
 */
int lista_rimuoviElementoNesimo(List lista, int n);

/* Modifica il contenuto dell'N-esimo nodo nella lista
 * PARAMETRI:
 * 	- Lista interessata
 *	- N-esimo nodo da modificare
 *	- Nuovo contenuto da associare al nodo interessato
 * OUTPUT:
 *	- SUCCESS | (Codice di errore)
 */
int lista_modificaElementoNesimo(List lista, unsigned int X,
				 NodeData nuovo_contenuto);

/* Distrugge la lista dalla memoria
 * PARAMETRI:
 * 	- Lista interessata
 */
void lista_distruggi(List lista);

/* Vede da quanti nodi è formata la lista
 * PARAMETRI:
 * 	- Lista interessata
 * OUTPUT:
 *	- La lunghezza della lista
 * RIFLESSIONI:
 * Questa funzione mi ha fatto molto riflettere sulla ricorsione. Ho provato a
 * scrivere questo metodo in modo ricorsivo ma la ricorsione in C presenta
 * sin troppi problemi di overhead causato dallo stack frame che deve essere
 * creato ad ogni chiamata funzione. Inoltre per liste grandi (~1 milione di
 * nodi), la ricorsione va in segmentation fault, quindi impossibile da
 * usare.
 */
unsigned int lista_lunghezza(List lista);

/* Capovolge l'ordine dei nodi di una lista
 * PARAMETRI:
 *	- Lista da capovolgere
 * OUTPUT:
 *	- Lista capovolta
 * NOTE:
 * La lista capovolta è una NUOVA lista e si provvede ad eliminare la lista data
 * in input. È quindi dovere dello sviluppatore duplicare la lista originaria se
 * si volesse mantere in memoria il vecchio ordine.
 */
List lista_capovolgi(List lista);

/* Scambia due nodi di una lista
 * PARAMETRI:
 * 	- Puntatore al primo elemento della lista memorizzato
 *	- X-esimo elemento da scambiare con Y
 *	- Y-esimo elemento da scambiare con X
 * OUTPUT:
 *	- SUCCESS | (Codice di errore)
 * NOTA:
 * Scambio solo il contenuto dei nodi
 */
int lista_scambiaElementiXY(List lista, unsigned int X, unsigned int Y);

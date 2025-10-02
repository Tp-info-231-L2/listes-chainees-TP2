#ifndef LINKED_LIST_H
#define LINKED_LIST_H


#include <stdio.h>
#include <stdlib.h>


// Structure Element which is the template of our list.
typedef struct Element Element ;
struct Element {
    int data;
    Element *next;
    Element *previous;
};

// Structure List which represents our linked-list
typedef struct List List;
struct List
{
    Element *first;
    Element *last;
};

// fucntion that initialize our list
List *init() ;

// function that insert an element in our list front

void insertBeginning(List *list, int newData);

// cette fonction fait la même mais pour une liste doublement chaînée.

void insertBeginning2(List *list, int newData);

// function that delete the first element of our list

void DeleteBeginning(List *list);

// function that prints the list.
void printList(const List *list);


// delete all occurences of an element in the list
void delete_occ(List *list, int data_toDelete);
// Insert at the end by having a second pointer for the end.
void insertEnd(List *list, int newData);

// ajouter un élément en tête dans une liste circulaire simplement chaînée.

void insertBeginningCercle(List *list, int newData);

// parcourir cette liste.
void printListCercle(const List *list);

// insertion en queue dans un liste circulaire simplement chaînée.
void insertEndCercle(List *list, int newData);

// Deux différents cas pour les listes doublement chaînées circulaires.

void insertBeginningCercle2(List *list, int newData);

void insertEndCercle2(List *list, int newData);

void printListCercle(const List *list) ;

// fonction pour afficher les listes circulaires doublement chaînées.

void printListCercle2(const List *list);

/* I++++++++++++++++++++++++++++++++++++++++++++++++++++
    ici il s'agit d'écrire une fonction qui trie une liste liste chainée à chaque insertion. 
    Nous allons utiliser "insertBeginning(List *list, int newData" pour la liste simplement chaînée et 
                                        pour la liste doublement chaînée.

    Nous allons creer une fonction nommée triList qui va trier la liste à chaque insertion.
*/

void triList (List *list);


// afficher la liste double chainee

void printListDouble(List *list) ;

#endif

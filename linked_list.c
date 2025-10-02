#include "linked_list.h"

// Initialisation de la liste 

List *init() {
    List *list = malloc(sizeof(*list));

    if (list == NULL) {
        perror("The memory allocation failed.");
        exit(1);
    }

    list->first = NULL;
    list->last = NULL;

    return list;
}


// Insertion en debut pour le cas des listes simplement chainées.

void insertBeginning(List *list, int newData) {
    if (list == NULL) {
        return;
    }
    Element *new_element = malloc(sizeof(*new_element));

    if (new_element == NULL) {
        perror("The memory allocation failed.");
        return;
    }

    new_element->data = newData;
    new_element->next = NULL;

    new_element->next = list->first;
    list->first = new_element;
}

// cette fonction fait la même mais pour une liste doublement chaînée.

void insertBeginning2(List *list, int newData) {
    if (list == NULL) {
        printf("The list doesn't exist.\n");

        return;
    }

    Element *new_element = malloc(sizeof(*new_element));
    if (new_element == NULL) {
        perror("Memory allocation failed.\n");
        return;
    }

    new_element->data = newData;
    new_element->previous = NULL;          
    new_element->next = list->first;       

    if (list->first != NULL) {
        list->first->previous = new_element;  
    }

    list->first = new_element; 
}

// Insertion en fin pour le cas des listes simplement chainées.

void insertEnd(List *list, int newData) {
   
    Element *new_element = malloc(sizeof(*new_element));

    if (new_element == NULL) {
        perror("The memory allocation failed.");
        return;
    }

    new_element->data = newData;
    new_element->next = NULL;

    if (list->first == NULL) {
        list->first = new_element;
        list->last = new_element;
    }
    else {
        list->last->next = new_element;
        list->last = new_element;
    }
}

// suppression de la liste

void DeleteBeginning(List *list) {
    if (list->first == NULL) {
        printf("The list is empty.\n");
        return;
    }

    Element *toDelete = list->first;
    list->first = list->first->next;

    free(toDelete);
}

// Afficher la liste

void printList(const List *list) {

    if (list == NULL) {
        perror("The list doesn't exist.\n");
        return;
    }

    if (list->first == NULL) {
        printf("the list is empty.\n");
        return;
    }

    Element *current = list->first;

    while (current != NULL) {
        printf("[%d] -> ", current->data);
        
        current = current->next;
    }
    printf("NULL\n");
}


// supprimer toutes les occurences d'un nombre dans un liste chainée simple.

void delete_occ(List *list, int data_toDelete) {
    
    if (list->first == NULL || list == NULL) {
        printf("La liste est vide.\n");
        return;
    }

    Element *current = list->first;
    Element *prec = NULL;


    while (current != NULL) {
       // Cas où les éléments se trouvent en début de liste
       if (current->data == data_toDelete) {
            Element *toDelete = current;
            if (prec == NULL) {
                list->first = list->first->next;
                current = list->first;
            }
            else {
                // Cas où les éléments sont au milieu
                prec->next = current->next;
                current = current->next;
            }
            free(toDelete);
       }
       else {
            prec = current;
            current = current->next;
       }
       
        
    }
    
}

// insertion en debut dans une liste circulaire simplement chaînée.

void insertBeginningCercle(List *list, int newData) {
    
    if (list == NULL) {
        printf("The list doesn't exist.\n");
        return ;
    }

    Element *new_element = malloc(sizeof(*new_element));
    if (new_element == NULL) {
        perror("Memory allocation failled.");
        return;
    }

    new_element->data = newData;
    if (list->first == NULL) {
        list->first = new_element;
        list->last = new_element;
    }
    else {
        new_element->next = list->first;
        list->first = new_element;
        list->last->next = new_element;
    }


}

// parcourir la liste.
void printListCercle(const List *list) {
    if (list == NULL) {
        printf("The list doesn't exist.\n");
        return ;
    }

    if (list->first == NULL) {
        printf("La liste est vide.\n");
        return;
    }

    Element *current = list->first;

    do 
    {
        printf("[%d] -> ", current->data);
        current = current->next;
    } while (current != list->first);
    printf("(begin again (%d))\n", list->first->data);

}

// insertion en queue dans un liste circulaire simplement chaînée.
void insertEndCercle(List *list, int newData) {

    if (list == NULL) {
        printf("The list doesn't exist.\n");
        return ;
    }

    Element *new_element = malloc(sizeof(*new_element));
    if (new_element == NULL) {
        perror("Memory allocation failled.");
        return;
    }

    new_element->data = newData;
    if (list->first == NULL) {
        list->first = new_element;
        list->last = new_element;
        new_element->next = list->first;
    }
    else 
    {
        list->last->next = new_element;
        list->last = new_element;
        new_element->next = list->first;
        
    }
}

// Deux différents cas pour les listes doublement chaînées circulaires.

void insertBeginningCercle2(List *list, int newData) {
  
    if (list == NULL) {
        printf("The list doesn't exist.\n");
        return ;
    }

    Element *new_element = malloc(sizeof(*new_element));
    if (new_element == NULL) {
        perror("Memory allocation failled.");
        return;
    }

    new_element->data = newData;

    if (list->first == NULL) {
        new_element->next = new_element;
        new_element->previous = new_element;
        list->first = new_element;
        list->last = new_element;
    }
    else {
        new_element->next = list->first;
        list->first->previous = new_element;
        new_element->previous = list->last;
        list->last->next = new_element; 
        list->first = new_element;
    }
}

void insertEndCercle2(List *list, int newData) {

    if (list == NULL) {
        printf("The list doesn't exist.\n");
        return ;
    }

    Element *new_element = malloc(sizeof(*new_element));
    if (new_element == NULL) {
        perror("Memory allocation failled.");
        return;
    }

    new_element->data = newData;

    if (list->first == NULL) {
        new_element->next = new_element;
        new_element->previous = new_element;
        list->first = new_element;
        list->last = new_element;
    }
    else {
        new_element->next = list->first;
        list->last->next = new_element;
        new_element->previous = list->last;
        list->first->previous = new_element;
        list->last = new_element;
        
    }
}


// fonction pour afficher les listes circulaires doublement chaînées.

void printListCercle2(const List *list) {
    
    if (list == NULL) {
        printf("The list doesn't exist.\n");
        return ;
    }

    if (list->first == NULL) {
        printf("La liste est vide.\n");
        return;
    }

    Element *current = list->first;

    do 
    {
        printf("[%d] <-> ", current->data);
        current = current->next;
    } while (current != list->first);
    printf("(begin again (%d))\n", list->first->data);
}


/* I+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
    ici il s'agit d'écrire une fonction qui trie une liste liste chainée à chaque insertion. 
    Nous allons utiliser "insertBeginning(List *list, int newData" pour la liste simplement chaînée et 
    "void insertBeginning (List *list, ine newData)" pour la liste doublement chaînée. 

    Nous allons creer une fonction nommée triList qui va trier la liste à chaque insertion.

    ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
*/

void triList(List *list) {
    if (list == NULL) {
        printf("The list doesn't exist.\n");
        return;
    }

    if (list->first == NULL) {
        printf("La liste est vide.\n");
        return;
    }

    int permute;  
    Element *courant;
    Element *dernier = NULL;

    // Bubble sort sur liste
    do {
        permute = 0;
        courant = list->first;

        while (courant->next != dernier) {
            if (courant->data > courant->next->data) {
                // permutation correcte
                int temp = courant->data;
                courant->data = courant->next->data;
                courant->next->data = temp;

                permute = 1;
            }
            courant = courant->next;
        }
        dernier = courant; // optimisation : la plus grande valeur est à la fin
    } while (permute);
}

// afficher la liste double chainee

void printListDouble(List *list) {
    
    if (list == NULL) {
        perror ("The list doesn't exist.\n");
        
        return;
    }

    if (list->first == NULL) {
        printf("the list is empty.\n");
        return;
    }

    Element *current = list->first;

    while (current != NULL) {
        printf("[%d] <-> ", current->data);
        
        current = current->next;
    }
    printf("NULL\n");


}

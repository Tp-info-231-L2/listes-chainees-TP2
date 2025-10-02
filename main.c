#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"
#include <unistd.h>

int main() {
    
    // Menu du devoir

    int choix = 1;
    do {
        printf("\n\t\t\t\t\t\t\t\t\t\t MENU\n\n");
        
        printf("\t\t\t\t1. Supprimer les occurences d'un nombre dans une liste chaînée.\n");
        printf("\t\t\t\t2. insertion d'un élément dans une liste simplement chaînée pour que la liste reste toujours triée.\n");
        printf("\t\t\t\t3. insertion d'un élément  dans une liste doublement chaînée pour que la liste reste toujours triée.\n");
        printf("\t\t\t\t4. insertion en tête dans une liste simplement chaînée circulaire\n");
        printf("\t\t\t\t5. insertion en queue dans une liste simplement chaînée circulaire\n");
        printf("\t\t\t\t6. insertion en tête dans une liste doublement chaînée circulaire\n");
        printf("\t\t\t\t7. insertion en queue dans une liste doublement chaînée circulaire\n");

        printf("\n\t\t\t\t0. Quitter.\n");

        printf("Entrez votre choix : ");

        if (scanf("%d", &choix) != 1) {
            // si l'utiliateur entre autre chose q'un entier.
            printf("Entrée invalide.\n");
            // vider le buffet

            while (getchar() != '\n');
            choix = -1; // valeur sans sens pour rester dans la boucle.
        }

        printf("\n");


        switch (choix) {
            case 1: {
                // Supprimer les occurences d'un nombre dans une liste chaînée
                List *list = init();

                size_t nb_elements = 0;
                int data = 0;
                int dataToDelete = 0;
                printf("Combien d'entiers souhaitez-vous insérer dans la liste : ");
                scanf("%zu", &nb_elements);

                for (size_t i = 0; i < nb_elements; i++) {
                    printf("Entrez l'élément %zu : ", i + 1);
                    scanf("%d", &data);
                    insertEnd(list, data);
                }

                printf("Liste avant suppression : \n");
                printList(list);

                printf("Entrez l'entier à supprimer : ");
                scanf("%d", &dataToDelete);
                delete_occ(list, dataToDelete);

                printf("Après suppression : \n");
                printList(list);

                free(list);
                
                break;
            }

           case 2: {
            // insertion d'un élément dans une liste simplement chaînée pour que la liste reste toujours triée.
                List *list = init();

                size_t nb_elements = 0;
                int data = 0;

                printf("Combien d'entiers souhaitez-vous insérer dans la liste : ");
                scanf("%zu", &nb_elements);

                for (size_t i = 0; i < nb_elements; i++) {
                    printf("Entrez l'élément %zu : ", i + 1);
                    scanf("%d", &data);
                    insertBeginning(list, data);
                }

                printf("Voici la liste chaînée triée : \n");

                triList(list);
                printList(list);
                printf("\n");

                printf("Entrez un nouvel élément à insérer : ");
                scanf("%d", &data);
                printf("\n");

                insertBeginning(list, data);
                triList(list);

                // Affichage de la liste apres nouvelle insertion
                printf("Regardez la liste est toujours triée. \n");
                printList(list);

                printf("\n");

                free(list);
                
                break;
            }

            case 3: {
                // insertion d'un élément  dans une liste doublement chaînée pour que la liste reste toujours triée
                 List *list = init();

                size_t nb_elements = 0;
                int data = 0;

                printf("Combien d'entiers souhaitez-vous insérer dans la liste : ");
                scanf("%zu", &nb_elements);

                for (size_t i = 0; i < nb_elements; i++) {
                    printf("Entrez l'élément %zu : ", i + 1);
                    scanf("%d", &data);
                    insertBeginning(list, data);
                }

                printf("Voici la liste doublement chaînée triée : \n");

                triList(list);
                printListDouble(list);
                printf("\n");

                printf("Entrez un nouvel élément à insérer : ");
                scanf("%d", &data);
                printf("\n");

                insertBeginning(list, data);
                triList(list);

                // Affichage de la liste apres nouvelle insertion
                printf("Regardez la liste est toujours triée. \n");
                printListDouble(list);

                printf("\n");

                free(list);
                
                break;
            }

            case 4: {
                // insertion en tête dans une liste simplement chaînée circulaire
                List *list = init();

                size_t nb_elements = 0;
                int data = 0;
                printf("Combien d'entiers souhaitez-vous insérer dans la liste : ");
                scanf("%zu", &nb_elements);

                for (size_t i = 0; i < nb_elements; i++) {
                    printf("Entrez l'élément %zu : ", i + 1);
                    scanf("%d", &data);
                    insertBeginningCercle(list, data);
                }
                printf("\n");

                printf("Voici la liste : \n");

                printListCercle(list);

                free(list);
                
                break;
            }

            case 5: {
                // insertion en queue dans une liste simplement chaînée circulaire
                List *list = init();

                size_t nb_elements = 0;
                int data = 0;
                printf("Combien d'entiers souhaitez-vous insérer dans la liste : ");
                scanf("%zu", &nb_elements);

                for (size_t i = 0; i < nb_elements; i++) {
                    printf("Entrez l'élément %zu : ", i + 1);
                    scanf("%d", &data);
                    insertEndCercle(list, data);
                }
                printf("\n");

                printf("Voici la liste : \n");

                printListCercle(list);
                printf("\n");

                free(list);
                
                break;
            }

            case 6: {
                // 6. insertion en tête dans une liste doublement chaînée circulaire
                List *list = init();

                size_t nb_elements = 0;
                int data = 0;
                printf("Combien d'entiers souhaitez-vous insérer dans la liste : ");
                scanf("%zu", &nb_elements);

                for (size_t i = 0; i < nb_elements; i++) {
                    printf("Entrez l'élément %zu : ", i + 1);
                    scanf("%d", &data);
                    insertBeginningCercle2(list, data);
                }
                printf("\n");

                printf("Voici la liste : \n");

                printListCercle2(list);
                printf("\n");

                free(list);
                
                break;
            }

            case 7: {
                // insertion en queue dans une liste doublement chaînée circulaire

                List *list = init();

                size_t nb_elements = 0;
                int data = 0;
                printf("Combien d'entiers souhaitez-vous insérer dans la liste : ");
                scanf("%zu", &nb_elements);

                for (size_t i = 0; i < nb_elements; i++) {
                    printf("Entrez l'élément %zu : ", i + 1);
                    scanf("%d", &data);
                    insertEndCercle2(list, data);
                }
                printf("\n");

                printf("Voici la liste : \n");

                printListCercle2(list);
                printf("\n");

                free(list);
                
                break;
            } 
            
            case 0:
                printf("Aurevoir ! Ca a été un plaisir pour moi. 🤓\n\n");
                break;
            default:
                printf("Une erreur de votre part s'est produite.\n\n");
        }

        sleep(1);
        

    } while (choix != 0);
    return 0;
}
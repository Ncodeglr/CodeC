#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// Structure de la liste chainée
struct Peoplelist{
    int age;
    char *name;
    struct Peoplelist *next;
};

// Fonction pour créer un nouveau noeud
struct Peoplelist *createNode(int age, const char *name){
    struct Peoplelist *newNode = malloc(sizeof(struct Peoplelist));
    if(newNode == NULL){
        perror("Erreur d'allocation de mémoire");
        return NULL;
    }
    newNode->age = age;
    newNode->name = strdup(name); // Duplication de la chaîne pour éviter les erreurs de mémoire
    newNode->next = NULL;
    return newNode;
}

// Ajoute un noeud au début de la liste
void pushFront(struct Peoplelist **head, int age, const char *name){
    struct Peoplelist *newNode = createNode(age, name);
    newNode->next = *head;
    *head = newNode;
}

// Ajoute un noeud à la fin de la liste
void pushBack(struct Peoplelist **head, int age, const char *name){
    struct Peoplelist *newNode = createNode(age, name);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    struct Peoplelist *current = *head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = newNode;
}

void popFront(struct Peoplelist **head) {
    if (*head == NULL) {
        puts("La liste est vide");
        return;
    }
    
    struct Peoplelist *temp = *head;  // Correction du nom de structure
    *head = (*head)->next;            // Met à jour la tête pour pointer vers le suivant
    free(temp->name);                 // Libère la mémoire du nom
    free(temp);                       // Libère la mémoire du noeud
}

void popBack(struct Peoplelist **head) {
    if (*head == NULL) {
        puts("La liste est vide");
        return;
    }
    
    // Si la liste contient seulement un élément
    if ((*head)->next == NULL) {
        free((*head)->name);
        free(*head);
        *head = NULL;
        return;
    }
    
    // Parcours jusqu'à l'avant-dernier élément
    struct Peoplelist *current = *head;  // Correction du nom de structure
    while (current->next->next != NULL) {
        current = current->next;
    }
    
    // Libération du dernier noeud
    free(current->next->name);
    free(current->next);
    current->next = NULL;
}







// Fonction pour afficher la liste
void printList(struct Peoplelist *head){
    struct Peoplelist *current = head;
    while (current != NULL) {
        printf("Nom: %s, Age: %d\n", current->name, current->age);
        current = current->next;
    }
}

int main(int argc, const char *argv[]) {
    struct Peoplelist *myList = NULL;  // Initialisation de myList à NULL

    pushFront(&myList, 25, "Toto");
    pushFront(&myList, 52, "Tata");
    pushFront(&myList, 26, "Titi");

    pushBack(&myList, 76, "Tete");
    pushBack(&myList, 20, "Tjtj");
    pushBack(&myList, 38, "Tqtq");

    popFront(&myList);
    popBack(&myList);
    popBack(&myList);
    printList(myList);

    return 0;
}

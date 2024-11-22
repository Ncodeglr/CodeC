#include <stdio.h>
#include <stdlib.h>
// AlgoMatrice Created on 05/10/2024.

int main(int argc, const char * argv[]) {
    
    int X,Y; //Nb rows /Nb columns
    printf("NB rows/NB columns : ");
    scanf("%d %d",&X,&Y);
    
    //-----------------------Allocation de la mémoire pour X lignes----------------------//
    int **matrix = NULL;
    matrix = malloc(X*sizeof(int *));
    if(matrix==NULL){
        exit(1);
    }
    

    
    // int **matrix : Cela déclare une variable matrix comme étant un pointeur vers un pointeur d'entiers. En d'autres termes, matrix pourra pointer vers un tableau de pointeurs, où chaque pointeur sera ensuite utilisé pour pointer vers une ligne d'entiers (une rangée d'une matrice, par exemple).
    
    //X : représente le nombre de lignes de la matrice que tu souhaites créer. En d'autres termes, tu es en train d'allouer de la mémoire pour X pointeurs, où chaque pointeur représentera une ligne de la matrice.
    
    // sizeof(int *) : représente la taille, en octets, d'un pointeur vers un entier (int *). Chaque ligne de la matrice sera un tableau d'entiers, donc tu as besoin d'un pointeur (de type int *) pour chaque ligne.
    
    // malloc(X*sizeof(int *)) = Cette expression alloue un bloc de mémoire suffisant pour stocker X pointeurs vers des entiers. Autrement dit, cette allocation crée l'espace pour un tableau de X pointeurs, où chaque pointeur pourra ensuite être utilisé pour pointer vers une ligne de la matrice.
    //-----------------------------------------------------------------------------------------------//
    
    //---------------------Allocation de la mémoire pour Y colonnes dans chaque ligne----------------//
    for (int i = 0; i < X; i++) {
        matrix[i] = malloc(Y * sizeof(int));
        if(matrix[i]==NULL){exit(1);}
    }
    //Pour chaque ligne, on alloue un tableau d'entiers de taille Y.
    //-----------------------------------------------------------------------------------------------//
    
    /*
    matrix  ---->  [ ptr_ligne1, ptr_ligne2, ptr_ligne3 ]
                     |            |            |
                     ↓            ↓            ↓
                [ int, int, int, int ]  [ int, int, int, int ]  [ int, int, int, int ]
                  (4 entiers)          (4 entiers)              (4 entiers)

    
    */
    
    
    // Initialisation de la matrice
    for (int i = 0; i < X; i++) {
        for (int j = 0; j < Y; j++) {
            matrix[i][j] = 0;  // Exemple : initialisation avec 0
        }
    }
    
    for(int i=0;i<X;i++){
        for(int j=0;j<Y;j++){
            printf("a%d%d = %d\n",i,j,matrix[i][j]);
        }
    }
   
    // Libération de la mémoire
    for (int i = 0; i < X; i++) {free(matrix[i]);}
    free(matrix);
    return 0;
}

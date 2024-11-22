#include <stdio.h>
#include <stdlib.h>

//  Created on 02/10/2024.

int algoCalculette(void){
    int x = 0,y = 0;
    int operation;
    
    //-------------------------------SAISIE USER-----------------------------------------------//
    printf("------------------------Calculatrice-------------\n");
    printf("Opération (0=Quitter,+=1,-=2,x=3,/=4), que vous voulez faire ? : ");
    scanf("%d",&operation);
    while(operation<0 || operation>4){
        printf("Error saisie\n");
        printf("Quelle est l'opération (0=Quitter,+=1,-=2,x=3,/=4), que vous voulez faire ?");
        scanf("%d",&operation);
    }
    //------------------------------------------------------------------------------------------//
    
    if(operation==0){
        printf("Au revoir\n");
        return 0;
    }
    else{
        printf("Give x your operande = ");
        scanf("%d",&x);
        printf("\n");
        while (x<-1000 || x>1000) {
            printf("Error saisie, xE[-1000,1000]");
            printf("Give x first operande = ");
            scanf("%d",&x);
        }
        printf("Give y second operande = ");
        scanf("%d",&y);
        printf("\n");
        while (y<-1000 || y>1000) {
            printf("Error saisie, yE[-1000,1000]");
            printf("Give y second operande = ");
            scanf("%d",&y);
        }
        
        //----------------------------------CHOIX OPERATION------------------------------------------//
        if(operation==1){ printf("Somme = %d\n",x+y);}
        else if (operation==2){printf("Différence = %d\n",x-y);}
        else if (operation==3){printf("Produit = %d\n",x*y);}
        else if (operation==4){if(y==0){printf("Division impossible");}else{printf("Division = %d\n",x/y);}}
        algoCalculette();
        //------------------------------------------------------------------------------------------//
    }
    return 0;
}

int main(int argc, const char * argv[]) {
    algoCalculette();
    return 0;
}

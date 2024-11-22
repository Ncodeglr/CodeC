#include <stdio.h>
#include <stdlib.h>

//  Created on 30/09/2024.

float writesommeTot(float montantTot){
    int sommeTot;//Somme totale que le client donne
    printf("Donner votre Somme : ");
    scanf("%d",&sommeTot);
    while(sommeTot<montantTot){
        printf("Erreur, il n'y a pas assez d'argent donnée\n");
        printf("Donner votre Somme : ");
        scanf("%d",&sommeTot);
        }
    if(sommeTot==montantTot){
        printf("Merci de votre achat, à bientôt dans notre magasin");
        return EXIT_SUCCESS;
    }
    return sommeTot;
}

float writeMontantTot(void){
    int montantTot;//Montant Totale que doit payer le client
    printf("Donner le Montant totale : ");
    scanf("%d",&montantTot);
    return montantTot;
}

void algoRenduMonnaie(int montantTot, int sommeTot){
    int tab[5] ={20,10,5,2,1};
    int tabStock[5]={0,0,0,0,0};
    int rend =(sommeTot-montantTot); //Valeur que doit rendre le vendeur
    int k=0;
    for(int i=0;i<5;i++){
        k=0;
        while((tab[i]*k<=rend)){
            printf("Valeur billet = %d,  k = %d ,  Calcul = %d\n",tab[i],k,tab[i]*k);
            tabStock[i] = k;
            k++;
        }
        rend = rend - (k-1)*tab[i];
    }
    printf("\n_____MONNAIE A RENDRE______\n");
    for(int i=0;i<5;i++){
        printf("Nombre de billets de %d : %d\n",tab[i],tabStock[i]);
    }
    int s=0;
    for(int i=0;i<5;i++){
        s=s+tabStock[i]*tab[i];
        printf("S = %d\t",s);
    }
    
}


int main(int argc, const char * argv[]) {
    float montantTot;
    float sommeTot;
    montantTot = writeMontantTot();
    sommeTot = writesommeTot(montantTot);
    algoRenduMonnaie(montantTot, sommeTot);
    return 0;
}

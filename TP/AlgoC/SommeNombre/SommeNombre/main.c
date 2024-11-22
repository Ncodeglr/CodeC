#include <stdio.h>
#include <stdlib.h>
//  Created on 02/10/2024.

int askMin(void){
    
    int min; //Borne inf
    printf("Donner le min de votre somme : ");
    scanf("%d",&min);
    while(min<1){
        printf("Error, min doit être >=1\n");
        printf("Donner le min de votre somme : ");
        scanf("%d",&min);
    }
    
    return min;
}

int askMax(void){
    
    int max; //Borne sup
    printf("Donner le max de votre somme : ");
    scanf("%d",&max);
    while(max>1000){
        printf("Error, max doit être <=1000\n");
        printf("Donner le min de votre somme : ");
        scanf("%d",&max);
    }
    
    return max;
}

void algoSomme(int min, int max){
    int somme=0;
    if(min == max){
        printf("Somme = %d",0);
    }
    else{
        for (int i=min; i<max+1; i++){
            somme +=i;
        }
        printf("Somme = %d",somme);
    }
}


int main(int argc, const char * argv[]) {
   
    int borneMin, borneMax;
    borneMin = askMin();
    borneMax = askMax();
    algoSomme(borneMin,borneMax);
    
    return 0;
}

#include<stdio.h>
#include<stdlib.h>
//   AlgoTri Created on 05/10/2024.

void algoTriBulle(int tab[3], int taille){
    int k=0;
    while(k<taille*taille){
        for(int i=0;i<taille-1;i++){
            if(tab[i]>tab[i+1]){
                int tmp =tab[i];
                tab[i]=tab[i+1];
                tab[i+1]=tmp;
            }
            k++;
        }
    }
    for(int i=0; i<taille;i++){printf("data[%d] = %d\n",i,tab[i]);}
}

void algoTriInsertion(int tab[7], int taille){
    int x, j;
    for(int i=1; i<taille;i++){
        x=tab[i] ;
        j = i-1;
        while(j>=0 && tab[j]>x){
            tab[j+1] = tab[j];
            j=j-1;
        }
        tab[j+1]=x;
    }
    for(int i=0; i<taille;i++){printf("data[%d] = %d\n",i,tab[i]);}
}

void algoTriSelection(int tab[7], int taille){
    for(int i=0; i<taille-1;i++){
        int min=i;
        for(int j=i+1;j<taille;j++){
            if(tab[min]>tab[j]){
                min=j;
            }
        }
        if(min!=i){
            int tmp=tab[min];
            tab[min]=tab[i];
            tab[i]=tmp;
        }
    }
    for(int i=0; i<taille;i++){printf("data[%d] = %d\n",i,tab[i]);}
}



int main(int argc, const char * argv[]) {
  
    
    int data[7]= {3,2,1,98,-3,7,-10};
    //algoTriBulle(data,7);
    //algoTriInsertion(data,7);
    algoTriSelection(data,7);
    
    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//  Created by Grolier Nicolas on 21/09/2024.

_Bool tab[100];

void SieveEratosthenes1(void){
    
    for (int i = 0; i<100; i++){tab[i] = true;}
    
    for (int i = 2; i < 100; i++) {
        if (tab[i]) {
            int compteur = 2;
            while (i * compteur < 100) {
                tab[i * compteur] = false;
                compteur++;
            }
        }
    }
    
    for (int i = 0; i<100; i++){printf("tab[%d] = %d\n", i, tab[i]);}
}

void SieveEratosthenes2(void){
    int tab2[100];
    for(int i=0; i<100; i++){tab2[i] = i;}
    
    for(int i=3; i<100; i++){
        int compt=1;
        while(compt<100){
            int k = 2;
            if((tab2[i] == k*compt) && k*compt<=tab2[i])
            {
                tab2[i] = 0;
            }
            if((tab2[i] == (k+1)*compt) && (k+1)*compt<=tab2[i])
            {
                tab2[i] = 0;
            }
            if((tab2[i] == (k+3)*compt) && (k+3)*compt<=tab2[i])
            {
                tab2[i] = 0;
            }
            
            
            
            compt++;
            
            
            
        }
    }
    
    
    
    
    for(int i=0; i<100;i++){printf("tab2[%d]=%d\n",i,tab2[i]);}
    
    
}




int main(int argc, const char * argv[]) {
    //SieveEratosthenes1();
    SieveEratosthenes2();
    
    return EXIT_SUCCESS;
}

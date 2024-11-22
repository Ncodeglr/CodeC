#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//  Created on 04/10/2024.

int str_length(const char *ptr){
    int i=0;
    while(ptr[i] != '\0'){i++;}
    printf("Le nombre de caratèrs est de : %d\n",i);
    return i;
    
}

int count_occurences_of(const char *ptr, const char lettre){
    int i=0;
    int count=0;
    while(i<str_length(ptr)){
        if(ptr[i]==lettre){
            count++;
        }
        i++;
    }
    printf("Le nombre d'occurences de la lettre %c est de : %d\n",lettre,count);
    return count;
}


int main(int argc, const char * argv[]) {
    char myStr[]="HelloWorld";
    char lettre = 'o';
    str_length(myStr);
    count_occurences_of(myStr,lettre);
    
    return 0;
}

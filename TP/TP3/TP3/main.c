#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//  TP3
//  Created by Grolier Nicolas on 24/09/2024.


bool isNegative(int a){
    if(a<0){return true;}
    else{return false;}
}

bool isNegative2(int v)
{
  return (v >> 31) & 1; //Méthode avec le shift de bits
}



int main(int argc, const char * argv[]) {
    
    bool a = isNegative(-6);
    bool b = isNegative2(3);
    printf("Le resultat est %i\n",a);
    printf("Le resultat est %i\n",b);
    return EXIT_SUCCESS;
}

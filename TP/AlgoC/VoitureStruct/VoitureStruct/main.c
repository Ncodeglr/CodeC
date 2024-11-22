#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//  Created on 05/10/2024

//------------------DataStructure : Voiture--------------------------------//

typedef struct Car {
    char nameCar[30]; //Nom car
    char nameModele[30]; //Nom de modèle
    float nbGazole;
    float maxVitesse;
    char state[15];
   
} Car;

//-------------------------------------------------------------------------//

void carCreate(char name[30],char Modele[30],float maxV, Car *ptr ){
    strcpy((*ptr).nameCar,name);
    strcpy((*ptr).nameModele,Modele);
    (*ptr).nbGazole = 15;
    (*ptr).maxVitesse = maxV;
    strcpy((*ptr).state,"fonctionnel");
    
    
}

void readCar(Car *ptr){
    printf("Vehicule : %s\n",(*ptr).nameCar);
    printf("Modèle : %s\n",(*ptr).nameModele);
    printf("Gazole : %3.f L\n",(*ptr).nbGazole);
    printf("Vitesse Max : %3.f Km/h\n",(*ptr).maxVitesse);
    printf("Etat Vehicule : %s\n",(*ptr).state);
}


int main(int argc, const char * argv[]) {
    Car car1; //Création Structure type Car
    carCreate("Porche","911",222.50,&car1);
    readCar(&car1);
    return 0;
}

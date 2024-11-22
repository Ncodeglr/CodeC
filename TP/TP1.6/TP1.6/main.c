#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

//  Created on 31/10/2024.


char *splitPrefix(char *s, char delimiter){
    for(;*s != '\0'; s++){
        if(*s==delimiter){
            *s ='\0';
            return ++s; //En même temps qu'on incrémente s, on retourne ce pointeur modifié. Cela signifie que la fonction renvoie un pointeur vers la partie de la chaîne après le délimiteur, en excluant le délimiteur lui-même.
        }
    }
    return NULL;
}


struct star{
    unsigned int ID; //ID de la star
    char name[21];//Nom de la star
    char constellation[4]; //Nom de la Constellation de la star
    unsigned int distance;//Distance entre Earth et star
    float magnitude;// Magnitude de la star
};
typedef struct star star_t;

void initStar(star_t *s)
{
    s->ID = 0;
    for(unsigned int i = 0; i < sizeof(s->name); i++)
        s->name[i] = '\0';
    for(unsigned int i = 0; i < sizeof(s->constellation); i++)
        s->constellation[i] = '\0';
    s->distance = 0;
    s->magnitude = 0.0;
}

void printStar(FILE *f, const star_t *s)
{
    int tmp = fprintf(f, "%6u %3s %3d %+3.2f %s\n", s->ID, s->constellation, s->distance, s->magnitude, s->name);

    if (tmp < 0)
    {
        perror("printStar");
        exit(EXIT_FAILURE);
    }
}

void testStar(void)
{
    star_t s1;
    initStar(&s1);
    printStar(stdout, &s1);

    star_t s2 = {30365,"Canopus","Car", 94,-0.62};
    printStar(stdout, &s2);
}


bool readStar(FILE *f, star_t *s)
{
    unsigned int ID;
    float distance, magnitude;
    char identifier[20+3+1];               //676,And:Alpheratz ,29.744200,2.070000
    int tmp = fscanf(f, "%u , %s , %f , %f", &ID, identifier, &distance, &magnitude);

    if (tmp == EOF)
    {
        initStar(s);
        return false;
    }
    else if (tmp == 4)
    {
        initStar(s);
        s->ID = ID;
        s->distance = distance;
        s->magnitude = magnitude;
        strncpy(s->name, splitPrefix(identifier, ':'), sizeof(s->name));
        strncpy(s->constellation, identifier, sizeof(s->constellation));
        return true;
    }
    else
    {
        perror("readStar");
        exit(EXIT_FAILURE);
    }
}

void readAllStars(const char *filename)
{
    FILE *f = fopen(filename, "r");
    if (!f)
    {
        perror("readAllStars");
        exit(EXIT_FAILURE);
    }

    static star_t stars[400]; //Tableau de Structure de type stars_t
    for(unsigned  int i = 0; readStar(f, &stars[i]); i++)
    {
        printStar(stdout, &stars[i]);
    }

    if (fclose(f) == EOF)
    {
        perror("readAllStars");
        exit(EXIT_FAILURE);
    }
}




int main(int argc, const char * argv[]) {
    /*
    char in1[] = "a:x";
    char *out1 = splitPrefix(in1, ':');
    printf("%s %s\n", in1, out1);
   
    testStar();
    return EXIT_SUCCESS;
    */
    
    readAllStars("/Users/nicolasgrolier/Desktop/TP1.6/stars.csv");
    return EXIT_SUCCESS;
}

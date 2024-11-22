#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main(void) {
  pid_t rv;
  printf("[%8d/%8d] printf-0 Before fork()\n", (int)getpid(), (int)getppid());
  rv = fork(); //Création d'un process
  
  printf("[%8d/%8d] printf-1 After fork()\n", (int)getpid(), (int)getppid());
  printf("[%8d/%8d] printf-2 returned value : %d\n", (int)getpid(),(int)getppid(), rv);
  return 0;
  /*------------Explication du code compilé------------------*/
  //Donc la première ligne est exécuté. Puis à partir du père, on crée un process fils.
  //Donc le père est éxécuté puis le fils, d'où le faite qu'il est deux fois printf-1 et printf-2, un pour le père et un pour le fils
  //On s'apercoit que la valeur de rv du père et différent du fils car le rv_fils = 0
}

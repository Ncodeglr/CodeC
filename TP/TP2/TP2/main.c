#include <stdio.h>
#include <stdlib.h>

//  Created by Grolier Nicolas on 21/09/2024.
static const float data[50] = {18042893.83, 8469308.86, 16816927.77, 17146369.15, 19577477.93, 4242383.35, -7198853.86, 16497604.92, 5965166.49, 11896414.21, 10252023.62, 13504900.27, 7833686.90, 11025200.59, 20448977.63, 19675139.26, 13651805.40, 15403834.26, 3040891.72, 13034557.36, 350052.11, 5215953.68, 2947025.67, 17269564.29, 3364657.82, 8610215.30, 2787228.62, 2336651.23, 21451740.67, 4687031.35, 11015139.29, 18019798.02, 13156340.22, 6357230.58, 13691330.69, 11258981.67, 10599613.93, 20890184.56, 6281750.11, 16564780.42, 11311762.29, 16533773.73, 8594844.21, 19145449.19, 6084137.84, 7568985.37, 17345751.98, 19735943.24, 1497983.15, 20386643.70};

void minIdex(int start){
    int k = start;
    float min = data[start];
    for (int i= start; i<50; i++){
        if(data[i]<min){
            min = data[i];
            k=i;
        }
    }
    printf("The minimum value is at index %d\n", k);
}

void sort(void){
    int taille = 3;
    int data[3] = {4,3,2};
    int k=0;
    while(k<taille){
        for (int i=0; i<taille; i++){
            if(data[k]>data[i]){
                const int temp=data[i];
                data[i] = data[k];
                data[k] = temp;
                
                
            }
        }
        k++;
        
    }
    
    
    
    
    
    
    for (int i = 0; i<4; i++){printf("data2[%d] = %d\n", i, data[i]);}
    
}

int main(int argc, const char * argv[]) {
   
//    minIdex(22);
      sort();
    return 0;
}

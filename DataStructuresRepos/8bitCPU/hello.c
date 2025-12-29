#include <stdio.h>
void converting(int num, FILE *writeFile){
    if(num < 2){
        fprintf(writeFile, "%d", num); 
        return; 
    }
    converting(num / 2, writeFile);

    if(num % 2 == 0)
        fprintf(writeFile, "0"); 
    else
        fprintf(writeFile, "1"); 
}



int main(int argc,char * argv[]){
    if(argc != 3){
        printf("Error"); 
        return 1; 
    }
    FILE *readFile = fopen(argv[1], "r"); 
    FILE *writeFile = fopen(argv[2], "w");
    
    //instruction 1
    int x = 5;
    //instruction 2
    x = x+1;
    //instruction 3
    if(x == 5){
        //instruction 4
        x--;
    }
    //instruction 5
    x+=3;




    int input; 
    while(fscanf(readFile, "%d", &input) == 1){
        converting(input, writeFile); 
        fprintf(writeFile, "\n"); 
    }


   fclose(readFile); 
   fclose(writeFile); 

   return 0; 
    
}
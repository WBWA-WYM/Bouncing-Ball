#include<stdio.h>  
#include<stdlib.h>  
#include<conio.h>  
#include<windows.h>  
#include<time.h>  

#define High 25  
#define Width 50  

int cell[High+2][Width+2];  

void startup() {  
   srand((unsigned)time(NULL));  
   int i, j;  
   for (i = 1; i < High+1; i++) {  
       for (j = 1; j < Width+1; j++) {  
           cell[i][j] = rand() % 2;  
       }  
   }  
}  

void show() {  
    system("cls");
    int i, j;
    for (i = 1; i < High+1; i++) {
        for (j = 1; j < Width+1; j++) {
            if (cell[i][j] == 1){
                printf("*");
            }
            if (cell[i][j] == 0) {
                printf(" ");
            }
       } 
        printf("\n");
    }
    Sleep(1000);
}  

void DateupWithInput() {
     
}

void DateupWithoutInput() {
    int NewCell[High+2][Width+2];
    int NeibourNumber;
    int i,j;
    for (i =1; i < High+1; i++) {
        for (j = 1; j < Width+1; j++) {
            NeibourNumber = cell[i - 1][j - 1] + cell[i - 1][j] + cell[i - 1][j + 1] + cell[i][j - 1]+cell[i][j + 1] + cell[i + 1][j - 1] + cell[i + 1][j] + cell[i + 1][j + 1];
            if (NeibourNumber==3) {
                NewCell[i][j] = 1;
            }
            if (NeibourNumber == 2) {
                NewCell[i][j] = cell[i][j];
            }
            else {
                NewCell[i][j] = 0;
            }

        }
        
    }
    for (i = 1; i < High+1; i++) {
        for (j = 1; j < Width+1; j++) {
            cell[i][j] = NewCell[i][j];
        }
    }
}

int main() {  
   startup();  
   while (1) {  
       show();  
       DateupWithInput();  
       DateupWithoutInput();  
   }  
   return 0;  
}
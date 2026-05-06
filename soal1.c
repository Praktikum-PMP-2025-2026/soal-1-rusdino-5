#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Pasien{
    char id[100];
    int time;
}Pasien;

void TampilkanWait(Pasien* x, int N){
    int temp = 0;
    for(int j =1; j< N; j++){
        for(int i =0; i< j; i++){
            temp += x[i].time;
        }
    }
    printf("%d\n", temp);
}

void TampilkanUrut(Pasien* x, int N){
    for(int i =0; i< N; i++){
        printf(" %s", x[i].id);
    }
}

int main(){
    char buff[1024]; 
    fgets(buff, sizeof(buff), stdin);
    int N = atoi(strtok(buff, " "));
    if(N!=0){
    Pasien *x = (Pasien*)calloc(N, sizeof(Pasien));
    for(int i =0; i < N; i++){
        for(int j = 0; j <2; j++){
        char *temp = strtok(NULL, " ");
        if(temp != NULL){
            if(j%2 == 0){
                strcpy(x[i].id, temp);
            }else if(j%2 == 1){
                x[i].time = atoi(temp);
            }
            }
        }

    }
    printf("\nORDER");
    TampilkanUrut(x, N);
    printf("\nWAIT ");
    TampilkanWait(x, N);
    
}
}

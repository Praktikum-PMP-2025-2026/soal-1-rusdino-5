/** EL2008 Praktikum Pemecahan Masalah dengan Pemrograman 2024/2025
 *   Modul               : 4
 *   Hari dan Tanggal    : Rabu, 6 Mei 2026
 *   Nama (NIM)          : Rusydi Noor Abdurrahman (13224030)
 *   Nama File           : soal1.c
 *   Deskripsi           : Deskripsi Soal
Sebuah terminal medis orbit menangani pasien berdasarkan urutan kedatangan. Setiap pasien membutuhkan durasi pelayanan yang berbeda. Untuk mengevaluasi efisiensi pelayanan, manajemen terminal ingin mengetahui urutan pasien yang diproses serta total waktu tunggu seluruh antrean. Anda diminta mensimulasikan antrean tersebut sesuai aturan layanan yang berlaku.
Simulasikan antrean pasien dan hitung total waktu tunggu.
Kondisi/Aturan
1. Pasien diproses sesuai urutan datang
2. Waktu tunggu pasien pertama = 0
3. Waktu tunggu pasien berikutnya = total durasi semua pasien sebelumnya
4. Cetak urutan ID dan total waktu tunggu seluruh pasien
**/
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

#include <stdio.h>
#include <stdlib.h>
#include "boardf.h"

char** allocates_board(int size){
    int i;
    char** vet = (char**)malloc(sizeof(char*) * size);
    for(i=0 ; i<size ; i++){
        *(vet+i) = (char*)malloc(sizeof(char) * size);
    }
    return vet;
}

int** allocates_id(int size){
    int i;
    int** vet = (int**)malloc(sizeof(int*) * size);
    for(i=0 ; i<size ; i++){
        *(vet+i) = (int*)malloc(sizeof(int) * size);
    }
    return vet;
}

void inicialize_board(char** matriz, int size){
	int i, j;

	for(i=1 ; i<size ; i++){
        **matriz = 0;
	    *(*(matriz)+i) = 64 + i;
        *(*(matriz+i)) = i;
        for(j=1 ; j<size ; j++){
            *(*(matriz+i)+j) = '.';
        }
    }
}

void inicialize_id(int** matriz, int size){
    int i, j;
    for(i=0 ; i<size ; i++){
        for(j=0 ; j<size ; j++){
            matriz[i][j] = 0;
        }
    }
}

void print_board(char** matriz, int size){
	int i, j;

    for(i=0 ; i<size ; i++){
        for(j=0 ; j<size ; j++){
            if(j==0){
                if(i<10){
                    printf("0");
                }
                printf("%d  ", matriz[i][0]);
            }
            else{
                printf("%c  ", matriz[i][j]);
            }
        }
    printf("\n");
    }
}

void print_menu(){
    int i;
    for(i=0 ; i<15 ; i++)
        printf("%c", '-');
    printf(" MENU ");
    for(i=0 ; i<15 ; i++)
        printf("%c", '-');
    printf("\n(1)Posicionamento aleatorio        %c\n", '-');
    printf("(2)Reposicionamento                %c\n", '-');
    printf("(3)Printa tabuleiro                %c\n", '-');
    printf("(4)Salvar                          %c\n", '-');
    printf("(5)Carregar                        %c\n", '-');
    printf("(6)Sair                            %c\n", '-');
    for(i=0 ; i<36 ; i++)
        printf("%c", '-');
    printf("\n");
}

int rando(int size){
    int x;
    x = ((rand() % (size-1)) + 1);
    return x;
}

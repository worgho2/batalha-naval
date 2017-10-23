#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "defines.h"
#include "boardf.h"
#include "vesself.h"
#include "arquivos.h"

int tamanho_tabuleiro = N;

int main(){
    char** matriz;
    int** matriz_id;
    int menu, id=(BOI_Q + HID_Q + SUB_Q + CRU_Q + ENC_Q + POR_Q);

    srand(time(NULL));

    matriz = allocates_board(tamanho_tabuleiro);
    matriz_id = allocates_id(tamanho_tabuleiro);

    inicialize_board(matriz, tamanho_tabuleiro);
    inicialize_id(matriz_id, tamanho_tabuleiro);

    while(1){
        print_menu();
        scanf("%d", &menu);

        switch(menu){
        case 1:
            system("clear");
            inicialize_board(matriz, tamanho_tabuleiro);
            inicialize_id(matriz_id, tamanho_tabuleiro);
            allocates_vessel_random(matriz, matriz_id, &id, tamanho_tabuleiro, POR_Q, POR, POR_N);
            allocates_vessel_random(matriz, matriz_id, &id, tamanho_tabuleiro, ENC_Q, ENC, ENC_N);
            allocates_vessel_random(matriz, matriz_id, &id, tamanho_tabuleiro, CRU_Q, CRU, CRU_N);
            allocates_vessel_random(matriz, matriz_id, &id, tamanho_tabuleiro, SUB_Q, SUB, SUB_N);
            allocates_vessel_random(matriz, matriz_id, &id, tamanho_tabuleiro, HID_Q, HID, HID_N);
            allocates_vessel_random(matriz, matriz_id, &id, tamanho_tabuleiro, BOI_Q, BOI, BOI_N);
            id=(BOI_Q + HID_Q + SUB_Q + CRU_Q + ENC_Q + POR_Q);
            print_board(matriz, tamanho_tabuleiro);
            printf("\n\n");
            break;
        case 2:
            realloc_vessel(matriz, matriz_id, tamanho_tabuleiro);
            printf("\n\n");
            break;
        case 3:
            system("clear");
            print_board(matriz, tamanho_tabuleiro);
            printf("\n\n");
            break;
        case 4:
            system("clear");
            save_position(matriz_id, tamanho_tabuleiro);
            printf("Posicionamento Salvo\n\n");
            print_board(matriz, tamanho_tabuleiro);
            printf("\n\n");
            break;
        case 5:
            system("clear");
            inicialize_board(matriz, tamanho_tabuleiro);
            load_position(matriz, &tamanho_tabuleiro);
            printf("Posicionamento Carregado\n\n");
            print_board(matriz, tamanho_tabuleiro);
            printf("\n\n");
            break;
        case 6:
            system("clear");
            printf("Fim de Jogo\n\n");
            return 0;
        default:
            system("clear");
            printf("Opcao Invalida\n\n");
        }
    }
}

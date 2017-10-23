#include <stdio.h>
#include <stdlib.h>
#include "boardf.h"
#include "arquivos.h"


void allocates_vessel_random(char** matriz, int** matriz_id, int* id, int size, int num, int length_v, char code){
	int i, j, x, y, case_rand, flag=0;

    for(j=0 ; j<num ; j++){
        while(!flag){
            x = rando(size);
            y = rando(size);
            case_rand = rand() % 2;

            if(case_rand == 0){
                for(i=0 ; i<length_v ; i++){
                    if((x + length_v > size) || (y + length_v > size))
                        break;
                    if(matriz[x][(y+i)] == '.' ){
                        flag = 1;
                    }
                    else{
                        flag = 0;
                        break;
                    }
                }
                if(flag == 1){
                    for(i=0 ; i<length_v ; i++){
                        matriz[x][(y+i)] = code;
                        matriz_id[x][y+i] = *id;
                    }
                }
            }

            if(case_rand == 1){
                for(i=0 ; i<length_v ; i++){
                    if((x + length_v > size) || (y + length_v > size))
                        break;
                    if(matriz[(x+i)][y] == '.' ){
                        flag = 1;
                    }
                    else{
                        flag = 0;
                        break;
                    }
                }
                if(flag == 1){
                    for(i=0 ; i<length_v ; i++){
                        matriz[(x+i)][y] = code;
                        matriz_id[(x+i)][y] = *id;
                    }
                }
            }
        }
        *id -= 1;
        flag = 0;
    }
}

void realloc_vessel(char** matriz, int** matriz_id, int size){
    int i, flag=0, horizontal, vertical, id, x_i, y_i, length_v, x_f, y_f, direction1, direction2;
    char code;

    system("clear");
	print_board(matriz, size);

    while(1){
        printf("Orientacao Inicial\n");

        printf("[linha]-> ");
        scanf("%d", &x_i);

        printf("[coluna]-> ");
        scanf("%d", &y_i);

        code = matriz[x_i][y_i];

        if(code=='1')
            length_v = 1;
        if(code=='2')
            length_v = 2;
        if(code=='3')
            length_v = 3;
        if(code=='4')
            length_v = 4;
        if(code=='5')
            length_v = 5;
        if(code=='6')
            length_v = 7;

        if(code=='1'){
            direction1 = 1;
        }
        else{
            if(code!='.'){
                id = matriz_id[x_i][y_i];

                for(i=0 ; i<length_v ; i++){
                    if(matriz_id[x_i+i][y_i]!=id){
                        vertical = 0;
                        break;
                    }
                    vertical = 1;
                }
                for(i=0 ; i<length_v ; i++){
                    if(matriz_id[x_i][y_i+i]!=id){
                        horizontal = 0;
                        break;
                    }
                    horizontal = 1;
                }

                if(vertical == 1 && horizontal == 0){
                    direction1 = 1;
                }
                if(vertical == 0 && horizontal == 1){
                    direction1 = 2;
                }
                if(vertical == 0 && horizontal == 0){
                    printf("\nERRO - posicao invalida\n\n");
                    code = '.';
                }
            }
            if(code == '.'){
                printf("\nERRO - posicao invalida\n\n");
            }
        }

        if(x_i>0 && x_i<16 && y_i>0 && y_i<16 && code!='.'){
            break;
        }
    }

    if(direction1 == 1){
        for(i=0 ; i<length_v ; i++){
            matriz[x_i+i][y_i] = '.';
            matriz_id[x_i+i][y_i] = 0;
        }
    }
    if(direction1 == 2){
        for(i=0 ; i<length_v ; i++){
            matriz[x_i][y_i+i] = '.';
            matriz_id[x_i][y_i+i] = 0;
        }
    }

    while(!flag){
        printf("Orientacao final\n");

        printf("[linha]-> ");
        scanf("%d", &x_f);

        printf("[coluna]-> ");
        scanf("%d", &y_f);

        if(code=='1'){
            direction2 = 1;
        }
        else{
            printf("VERTICAL | HORIZONTAL (1|2)-> ");
            scanf("%d", &direction2);
        }

        if(direction2 == 2){
            for(i=0 ; i<length_v ; i++){
                if(y_f + length_v > size){
                    printf("\nERRO - Limite de mapa\n");
                    break;
                }
                if(matriz[x_f][(y_f+i)] == '.' ){
                    flag = 1;
                }
                else{
                    printf("\nERRO - Sobreposicao\n");
                    flag = 0;
                    break;
                }
            }
            if(flag == 1){
                for(i=0 ; i<length_v ; i++){
                    matriz[x_f][(y_f+i)] = code;
                    matriz_id[x_f][y_f+i] = id;
                }
            }
        }

        if(direction2 == 1){
            for(i=0 ; i<length_v ; i++){
                if(x_f + length_v > size){
                    printf("\nERRO - Limite de mapa\n");
                    break;
                }
                if(matriz[(x_f+i)][y_f] == '.' ){
                    flag = 1;
                }
                else{
                    printf("\nERRO - Sobreposicao\n");
                    flag = 0;
                    break;
                }
            }
            if(flag == 1){
                for(i=0 ; i<length_v ; i++){
                    matriz[(x_f+i)][y_f] = code;
                    matriz_id[(x_f+i)][(y_f)] = id;
                }
            }
        }
    }
    system("cls");
    printf("Sucesso\n\n");
	print_board(matriz, size);
}

void allocates_vessel(char** matriz, int size, int length_v, char code, int x, int y, int direction){
    int i, flag = 0;

    while(!flag){
        if(direction == 2){
            for(i=0 ; i<length_v ; i++){
                if((x + length_v > size) || (y + length_v > size)){
                    printf("\n\nERRO - EXCEDE LIMITE DO MAPA\n\n");
                    exit(0);
                }
                if(matriz[x][(y+i)] == '.' ){
                    flag = 1;
                }
                else{
                    printf("\n\nERRO - SOBREPOSICAO 1 \n\n");
                }
            }
            if(flag == 1){
                for(i=0 ; i<length_v ; i++){
                    matriz[x][(y+i)] = code;
                }
            }
        }

        if(direction == 1){
            for(i=0 ; i<length_v ; i++){
                if((x + length_v > size) || (y + length_v > size)){
                    printf("\n\nERRO - EXCEDE LIMITE DO MAPA\n\n");
                    exit(0);
                }

                if(matriz[(x+i)][y] == '.' ){
                    flag = 1;
                }
                else{
                    printf("\n\nERRO - SOBREPOSICAO 2 \n\n");
                }
            }
            if(flag == 1){
                for(i=0 ; i<length_v ; i++){
                    matriz[(x+i)][y] = code;
                }
            }
        }

        if(flag==0){
            printf("ERRO - CARREGAMENTO FALHOU");
                exit(1);
        }
    }
}

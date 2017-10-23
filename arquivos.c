#include <stdio.h>
#include <stdlib.h>
#include "arquivos.h"
#include "defines.h"
#include "vesself.h"
#include "boardf.h"

void fprint_vessel(int** matriz_id, int size, int l_i, int l_f, int length_v){
    int i, j, k, direction, id, vertical;

    FILE* arquivo = fopen("save.game", "a");

    for(i=1 ; i<size ; i++){
        for(j=1 ; j<size ; j++){
            if(matriz_id[i][j]>l_i && matriz_id[i][j]<=l_f){
                id = matriz_id[i][j];

                if((i + length_v > size)||(j + length_v > size)){
                    if(i + length_v > size)
                        vertical = 0;
                    if(j + length_v > size)
                        vertical = 1;
                }
                else{
                    for(k=0 ; k<length_v ; k++){
                        if(matriz_id[i+k][j]!=id){
                            vertical = 0;
                            break;
                        }
                        vertical = 1;
                    }
                }

                if(vertical == 1){
                    direction = 1; // vertical
                    for(k=0 ; k<length_v ; k++)
                        matriz_id[i+k][j] = 0;
                }
                else{
                    direction = 2; // horizontal
                    for(k=0 ; k<length_v ; k++)
                        matriz_id[i][j+k] = 0;
                }

                fprintf(arquivo, "%d %d %d\n", i, j, direction);

            }
        }
    }

    fclose(arquivo);
}

void save_position(int** matriz_id_o, int size){
    int i, j, aux=0;
    int** matriz_id = allocates_id(size);

    FILE* arquivo = fopen("save.game", "w");

    for(i=1 ; i<size ; i++){
        for(j=1 ; j<size ; j++){
            matriz_id[i][j] = matriz_id_o[i][j];
       }
    }

    fprintf(arquivo, "%d\n", N);
    fprintf(arquivo, "%d\n", BOI_Q);
    fprintf(arquivo, "%d\n", HID_Q);
    fprintf(arquivo, "%d\n", SUB_Q);
    fprintf(arquivo, "%d\n", CRU_Q);
    fprintf(arquivo, "%d\n", ENC_Q);
    fprintf(arquivo, "%d\n", POR_Q);

    fclose(arquivo);

    fprint_vessel(matriz_id, size, aux, aux+BOI_Q, BOI);

    aux += BOI_Q;
    fprint_vessel(matriz_id, size, aux, aux+HID_Q, HID);

    aux += HID_Q;
    fprint_vessel(matriz_id, size, aux, aux+SUB_Q, SUB);

    aux += SUB_Q;
    fprint_vessel(matriz_id, size, aux, aux+CRU_Q, CRU);

    aux += CRU_Q;
    fprint_vessel(matriz_id, size, aux, aux+ENC_Q, ENC);

    aux += ENC_Q;
    fprint_vessel(matriz_id, size, aux, aux+POR_Q, POR);


}

void load_position(char** matriz, int* size){
    int i, boi_q, hid_q, sub_q, cru_q, enc_q, por_q, x, y, direction;
    char code;
    FILE* arquivo = fopen("save.game", "r");

    if(arquivo == NULL){
        printf("ERRO - MAPA RESETADO\n");
        return;
    }

    fscanf(arquivo, "%d", size);
    fscanf(arquivo, "%d", &boi_q);
    fscanf(arquivo, "%d", &hid_q);
    fscanf(arquivo, "%d", &sub_q);
    fscanf(arquivo, "%d", &cru_q);
    fscanf(arquivo, "%d", &enc_q);
    fscanf(arquivo, "%d", &por_q);

    for(i=0 ; i<boi_q ; i++){
        fscanf(arquivo, "%d%d%d", &x, &y, &direction);
        code = '1';
        allocates_vessel(matriz, *size, 1, code, x, y, direction);
    }
    for(i=0 ; i<hid_q ; i++){
        fscanf(arquivo, "%d%d%d", &x, &y, &direction);
        code = '2';
        allocates_vessel(matriz, *size, 2, code, x, y, direction);
    }
    for(i=0 ; i<sub_q ; i++){
        fscanf(arquivo, "%d%d%d", &x, &y, &direction);
        code = '3';
        allocates_vessel(matriz, *size, 3, code, x, y, direction);
    }
    for(i=0 ; i<cru_q ; i++){
        fscanf(arquivo, "%d%d%d", &x, &y, &direction);
        code = '4';
        allocates_vessel(matriz, *size, 4, code, x, y, direction);
    }
    for(i=0 ; i<enc_q ; i++){
        fscanf(arquivo, "%d%d%d", &x, &y, &direction);
        code = '5';
        allocates_vessel(matriz, *size, 5, code, x, y, direction);
    }
    for(i=0 ; i<por_q ; i++){
        fscanf(arquivo, "%d%d%d", &x, &y, &direction);
        code = '6';
        allocates_vessel(matriz, *size, 7, code, x, y, direction);
    }

    fclose(arquivo);

}


#ifndef BOARDF_H_INCLUDED
#define BOARDF_H_INCLUDED

char** allocates_board(int size);
int** allocates_id(int size);
void inicialize_board(char** matriz, int size);
void inicialize_id(int** matriz, int size);
void print_board(char** matriz, int size);
void print_menu();
int rando(int size);

#endif // BOARDF_H_INCLUDED

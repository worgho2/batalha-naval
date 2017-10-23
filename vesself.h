#ifndef VESSELF_H_INCLUDED
#define VESSELF_H_INCLUDED

void allocates_vessel_random(char** matriz, int** matriz_id, int* id, int size, int num, int length_v, char code);
void realloc_vessel(char** matriz, int** matriz_id, int size);
void allocates_vessel(char** matriz, int size, int length_v, char code, int x, int y, int direction);

#endif // VESSELF_H_INCLUDED

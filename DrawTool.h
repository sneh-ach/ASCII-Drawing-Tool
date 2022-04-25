#ifndef DrawTool_h
#define DrawTool_h
#define MAX 20

#include <string.h>
#include <stdio.h>

void CreateMap (char map[20][20], int *sizePtr);
void printInstructions(void);
void printMap(char map[20][20], int size);
void drawLines(char letter, int row, int col, int length, char marker, char map[MAX][MAX], int size);

#endif 

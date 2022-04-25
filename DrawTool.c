#include "DrawTool.h"



void CreateMap (char map[20][20], int *sizePtr)
{
    
    
    
    char backgroundChar;
    
    while(*sizePtr < 1 || *sizePtr > 20)
    {
        //Asks for size of array and background character
        printf("How big is the array? (Enter a value between 1 and 20)");
        scanf("%d",sizePtr);
    }
  
    
    printf("What is the background character?");
    scanf(" %c",&backgroundChar);
    getchar();
    
    
    
    
    
    
    int i;
    int j;
    for(i = 0; i < *sizePtr; i++)
    {
        for(j = 0; j < *sizePtr; j++)
        {
            *( *(map+ i) +j)= backgroundChar;
        }
    }
    
    
}

void printInstructions()
{
    
   
    
    printf("Draw commands start with\n\n");
    printf("\tP for a single point\n");
    printf("\tH for a horizontal line\n");
    printf("\tV for a vertical line\n\n\n");
    
    printf("After the P/V/H, enter a row,col coordinate and the number of spots to mark enclosed in () and separated by commas and then the character for the mark. 'X' will be used if a mark is not entered. For example,\n\n");
    
    printf("\tP(2,3,1)*\tstart at point 2,3 in the array and mark one spot\n\t\t\twith an *. For P, the 3rd parameter is ignored.\n\n\n");
    printf("\tV(1,2,3)$\tstart at point 1,2 in the array and mark the next\n\t\t\t3 spots down from the current position with $\n\n\n");
    printf("\tH(4,6,7)#\tstart at point 4,6 in the array and mark the next\n\t\t\t7 spots to the right with #\n\n\n");
    printf("Coordinates out of range and lines drawn past the borders are not allowed.\n\n\n");
       printf("Enter Q at the draw command prompt to quit\n\n\n");    
    
}

void printMap(char map[MAX][MAX], int size)
{
    
    int i;
    int j;
    
    
    
    printf("\n");
    
    for(i = 0; i < size; i++)
    {
        for(j = 0; j < size; j++)
        {
            printf("%c ",*( *(map+ i) +j));
        }
        
        printf("\n");
    }
    
    printf("\n");
    
    
}

void drawLines(char letter, int row, int col, int length, char marker, char map[MAX][MAX], int size)
{
    
    
    
    
    if(letter == 'H' || letter == 'h')
    {
        
        int i;
        
        //checks if point is on grid and if drawing is out of bounds
        if(row >= size || col >= size || (length + col) > size)
        {
            printf("\nThat draw command is out of range\n");
        }
        else
        {
            for(i = 0; i < length; i++)
            {
                *( *(map+ row) +(col+i))= marker;
            }
            
        }
        
        
        
        
    }
    
  
    if(letter == 'V' || letter == 'v')
    {
        

        int i;
        
        //checks if point is on grid  and if drawing is out of bounds
        if(row >= size || col >= size || (length + row) > size)
        {
            printf("\nThat draw command is out of range\n");
        }
        else
        {
            for(i = 0; i < length; i++)
            {
                *( *(map + row + i) +(col))= marker;
            }
            
        }
        
        
    }
    
    
    
}

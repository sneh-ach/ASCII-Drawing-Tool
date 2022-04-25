// Sneh Acharya - 1001916002
// CSE 1320 - Donna French

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "DrawTool.h"

int main(void)
{

	char array_canvas[MAXMAPSIZE][MAXMAPSIZE] = {}; //Declare 2d array with max size of 20/MAXMAPSIZE

	int user_choice; //variables for array size and background character from user
	char background_char;

	InitializeMap(array_canvas, &user_choice); //Call initialize map from DrawTool

	PrintInstructions(); //Call print function from DrawTool

	PrintMap(array_canvas, user_choice); //Call function to PrintMap() from DrawTool

	char quit;
	char draw_command[MAXMAPSIZE];

	char direction[2], mark[2]; //direction is a variable for P/V/H
	//(row,col) is start point on array_canvas & range is how far it goes

	int r, c, rng;

	char *Token;

	do
	{

		printf("Enter draw command (enter Q to quit)"); //Ask the user for draw command
		fgets(draw_command, MAXMAPSIZE, stdin);
		quit = toupper(draw_command[0]);

		if (quit == 'Q')
			; //Check if draw command is to quit

		else
		{

			Token = strtok(draw_command, "(),"); //String tok for direction
			//Assign to direction
			strcpy(direction, Token);

			Token = strtok(NULL, "(),"); //String tok for row

			r = atoi(Token);

			Token = strtok(NULL, "(),"); //String tok for col

			c = atoi(Token);

			Token = strtok(NULL, "(),"); //String tok for range

			rng = atoi(Token);

			Token = strtok(NULL, "(),"); //String tok for mark

			if (*Token == '\n') //Assign to mark
				mark[0] = 'X';
			else
				strcpy(mark, Token);

			direction[0] = toupper(direction[0]); //Convert p,v,h to Uppercase

			//Validate draw command
			if (direction[0] != 'P' && direction[0] != 'V' && direction[0] != 'H')
			{
				printf("That draw command is unknown\n");
			}

			if (direction[0] == 'P' && (r < 0 || r > user_choice - 1 || c < 0 || c > user_choice - 1))
				printf("That draw command is out of range\n");
			else if (direction[0] == 'P')
				array_canvas[r][c] = mark[0];

			else if (direction[0] == 'V' && ((r < 0 || r > user_choice - 1) || (c < 0 || c > user_choice - 1) || (rng < 0 || rng > user_choice - 1)))
			{
				printf("That draw command is out of range\n");
			}
			else if (direction[0] == 'H' && ((r < 0 || r > user_choice - 1) || (c < 0 || c > user_choice - 1) || (rng < 0 || rng > user_choice - 1)))
			{
				printf("That draw command is out of range\n");
			}
			//For point Command
			else
			{

				DrawLine(array_canvas, r, c, direction[0], rng, mark[0]); //Draw line in vertical or horizontal
			}
			PrintMap(array_canvas, user_choice);
		}

	} while (quit != 'Q');

	return 0;
}
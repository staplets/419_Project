#include "animation.hpp"


void printKey(int startrow, int startcolumn)
{
	int x = startcolumn;
	int y = startrow;

	move(x, y);
	printw("    **    ");
	x++;
	move(x, y);
	printw("   ****   ");
	x++;
	move(x, y);
	printw("  **  **  ");
	x++;
	move(x, y);
	printw(" **    ** ");
	x++;
	move(x, y);
	printw("**      **");
	x++;
	move(x, y);
	printw("**      **");
	x++;
	move(x, y);
	printw(" **    ** ");
	x++;
	move(x, y);
	printw("  **  **  ");
	x++;
	move(x, y);
	printw("   ****   ");
	x++;
	move(x, y);
	printw("    **    ");

	x = startcolumn + 5;

	for (y = startrow + 10; y <= startrow + 30; y++)
	{
		move(x, y);
		printw("*");
		x--;
		move(x, y);
		printw("*");
		x++;
		move(x, y);
	}

	for (y = startrow + 21; y <= startrow + 22; y++)
	{
		for (x = startcolumn + 6; x <= startcolumn + 9; x++)
		{
			move(x, y);
			printw("*");
		}
	}

	for (y = startrow + 29; y <= startrow + 30; y++)
	{
		for (x = startcolumn + 6; x <= startcolumn + 9; x++)
		{
			move(x, y);
			printw("*");
		}
	}
}

void eraseKey(int startrow, int startcolumn)
{
	int x = startcolumn;
	int y = startrow;

	move(x, y);
	printw("          ");
	x++;
	move(x, y);
	printw("          ");
	x++;
	move(x, y);
	printw("          ");
	x++;
	move(x, y);
	printw("          ");
	x++;
	move(x, y);
	printw("          ");
	x++;
	move(x, y);
	printw("          ");
	x++;
	move(x, y);
	printw("          ");
	x++;
	move(x, y);
	printw("          ");
	x++;
	move(x, y);
	printw("          ");
	x++;
	move(x, y);
	printw("          ");

	x = startcolumn + 5;

	for (y = startrow + 10; y <= startrow + 30; y++)
	{
		move(x, y);
		printw(" ");
		x--;
		move(x, y);
		printw(" ");
		x++;
		move(x, y);
	}

	for (y = startrow + 21; y <= startrow + 22; y++)
	{
		for (x = startcolumn + 6; x <= startcolumn + 9; x++)
		{
			move(x, y);
			printw(" ");
		}
	}

	for (y = startrow + 29; y <= startrow + 30; y++)
	{
		for (x = startcolumn + 6; x <= startcolumn + 9; x++)
		{
			move(x, y);
			printw(" ");
		}
	}
}

void printLock(int startrow, int startcolumn, int height, int width)
{
	for (int r = startrow; r <= startrow + height; r++)
	{
		for (int c = startcolumn; c <= startcolumn + width; c++)
		{
			move(r, c);
			printw("*");
		}
	}
}

void eraseLock(int startrow, int startcolumn, int height, int width)
{
	for (int r = startrow; r <= startrow + height; r++)
	{
		for (int c = startcolumn; c <= startcolumn + width; c++)
		{
			move(r, c);
			printw(" ");
		}
	}
}

void printBurst(int startrow, int startcol, int speed, int size)
{
	int x = startcol;
	int y = startrow;
	for (int i = 0; i < size; i++)
	{
		//top-left
		move(x - i, y - i);
		printw("*");

		//top-middle
		move(x, y - i);
		if (i % 2 == 0)
		{
			printw("*");
		}
		else
		{
			printw(" ");
		}

		//top-right
		move(x + i, y - i);
		printw("*");

		//bottom-left
		move(x - i, y + i);
		printw("*");

		//bottom-middle
		move(x, y + i);
		if (i % 2 == 0)
		{
			printw("*");
		}
		else
		{
			printw(" ");
		}

		//bottom-right
		move(x + i, y + i);
		printw("*");

		refresh();

		for (int s = 1; s <= speed; s++);

		refresh();
	}

}

void eraseBurst(int startrow, int startcol, int speed, int size)
{
	int x = startcol;
	int y = startrow;
	for (int i = 0; i < size; i++)
	{
		//top-left
		move(x - i, y - i);
		printw(" ");

		//top-middle
		move(x, y - i);
		if (i % 2 == 0)
		{
			printw(" ");
		}
		else
		{
			printw(" ");
		}

		//top-right
		move(x + i, y - i);
		printw(" ");

		//bottom-left
		move(x - i, y + i);
		printw(" ");

		//bottom-middle
		move(x, y + i);
		if (i % 2 == 0)
		{
			printw(" ");
		}
		else
		{
			printw(" ");
		}

		//bottom-right
		move(x + i, y + i);
		printw(" ");

		refresh();

		for (int s = 1; s <= speed; s++);

		refresh();
	}

}

void printPiano(int startrow, int startcolumn)
{
	int r = startrow;
	int c = startcolumn;
	
	for (r = startrow; r <= startrow + 10; r++)
	{
		for (c = startcolumn; c <= startcolumn + 55; c=c+5)
		{
			move(r, c);
			printw("*");

			//create top and bottom of the piano
			if (r == startrow || r == (startrow + 10))
			{
				if (c != (startcolumn +55))
				{
					printw("****");
				}
			}

			//create the black keys
			if (r < startrow + 5 && r > startrow)
			{
				if (c == startcolumn)
				{
					printw("    ***  ");
				}
				if (c == startcolumn + 10)
				{
					printw("**");
				}
				if (c == startcolumn + 15)
				{
					printw("  ***   ***   ***");
				}
				if (c == startcolumn + 35)
				{
					printw("   ***   **");
				}

			}
		}
	}
}

void printHands(int startrow, int startcolumn)
{
	int r;
	int c;
	
	//left arm
	for (r = startrow + 20; r < startrow + 30; r++)
	{
		for (c = startcolumn + 10; c < startcolumn + 25; c = c + 10)
		{
			move(r, c);
			printw("*");
			if (r == startrow + 20 && c == startcolumn + 10)
			{
				printw("*********");
			}
		}
	}

	//left hand
	r = startrow + 13;
	c = startcolumn + 9;
	move(r, c);
	printw("      ***");
	r++; move(r, c);
	printw(" * * ** *");
	r++; move(r, c);
	printw("* * * * *");
	r++; move(r, c);
	printw("* * * * * ***");
	r++; move(r, c);
	printw("* * * * * * *");
	r++; move(r, c);
	printw("*        ** *");
	r++; move(r, c);
	printw("*           *");
	r++; move(r, c);
	printw("*           *");
	r++; move(r, c);
	printw(" ***********");


	//right arm
	for (r = startrow + 20; r < startrow + 30; r++)
	{
		for (c = startcolumn + 40; c < startcolumn + 55; c = c + 10)
		{
			move(r, c);
			printw("*");
			if (r == startrow + 20 && c == startcolumn + 40)
			{
				printw("*********");
			}
		}
	}

	r = startrow + 13;
	c = startcolumn + 39;
	move(r, c);
	printw("    ***      ");
	r++; move(r, c);
	printw("    * ** * * ");
	r++; move(r, c);
	printw("    * * * * *");
	r++; move(r, c);
	printw("*** * * * * *");
	r++; move(r, c);
	printw("* * * * * * *");
	r++; move(r, c);
	printw("* **        *");
	r++; move(r, c);
	printw("*           *");
	r++; move(r, c);
	printw("*           *");
	r++; move(r, c);
	printw(" *********** ");

}

void eraseHands(int startrow, int startcolumn)
{
	int r;
	int c;

	//left arm
	for (r = startrow + 20; r < startrow + 30; r++)
	{
		for (c = startcolumn + 10; c < startcolumn + 25; c = c + 10)
		{
			move(r, c);
			printw(" ");
			if (r == startrow + 20 && c == startcolumn + 10)
			{
				printw("         ");
			}
		}
	}

	//left hand
	r = startrow + 13;
	c = startcolumn + 9;
	move(r, c);
	printw("             ");
	r++; move(r, c);
	printw("             ");
	r++; move(r, c);
	printw("             ");
	r++; move(r, c);
	printw("             ");
	r++; move(r, c);
	printw("             ");
	r++; move(r, c);
	printw("             ");
	r++; move(r, c);
	printw("             ");
	r++; move(r, c);
	printw("             ");
	r++; move(r, c);
	printw("             ");


	//right arm
	for (r = startrow + 20; r < startrow + 30; r++)
	{
		for (c = startcolumn + 40; c < startcolumn + 55; c = c + 10)
		{
			move(r, c);
			printw(" ");
			if (r == startrow + 20 && c == startcolumn + 40)
			{
				printw("         ");
			}
		}
	}

	r = startrow + 13;
	c = startcolumn + 39;
	move(r, c);
	printw("             ");
	r++; move(r, c);
	printw("             ");
	r++; move(r, c);
	printw("             ");
	r++; move(r, c);
	printw("             ");
	r++; move(r, c);
	printw("             ");
	r++; move(r, c);
	printw("             ");
	r++; move(r, c);
	printw("             ");
	r++; move(r, c);
	printw("             ");
	r++; move(r, c);
	printw("             ");

}

void printSherlock(int startrow, int startcolumn)
{
	int r = startrow;
	int c = startcolumn;

	move(r, c);
	printw("                    ********");
	r++;
	move(r, c);
	printw("                   *  o  o  *");
	r++;
	move(r, c);
	printw("                   *   /    *");
	r++;
	move(r, c);
	printw("                   *   --   *");
	r++;
	move(r, c);
	printw("                      *   *");
	r++;
	move(r, c);
	printw(" **  ****************       **************** **");
	r++;
	move(r, c);
	printw("**  *                 *   *                *  **");
	r++;
	move(r, c);
	printw(" **  *************     ***     ************* **");
	r++;
	move(r, c);
	printw("                  *     *     *");
	r++;
	move(r, c);
	printw("                  *     *     *");
	r++;
	move(r, c);
	printw("                  *     *     *");
	r++;
	move(r, c);
	printw("                  *     *     *");
	r++;
	move(r, c);
	printw("                  *     *     *");
	r++;
	move(r, c);
	printw("                  *    * *    *");
	r++;
	move(r, c);
	printw("                 * *********** *");
	r++;
	move(r, c);
	printw("                  *           *");
	r++;
	move(r, c);
	printw("                  *     *     *");
	r++;
	move(r, c);
	printw("                  *     *     *");
	r++;
	move(r, c);
	printw("                  *     *     *");
	r++;
	move(r, c);
	printw("                  *     *     *");
	r++;
	move(r, c);
	printw("                  *     *     *");
	r++;
	move(r, c);
	printw("                  *     *     *");
	r++;
	move(r, c);
	printw("                  *     *     *");
	r++;
	move(r, c);
	printw("                  *     *     *");
	r++;
	move(r, c);
	printw("                  ****** ******");	
	r++;
	move(r, c);
	printw("                **     * *     **");	
	r++;
	move(r, c);
	printw("                ******** ********");
}

void printDrops1(int startrow, int startcolumn)
{
	int r = startrow + 8;
	int c = startcolumn;

	move(r, c);
	printw("      U     U");
	c = c + 35;
	move(r, c);
	printw("U");
	c = c - 35;
}

void printDrops2(int startrow, int startcolumn)
{
	int r = startrow + 8;
	int c = startcolumn;

	move(r, c);
	printw("        U");
	c = c + 40;
	move(r, c);
	printw("U");
	c = c - 40;
}

void eraseDrops1(int startrow, int startcolumn) 
{
	int r = startrow + 8;
	int c = startcolumn;

	move(r, c);
	printw("              ");
	c = c + 34;
	move(r, c);
	printw("   ");
	c = c - 34;
}

void eraseDrops2(int startrow, int startcolumn)
{
	int r = startrow + 8;
	int c = startcolumn;

	move(r, c);
	printw("          ");
	c = c + 39;
	move(r, c);
	printw("   ");
	c = c - 39;
}

void printSpider1(int startrow, int startcolumn)
{
	int r = startrow;
	int c = startcolumn;

	move(r, c);

	printw("   \\   \\    /");
	r++; move(r, c);
	printw("    \\   |  |   /");
	r++; move(r, c);
	printw("     |  |  |  /");
	r++; move(r, c);
	printw("    ******** |   ");
	r++; move(r, c);
	printw("   *        *  *****");
	r++; move(r, c);
	printw("  *          **  :: *>");
	r++; move(r, c);
	printw("  *          **  :: *>");
	r++; move(r, c);
	printw("   *        *  *****");
	r++; move(r, c);
	printw("    ******** |");
	r++; move(r, c);
	printw("     |  |  |  \\ ");
	r++; move(r, c);
	printw("    /   |  |   \\");
	r++; move(r, c);
	printw("   /   /    \\");	
}

void printSpider2(int startrow, int startcolumn)
{
	int r = startrow;
	int c = startcolumn;

	move(r, c);

	printw("  __  __    __");
	r++; move(r, c);
	printw("   \\   |  |   __");
	r++; move(r, c);
	printw("     |  |  |  /");
	r++; move(r, c);
	printw("    ******** |   ");
	r++; move(r, c);
	printw("   *        *  *****");
	r++; move(r, c);
	printw("  *          **  :: *>");
	r++; move(r, c);
	printw("  *          **  :: *>");
	r++; move(r, c);
	printw("   *        *  *****");
	r++; move(r, c);
	printw("    ******** |");
	r++; move(r, c);
	printw("     |  |  | \\__ ");
	r++; move(r, c);
	printw("  __/ __|  |__   ");
}

void printSpider3(int startrow, int startcolumn)
{
	int r = startrow;
	int c = startcolumn;

	move(r, c);

	printw("     __   ");
	r++; move(r, c);
	printw("  ___ \\    ____ ");
	r++; move(r, c);
	printw("     |  |  |  ____");
	r++; move(r, c);
	printw("    ******** |   ");
	r++; move(r, c);
	printw("   *        *  *****");
	r++; move(r, c);
	printw("  *          **  :: *>");
	r++; move(r, c);
	printw("  *          **  :: *>");
	r++; move(r, c);
	printw("   *        *  *****");
	r++; move(r, c);
	printw("    ******** |____");
	r++; move(r, c);
	printw("  ___|  |  |____");
	r++; move(r, c);
	printw("     __/    ");
}

void eraseSpider(int startrow, int startcolumn)
{
	int r = startrow;
	int c = startcolumn;

	move(r, c);

	printw("                     ");
	r++; move(r, c);
	printw("                     ");
	r++; move(r, c);
	printw("                    ");
	r++; move(r, c);
	printw("                     ");
	r++; move(r, c);
	printw("                     ");
	r++; move(r, c);
	printw("                      ");
	r++; move(r, c);
	printw("                      ");
	r++; move(r, c);
	printw("                     ");
	r++; move(r, c);
	printw("                     ");
	r++; move(r, c);
	printw("                    ");
	r++; move(r, c);
	printw("                    ");
	r++; move(r, c);
	printw("                    ");
}

void printCandle(int startrow, int startcolumn)
{
	int r = startrow + 4;
	int c = startcolumn;

	move(r, c);

	printw("        |");
	r++; move(r, c);
	printw("     *******");
	r++; move(r, c);
	printw("     *     *");
	r++; move(r, c);
	printw("     *     *");
	r++; move(r, c);
	printw("     *     *");
	r++; move(r, c);
	printw("     *     *");
	r++; move(r, c);
	printw(" ___ *     *");
	r++; move(r, c);
	printw("|    *     *");
	r++; move(r, c);
	printw("|___ *     *");
	r++; move(r, c);
	printw("     *******");
}

void printFlame1(int startrow, int startcolumn)
{
	int r = startrow;
	int c = startcolumn;

	move(r, c);

	printw("        |");
	r++; move(r, c);
	printw("   \\       /");
	r++; move(r, c);
	printw("  __  ( )    __");
	r++; move(r, c);
	printw("      (   )");
	r++; move(r, c);
	printw("    /   |  \\");

}

void printFlame2(int startrow, int startcolumn)
{
	int r = startrow;
	int c = startcolumn;

	move(r, c);

	printw("         ");
	r++; move(r, c);
	printw("                ");
	r++; move(r, c);
	printw("    \\  ( ) /    ");
	r++; move(r, c);
	printw("   -- (   ) --");
	r++; move(r, c);
	printw("     /  | \\  ");
	r++; move(r, c);

}

void printFlame3(int startrow, int startcolumn)
{
	int r = startrow;
	int c = startcolumn;

	move(r, c);

	printw("        |");
	r++; move(r, c);
	printw("   \\       /");
	r++; move(r, c);
	printw("  __    ( )  __");
	r++; move(r, c);
	printw("      (   )");
	r++; move(r, c);
	printw("    /   |  \\");

}

void eraseFlame(int startrow, int startcolumn)
{
	int r = startrow;
	int c = startcolumn;

	move(r, c);

	printw("          ");
	r++; move(r, c);
	printw("             ");
	r++; move(r, c);
	printw("               ");
	r++; move(r, c);
	printw("             ");
	r++; move(r, c);
	printw("             ");

}

void printZee(int startrow, int startcolumn)
{
	int r = startrow;
	int c = startcolumn;

	move(r, c);

	printw("************* ");
	r++; move(r, c);
	printw("*********   * ");
	r++; move(r, c);
	printw("        *  *  ");
	r++; move(r, c);
	printw("      *  *    ");
	r++; move(r, c);
	printw("    *  *      ");
	r++; move(r, c);
	printw("  *  *        ");
	r++; move(r, c);
	printw("*  ***********");
	r++; move(r, c);
	printw("**************");
}

void printBar(int startrow, int startcolumn)
{
	int r = startrow + 3;
	int c = startcolumn;

	move(r, c);

	printw("                         ______________");
	r++; move(r, c);
	printw("                        |              |");
	r++; move(r, c);
	printw("                        |              |");
	r++; move(r, c);
	printw("                        |              |");
	r++; move(r, c);
	printw("                        |              |");
	r++; move(r, c);
	printw("                        |              |");
	r++; move(r, c);
	printw("                        |              |");
	r++; move(r, c);
	printw("                        |              |");
	r++; move(r, c);
	printw("                        |              |");
	r++; move(r, c);
	printw(" _______________________|______________|_____________________");
	r++; move(r, c);
	printw("|____________________________________________________________|");
}

void printPour(int startrow, int startcolumn)
{
	int r = startrow;
	int c = startcolumn + 35;
	move(r, c);
	printw("**");
}

void printGlass(int startrow, int startcolumn)
{
	int r = startrow;
	int c = startcolumn + 35;
	move(r, c);
	printw("__");
}

void erasePour(int startrow, int startcolumn)
{
	int r = startrow;
	int c = startcolumn + 35;
	move(r, c);
	printw("  ");
}

void printFill(int startrow, int startcolumn)
{
	int r = startrow;
	int c = startcolumn + 25;
	move(r, c);
	printw(" ************ ");
}

void printPainting(int startrow, int startcolumn)
{
	int r = startrow;
	int c = startcolumn;

	move(r, c);

	printw("*****************************************");
	r++; move(r, c);
	printw("*                                       *");
	r++; move(r, c);
	printw("*              . ~,.,, I.               *");
	r++; move(r, c);
	printw("*                .~.:. .,.              *");
	r++; move(r, c);
	printw("*             .:    ..$: ..             *");
	r++; move(r, c);
	printw("*            .7        7..:             *");
	r++; move(r, c);
	printw("*                      ~= ,I            *");
	r++; move(r, c);
	printw("*                ,  =O ...I,            *");
	r++; move(r, c);
	printw("*            =.         . ?.            *");
	r++; move(r, c);
	printw("*            +   =.=   =7  ..           *");
	r++; move(r, c);
	printw("*            I ..Z.O  . + . .           *");
	r++; move(r, c);
	printw("*            I Z+... I  I,.Z8           *");
	r++; move(r, c);
	printw("*            . 8,+ .    :,.O.           *");
	r++; move(r, c);
	printw("*            . ..7O.    78=D,.          *");
	r++; move(r, c);
	printw("*            .. =? .     :Z~.~          *");
	r++; move(r, c);
	printw("*            .:?         +.   :.        *");
	r++; move(r, c);
	printw("*           . .           . .  .?       *");
	r++; move(r, c);
	printw("*         Z. ?           ,+=~.??,+      *");
	r++; move(r, c);
	printw("*       D  ..IO.       8= .  : .   :.   *");
	r++; move(r, c);
	printw("*      7Z  =  ?$,~?::+..7.          .   *");
	r++; move(r, c);
	printw("*     .OZ   .:.7 .Z.  $. . . Z  . I,.   *");
	r++; move(r, c);
	printw("*      :  .    .: +.:.   . O  .O     7  *");
	r++; move(r, c);
	printw("*     .    .   .: Z=..  =.O   .      .  *");
	r++; move(r, c);
	printw("*   .=Z.   O    .I.=.    . Z.        .  *");
	r++; move(r, c);
	printw("*  .       .    $   .  . .O  ..         *");
	r++; move(r, c);
	printw("* :  .:$Z..... I       .,+ . ?   .    . *");
	r++; move(r, c);
	printw("*.. .I$7Z~OZ.=       . ..  7. ... = . ? *");
	r++; move(r, c);
	printw("*.. O:~ Z,$.  . :    .  I $?7.. O. ,7 $ *");
	r++; move(r, c);
	printw("* =  .:+ ?,        ?,.  ... .?. 7.O   . *");
	r++; move(r, c);
	printw("* .D..I,,?= ,      ...=$?.I=I,.:     .  *");
	r++; move(r, c);
	printw("*       .:.   ..  . ..:7 IO  .$.I .. +  *");
	r++; move(r, c);
	printw("*        =$   . ., ~ Z.I:O I$ ..D  . .  *");
	r++; move(r, c);
	printw("*        : .  =7  ,~?O:, 8OD,..:  .+    *");
	r++; move(r, c);
	printw("*          ..              .    ..I     *");
	r++; move(r, c);
	printw("*          .               ....I        *");
	r++; move(r, c);
	printw("*****************************************");
}

void printCar(int startrow, int startcolumn)
{
	int r = startrow;
	int c = startcolumn;

	move(r, c);

	printw("                        *****************");
	r++; move(r, c);
	printw("                       *    |     |----|   *");
	r++; move(r, c);
	printw("           ************_____|     |____|      *");
	r++; move(r, c);
	printw("         *                                       *****");
	r++; move(r, c);
	printw("       *                                              *");
	r++; move(r, c);
	printw("       *___      _________________________     _______*");
	r++; move(r, c);
	printw("           (    )                         (    )");
	r = r + 3; move(r, c);
	printw("              PRESS ENTER TO OPEN THE TRUNK");
	r++; c = c + 28; move(r, c);
}

void printOpen(int startrow, int startcolumn)
{
	int r = startrow + 3;
	int c = startcolumn + 49;
	int speed;

	for (int i = 1; i <= 1; i++)
	{
		move(r, c);
		printw("***  ");
		r--;
		move(r, c);
		printw("   **");
		r = r + 1;

		for (speed = 1; speed <= 48000000; speed++);
		refresh();
	}

	for (int i = 1; i <= 1; i++)
	{
		move(r, c);
		printw("*    ");
		r--;
		move(r, c);
		printw(" *** ");
		r--;
		move(r, c);
		printw("    *");
		r = r + 2;

		for (speed = 1; speed <= 48000000; speed++);
		refresh();
	}

	for (int i = 1; i <= 1; i++)
	{
		move(r, c);
		printw("*    ");
		r--;
		move(r, c);
		printw("*    ");
		r--;
		move(r, c);
		printw(" *   ");
		r--;
		move(r, c);
		printw("  ** ");
		r = r + 3;

		for (speed = 1; speed <= 48000000; speed++);
		refresh();
	}
}

void printFishbowl(int startrow, int startcolumn)
{
	int r = startrow;
	int c = startcolumn;

	move(r, c);

	printw("               *******************");
	r++; move(r, c);
	printw("               *                 *");
	r++; move(r, c);
	printw("             * ^^^^^^^^^^^^^^^^^^ *");
	r++; move(r, c);
	printw("            *                       *");
	r++; move(r, c);
	printw("           *                         *");
	r++; move(r, c);
	printw("          *                           *");
	r++; move(r, c);
	printw("          *                           *");
	r++; move(r, c);
	printw("          *                           *");
	r++; move(r, c);
	printw("           *                         *");
	r++; move(r, c);
	printw("            *                       *");
	r++; move(r, c);
	printw("             *                     *");
	r++; move(r, c);
	printw("              *********************");
}

void printLeftFish(int startrow, int startcolumn)
{
	int r = startrow;
	int c = startcolumn;

	move(r, c);

	printw("   _____");
	r++; move(r, c);
	printw("|>[__ _*]");
	r++; move(r, c);
	printw("     V");
}

void printRightFish(int startrow, int startcolumn)
{
	int r = startrow;
	int c = startcolumn;

	move(r, c);

	printw(" _____");
	r++; move(r, c);
	printw("[*_ __]<|");
	r++; move(r, c);
	printw("   V");
}

void eraseFish(int startrow, int startcolumn)
{
	int r = startrow;
	int c = startcolumn;

	move(r, c);

	printw("        ");
	r++; move(r, c);
	printw("         ");
	r++; move(r, c);
	printw("       ");
}

void printParrot1(int startrow, int startcolumn)
{
	int r = startrow;
	int c = startcolumn;

	move(r, c);

	printw("             *****");
	r++; move(r, c);
	printw("           *   0 0 *         ");
	r++; move(r, c);
	printw("          *       _*___      ");
	r++; move(r, c);
	printw("          *      *-----\\    ");
	r++; move(r, c);
	printw("          *      *------\\   ");
	r++; move(r, c);
	printw("           *        *");
	r++; move(r, c);
	printw("           *        *");
	r++; move(r, c);
	printw("          *          *");
	r++; move(r, c);
	printw("         *            *");
	r++; move(r, c);
	printw("         *            *");
	r++; move(r, c);
	printw("         *            *");
	r++; move(r, c);
	printw("         *            *");
	r++; move(r, c);
	printw("         *            *");
	r++; move(r, c);
	printw("         *  **    **  *");
	r++; move(r, c);
	printw(" ___________||____||_____________");
	r++; move(r, c);
	printw(" ___________MM____MM_____________|");
	r++; move(r, c);
	printw("          *     *");
	r++; move(r, c);
	printw("          *     *");
	r++; move(r, c);
	printw("          *    *");
	r++; move(r, c);
	printw("          *   *");
	r++; move(r, c);
	printw("          *   *");
	r++; move(r, c);
	printw("          *  *");
	r++; move(r, c);
	printw("          *  *");
	r++; move(r, c);
	printw("           * *");
	r++; move(r, c);
	printw("             *");
}

void printParrot2(int startrow, int startcolumn)
{
	int r = startrow;
	int c = startcolumn;

	move(r, c);

	printw("             *****");
	r++; move(r, c);
	printw("           *   0 0_____    ");
	r++; move(r, c);
	printw("          *      *-----\\  /");
	r++; move(r, c);
	printw("          *      _______  --");
	r++; move(r, c);
	printw("          *      *------\\ \\");
	r++; move(r, c);
	printw("           *        *");
	r++; move(r, c);
	printw("           *        *");
	r++; move(r, c);
	printw("          *          *");
	r++; move(r, c);
	printw("         *            *");
	r++; move(r, c);
	printw("         *            *");
	r++; move(r, c);
	printw("         *            *");
	r++; move(r, c);
	printw("         *            *");
	r++; move(r, c);
	printw("         *            *");
	r++; move(r, c);
	printw("         *  **    **  *");
	r++; move(r, c);
	printw(" ___________||____||_____________");
	r++; move(r, c);
	printw(" ___________MM____MM_____________|");
	r++; move(r, c);
	printw("          *     *");
	r++; move(r, c);
	printw("          *     *");
	r++; move(r, c);
	printw("          *    *");
	r++; move(r, c);
	printw("          *   *");
	r++; move(r, c);
	printw("          *   *");
	r++; move(r, c);
	printw("          *  *");
	r++; move(r, c);
	printw("          *  *");
	r++; move(r, c);
	printw("           * *");
	r++; move(r, c);
	printw("             *");
}

void printBilliards(int startrow, int startcolumn)
{
	int r = startrow;
	int c = startcolumn;

	move(r, c);
	printw(" ___________________________________________");
	r++; move(r, c);
	printw("|()                  ()                   ()|");
	r++; move(r, c);
	printw("|                                           |");
	r++; move(r, c);
	printw("|       O                                   |");
	r++; move(r, c);
	printw("|       O O                                 |");
	r++; move(r, c);
	printw("|       O O O                    O          |");
	r++; move(r, c);
	printw("|       O O                                 |");
	r++; move(r, c);
	printw("|       O                                   |");
	r++; move(r, c);
	printw("|                                           |");
	r++; move(r, c);
	printw("|()__________________()___________________()|");
}

void printCueBall(int startrow, int startcolumn)
{
	int r = startrow + 5;
	int c = startcolumn + 33;

	for (int i = 0; i < 21; i++)
	{
		move(r, c);
		printw(" ");
		c--;
		move(r, c);
		printw("O");
		refresh();
		for (int s = 1; s <= 60000000; s++);
	}
}

void printBalls(int startrow, int startcolumn)
{
	int r = startrow + 3;
	int c = startcolumn + 8;
	int i = 0;

	for (int p = 0; p < 6; p++)
	{

		r = startrow + 3;
		c = startcolumn + 8;

		//erase top
		if (i < 2)
		{
			move(r - i, c);
			printw(" ");
		}
		else
		{
			move(r - 2, c);
			printw(" ");
		}

		//erase 2nd-left
		r++;
		if (i < 3)
		{
			move(r - i, c - (i * 2));
			printw(" ");
		}
		else
		{
			move(r - 3, c - 6);
			printw("  ");
		}

		//erase 2nd-right
		c = c + 2;
		if (i < 3)
		{
			move(r - i, c + (i * 2));
			printw(" ");
		}
		else
		{
			move(r - 3, c + 6);
			printw(" ");
		}

		//erase 3rd-left
		r++;
		c = c - 2;
		if (i < 3)
		{
			move(r, c - (i * 2));
			printw(" ");
		}
		else
		{
			move(r, c - 6);
			printw(" ");
		}

		//erase 3rd-middle
		c = c + 2;
		move(r, c);
		printw(" ");

		//erase 3rd-right
		c = c + 2;
		move(r, c);
		printw(" ");

		//erase 4th-left
		c = c - 4;
		r++;
		if (i < 3)
		{
			move(r + i, c - (i * 2));
			printw(" ");
		}
		else
		{
			move(r + 3, c - 6);
			printw("  ");
		}

		//erase 4th-right
		c = c + 2;
		if (i < 3)
		{
			move(r + i, c + (i * 2));
			printw(" ");
		}
		else
		{
			move(r + 3, c + 6);
			printw(" ");
		}

		//erase bottom
		c = c - 2;
		r++;
		if (i < 3)
		{
			move(r + i, c);
			printw(" ");
		}
		else
		{
			move(r + 3, c);
			printw(" ");
		}

		i++;
		r = startrow + 3;
		c = startcolumn + 8;

		//top
		if (i < 2)
		{
			move(r - i, c);
			printw("O");
		}
		else
		{
			move(r - 2, c);
			printw("O");
		}

		//2nd-left
		r++;
		if (i < 3)
		{
			move(r - i, c - (i * 2));
			printw("O");
		}
		else
		{
			move(r - 3, c - 6);
			printw("O)");
		}

		//2nd-right
		c = c + 2;
		if (i < 3)
		{
			move(r - i, c + (i * 2));
			printw("O");
		}
		else
		{
			move(r - 3, c + 6);
			printw("O");
		}

		//3rd-left
		r++;
		c = c - 2;
		if (i < 3)
		{
			move(r, c - (i * 2));
			printw("O");
		}
		else
		{
			move(r, c - 6);
			printw("O");
		}

		//3rd-middle
		c = c + 2;
		move(r, c);
		printw("O");

		//3rd-right
		c = c + 2;
		move(r, c);
		printw("O");

		//4th-left
		c = c - 4;
		r++;
		if (i < 3)
		{
			move(r + i, c - (i * 2));
			printw("O");
		}
		else
		{
			move(r + 3, c - 6);
			printw("O)");
		}

		//4th-right
		c = c + 2;
		if (i < 3)
		{
			move(r + i, c + (i * 2));
			printw("O");
		}
		else
		{
			move(r + 3, c + 6);
			printw("O");
		}

		//bottom
		c = c - 2;
		r++;
		if (i < 2)
		{
			move(r + i, c);
			printw("O");
		}
		else
		{
			move(r + 2, c);
			printw("O");
		}

		refresh();

		for (int s = 1; s <= 60000000; s++);
	}
}

void printBookshelf(int startrow, int startcolumn)
{
	int r = startrow;
	int c = startcolumn + 20;

	move(r, c);
	printw(" __________________________________________");
	r++; move(r, c);
	printw("|__________________________________________|");
	r++; move(r, c);
	printw("| |  | |  | || | |   |  | | | ||  | |  | | |");
	r++; move(r, c);
	printw("| |  | |  | || | |   |  | | | ||  | |  | | |");
	r++; move(r, c);
	printw("|_|__|_|__|_||_|_|___|__|_|_|_||__|_|__|_|_|");
	r++; move(r, c);
	printw("|__________________________________________|");
	r++; move(r, c);
	printw("|  || |  | |  | || | |   |  | | | ||  | |  |");
	r++; move(r, c);
	printw("|  || |  | |  | || | |   |  | | | ||  | |  |");
	r++; move(r, c);
	printw("|__||_|__|_|__|_||_|_|___|__|_|_|_||__|_|__|");
	r++; move(r, c);
	printw("|__________________________________________|");
	r++; move(r, c);
	printw("| || | |   ||  | |  | || | |   |  | | | || |");
	r++; move(r, c);
	printw("| || | |   ||  | |  | || | |   |  | | | || |");
	r++; move(r, c);
	printw("|_||_|_|___||__|_|__|_||_|_|___|__|_|_|_||_|");
	r++; move(r, c);
	printw("|__________________________________________|");
	r++; move(r, c);
	printw("| |  | |  | || | |   |  | | | ||  | |  | | |");
	r++; move(r, c);
	printw("| |  | |  | || | |   |  | | | ||  | |  | | |");
	r++; move(r, c);
	printw("|_|__|_|__|_||_|_|___|__|_|_|_||__|_|__|_|_|");
	r++; move(r, c);
	printw("|__________________________________________|");
	r++; move(r, c);
	printw("|  || |  | |  | || | |   |  | | | ||  | |  |");
	r++; move(r, c);
	printw("|  || |  | |  | || | |   |  | | | ||  | |  |");
	r++; move(r, c);
	printw("|__||_|__|_|__|_||_|_|___|__|_|_|_||__|_|__|");
	r++; move(r, c);
	printw("|__________________________________________|");
	r = r + 3; move(r, c);
	printw("     PRESS ENTER TO PUSH THE BOOK SHELF");
}

void printDoorway(int startrow, int startcolumn)
{
	int r = startrow + 5;
	int c = startcolumn + 20;

	move(r, c);
	printw("____________________________");
	r++; move(r, c);
	printw("|  || |  | |  | || | |   |  |*");
	r++; move(r, c);
	printw("|  || |  | |  | || | |   |  |*");
	r++; move(r, c);
	printw("|__||_|__|_|__|_||_|_|___|__|*");
	r++; move(r, c);
	printw("|____________________________*");
	r++; move(r, c);
	printw("| || | |   ||  | |  | || | | *");
	r++; move(r, c);
	printw("| || | |   ||  | |  | || | | *");
	r++; move(r, c);
	printw("|_||_|_|___||__|_|__|_||_|_|_*");
	r++; move(r, c);
	printw("|____________________________*");
	r++; move(r, c);
	printw("| |  | |  | || | |   |  | | |*");
	r++; move(r, c);
	printw("| |  | |  | || | |   |  | | |*");
	r++; move(r, c);
	printw("|_|__|_|__|_||_|_|___|__|_|_|*");
	r++; move(r, c);
	printw("|____________________________*");
	r++; move(r, c);
	printw("|  || |  | |  | || | |   |  |*");
	r++; move(r, c);
	printw("|  || |  | |  | || | |   |  |*");
	r++; move(r, c);
	printw("|__||_|__|_|__|_||_|_|___|__|*");
	r++; move(r, c);
	printw("|____________________________*");
}

void printOldPhoto(int startrow, int startcolumn)
{
	int r = startrow;
	int c = startcolumn;
	move(r, c);

	printw("DDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDD");
	r++; move(r, c);
	printw("D                                 D");
	r++; move(r, c);
	printw("D                                 D");
	r++; move(r, c);
	printw("D                                 D");
	r++; move(r, c);
	printw("D             MMMMMMMM            D");
	r++; move(r, c);
	printw("D           MM M    M MM          D");
	r++; move(r, c);
	printw("D    MMMM      DMMMMD      MMMMM  D");
	r++; move(r, c);
	printw("D    MMMM~                 MMMM   D");
	r++; move(r, c);
	printw("D     MMM                  MMMM   D");
	r++; move(r, c);
	printw("D    MMMM                   MM    D");
	r++; move(r, c);
	printw("D    MMMMM DMMM      NMM  MMMMZ   D");
	r++; move(r, c);
	printw("D    MMMMMMM   D$$~     MMMMMM    D");
	r++; move(r, c);
	printw("D    MMMM        M         MM     D");
	r++; move(r, c);
	printw("D    MMMM   :I  MM  ZM     MMM    D");
	r++; move(r, c);
	printw("D   MMMMMM               NMMMMD   D");
	r++; move(r, c);
	printw("D   MMMMMMMMMO,        MMMMNMMM   D");
	r++; move(r, c);
	printw("D   +MM?~MMMMM        ,MMD MMM    D");
	r++; move(r, c);
	printw("D        M MMMM       MMMN  M     D");
	r++; move(r, c);
	printw("D        M MMMM       MMMN  M     D");
	r++; move(r, c);
	printw("D        M MMMMM      MM N  M     D");
	r++; move(r, c);
	printw("D        MMMMMMM     M MMN  M     D");
	r++; move(r, c);
	printw("D      M MMMM MMMM  M8,M$N        D");
	r++; move(r, c);
	printw("D                                 D");
	r++; move(r, c);
	printw("DDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDD");
}

void printOutline(int startrow, int startcolumn)
{
	int r = startrow;
	int c = startcolumn;
	move(r, c);

	printw("                      @*                                   ");
	r++; move(r, c);
	printw("                     @  ,@@.                               ");
	r++; move(r, c);
	printw("          @@@@@      @,   (@(                             ");
	r++; move(r, c);
	printw("         @     @@*      @&   .@&                           ");
	r++; move(r, c);
	printw("         @       #@.  .@@@      @                          ");
	r++; move(r, c);
	printw("          (@               . @@@.                          ");
	r++; move(r, c);
	printw("          @@            .@                                 ");
	r++; move(r, c);
	printw("      #@&.               .@(                               ");
	r++; move(r, c);
	printw("    &&      (@@&            *@,                            ");
	r++; move(r, c);
	printw("    @    .@.    #@,            &@*                         ");
	r++; move(r, c);
	printw("    @    @         @#             %@%*                     ");
	r++; move(r, c);
	printw("     %.  .@          %@.                 .@&@#             ");
	r++; move(r, c);
	printw("      (*             .@#                    %#           ");
	r++; move(r, c);
	printw("       *%   ,@            &@      @@@@&@       @.          ");
	r++; move(r, c);
	printw("         @, .@              #@      @     &&   ,&          ");
	r++; move(r, c);
	printw("           .                  #@      &    #    @.         ");
	r++; move(r, c);
	printw("                                &%      @   @    %@#.      ");
	r++; move(r, c);
	printw("                                  @       %@&%        @    ");
	r++; move(r, c);
	printw("                                    @%       ,&@@@@@@@%    ");
	r++; move(r, c);
	printw("                                      .&@@(.       #@      ");
	r++; move(r, c);
	printw("                                            .(@@*   (      ");
	r++; move(r, c);
	printw("                                                ,%   (     ");
	r++; move(r, c);
	printw("                                                 @   /    ");
	r++; move(r, c);
	printw("                                                 ,@@@  ");
}

void printGuilty(int startrow, int startcolumn)
{
	int r = startrow;
	int c = startcolumn;
	move(r, c);

	printw("     |      |                   |      |    ");
	r++; move(r, c);
	printw("     |      |                   |      |    ");
	r++; move(r, c);
	printw("     |      |                   |      |    ");
	r++; move(r, c);
	printw("     |      |                   |      |    ");
	r++; move(r, c);
	printw("     |      |                   |      |    ");
	r++; move(r, c);
	printw("     |      |                   |      |    ");
	r++; move(r, c);
	printw("     |      |                   |      |    ");
	r++; move(r, c);
	printw("     |      |                   |      |    ");
	r++; move(r, c);
	printw("     |      |                   |      |    ");
	r++; move(r, c);
	printw("    /       |                   |       \\");
	r++; move(r, c);
	printw("    |        \\                 /        |");
	r++; move(r, c);
	printw("    |         \\               /         |");
	r++; move(r, c);
	printw("    |       |  |             |  |       |");
	r++; move(r, c);
	printw("    | | | | || |             | || | | | |");
	r++; move(r, c);
	printw("    | | | | ||_|             |_|| | | | |");
	r++; move(r, c);
	printw("    |_| | | |                   | | | |_|");
	r++; move(r, c);
	printw("      |_| |_|                   |_| |_|");
	r++; move(r, c);
	printw("        |_|                       |_|");
}

void printCuffs(int startrow, int startcolumn)
{
	int r = startrow;
	int c = startcolumn;
	move(r, c);

	printw("   -----------                 ----------- ");
	r++; move(r, c);
	printw("  |           |===============|           |");
	r++; move(r, c);
	printw("   -----------                 ----------- ");
}

void printDog(int startrow, int startcolumn)
{
	int r = startrow;
	int c = startcolumn;
	move(r, c);

	printw("       **                               ");
	r++; move(r, c);
	printw("       ***                              ");
	r++; move(r, c);
	printw("       ****                             ");
	r++; move(r, c);
	printw("     *******                            ");
	r++; move(r, c);
	printw("  ************                          ");
	r++; move(r, c);
	printw("**************                          ");
	r++; move(r, c);
	printw(" **********   ***                       ");
	r++; move(r, c);
	printw("         *   ********     ***********   ");
	r++; move(r, c);
	printw("          **************************    ");
	r++; move(r, c);
	printw("          ***************************   ");
	r++; move(r, c);
	printw("          ***************************   ");
	r++; move(r, c);
	printw("          ***************************   ");
	r++; move(r, c);
	printw("          ***************   *********   ");
	r++; move(r, c);
	printw("           **********       *********   ");
	r++; move(r, c);
	printw("           ******            *******    ");
	r++; move(r, c);
	printw("           ******            *******    ");
	r++; move(r, c);
	printw("           ******             *** ***   ");
	r++; move(r, c);
	printw("           *** **             *** ***  ");
	r++; move(r, c);
	printw("           *** ***            *** ****  ");
	r++; move(r, c);
	printw("           *** ***           **** ***  ");
	r++; move(r, c);
	printw("         **** ****           ***  ***   ");
}

void printTail1(int startrow, int startcolumn)
{
	int r = startrow + 2;
	int c = startcolumn + 35;
	move(r, c);

	printw("**         ");
	r++; move(r, c);
	printw(" **     ");
	r++; move(r, c);
	printw(" **       ");
	r++; move(r, c);
	printw(" **      ");
	r++; move(r, c);
	printw("**       ");
}

void printTail2(int startrow, int startcolumn)
{
	int r = startrow + 2;
	int c = startcolumn + 35;
	move(r, c);

	printw(" **         ");
	r++; move(r, c);
	printw("  **     ");
	r++; move(r, c);
	printw("  **       ");
	r++; move(r, c);
	printw("  **      ");
	r++; move(r, c);
	printw("**       ");
}

void printTail3(int startrow, int startcolumn)
{
	int r = startrow + 2;
	int c = startcolumn + 35;
	move(r, c);

	printw("     **     ");
	r++; move(r, c);
	printw("    **     ");
	r++; move(r, c);
	printw("   **       ");
	r++; move(r, c);
	printw("  **      ");
	r++; move(r, c);
	printw("**       ");
}

void printTail4(int startrow, int startcolumn)
{
	int r = startrow + 2;
	int c = startcolumn + 35;
	move(r, c);

	printw("            ");
	r++; move(r, c);
	printw("    ** **  ");
	r++; move(r, c);
	printw("   **       ");
	r++; move(r, c);
	printw("  **      ");
	r++; move(r, c);
	printw("**       ");
}

void printVial(int startrow, int startcolumn)
{
	int r = startrow + 5;
	int c = startcolumn;
	move(r, c);

	printw("  _______________");
	r++; move(r, c);
	printw(" |_             _|");
	r++; move(r, c);
	printw("   |           |");
	r++; move(r, c);
	printw("   |^^^^^^^^^^^|");
	r++; move(r, c);
	printw("   |           |");
	r++; move(r, c);
	printw("   |           |");
	r++; move(r, c);
	printw("   |           |");
	r++; move(r, c);
	printw("   |           |");
	r++; move(r, c);
	printw("   |           |");
	r++; move(r, c);
	printw("   |           |");
	r++; move(r, c);
	printw("   |           |");
	r++; move(r, c);
	printw("   |___________|");
}

void printGrape(int startrow, int startcolumn)
{
	int r = startrow;
	int c = startcolumn + 7;
	move(r, c);

	printw(" ___");
	r++; move(r, c);
	printw("/   \\");
	r++; move(r, c);
	printw("\\___/");
}

void eraseGrape(int startrow, int startcolumn)
{
	int r = startrow;
	int c = startcolumn + 7;
	move(r, c);

	printw("     ");
	r++; move(r, c);
	printw("      ");
	r++; move(r, c);
	printw("     ");
}

void printReaction(int startrow, int startcolumn)
{
	int r = startrow + 13;
	int c = startcolumn + 7;
	int speed;
	move(r, c);

	for (int i = 0; i <= 5; i++)
	{
		move(r, c);
		printw("o");
		c = c + 3; move(r, c);
		printw("o");
		r--; c = startcolumn + 7;
		refresh();
		for (speed = 1; speed <= 55000000; speed++);
	}

	r = startrow + 8;
	c = startcolumn + 4;
	move(r, c);
	printw("^^oo^^^oo^^");
	refresh();
	for (speed = 1; speed <= 55000000; speed++);
	move(r, c);
	printw("^ooo^^^ooo^");
	refresh();
	for (speed = 1; speed <= 55000000; speed++);
	move(r, c);
	printw("oooo^^^oooo");
	refresh();
	for (speed = 1; speed <= 55000000; speed++);
	move(r, c);
	printw("ooooo^ooooo");
	refresh();
	for (speed = 1; speed <= 55000000; speed++);
	move(r, c);
	printw("ooooooooooo");
	refresh();
	for (speed = 1; speed <= 55000000; speed++);
}

void printPie(int startrow, int startcolumn)
{
	int r = startrow;
	int c = startcolumn;
	move(r, c);

	printw("              *  ** ***   ");
	r++; move(r, c);
	printw("            **         *     ");
	r++; move(r, c);
	printw("       ******           *          ");
	r++; move(r, c);
	printw("      ** *  * **********             ");
	r++; move(r, c);
	printw("     *    ***          ***             ");
	r++; move(r, c);
	printw("  ****  **        *  **  *              ");
	r++; move(r, c);
	printw(" *    **         *****   **             ");
	r++; move(r, c);
	printw(" * * **         * *       **            ");
	r++; move(r, c);
	printw("     **      * *  * * ** *  **         ");
	r++; move(r, c);
	printw("     *  *****  *  *  * *      *         ");
	r++; move(r, c);
	printw("     *   *  ***** * **         *        ");
	r++; move(r, c);
	printw("    ***          ****           *       ");
	r++; move(r, c);
	printw("      *              ****        *   ");
	r++; move(r, c);
	printw("      **                  ***      *   ");
	r++; move(r, c);
	printw("        *****                  **   *   ");
	r++; move(r, c);
	printw("             *****                  **  ");
	r++; move(r, c);
	printw("              ********              *  ");
	r++; move(r, c);
	printw("                     *******         *  ");
	r++; move(r, c);
	printw("                          *** ****  *   ");
	r++; move(r, c);
	printw("                                  * *   ");
}

void printCig(int startrow, int startcolumn)
{
	int r = startrow + 7;
	int c = startcolumn + 7;
	move(r, c);

	printw(" __________________________________");
	r++; move(r, c);
	printw(":                          |       |");
	r++; move(r, c);
	printw(":__________________________|_______|");
}

void printSmoke1(int startrow, int startcolumn)
{
	int r = startrow;
	int c = startcolumn;
	move(r, c);

	printw("   *  *  *  ");
	r++; move(r, c);
	printw("    *  *  *  ");
	r++; move(r, c);
	printw("   * *  *   ");
	r++; move(r, c);
	printw("    *  * *  ");
	r++; move(r, c);
	printw("   *  *     ");
	r++; move(r, c);
	printw("   * *  *   ");
	r++; move(r, c);
	printw("    *  *   ");
	r++; move(r, c);
	printw("     * *");
	r++; move(r, c);
	printw("      *");
}

void printSmoke2(int startrow, int startcolumn)
{
	int r = startrow;
	int c = startcolumn;
	move(r, c);

	printw("    *  *  *       ");
	r++; move(r, c);
	printw("     * *   *       ");
	r++; move(r, c);
	printw("    * *  * ");
	r++; move(r, c);
	printw("   * *  *        ");
	r++; move(r, c);
	printw("    *  *   ");
	r++; move(r, c);
	printw("    *  * *   ");
	r++; move(r, c);
	printw("     *  *  ");
	r++; move(r, c);
	printw("    * * ");
	r++; move(r, c);
	printw("     * ");
}

void printSmoke3(int startrow, int startcolumn)
{
	int r = startrow;
	int c = startcolumn;
	move(r, c);

	printw("    *  *   *       ");
	r++; move(r, c);
	printw("    *  *  *       ");
	r++; move(r, c);
	printw("   *  * * ");
	r++; move(r, c);
	printw("  *  * *        ");
	r++; move(r, c);
	printw("   * * *          ");
	r++; move(r, c);
	printw("    *   *   ");
	r++; move(r, c);
	printw("    *  *  ");
	r++; move(r, c);
	printw("     * *");
	r++; move(r, c);
	printw("      *");
}

void printSmoke4(int startrow, int startcolumn)
{
	int r = startrow;
	int c = startcolumn;
	move(r, c);

	printw("   *   *   *    ");
	r++; move(r, c);
	printw("   *  *  *     ");
	r++; move(r, c);
	printw("    * *   *     ");
	r++; move(r, c);
	printw("   *  * *     ");
	r++; move(r, c);
	printw("  *  * *       ");
	r++; move(r, c);
	printw("   *   *       ");
	r++; move(r, c);
	printw("   *  *        ");
	r++; move(r, c);
	printw("    * * ");
	r++; move(r, c);
	printw("      *");
}

void printTub(int startrow, int startcolumn)
{
	int r = startrow + 4;
	int c = startcolumn;
	move(r, c);

	printw("  ____                  ____");
	r++; move(r, c);
	printw("  \\   \\________________/   /");
	r++; move(r, c);
	printw("   |                      |");
	r++; move(r, c);
	printw("   |                      |");
	r++; move(r, c);
	printw("    \\____________________/");
	r++; move(r, c);
	printw("      ||              ||");
}

void printBubbles1(int startrow, int startcolumn)
{
	int r = startrow + 2;
	int c = startcolumn;
	move(r, c);

	printw("          o               ");
	r++; move(r, c);
	printw("              o    x            ");
	r++; move(r, c);
	printw("  ____  o               ____");
}

void printBubbles2(int startrow, int startcolumn)
{
	int r = startrow + 2;
	int c = startcolumn;
	move(r, c);

	printw("          x   o           ");
	r++; move(r, c);
	printw("        o                    ");
	r++; move(r, c);
	printw("  ____              o   ____");
}

void printBubbles3(int startrow, int startcolumn)
{
	int r = startrow + 2;
	int c = startcolumn;
	move(r, c);

	printw("        o     x           ");
	r++; move(r, c);
	printw("                    o         ");
	r++; move(r, c);
	printw("  ____     o            ____");
}

void printBubbles4(int startrow, int startcolumn)
{
	int r = startrow + 2;
	int c = startcolumn;
	move(r, c);

	printw("        x                 ");
	r++; move(r, c);
	printw("           o        o        ");
	r++; move(r, c);
	printw("  ____         o        ____");
}

void printSky(int startrow, int startcolumn)
{
	int r = startrow;
	int c = startcolumn;
	move(r, c);

	printw("                                           ");
	r++; move(r, c);
	printw("                      *                     ");
	r++; move(r, c);
	printw("      *                     *        *        ");
	r++; move(r, c);
	printw("                                           ");
	r++; move(r, c);
	printw("                                           ");
	r++; move(r, c);
	printw("         *          *                       ");
	r++; move(r, c);
	printw("                                           ");
	r++; move(r, c);
	printw("                                           ");
	r++; move(r, c);
	printw("   *                            *            ");
	r++; move(r, c);
	printw("                  *                       *  ");
	r++; move(r, c);
	printw("                                           ");
	r++; move(r, c);
	printw("__________________________________________");
	r++; move(r, c);
	printw("__________________________________________|");
	r++; move(r, c);
	printw("   | |        | |        | |        | |");
	r++; move(r, c);
	printw("   | |    *   | |        | |        | |");
	r++; move(r, c);
	printw("   | |        | |        | |        | |");
	r++; move(r, c);
	printw("   | |        | |        | |      * | |");
}

void printShootingStar(int startrow, int startcolumn)
{
	int r = startrow;
	int c = startcolumn;
	move(r, c);

	printw("----x");
}

void eraseShootingStar(int startrow, int startcolumn)
{
	int r = startrow;
	int c = startcolumn;
	move(r, c);

	printw("     ");
}
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
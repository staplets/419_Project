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

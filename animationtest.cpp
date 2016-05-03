#include <iostream>
#include "animation.cpp"

using namespace std;

int main()
{
	int choice;
	int start_row = 4;
	int start_column = 4;
	int i;
	int speed;

	cout << "Which animation would you like to see?" <<endl;
	cout << "1. Key" << endl;
	cout << "2. Light" << endl;
	cout << "3. Piano" << endl;
	cout << "4. Dripping" << endl;
	cin >> choice;

	initscr();

	if (choice == 1)
	{

		for (i = 1; i <= 28; i++)
		{
			printKey(start_row, start_column);
			eraseLock(6, 54, 9, 8);
			refresh();
			for (speed = 1; speed <= 55000000; speed++);

			eraseKey(start_row, start_column);
			refresh();

			printLock(6, 48, 9, 5);
			eraseLock(6, 54, 9, 8);

			start_row++;
		}
		printKey(start_row, start_column);
		eraseLock(6, 54, 9, 8);
		refresh();

		getch();
		endwin();
	}

	else if (choice == 2)
	{
		printBurst(30, 10, 50000000, 7);
		eraseBurst(30, 10, 50000000, 7);

		getch();
		endwin();
	}

	else if (choice == 3)
	{
		start_row = 3;
		start_column = 10;
		for (i = 1; i < 7; i++)
		{
			eraseHands(start_row, start_column);
			printPiano(3, 10);
			refresh();
			start_row--;
			printHands(start_row, start_column);
			refresh();
			for (speed = 1; speed <= 55000000; speed++);
		}

		for (i = 1; i < 12; i++)
		{
			refresh();
			for (speed = 1; speed <= 55000000; speed++);
		}

		for (i = 1; i < 8; i++)
		{
			eraseHands(start_row, start_column);
			printPiano(3, 10);
			refresh();
			start_column--;
			printHands(start_row, start_column);
			refresh();
			for (speed = 1; speed <= 55000000; speed++);
		}

		for (i = 1; i < 10; i++)
		{
			refresh();
			for (speed = 1; speed <= 55000000; speed++);
		}

		for (i = 1; i < 8; i++)
		{
			eraseHands(start_row, start_column);
			printPiano(3, 10);
			refresh();
			start_column++;

			printHands(start_row, start_column);
			refresh();
			for (speed = 1; speed <= 55000000; speed++);
		}

		eraseHands(start_row, start_column);
		printPiano(3, 10);
		refresh();
		printHands(start_row, start_column);

		getch();
		endwin();
	}

	else if (choice == 4)
	{
		printSherlock(start_row, start_column);
		for (i = 0; i < 19; i++)
		{
			printDrops1(start_row, start_column);
			refresh();
			eraseDrops1(start_row, start_column);
			start_row = start_row + 1;
			for (speed = 1; speed <= 56000000; speed++);
		}
		refresh();
		for (speed = 1; speed <= 5500000; speed++);
		start_row = start_row - 19;
		for (i = 0; i < 19; i++)
		{
			printDrops2(start_row, start_column);
			refresh();
			eraseDrops2(start_row, start_column);
			start_row = start_row + 1;
			for (speed = 1; speed <= 56000000; speed++);
		}
		refresh();
		for (speed = 1; speed <= 5500000; speed++);
		start_row = start_row - 19;
		for (i = 0; i < 19; i++)
		{
			printDrops1(start_row, start_column);
			refresh();
			eraseDrops1(start_row, start_column);
			start_row = start_row + 1;
			for (speed = 1; speed <= 56000000; speed++);
		}

		getch();
		endwin();
	}

	cout << "I hope you enjoyed the animation!" << endl;
	return 0;
}
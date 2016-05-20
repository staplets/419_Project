#include <ncurses.h>


void printKey(int startrow, int startcolumn);
void eraseKey(int startrow, int startcolumn);

void printLock(int startrow, int startcolumn, int height, int width);
void eraseLock(int startrow, int startcolumn, int height, int width);

void printBurst(int startrow, int startcol, int speed, int size);
void eraseBurst(int startrow, int startcol, int speed, int size);

void printPiano(int startrow, int startcolumn);

void printHands(int startrow, int startcolumn);
void eraseHands(int startrow, int startcolumn);

void printSherlock(int startrow, int startcolumn);

void printDrops1(int startrow, int startcolumn);
void printDrops2(int startrow, int startcolumn);

void eraseDrops1(int startrow, int startcolumn);
void eraseDrops2(int startrow, int startcolumn);

void printSpider1(int startrow, int startcolumn);
void printSpider2(int startrow, int startcolumn);
void printSpider3(int startrow, int startcolumn);
void eraseSpider(int startrow, int startcolumn);

void printCandle(int startrow, int startcolumn);
void printFlame1(int startrow, int startcolumn);
void printFlame2(int startrow, int startcolumn);
void printFlame3(int startrow, int startcolumn);
void eraseFlame(int startrow, int startcolumn);

void printZee(int startrow, int startcolumn);

void printBar(int startrow, int startcolumn);
void printPour(int startrow, int startcolumn);
void printGlass(int startrow, int startcolumn);
void erasePour(int startrow, int startcolumn);
void printFill(int startrow, int startcolumn);

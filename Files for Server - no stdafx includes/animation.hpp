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
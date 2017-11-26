#ifndef _BLOCK_H_
#define _BLOCK_H_
#include <vector>
#include <iostream>
#include <string>
#include "cell.h"

class Board;

class Block {
protected:
	Board* board;
    std::vector<Cell *> cells;
	char type;
	int ID;
	int curr_level;
public:
	Block(Board* pboard);
	virtual ~Block();

	virtual void rotateCW() = 0;
	virtual void rotateCCW() = 0;

	void setLevel(int);
	char getType();
	int getID();
	void transferID(int index, int r, int c);
	bool isLegalMove(int pr, int pc);
	bool isLegalCell(int r, int c);
	void left();
	void right();
	void down();


	friend std::ostream &operator<<(std::ostream &out, Block &bl);

};

#endif
#pragma once

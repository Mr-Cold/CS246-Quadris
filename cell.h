#ifndef _CELL_H_
#define _CELL_H_

#include <iostream>
#include <string>

class Cell {
	int row, col;
	int b_id;
	char b_type;
	int lvl_started;
	bool filled;
public:
	//Cell();
	Cell(int r, int c);
	Cell(int r, int c, int b_id, char type, int lvl, bool filled);
	~Cell();
	int getRow();
	int getCol();
	int getID();
	int getLvl();
	void setID(int);
	void setRow(int);
	void setCol(int);
	bool isFilled();
	friend std::ostream &operator<<(std::ostream &out, const Cell &c);
};
#endif
#pragma once

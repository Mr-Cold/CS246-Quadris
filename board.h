#ifndef _BOARD_H_
#define _BOARD_H_

#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <vector>
#include <cstdlib>

class Cell;
class Block;

class Board {
	Cell ***grids; //2d array of pointers
	//Xwindow w;    later
	Block * curr_block;
	Block * next_block;
	std::vector <int> usedID;
	std::string fileName;
	int level = 0;
	int l0counter = 1;
	int curr_score;
	int hi_score;
	int curr_ID;
	const int row_size = 18;
	const int col_size = 11;
	bool graphicOn;
	bool random;

	bool hasNeighbour(int r, int c);
	void calculateScore();
	void removeRow(int r);
	bool gameFinished();
	//void updateGraphic();
	void undrawBlock();
	void drawBlock();
	bool hasAbove(int r, int c);
	Block* createBlock();
	Block* createSpBlock(char c);
public:
	Board();
	~Board();
	Cell* getCell(int r, int c);
	void setSeed(int i);
	void setLevel(int);
	void setFile(std::string);
	void GraphicOn();
	void GraphicOff();
	bool isGraphicOn();
	void restart();
	void lvlUp();
	void lvlDown();
	void left();
	void right();
	void down();
	void	drop();
	void rotateCW();
	void rotateCCW();
	//void hint();

	friend std::ostream &operator<<(std::ostream &out, const Board &b);

};

#endif
#pragma once

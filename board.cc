#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <time.h> 
#include <stdlib.h>  

#include "board.h"
#include "block.h"
#include "iblock.h"
#include "jblock.h"
#include "oblock.h"
#include "zblock.h"
#include "sblock.h"
#include "tblock.h"
#include "lblock.h"

using namespace std;

Board::Board() {
	grids = new Cell* *[row_size];
	for (int i = 0; i < row_size; i++) {
		grids[i] = new Cell*[col_size];
		for (int j = 0; j < col_size; j++) {
			grids[i][j] = new Cell(i, j);
		}
	}
	level = 0;
	curr_score = 0;
	hi_score = 0;
	graphicOn = false;
	curr_ID = 0;
	srand(time(NULL));
	fileName = "sequence.txt";

	
	curr_block = createBlock();
	next_block = createBlock();


	//draw curr_block into the grid
	drawBlock();
}


Board::~Board() {
	for (int i = 0; i < row_size; i++) {
		for (int j = 0; j < col_size; j++) {
			delete grids[i][j];
		}
	}
	delete grids;
	delete curr_block;
	delete next_block;
}

bool Board::hasNeighbour(int r, int c) {
	int tmpid = getCell(r, c)->getID();
	bool has_neighbour = false;
	//check from (r-3,c-3) to (r+3, c+3)
	for (int i = -3; i < 4; i++) {
		for (int j = -3; j < 4; j++) {
			if (getCell(r + i, c + j)->getID() == tmpid) {
				has_neighbour = true;
				break;
			}
		}
	}
	return has_neighbour;
}


void Board::calculateScore() {
	int linecleared = 0;
	//first check lines
	for (int i = row_size - 1; i >= 0; i--) {
		bool linefull = true;
		for (int j = 0; j < col_size; j++) {
			if (!grids[i][j]->isFilled()) {
				linefull = false;
			}
		}
		if (linefull) {
			for (int k = 0; k < col_size; k++) {
				bool sameid = false;
				for (auto it : usedID) {
					if (grids[i + linecleared][k]->getID() == it) {
						sameid = true; // means the block hasn't been completely removed yet
					}
				}
				if (sameid == false) { // if the block was cleared, add bonus mark for that block
					usedID.emplace_back(grids[i + linecleared][k]->getID());
					int block_bonus = getCell(i + linecleared, k)->getLvl() + 1;
					curr_score += block_bonus*  block_bonus;
				}
			}
			removeRow(i + linecleared);
			linecleared++;
		}
	}
	// if we have some rows cleraed, add the score
	if (linecleared != 0) {
		curr_score += (linecleared + level)*(linecleared + level);
		if (curr_score > hi_score) {
			hi_score = curr_score;
		}
	}
}

void Board::removeRow(int r) {
	for (int i = r; i > 0; i++) {
		for (int j = 0; j < col_size; j++) {
			if (i == r) {
				delete grids[i][j];
			}
			else {
				grids[i][j] = grids[i - 1][j];
			}
		}
	}
	for (int k = 0; k < col_size; k++) {
		grids[0][k] = new Cell(0, k);
	}
}

bool Board::gameFinished() { // after drop, check if there are any cells on row[3]. if so,that means game over
	for (int j = 0; j < 4; j++) {
		if (grids[3][j]->isFilled()) {
			return true;
		}
	}
	return false;
}

void Board::undrawBlock() {
	vector<Cell*> cells = curr_block->getCells();
	for (int i = 0; i < 4; i++) {
		int r = cells[i]->getRow();
		int c = cells[i]->getCol();
		grids[r][c] = new Cell(r, c);
	}
}

void Board::drawBlock() {
	vector<Cell*> cells = curr_block->getCells();
	for (int i = 0; i < 4; i++) {
		int r = cells[i]->getRow();
		int c = cells[i]->getCol();
		//delete grids[r][c];
		grids[r][c] = cells[i];
		
	}
}

bool Board::hasAbove(int r, int c) {
	bool above = true;
	for (int i = r; i > 0; i--) {
		if (grids[i][c]->isFilled()) {
			return false;
		}
	}
	return above;
}

Cell* Board::getCell(int r, int c) {
	return grids[r][c];
}

Block * Board::createBlock() {

	curr_ID++;
	switch (level) {
	case 0: {
		char type;
		ifstream file(fileName);
		for (int i = 0; i < l0counter; i++) {
			file >> type;
			
			if (file.eof()) {
				file.clear(); //clear fail end of bits
				file.seekg(0, std::ios::beg); // back to the start!
				file >> type;
				l0counter = 1;
			}
		}


		l0counter++;
		switch (type) {
		case 'I': { return new iBlock(this, curr_ID); break; }
		case 'J': { return new jBlock(this, curr_ID); break; }
		case 'O': { return new oBlock(this, curr_ID); break; }
		case 'S': { return new sBlock(this, curr_ID); break; }
		case 'Z': { return new zBlock(this, curr_ID); break; }
		case 'L': { return new lBlock(this, curr_ID); break; }
		case 'T': { return new tBlock(this, curr_ID); break; }
		}
	}
	default: {
		cout << "ERROR with generating Block" << endl;
	}
	}
	cout << "After Switch" << endl;
}

Block* Board::createSpBlock(char c) {
	switch (c) {
	case 'I': { return new iBlock(this, curr_ID); break; }
	case 'J': { return new jBlock(this, curr_ID); break; }
	case 'O': { return new oBlock(this, curr_ID); break; }
	case 'S': { return new sBlock(this, curr_ID); break; }
	case 'Z': { return new zBlock(this, curr_ID); break; }
	case 'L': { return new lBlock(this, curr_ID); break; }
	case 'T': { return new tBlock(this, curr_ID); break; }
	}
}


void Board::setSeed(int i) {
	srand(i);
}

void Board::setLevel(int l) {
	level = l;
}

void Board::setFile(string f) {
	fileName = f;
}

void Board::GraphicOn() {
	graphicOn = true;
}

void Board::GraphicOff() {
	graphicOn = false;
}

bool Board::isGraphicOn() {
	return graphicOn;
}

void Board::restart() {
	for (int i = 0; i < row_size; i++) {
		for (int j = 0; j < col_size; j++) {
			delete grids[i][j];
			grids[i][j] = new Cell(i, j);
		}
	}
	delete next_block;
	curr_score = 0;
	curr_ID = 0;
	curr_block = createBlock();
	next_block = createBlock();

	drawBlock();
}

void Board::lvlUp() {
	level++;
}

void Board::lvlDown() {
	level--;
}

void Board::left() {
	undrawBlock();
	curr_block->left();
	drawBlock();
}

void Board::right() {
	undrawBlock();
	curr_block->right();
	drawBlock();
}

void Board::down() {
	undrawBlock();
	curr_block->right();
	drawBlock();
}

void Board::drop() {
	undrawBlock();
	int count = 0;
	bool move = true;
	while (move) {
		move = curr_block->isLegalMove(count, 0);
		count++;
	}
	for (int i = 1; i < count; i++) {
		curr_block->down();
	}
	drawBlock();
	calculateScore();
	delete curr_block;

	if (gameFinished()) {
		cout << "GAME OVER" << endl;
	}
	else {
		curr_block = next_block;
		next_block = createBlock();
		drawBlock();
	}
}

void Board::rotateCW() {
	undrawBlock();
	curr_block->rotateCW();
	drawBlock();
}

void Board::rotateCCW() {
	undrawBlock();
	curr_block->rotateCCW();
	drawBlock();
}

std::ostream &operator<<(std::ostream &out, const Board &b) {
	out << "Level:      " << b.level << endl;
	out << "Score:      " << b.curr_score << endl;
	out << "Hi Score:   " << b.hi_score << endl;
	out << "------------" << endl;
	for (int i = 0; i < 18; i++) {
		for (int j = 0; j < 11; j++) {
			out << *(b.grids[i][j]);
		}
		out << endl;
	}
	out << "------------" << endl;
	out << "Next:" << endl;
	out << *(b.next_block);

	return out;
}

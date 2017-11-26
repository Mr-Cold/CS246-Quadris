#include <iostream>
#include <string>
#include <vector>
#include "block.h"
#include "board.h"

using namespace std;


Block::Block(Board* pboard): board { pboard }{}

Block::~Block() {
    if (board) delete board;
    for (vector<Cell *>::iterator it = cells.begin(); it != cells.end(); ++it) {
        delete it;
    }
}

void Block::setLevel(int lvl) {
	curr_level = lvl;
}

char Block::getType() {
	return type;
}

int Block::getID() {
	return ID;
}

void Block::transferID(int index, int r, int c) {
	cells.at(index)->setRow(r);
	cells.at(index)->setCol(c);
}

bool Block::isLegalCell(int r, int c) {
	if (r < 0 || r >= 18 || c < 0 || c >= 11 || board->getCell(r, c)->isFilled()) {
		return false;
	}
	else {
		return true;
	}
}

bool Block::isLegalMove(int pr, int pc) {
	bool legal = true;
	for (int i = 0; i < 4; i++) {
		int tmpR = cells.at(i)->getRow() + pr;
		int tmpC = cells.at(i)->getCol() + pc;
		if (isLegalCell(tmpR, tmpC)){
			legal = false;
			break;
		}
	 }
	return legal;
}

void Block::left() {
	if (isLegalMove(0, -1)) {
		for (int i = 0; i < 4; i++) {
			int tmpR = cells.at(i)->getRow();
			int tmpC = cells.at(i)->getCol() - 1;
			transferID(i, tmpR, tmpC);
		}
	}
}

void Block::right() {
	if (isLegalMove(0, 1)) {
		for (int i = 0; i < 4; i++) {
			int tmpR = cells.at(i)->getRow();
			int tmpC = cells.at(i)->getCol() + 1;
			transferID(i, tmpR, tmpC);
		}
	}
}

void Block::down() {
	if (isLegalMove(1, 0)) {
		for (int i = 0; i < 4; i++) {
			int tmpR = cells.at(i)->getRow() + 1;
			int tmpC = cells.at(i)->getCol();
			transferID(i, tmpR, tmpC);
		}
	}
}
std::ostream &operator<<(std::ostream &out, Block &b) {
	for (int i = 3; i < 7; i++) {
		string s;
		for (int j = 0; j < 4; j++) {
			if (b.cells.at(j)->getRow() == i && b.cells.at(j)->getCol() == j) {
				s += b.type;
			}
		}
		out << s<<endl;
	}
}

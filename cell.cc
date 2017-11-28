#include <iostream>
#include "cell.h"

using namespace std;

Cell::Cell(int r, int c) : row{ r }, col{ c } {
	b_id = -1;
	b_type = ' ';
	lvl_started = -1;
	filled = false;
}

Cell::Cell(int r, int c, int b_id, char type, int lvl, bool filled) : row{ r }, col{ c }, b_id{ b_id }, b_type{ type }, lvl_started{ lvl }, filled{ filled } {}

Cell::~Cell() {}

int Cell::getRow() {
	return row;
}

int Cell::getCol() {
	return col;
}

int Cell::getID() {
	return b_id;
}

void Cell::setID(int id) {
	b_id = id;
}

void Cell::setRow(int r) {
	row = r;
}

void Cell::setCol(int c) {
	col = c;
}

bool Cell::isFilled() {
	return filled;
}

std::ostream &operator<<(std::ostream &out, const Cell &c) {
	if (c.filled) {
		out << c.b_type;
	}
	else {
		out << ' ';
	}
	return out;
}



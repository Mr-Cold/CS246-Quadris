#include "cell.h"
#include "block.h"
#include "iblock.h"
#include <iostream>
using namespace std;
iBlock::iBlock(Board *pb, int id) : Block{ pb } {
	type = 'I';
	cells.emplace_back(new Cell(3, 0, id, 'I', curr_level, true));
	cells.emplace_back(new Cell(3, 1, id, 'I', curr_level, true));
	cells.emplace_back(new Cell(3, 2, id, 'I', curr_level, true));
	cells.emplace_back(new Cell(3, 3, id, 'I', curr_level, true));
}


void iBlock::rotateCW() {
	// if it is vertical
	if (cells[0]->getRow() != cells[1]->getRow()) {
		cout << "vertical" << endl;
		//check if cells on board are avaliable
		if (isLegalCell(cells.at(0)->getRow() + 3, cells.at(1)->getCol()) && isLegalCell(cells.at(1)->getRow() + 2, cells.at(1)->getCol() + 1) && isLegalCell(cells.at(2)->getRow() + 1, cells.at(2)->getCol() + 2) && isLegalCell(cells.at(3)->getRow(), cells.at(3)->getCol()) + 3) {
			transferID(0, cells.at(0)->getRow() + 3, cells.at(0)->getCol());
			transferID(1, cells.at(1)->getRow() +2, cells.at(1)->getCol()+1 );
			transferID(2, cells.at(2)->getRow() +1, cells.at(2)->getCol()+2);
			transferID(3, cells.at(3)->getRow() , cells.at(3)->getCol() +3);
		}
	}
	else { // if it is horizontal, flip it to vertical
		cout << "horizontal" << endl;
		if (isLegalCell(cells.at(0)->getRow() - 3, cells.at(1)->getCol()) && isLegalCell(cells.at(1)->getRow()-2, cells.at(1)->getCol()-1) && isLegalCell(cells.at(2)->getRow() -1, cells.at(2)->getCol() - 2) && isLegalCell(cells.at(3)->getRow() , cells.at(3)->getCol())-3) {
			transferID(0, cells.at(0)->getRow() - 3, cells.at(0)->getCol());
			transferID(1, cells.at(1)->getRow() -2, cells.at(1)->getCol() -1);
			transferID(2, cells.at(2)->getRow() - 1, cells.at(2)->getCol() -2 );
			transferID(3, cells.at(3)->getRow() , cells.at(3)->getCol()-3);

		}
	}
}

	void iBlock::rotateCCW() {
		rotateCW();
	}

	iBlock::~iBlock() {}
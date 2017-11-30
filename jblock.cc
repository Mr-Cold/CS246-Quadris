#include "jblock.h"
#include "cell.h"

jBlock::jBlock(Board *pb, int id) :	Block{ pb } 
{		
	type = 'J';
	cells.emplace_back(new Cell(2, 0, id, 'J', curr_level, true));
	cells.emplace_back(new Cell(3, 0, id, 'J', curr_level, true));
	cells.emplace_back(new Cell(3, 1, id, 'J', curr_level, true));
	cells.emplace_back(new Cell(3, 2, id, 'J', curr_level, true));
}

void jBlock::rotateCW() {
	// in position like "|___"
	if (cells.at(1)->getCol() < cells.at(2)->getCol()) {
		if (isLegalCell(cells.at(0)->getRow() - 1, cells.at(1)->getCol() + 1) && isLegalCell(cells.at(1)->getRow() - 2, cells.at(1)->getCol()) && isLegalCell(cells.at(2)->getRow() - 1, cells.at(2)->getCol() - 1) && isLegalCell(cells.at(3)->getRow(), cells.at(3)->getCol() - 2)) {
			transferID(0, cells.at(0)->getRow() - 1, cells.at(0)->getCol() + 1);
			transferID(1, cells.at(1)->getRow() - 2, cells.at(0)->getCol() );
			transferID(2, cells.at(2)->getRow() - 1, cells.at(0)->getCol() - 1);
			transferID(3, cells.at(3)->getRow(), cells.at(0)->getCol() -2);
		}
	}
	//in position like "|``"
	else if (cells.at(1)->getCol() < cells.at(0)->getCol()) {
		if (isLegalCell(cells.at(0)->getRow() +2, cells.at(1)->getCol() + 1) && isLegalCell(cells.at(1)->getRow() + 1, cells.at(1)->getCol()+2) && isLegalCell(cells.at(2)->getRow() , cells.at(2)->getCol() +1) && isLegalCell(cells.at(3)->getRow()-1, cells.at(3)->getCol())) {
			transferID(0, cells.at(0)->getRow() +2, cells.at(0)->getCol() + 1);
			transferID(1, cells.at(1)->getRow() + 1 , cells.at(0)->getCol()+2);
			transferID(2, cells.at(2)->getRow(), cells.at(0)->getCol() + 1);
			transferID(3, cells.at(3)->getRow() - 1, cells.at(0)->getCol());
		}
	}
	// in position like "--="
	else if (cells.at(1)->getRow() < cells.at(0)->getRow()) {
		if (isLegalCell(cells.at(0)->getRow() , cells.at(1)->getCol() -2) && isLegalCell(cells.at(1)->getRow() - 1, cells.at(1)->getCol() - 1) && isLegalCell(cells.at(2)->getRow(), cells.at(2)->getCol()) && isLegalCell(cells.at(3)->getRow() - 1, cells.at(3)->getCol()+1)) {
			transferID(0, cells.at(0)->getRow(), cells.at(0)->getCol() - 2);
			transferID(1, cells.at(1)->getRow() - 1, cells.at(0)->getCol() -1);
			transferID(2, cells.at(2)->getRow(), cells.at(0)->getCol());
			transferID(3, cells.at(3)->getRow() - 1, cells.at(0)->getCol()+1);
		}
	}
	// in position like "_|"
	else if (cells.at(1)->getCol() > cells.at(0)->getCol()) {
		if (isLegalCell(cells.at(0)->getRow() - 1, cells.at(1)->getCol()) && isLegalCell(cells.at(1)->getRow(), cells.at(1)->getCol() - 1) && isLegalCell(cells.at(2)->getRow() +1, cells.at(2)->getCol()) && isLegalCell(cells.at(3)->getRow() +2, cells.at(3)->getCol() + 1)) {
			transferID(0, cells.at(0)->getRow() -1, cells.at(0)->getCol());
			transferID(1, cells.at(1)->getRow(), cells.at(0)->getCol() - 1);
			transferID(2, cells.at(2)->getRow()+1, cells.at(0)->getCol());
			transferID(3, cells.at(3)->getRow() +2, cells.at(0)->getCol() + 1);
		}
	}
}

void jBlock::rotateCCW() {
	// in position like "|___"
	if (cells.at(1)->getCol() < cells.at(2)->getCol()) {
		if (isLegalCell(cells.at(0)->getRow() + 1, cells.at(1)->getCol()) && isLegalCell(cells.at(1)->getRow(), cells.at(1)->getCol() + 1) && isLegalCell(cells.at(2)->getRow() - 1, cells.at(2)->getCol()) && isLegalCell(cells.at(3)->getRow() - 2, cells.at(3)->getCol() - 1)) {
			transferID(0, cells.at(0)->getRow() + 1, cells.at(0)->getCol());
			transferID(1, cells.at(1)->getRow(), cells.at(0)->getCol() + 1);
			transferID(2, cells.at(2)->getRow() - 1, cells.at(0)->getCol());
			transferID(3, cells.at(3)->getRow() - 2, cells.at(0)->getCol() - 1);
		}
	}
	// in position like "_|"
	else if (cells.at(1)->getCol() > cells.at(0)->getCol()) {
		if (isLegalCell(cells.at(0)->getRow(), cells.at(1)->getCol() + 2) && isLegalCell(cells.at(1)->getRow() + 1, cells.at(1)->getCol() + 1) && isLegalCell(cells.at(2)->getRow(), cells.at(2)->getCol()) && isLegalCell(cells.at(3)->getRow() + 1, cells.at(3)->getCol() - 1)) {
			transferID(0, cells.at(0)->getRow(), cells.at(0)->getCol() + 2);
			transferID(1, cells.at(1)->getRow() + 1, cells.at(0)->getCol() + 1);
			transferID(2, cells.at(2)->getRow(), cells.at(0)->getCol());
			transferID(3, cells.at(3)->getRow() + 1, cells.at(0)->getCol() - 1);
		}
	}
	// in position like "--="
	else if (cells.at(1)->getRow() < cells.at(0)->getRow()) {
		if (isLegalCell(cells.at(0)->getRow() - 2, cells.at(1)->getCol() - 1) && isLegalCell(cells.at(1)->getRow() - 1, cells.at(1)->getCol() - 2) && isLegalCell(cells.at(2)->getRow(), cells.at(2)->getCol() - 1) && isLegalCell(cells.at(3)->getRow() + 1, cells.at(3)->getCol())) {
			transferID(0, cells.at(0)->getRow() - 2, cells.at(0)->getCol() - 1);
			transferID(1, cells.at(1)->getRow() - 1, cells.at(0)->getCol() - 2);
			transferID(2, cells.at(2)->getRow(), cells.at(0)->getCol() - 1);
			transferID(3, cells.at(3)->getRow() + 1, cells.at(0)->getCol());
		}
	}
	//in position like "|``"
	else if (cells.at(1)->getCol() < cells.at(0)->getCol()) {
		if (isLegalCell(cells.at(0)->getRow() + 1, cells.at(1)->getCol() - 1) && isLegalCell(cells.at(1)->getRow() + 2, cells.at(1)->getCol()) && isLegalCell(cells.at(2)->getRow() + 1, cells.at(2)->getCol() + 1) && isLegalCell(cells.at(3)->getRow(), cells.at(3)->getCol() + 2)) {
			transferID(0, cells.at(0)->getRow() + 1, cells.at(0)->getCol() - 1);
			transferID(1, cells.at(1)->getRow() + 2, cells.at(0)->getCol());
			transferID(2, cells.at(2)->getRow() + 1, cells.at(0)->getCol() + 1);
			transferID(3, cells.at(3)->getRow(), cells.at(0)->getCol() + 2);
		}
	}
}
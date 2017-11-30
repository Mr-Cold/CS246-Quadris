//
//  tblock.cpp
//  q5
//
//  Created by Katie on 2017/11/28.
//  Copyright © 2017年 Katie. All rights reserved.
//

#include "tblock.h"
#include "cell.h"
#include "block.h"

tBlock::tBlock(Board * pb, int id): Block{pb} {
	type = 'T';
    cells.emplace_back(new Cell(2, 0, id, 'T', curr_level, true));
    cells.emplace_back(new Cell(2, 1, id, 'T', curr_level, true));
    cells.emplace_back(new Cell(2, 2, id, 'T', curr_level, true));
    cells.emplace_back(new Cell(3, 1, id, 'T', curr_level, true));

}

void tBlock::rotateCW() {
    // if it t is on the bottom
    if ((cells[3]->getCol() == cells[1]->getCol()) &&
        (cells[3]->getRow() > cells[1]->getRow())) {
        //check if cells on board are avaliable
        if (isLegalCell(cells.at(0)->getRow() - 1, cells.at(0)->getCol() + 1) && isLegalCell(cells.at(2)->getRow() + 1, cells.at(2)->getCol() - 1) && isLegalCell(cells.at(3)->getRow() - 1, cells.at(3)->getCol() - 1)) {
            transferID(0, cells.at(1)->getRow() - 1, cells.at(1)->getCol() + 1);
            transferID(2, cells.at(2)->getRow() + 1, cells.at(2)->getCol() - 1);
            transferID(3, cells.at(3)->getRow() - 1, cells.at(3)->getCol() - 1);
        }
    }
    // if it t is on the left
    if ((cells[3]->getRow() == cells[1]->getRow()) &&
        (cells[3]->getCol() < cells[1]->getCol())) {
        //check if cells on board are avaliable
        if (isLegalCell(cells.at(0)->getRow() + 2, cells.at(0)->getCol() + 1) && isLegalCell(cells.at(1)->getRow() + 1, cells.at(1)->getCol()) && isLegalCell(cells.at(2)->getRow(), cells.at(2)->getCol() - 1) && isLegalCell(cells.at(3)->getRow(), cells.at(3)->getCol() + 1)) {
            transferID(0, cells.at(1)->getRow() + 2, cells.at(1)->getCol() + 1);
            transferID(1, cells.at(1)->getRow() + 1, cells.at(1)->getCol());
            transferID(2, cells.at(2)->getRow(), cells.at(2)->getCol() - 1);
            transferID(3, cells.at(3)->getRow(), cells.at(3)->getCol() + 1);
        }
    }
    // if it t is on the top
    if ((cells[3]->getCol() == cells[1]->getCol()) &&
        (cells[3]->getRow() < cells[1]->getRow())) {
        //check if cells on board are avaliable
        if (isLegalCell(cells.at(0)->getRow(), cells.at(0)->getCol() - 2) && isLegalCell(cells.at(1)->getRow() - 1, cells.at(1)->getCol() - 1) && isLegalCell(cells.at(2)->getRow() - 2, cells.at(2)->getCol())) {
            transferID(0, cells.at(1)->getRow(), cells.at(1)->getCol() - 2);
            transferID(1, cells.at(1)->getRow() - 1, cells.at(1)->getCol() - 1);
            transferID(2, cells.at(2)->getRow() - 2, cells.at(2)->getCol());
        }
    }
    else { // if it t is on the right
        if (isLegalCell(cells.at(0)->getRow() - 1, cells.at(0)->getCol()) && isLegalCell(cells.at(1)->getRow(), cells.at(1)->getCol() + 1) && isLegalCell(cells.at(2)->getRow() + 1, cells.at(2)->getCol() + 2) && isLegalCell(cells.at(3)->getRow() + 1, cells.at(3)->getCol())) {
            transferID(0, cells.at(0)->getRow() - 1, cells.at(0)->getCol());
            transferID(1, cells.at(1)->getRow(), cells.at(1)->getCol() + 1);
            transferID(2, cells.at(2)->getRow() + 1, cells.at(2)->getCol() + 2);
            transferID(3, cells.at(3)->getRow() + 1, cells.at(3)->getCol());
            
        }
    }
}

void tBlock::rotateCCW() {
    rotateCW();
    rotateCW();
    rotateCW();
}

tBlock::~tBlock() {}

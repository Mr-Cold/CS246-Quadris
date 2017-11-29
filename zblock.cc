//
//  zblock.cpp
//  q5
//
//  Created by Katie on 2017/11/28.
//  Copyright © 2017年 Katie. All rights reserved.
//

#include "zblock.h"
#include "cell.h"
#include "block.h"

zBlock::zBlock(Board * pb, int id): Block{pb} {
    cells.emplace_back(new Cell(2, 0, id, 'Z', curr_level, true));
    cells.emplace_back(new Cell(2, 1, id, 'Z', curr_level, true));
    cells.emplace_back(new Cell(3, 1, id, 'Z', curr_level, true));
    cells.emplace_back(new Cell(3, 2, id, 'Z', curr_level, true));
}

void zBlock::rotateCW() {
    // if it is vertical
    if (cells[0]->getRow() != cells[1]->getRow()) {
        //check if cells on board are avaliable
        if (isLegalCell(cells.at(0)->getRow() + 1, cells.at(0)->getCol() - 1) && isLegalCell(cells.at(2)->getRow() + 1, cells.at(2)->getCol() + 1) && isLegalCell(cells.at(3)->getRow(), cells.at(3)->getCol() + 2)) {
            transferID(0, cells.at(0)->getRow() + 1, cells.at(0)->getCol() - 1);
            transferID(2, cells.at(2)->getRow() + 1, cells.at(2)->getCol() + 1);
            transferID(3, cells.at(3)->getRow(), cells.at(3)->getCol() + 2);
        }
    }
    else { // if it is horizontal, flip it to vertical
        if (isLegalCell(cells.at(0)->getRow() - 1, cells.at(0)->getCol() + 1) && isLegalCell(cells.at(2)->getRow() - 1, cells.at(2)->getCol() - 1) && isLegalCell(cells.at(3)->getRow(), cells.at(3)->getCol() - 2)) {
            transferID(0, cells.at(0)->getRow() - 1, cells.at(0)->getCol() + 1);
            transferID(2, cells.at(2)->getRow() - 1, cells.at(2)->getCol() - 1);
            transferID(3, cells.at(3)->getRow(), cells.at(3)->getCol() - 2);
            
        }
    }
}

void zBlock::rotateCCW() {
    rotateCW();
}

zBlock::~zBlock() {}

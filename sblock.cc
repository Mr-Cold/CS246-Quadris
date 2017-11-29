//
//  sblock.cpp
//  q5
//
//  Created by Katie on 2017/11/27.
//  Copyright © 2017年 Katie. All rights reserved.
//

#include "sblock.h"
#include "cell.h"
#include "block.h"

sBlock::sBlock(Board * pb, int id): Block{pb} {
    cells.emplace_back(new Cell(2, 1, id, 'S', curr_level, true));
    cells.emplace_back(new Cell(2, 2, id, 'S', curr_level, true));
    cells.emplace_back(new Cell(3, 0, id, 'S', curr_level, true));
    cells.emplace_back(new Cell(3, 1, id, 'S', curr_level, true));
}

void sBlock::rotateCW() {
    // if it is vertical
    if (cells[0]->getRow() != cells[1]->getRow()) {
        //check if cells on board are avaliable
        if (isLegalCell(cells.at(1)->getRow() - 1, cells.at(1)->getCol() + 1) && isLegalCell(cells.at(2)->getRow() + 2, cells.at(2)->getCol()) && isLegalCell(cells.at(3)->getRow() + 1, cells.at(3)->getCol() + 1)) {
            transferID(1, cells.at(1)->getRow() - 1, cells.at(1)->getCol() + 1);
            transferID(2, cells.at(2)->getRow() + 2, cells.at(2)->getCol());
            transferID(3, cells.at(3)->getRow() + 1, cells.at(3)->getCol() + 1);
        }
    }
    else { // if it is horizontal, flip it to vertical
        if (isLegalCell(cells.at(1)->getRow() + 1, cells.at(1)->getCol() - 1) && isLegalCell(cells.at(2)->getRow() - 2, cells.at(2)->getCol()) && isLegalCell(cells.at(3)->getRow() - 1, cells.at(3)->getCol() - 1)) {
            transferID(1, cells.at(1)->getRow() + 1, cells.at(1)->getCol() - 1);
            transferID(2, cells.at(2)->getRow() - 2, cells.at(2)->getCol());
            transferID(3, cells.at(3)->getRow() - 1, cells.at(3)->getCol() - 1);
            
        }
    }
}

void sBlock::rotateCCW() {
    rotateCW();
}

sBlock::~sBlock() {}

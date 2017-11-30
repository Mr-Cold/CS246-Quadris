
//
//  oblock.cpp
//  q5
//
//  Created by Katie on 2017/11/28.
//  Copyright © 2017年 Katie. All rights reserved.
//

#include "oblock.h"
#include "cell.h"
#include "block.h"

oBlock::oBlock(Board * pb, int id): Block{pb} {
	type = 'O';
    cells.emplace_back(new Cell(2, 0, id, 'O', curr_level, true));
    cells.emplace_back(new Cell(2, 1, id, 'O', curr_level, true));
    cells.emplace_back(new Cell(3, 0, id, 'O', curr_level, true));
    cells.emplace_back(new Cell(3, 1, id, 'O', curr_level, true));
}

void oBlock::rotateCW() {}

void oBlock::rotateCCW() {}

oBlock::~oBlock() {}

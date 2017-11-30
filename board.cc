//
//  board.cpp
//  q5
//
//  Created by Katie on 2017/11/26.
//  Copyright © 2017年 Katie. All rights reserved.
//

#include "board.h"
using namespace std;

std::ostream &operator<<(std::ostream &out, const Board &b) {
    out << "Level:      " << b.level << endl;
    out << "Score:      " << b.curr_score << endl;
    out << "Hi Score:   " << b.hi_score << endl;
    out << "------------" << endl;
    for (int i = 0; i < 18; i++) {
        for (int j = 0; j < 11; j++) {
            out << grids[i][j];
        }
        out << endl;
    }
    out << "------------" << endl;
    out << "Next:" << endl;
    out << next_block;
}

#ifndef _TBLOCK_H_
#define _TBLOCK_H_

#include "block.h"

class Board;
class tBlock : public Block {
	tBlock(Board * pb, int id);
	~tBlock();

	void rotateCW();
	void rotateCCW();
};

#endif
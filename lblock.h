#ifndef _LBLOCK_H_
#define _LBLOCK_H_

#include "block.h"

class Board;
class lBlock : public Block {
	lBlock(Board * pb, int id);
	~lBlock();

	void rotateCW();
	void rotateCCW();
};

#endif
#ifndef _OBLOCK_H_
#define _OBLOCK_H_

#include "block.h"

class Board;
class oBlock : public Block {
public:
	oBlock(Board * pb, int id);
	~oBlock();

	void rotateCW();
	void rotateCCW();
};

#endif
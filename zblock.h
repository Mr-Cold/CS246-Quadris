#ifndef _ZBLOCK_H_
#define _ZBLOCK_H_

#include "block.h"

class Board;
class zBlock : public Block {
	zBlock(Board * pb, int id);
	~zBlock();

	void rotateCW();
	void rotateCCW();
};

#endif

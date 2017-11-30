#ifndef _SBLOCK_H_
#define _SBLOCK_H_

#include "block.h"

class Board;
class sBlock : public Block {
public:
	sBlock(Board * pb, int id);
	~sBlock();

	void rotateCW();
	void rotateCCW();
};

#endif
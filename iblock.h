#ifndef _IBLOCK_H_
#define _IBLOCK_H_

#include "block.h"

class Board;
class iBlock : public Block {
	iBlock(Boad * pb, int id));
	~iBlock();

	void rotateCW();
	void rotateCCW();
};

#endif
#pragma once

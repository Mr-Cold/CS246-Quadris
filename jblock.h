#ifndef _JBLOCK_H_
#define _JBLOCK_H_

#include "block.h"

class Board;
class jBlock : public Block {
	jBlock(Board * pb, int id);
	~jBlock();

	void rotateCW();
	void rotateCCW();
};

#endif
#pragma once

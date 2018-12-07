//�`��֘A�̏���
#include "main.h"
#include"GV.h"
#include"class.h"

//�w�i�`��
list<Block> blkList;

void DrawBoard() {
	DrawGraph(0, 0, IMG::board[2], true);
	DrawGraph(112, 0, IMG::board[1], true);
	DrawGraph(112, 448, IMG::board[1], true);
	DrawGraph(304, 0, IMG::board[0], true);
}
//�u���b�N�`��
void DrawBlock() {
	//�t�B�[���h��ɂ���u���b�N�̕`��
	for (list<Block>::iterator it = blkList.begin();
		it != blkList.end(); ++it) {
		DrawGraph(it->x, it->y, IMG::block[(int)it->color], true);
	}

	//���݃e�g���~�m�̕`��
	for (int i = 0; i < 4; i++) {
		DrawGraph(cur.blk[i].x, cur.blk[i].y, IMG::block[(int)cur.blk[i].color], true);
	}
}

//�`�惁�C��
void DrawMain() {

	//�w�i�`��
	DrawBoard();
	//�u���b�N�`��
	DrawBlock();
}
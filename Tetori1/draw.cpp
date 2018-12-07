//描画関連の処理
#include "main.h"
#include"GV.h"
#include"class.h"

//背景描画
list<Block> blkList;

void DrawBoard() {
	DrawGraph(0, 0, IMG::board[2], true);
	DrawGraph(112, 0, IMG::board[1], true);
	DrawGraph(112, 448, IMG::board[1], true);
	DrawGraph(304, 0, IMG::board[0], true);
}
//ブロック描画
void DrawBlock() {
	//フィールド上にあるブロックの描画
	for (list<Block>::iterator it = blkList.begin();
		it != blkList.end(); ++it) {
		DrawGraph(it->x, it->y, IMG::block[(int)it->color], true);
	}

	//現在テトリミノの描画
	for (int i = 0; i < 4; i++) {
		DrawGraph(cur.blk[i].x, cur.blk[i].y, IMG::block[(int)cur.blk[i].color], true);
	}
}

//描画メイン
void DrawMain() {

	//背景描画
	DrawBoard();
	//ブロック描画
	DrawBlock();
}
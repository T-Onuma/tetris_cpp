//初期化処理
#include "define.h"

#include "main.h"
#include"GV.h"
#include"func.h"
#include"class.h"

//画像イメージのネームスペースを使用する
using namespace IMG;

//初期化処理
void init() {
	//背景ボード画像のロード
	board[0] = LoadGraph("resource/board/board.png");
	board[1] = LoadGraph("resource/board/level.png");
	board[2] = LoadGraph("resource/board/vertical.png");

	//ブロック画像のロード
	LoadDivGraph("resource/img/block.png", 7, 7, 1, 16, 16, block);

	//数字画像のロード
	LoadDivGraph("resource/img/num.png", 10, 10, 1, 12, 16, num);

	//初期テトリミノ生成
	cur = CreateTetriMino(Point(FX + BS * 6, FY - BS * 2), (BLK_COL)GetRand(BLK_KND_NUM - 1));
	//画面内有効フラグをtrueに
	cur.flag = true;
}
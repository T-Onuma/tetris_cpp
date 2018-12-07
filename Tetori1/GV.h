//グローバル変数

#ifdef FIRST_LOADING
#define E 
#else
#define E extern
#endif

#include "class.h"

//コンフィグクラス
E Config config;

namespace IMG {
	E int board[3];//背景画像
	E int block[7];//ブロック画像
	E int num[10]; //数字画像
};
//現在のテトリミノ
E TetriMino cur;
//フィールド上のブロック
//E list<Block> blkList;

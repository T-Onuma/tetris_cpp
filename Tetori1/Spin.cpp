#include "main.h"
#include"func.h"
#include "class.h"




//テトリミノの回転処理
bool Spin(TetriMino& t, bool isLeft) {

	//黄色は回転しない
	if (t.blk[0].color == YELLOW)return true;

	//キャッシュ
	TetriMino n = t;

	//キャッシュのfieldをクリア
	memset(n.field, false, sizeof(bool) * 5 * 5);

	//回転後の位置にあるキャッシュのfieldをtrueに
	for (int x = 0; x < 5; x++) {
		for (int y = 0; y < 5; y++) {
			if (t.field[x][y]) {
				if (isLeft)	n.field[y][4 - x] = true;//左回転
				else		n.field[4 - y][x] = true;//右回転
			}
		}
	}

	//blk同期
	FieldToBlk(n);

	//キャッシュをtに反映
	t = n;

	//回転終了
	return true;
}

//各種関数の処理
#include "main.h"
#include "func.h"
#include"class.h"
#include"define.h"
// フィールド情報から各ブロックの座標を設定する
//tそのもののベース点はフィールドの(2,2)の座標とする
bool FieldToBlk(TetriMino& tetri) {
	int i = 0;
	for (int x = 0; x < 5; x++) {
		for (int y = 0; y < 5; y++) {
			if (tetri.field[x][y]) {
				tetri.blk[i].x = tetri.x + BS * (x - 2);
				tetri.blk[i].y = tetri.y + BS * (y - 2);
				i++;
			}
		}
	}
	return (i == 4);
}

//テトリミノ移動関数(x)
bool AddX(TetriMino& t, int add) {

	//エラーチェック
	if (abs(add) % BS != 0)return false;

	//ベース点移動
	t.x += add;

	//blk同期
	FieldToBlk(t);

	//成功
	return true;
}

//テトリミノ移動関数(y)
bool AddY(TetriMino& t, int add) {

	//エラーチェック
	if (abs(add) % BS != 0)return false;

	//ベース点移動
	t.y += add;

	//blk同期
	FieldToBlk(t);

	//成功
	return true;
}
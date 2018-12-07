#include"func.h"
#include "class.h"

TetriMino CreateTetriMino(const Point& p, BLK_COL k) {
	TetriMino tetriM;

	//tそのもののベース点
	tetriM.x = p.x;
	tetriM.y = p.y;

	//(2,2),(2,3)は必ず存在する地点
	tetriM.field[2][2] = true;
	tetriM.field[2][3] = true;

	//指定された種類(色)に応じて振り分け
	switch (k) {
	case RED://赤
		tetriM.field[3][1] = true;
		tetriM.field[3][2] = true;
		break;
	case GREEN://緑
		tetriM.field[1][1] = true;
		tetriM.field[1][2] = true;
		break;
	case PURPLE://紫(T字)
		tetriM.field[1][2] = true;
		tetriM.field[3][2] = true;
		break;
	case BLUE://青(逆L字)
		tetriM.field[2][1] = true;
		tetriM.field[1][3] = true;
		break;
	case ORANGE://橙(L字)
		tetriM.field[2][1] = true;
		tetriM.field[3][3] = true;
		break;
	case YELLOW://黄(■)
		tetriM.field[1][2] = true;
		tetriM.field[1][3] = true;
		break;
	case SKY://空(｜)
		tetriM.field[2][0] = true;
		tetriM.field[2][1] = true;
		break;
	default://不明->エラー
		throw "int CreateTetriMino()::k error";
		break;
	}

	//blkのkndを設定する
	for (int i = 0; i < 4; i++)tetriM.blk[i].color = k;

	//FieldToBlk
	//フィールド情報から各ブロックの座標を設定する
	//tそのもののベース点はフィールドの(2,2)の座標とする
	FieldToBlk(tetriM);

	//設定したtを返す
	return tetriM;
}
#include "main.h"
#include"GV.h"
#include"func.h"
#include"class.h"

extern list<Block> blkList;
//コントロール
void Control() {
	if (cur.flag) {
		//入力状況を取得
		int input[] = {
			CheckStatePad(config.left),
			CheckStatePad(config.right),
			CheckStatePad(config.up),
			CheckStatePad(config.down),
			CheckStatePad(config.lSpin),
			CheckStatePad(config.rSpin),
			CheckStatePad(config.stock),
		};
		//自動落下間隔
		int interval = 40;
		//左
		if (input[0] == 1 || (input[0] > 12 && input[0] % 5 == 0)) {
			AddX(cur, -BS);
			if (!IsValid(cur))AddX(cur, BS);
		}//右
		else if (input[1] == 1 || (input[1] > 12 && input[1] % 5 == 0)) {
			AddX(cur, BS);
			if (!IsValid(cur))AddX(cur, -BS);
		}//上
		else if (input[2] == 1) {
			while (!IsValid(cur)) {
				AddY(cur, BS);
			}
			AddY(cur, -BS);
			cur.flag = false;
		}//下
		else if (input[3]) {
			interval = 5;
		}


		if (cur.cnt % interval == 0) {
			//自動落下
			AddY(cur, BS);
			if (!IsValid(cur)) {
				AddY(cur, -BS);
				cur.flag = false;
			}
		}

		//着地したら
		if (cur.flag == false) {
			//保持しているblkをフィールドへ追加
			for (int i = 0; i < 4; i++) {
				blkList.push_back(cur.blk[i]);
			}
		}

		//カウントアップ
		cur.cnt++;
	}
	else {
		//新テトリミノ生成
		cur = CreateTetriMino(Point(FX + BS * 6, FY - BS * 2), (BLK_COL)GetRand(BLK_KND_NUM - 1));
		//画面内有効フラグをtrueに
		cur.flag = true;
	}
}
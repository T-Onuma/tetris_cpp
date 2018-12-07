#include "main.h"
#include"GV.h"
#include"func.h"
#include"class.h"

extern list<Block> blkList;
//�R���g���[��
void Control() {
	if (cur.flag) {
		//���͏󋵂��擾
		int input[] = {
			CheckStatePad(config.left),
			CheckStatePad(config.right),
			CheckStatePad(config.up),
			CheckStatePad(config.down),
			CheckStatePad(config.lSpin),
			CheckStatePad(config.rSpin),
			CheckStatePad(config.stock),
		};
		//���������Ԋu
		int interval = 40;
		//��
		if (input[0] == 1 || (input[0] > 12 && input[0] % 5 == 0)) {
			AddX(cur, -BS);
			if (!IsValid(cur))AddX(cur, BS);
		}//�E
		else if (input[1] == 1 || (input[1] > 12 && input[1] % 5 == 0)) {
			AddX(cur, BS);
			if (!IsValid(cur))AddX(cur, -BS);
		}//��
		else if (input[2] == 1) {
			while (!IsValid(cur)) {
				AddY(cur, BS);
			}
			AddY(cur, -BS);
			cur.flag = false;
		}//��
		else if (input[3]) {
			interval = 5;
		}


		if (cur.cnt % interval == 0) {
			//��������
			AddY(cur, BS);
			if (!IsValid(cur)) {
				AddY(cur, -BS);
				cur.flag = false;
			}
		}

		//���n������
		if (cur.flag == false) {
			//�ێ����Ă���blk���t�B�[���h�֒ǉ�
			for (int i = 0; i < 4; i++) {
				blkList.push_back(cur.blk[i]);
			}
		}

		//�J�E���g�A�b�v
		cur.cnt++;
	}
	else {
		//�V�e�g���~�m����
		cur = CreateTetriMino(Point(FX + BS * 6, FY - BS * 2), (BLK_COL)GetRand(BLK_KND_NUM - 1));
		//��ʓ��L���t���O��true��
		cur.flag = true;
	}
}
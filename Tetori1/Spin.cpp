#include "main.h"
#include"func.h"
#include "class.h"




//�e�g���~�m�̉�]����
bool Spin(TetriMino& t, bool isLeft) {

	//���F�͉�]���Ȃ�
	if (t.blk[0].color == YELLOW)return true;

	//�L���b�V��
	TetriMino n = t;

	//�L���b�V����field���N���A
	memset(n.field, false, sizeof(bool) * 5 * 5);

	//��]��̈ʒu�ɂ���L���b�V����field��true��
	for (int x = 0; x < 5; x++) {
		for (int y = 0; y < 5; y++) {
			if (t.field[x][y]) {
				if (isLeft)	n.field[y][4 - x] = true;//����]
				else		n.field[4 - y][x] = true;//�E��]
			}
		}
	}

	//blk����
	FieldToBlk(n);

	//�L���b�V����t�ɔ��f
	t = n;

	//��]�I��
	return true;
}

//�e��֐��̏���
#include "main.h"
#include "func.h"
#include"class.h"
#include"define.h"
// �t�B�[���h��񂩂�e�u���b�N�̍��W��ݒ肷��
//t���̂��̂̃x�[�X�_�̓t�B�[���h��(2,2)�̍��W�Ƃ���
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

//�e�g���~�m�ړ��֐�(x)
bool AddX(TetriMino& t, int add) {

	//�G���[�`�F�b�N
	if (abs(add) % BS != 0)return false;

	//�x�[�X�_�ړ�
	t.x += add;

	//blk����
	FieldToBlk(t);

	//����
	return true;
}

//�e�g���~�m�ړ��֐�(y)
bool AddY(TetriMino& t, int add) {

	//�G���[�`�F�b�N
	if (abs(add) % BS != 0)return false;

	//�x�[�X�_�ړ�
	t.y += add;

	//blk����
	FieldToBlk(t);

	//����
	return true;
}
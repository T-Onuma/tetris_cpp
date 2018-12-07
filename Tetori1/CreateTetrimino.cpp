#include"func.h"
#include "class.h"

TetriMino CreateTetriMino(const Point& p, BLK_COL k) {
	TetriMino tetriM;

	//t���̂��̂̃x�[�X�_
	tetriM.x = p.x;
	tetriM.y = p.y;

	//(2,2),(2,3)�͕K�����݂���n�_
	tetriM.field[2][2] = true;
	tetriM.field[2][3] = true;

	//�w�肳�ꂽ���(�F)�ɉ����ĐU�蕪��
	switch (k) {
	case RED://��
		tetriM.field[3][1] = true;
		tetriM.field[3][2] = true;
		break;
	case GREEN://��
		tetriM.field[1][1] = true;
		tetriM.field[1][2] = true;
		break;
	case PURPLE://��(T��)
		tetriM.field[1][2] = true;
		tetriM.field[3][2] = true;
		break;
	case BLUE://��(�tL��)
		tetriM.field[2][1] = true;
		tetriM.field[1][3] = true;
		break;
	case ORANGE://��(L��)
		tetriM.field[2][1] = true;
		tetriM.field[3][3] = true;
		break;
	case YELLOW://��(��)
		tetriM.field[1][2] = true;
		tetriM.field[1][3] = true;
		break;
	case SKY://��(�b)
		tetriM.field[2][0] = true;
		tetriM.field[2][1] = true;
		break;
	default://�s��->�G���[
		throw "int CreateTetriMino()::k error";
		break;
	}

	//blk��knd��ݒ肷��
	for (int i = 0; i < 4; i++)tetriM.blk[i].color = k;

	//FieldToBlk
	//�t�B�[���h��񂩂�e�u���b�N�̍��W��ݒ肷��
	//t���̂��̂̃x�[�X�_�̓t�B�[���h��(2,2)�̍��W�Ƃ���
	FieldToBlk(tetriM);

	//�ݒ肵��t��Ԃ�
	return tetriM;
}
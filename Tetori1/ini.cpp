//����������
#include "define.h"

#include "main.h"
#include"GV.h"
#include"func.h"
#include"class.h"

//�摜�C���[�W�̃l�[���X�y�[�X���g�p����
using namespace IMG;

//����������
void init() {
	//�w�i�{�[�h�摜�̃��[�h
	board[0] = LoadGraph("resource/board/board.png");
	board[1] = LoadGraph("resource/board/level.png");
	board[2] = LoadGraph("resource/board/vertical.png");

	//�u���b�N�摜�̃��[�h
	LoadDivGraph("resource/img/block.png", 7, 7, 1, 16, 16, block);

	//�����摜�̃��[�h
	LoadDivGraph("resource/img/num.png", 10, 10, 1, 12, 16, num);

	//�����e�g���~�m����
	cur = CreateTetriMino(Point(FX + BS * 6, FY - BS * 2), (BLK_COL)GetRand(BLK_KND_NUM - 1));
	//��ʓ��L���t���O��true��
	cur.flag = true;
}
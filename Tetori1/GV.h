//�O���[�o���ϐ�

#ifdef FIRST_LOADING
#define E 
#else
#define E extern
#endif

#include "class.h"

//�R���t�B�O�N���X
E Config config;

namespace IMG {
	E int board[3];//�w�i�摜
	E int block[7];//�u���b�N�摜
	E int num[10]; //�����摜
};
//���݂̃e�g���~�m
E TetriMino cur;
//�t�B�[���h��̃u���b�N
//E list<Block> blkList;

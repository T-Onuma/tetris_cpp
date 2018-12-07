//�֐��v���g�^�C�v
#pragma once
#include "define.h"

class TetriMino;
class Point;

//fps.cpp//
void fps();

//key.cpp//
//�L�[���͂��擾����֐�
int GetHitKeyStateAll_2();
//���ʂ�Ԃ��֐�
int CheckStateKey(int KeyCode);
// �p�b�h�L�[�ƃL�[�{�[�h�̗����̓��͂��`�F�b�N����֐�
int GetHitPadStateAll();
//�n���ꂽ�p�b�h�L�[�̌��ʂ�Ԃ��֐�
int CheckStatePad(int PadKeyCode);

//ini.cpp//
//����������
void init();

//draw.cpp//
void DrawMain();

//CreateTetriMino.cpp//
TetriMino CreateTetriMino(const Point& p, BLK_COL k);

//func.cpp//
//�t�B�[���h��񂩂�e�u���b�N�̍��W��ݒ肷��
//t���̂��̂̃x�[�X�_�̓t�B�[���h��(2,2)�̍��W�Ƃ���
bool FieldToBlk(TetriMino& t);
//�e�g���~�m�ړ��֐�(x)
bool AddX(TetriMino& t, int add);
bool AddY(TetriMino& t, int add);

//control.cpp//
void Control();

//IsValid.cpp//
//�w�肳�ꂽ���W���t�B�[���h���ɂ��邩
//true->�t�B�[���h���ɂ��� false->�t�B�[���h���ɂȂ�
bool IsInField(const Point& p);
//�w�肳�ꂽ�e�g���~�m���t�B�[���h���ɂ��邩
//true->�t�B�[���h���ɂ��� false->�t�B�[���h���ɂȂ�
bool IsInField(const TetriMino& t);

//true->���܂��Ă��� false->���܂��Ă��Ȃ�
bool IsBury();
//�e�g���~�m���L���Ȉʒu�ɂ��邩
//true->�L���ł��� false->�����ł���
bool IsValid(const TetriMino& t);
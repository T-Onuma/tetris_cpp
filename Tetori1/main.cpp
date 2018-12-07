//メイン関数

#define FIRST_LOADING
#include "main.h"
#include "func.h"
#include"GV.h"
#include "class.h"

//キー入力を保持する変数
//int Key[256];

//キー入力を取得する関数
int GetHitKeyStateAll_2(int GetHitKeyStateAll_InputKey[]) {
	char GetHitKeyStateAll_Key[256];
	GetHitKeyStateAll(GetHitKeyStateAll_Key);
	for (int i = 0; i < 256; i++) {
		if (GetHitKeyStateAll_Key[i] == 1)	GetHitKeyStateAll_InputKey[i]++;
		else				GetHitKeyStateAll_InputKey[i] = 0;
	}
	return 0;
}

//ループ時の処理
bool ProcessLoop() {
	//メッセージ処理
	if (ProcessMessage() != 0) { return false; }
	//画面をクリア
	if (ClearDrawScreen() != 0) { return false; }
	//入力状態を保存
	if (GetHitKeyStateAll_2() != 0) { return false; }
	//パッド入力状態を保存
	if (GetHitPadStateAll() != 0) { return false; }
	//ESCが押されていない
	if (CheckStatePad(config.start) != 0) { return false; }
	return true;
}

//メイン関数
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {

	ChangeWindowMode(TRUE);//ウィンドウモード
	if (DxLib_Init() == -1 || SetDrawScreen(DX_SCREEN_BACK) != 0) return -1;//初期化と裏画面化

	try {
		init();

		while (ProcessLoop()) {

			Control();

			DrawMain();

			fps();

			ScreenFlip();
		}
	}
	catch (const char* e) {
		MessageBox(NULL, e, "error", NULL);
		DxLib_End();
		return -1;
	}

	DxLib_End();
	return 0;
}

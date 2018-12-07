//ÇÜÇêÇìï\é¶ÇÃèàóù
#include "main.h"

void fps() {
	const int FRAME = 60;
	static int time, ave, count, f[FRAME];

	f[count%FRAME] = GetNowCount() - time;
	time = GetNowCount();

	count++;

		
	if (count%FRAME == FRAME - 1) {
		ave = 0;
		for (int i = 0; i < FRAME; i++) {
			ave += f[i];
		}
			ave /= FRAME;
			count = 0;
		
	}
	if (ave != 0) {
		float s = 1000 / (float)ave;	//fps
		int col = GetColor(255, 255, 255);	//îí

		if (50 > s && s >= 30)	{
			col = GetColor(255, 255, 0);//â©
		}
		else if (30 > s) {
			col = GetColor(255, 0, 0);	//ê‘
		}
		//fpsï\é¶
		DrawFormatString(555, 460, col, "[%.1f]fps", s);
	}

	return;
}
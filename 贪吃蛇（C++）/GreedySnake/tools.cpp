#include"tools.h"
#include <windows.h>
#include<stdio.h>

// ���ô��ڴ�С
void SetWindowSize(int cols, int lines) {
	system("title ��ͬѧ��̰����");  // ���ô��ڱ���
	char cmd[30];
	sprintf(cmd, "mode con cols=%d lines=%d", cols * 2, lines);   // һ��ͼ�Ρ�ռ�����ַ����ʿ�ȳ���2
	system(cmd);  // system(mode con cols=88 lines=88)���ô��ڿ�Ⱥ͸߶�
}

// ���ù��λ��
void SetCursorPosition(const int x, const int y) {
	COORD position;
	position.X = x * 2;
	position.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), position);
}

// �����ı���ɫ
void SetColor(int colorID) {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), colorID);
}

// ���ñ���ɫ
void SetBackColor() {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),
							FOREGROUND_BLUE |
							BACKGROUND_BLUE |
							BACKGROUND_GREEN |
							BACKGROUND_RED);
}
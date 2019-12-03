#include<iostream>
#include"maze_people.h"
#include"maze_map.h"
#include"windows.h"


// ���캯��
MazePeople::MazePeople():mazePeople('o') {
	nowX = 1, nowY = 1;
	preX = 10000, preY = 10000;
	outOrNot = false;
	forward = UP;
}
MazePeople::MazePeople(int currentX, int currentY):mazePeople('o') {
	nowX = currentX, nowY = currentY;
	preX = 10000, preY = 10000;
	outOrNot = false;
	forward = UP;
}
MazePeople::MazePeople(int currentX, int currentY, objectiveDirections myForward) :mazePeople('o') {
	nowX = currentX, nowY = currentY;
	preX = 10000, preY = 10000;
	outOrNot = false;
	forward = myForward;
}


MazePeople &MazePeople::setPersonPosition(int coordX, int coordY) {
	nowX = coordX, nowY = coordY;
	return *this;
}

void MazePeople::gotoxy(int x, int y) {
	COORD cd;
	cd.X = x; 
	cd.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cd);
}

void MazePeople::goAhead() {
	preX = nowX, preY = nowY;  // �浱ǰ��
	// ����ǰ��ǰ���������������������ⷽ����һ��
	switch (forward) {
	case UP:
		nowX = nowX, nowY = nowY - 1;  // ���µ�ǰ��
		break;
	case DOWN:
		nowX = nowX, nowY = nowY + 1;  // ���µ�ǰ��
		break;
	case LEFT:
		nowX = nowX - 1, nowY = nowY;  // ���µ�ǰ��
		break;
	case RIGHT:
		nowX = nowX + 1, nowY = nowY;  // ���µ�ǰ��
		break;
	default:
		std::cout << "������������ǰ��" << std::endl;
	}

	// ����Ч��
	gotoxy(preX, preY);
	std::cout << ' ';
	gotoxy(nowX, nowY);
	std::cout << mazePeople;
	Sleep(500);

	// ����Ƿ񵽴����
	if (MazeMap::checkMazeOut(nowX, nowY)) {
		gotoxy(0, 22);
		std::cout << "��ϲ�㣬�ɹ�" << std::endl;
		outOrNot = true;
	}
}

bool MazePeople::moveForward() {
	// ��鵱ǰλ���Ƿ�Ϸ�
	if (MazeMap::checkWallOrNot(nowX, nowY)) {
		gotoxy(0, 23);
		std::cout << "��⵽��ǰ����ʼλ����ǽ�ڣ��������趨"<<std::endl;
		outOrNot = true;
		return false;
	}

	// �жϣ����ǰһ��λ����10000,���ڵ�ǰλ�û�����
	if (preX == 10000 && preY == 10000) {
		gotoxy(nowX, nowY);
		std::cout << mazePeople;
		Sleep(3000);
	}

	// �������к���
	// > ����Ҳ��Ƿ���ǽ��
	//	> ��ǽ  >> ���ǰ���Ƿ���ǽ��
	//					>> ����ǽ -��ǰ��������Ƿ��ǳ���
	//  > ����ǽ -�����з�����ת
	int rightX, rightY;  // x:width-��y:height|
	int forwardX, forwardY;
	switch (forward) {
	case UP:
		rightX = nowX + 1, rightY = nowY;  // ��ǰ����ұ�
		forwardX = nowX, forwardY = nowY - 1;
		break;
	case DOWN:
		rightX = nowX - 1, rightY = nowY;
		forwardX = nowX, forwardY = nowY + 1;
		break;
	case LEFT:
		rightX = nowX, rightY = nowY - 1;  // ��ǰ����ұ�
		forwardX = nowX - 1, forwardY = nowY;
		break;
	case RIGHT:
		rightX = nowX, rightY = nowY + 1;
		forwardX = nowX + 1, forwardY = nowY;
		break;
	}

	// ����Ҳ���ǽ
	if (MazeMap::checkWallOrNot(rightX, rightY)) {  // ��ǰ����ұߣ������ǽ
		if (MazeMap::checkWallOrNot(forwardX, forwardY)) {  // ��ǰ���ǰ���������ǽ
			//������ת
			switch (forward) {
			case UP:
				forward = LEFT;
				break;
			case LEFT:
				forward = DOWN;
				break;
			case DOWN:
				forward = RIGHT;
				break;
			case RIGHT:
				forward = UP;
				break;
			default:
				std::cout << "�������" << std::endl;
			}
			return 0;
		}
		else {
			goAhead();  // ǰ��һ��
			return 1;
		}
	}
	else {  // ����Ҳ಻��ǽ;�����ұ���ת���ټ���ǰ��
		Sleep(3000);
		// ������ת
		switch (forward) {
		case UP:
			forward = RIGHT;
			break;
		case RIGHT:
			forward = DOWN;
			break;
		case DOWN:
			forward = LEFT;
			break;
		case LEFT:
			forward = UP;
			break;
		default:
			std::cout << "�������" << std::endl;
		}
		goAhead();
		return 1;
	}
}

void MazePeople::start() {
	int i = 0;
	while (!outOrNot) {
		i += moveForward();
		gotoxy(0, 15);
		std::cout << i;
	}
}
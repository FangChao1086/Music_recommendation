#ifndef __MAZE_PEOPLE_H__
#define __MAZE_PEOPLE_H__

class MazePeople {
public:
	enum objectiveDirections { UP, DOWN, LEFT, RIGHT };
	MazePeople();  // ���캯����Ĭ�ϳ�ʼ���˵�λ��
	MazePeople(int currentX, int currentY);  // ���캯���������˵ĳ�ʼ��λ��
	MazePeople(int currentX, int currentY, objectiveDirections myForward);  // ���캯���������˵ĳ�ʼ��λ�úͷ���
	MazePeople &setPersonPosition(int coordX, int coordY);
	void  gotoxy(int x, int y);
	void goAhead();
	bool moveForward();  // ǰ������
	void start();

private:
	char mazePeople;
	int preX, preY;
	int nowX, nowY;
	bool outOrNot;
	objectiveDirections forward;
};
#endif
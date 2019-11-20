#include<iostream>
#include<time.h>
#include<conio.h>
#include<windows.h>
#include"controller.h"
#include"tools.h"
#include"start_interface.h"
#include"map.h"
#include"snake.h"
#include"food.h"

void Controller::Start() {
	SetWindowSize(41, 32);  // ���ô��ڴ�С
	SetColor(2);  // ���ö�����ɫ
	StartInterface *start = new StartInterface();
	start->Action();
	delete start;
	
	// ���ù��λ�ã������ʾ
	SetCursorPosition(13, 26);
	std::cout << "Press any key to start... ";
	SetCursorPosition(13, 27);
	system("pause");
}

// ѡ�����
void Controller::Select() {
	SetColor(3);
	SetCursorPosition(13, 26);
	std::cout << "                          ";
	SetCursorPosition(13, 27);
	std::cout << "                          ";
	SetCursorPosition(6, 21);
	std::cout << "��ѡ����Ϸ�Ѷȣ�";
	SetCursorPosition(6, 22);
	std::cout << "(���¼�ѡ�񣬻س�ȷ��)";
	SetCursorPosition(27, 22);
	SetBackColor();  // ����ѡ��ı���ɫ��ʾѡ��
	std::cout << "��ģʽ";
	SetCursorPosition(27, 24);
	SetColor(3);
	std::cout << "��ͨģʽ";
	SetCursorPosition(27, 26);
	std::cout << "����ģʽ";
	SetCursorPosition(27, 28);
	std::cout << "����ģʽ";
	SetCursorPosition(0, 31);
	score = 0;

	// �����ѡ��ģ��
	int ch;  // ��¼����ֵ
	key = 1;  // ��¼ѡ�����ʼѡ���һ��
	bool flag = false;  // ��¼�Ƿ����Enter,��ʼֵΪ��
	while ((ch = _getch())) {
		switch (ch)  // ��������
		{
		case 72:  // up�Ϸ����
			if (key > 1)  // ����ʱѡ����Ϊ��һ��ʱ��up�Ϸ������Ч
			{
				switch (key)
				{
				case 2:
					SetCursorPosition(27, 22);  // ����ѡ�е�ģʽ���ñ���ɫ
					SetBackColor();
					std::cout << "��ģʽ";
					SetCursorPosition(27, 24);  // ȡ����ѡ����ͨģʽ�ı���ɫ
					SetColor(3);
					std::cout << "��ͨģʽ";
					key--;
					break;
				case 3:
					SetCursorPosition(27, 24);
					SetBackColor();
					std::cout << "��ͨģʽ";
					SetCursorPosition(27, 26);
					SetColor(3);
					std::cout << "����ģʽ";
					key--;
					break;
				case 4:
					SetCursorPosition(27, 26);
					SetBackColor();
					std::cout << "����ģʽ";
					SetCursorPosition(27, 28);
					SetColor(3);
					std::cout << "����ģʽ";
					key--;
					break;
				}
			}
			break;
		case 80:  // down�·����
			if (key < 4)
			{
				switch (key)
				{
				case 1:
					SetCursorPosition(27, 24);  
					SetBackColor();
					std::cout << "��ͨģʽ";
					SetCursorPosition(27, 22);
					SetColor(3);
					std::cout << "��ģʽ";
					key++;
					break;
				case 2:
					SetCursorPosition(27, 26);
					SetBackColor();
					std::cout << "����ģʽ";
					SetCursorPosition(27, 24);
					SetColor(3);
					std::cout << "��ͨģʽ";
					key++;
					break;
				case 3:
					SetCursorPosition(27, 28);
					SetBackColor();
					std::cout << "����ģʽ";
					SetCursorPosition(27, 26);
					SetColor(3);
					std::cout << "����ģʽ";
					key++;
					break;
				}
			}
			break;
		case 13:  // enter�س���
			flag = true;
			break;
		default:  // ��Ч����
			break;
		}
		if (flag) break;  // �����⵽Enter,�˳��������ѭ��
		SetCursorPosition(0, 31);  // ������������½ǣ�������Ϸ���鲻��
	}

	// ����keyֵ(ģʽ�����Ѷ�)�����ߵ��ƶ��ٶ�
	switch (key) {
	case 1:
		speed = 135;
		break;
	case 2:
		speed = 120;
		break;
	case 3:
		speed = 60;
		break;
	case 4:
		speed = 30;
		break;
	default:
		break;
	}
}

// ������Ϸ����
void Controller::DrawGame() {
	system("cls");  // ����

	// ���Ƶ�ͼ
	SetColor(3);
	Map *init_map = new Map();
	init_map->PrintInitmap();
	delete init_map;

	// ���Ʋ����
	SetColor(3);
	SetCursorPosition(33, 1);
	std::cout << "Greedy Snake";
	SetCursorPosition(34, 2);
	std::cout << "̰����";
	SetCursorPosition(31, 4);
	std::cout << "�Ѷȣ�";
	SetCursorPosition(36, 5);
	switch (key) {
	case 1:
		std::cout << "��ģʽ";
		break;
	case 2:
		std::cout << "��ͨģʽ";
		break;
	case 3:
		std::cout << "����ģʽ";
		break;
	case 4:
		std::cout << "����ģʽ";
		break;
	default:
		break;
	}
	SetCursorPosition(31, 7);
	std::cout << "�÷֣�";
	SetCursorPosition(37, 8);
	std::cout << "    0";
	SetCursorPosition(33, 13);
	std::cout << "������ƶ�";
	SetCursorPosition(33, 15);
	std::cout << "ESC����ͣ";
}

int Controller::PlayGame() {
	// ��ʼ������ʳ��
	Snake *csnake = new Snake();
	Food *cfood = new Food();
	SetColor(6);
	csnake->InitSnake();
	srand((unsigned)time(NULL));  //�����ʳ����ֵ�λ��
	cfood->DrawFood(*csnake);

	// ��Ϸѭ��
	while (csnake->NotOverEdge() && csnake->NotHitItself()) {  // û��ײǽҲû��ײ������
		// ����ѡ��˵�
		if (!csnake->ChangeDirection()) {  // ��ESC��ʱ
			int tmp = Menu();  // ���Ʋ˵������õ�����ֵ
			switch (tmp) {
			case 1:  // ������Ϸ
				break;
			case 2:  // ���¿�ʼ
				delete csnake;
				delete cfood;
				return 1;
			case 3:  // �˳���Ϸ
				delete csnake;
				delete cfood;
				return 2;
			default:
				break;
			}
		}
		if (csnake->GetFood(*cfood)) {
			csnake->Move();  //Move ������ 
			UpdateScore(1);
			ReWriteScore();
			cfood->DrawFood(*csnake);  // 
		}
		else {
			csnake->NormalMove();
		}
		if (csnake->GetBigFood(*cfood)) {  // �Ե���ʱʳ��
			csnake->Move();
			UpdateScore(cfood->GetProgressBar() / 5);  // ��������ʱ�������ȷ��
			ReWriteScore();
		}
		if (cfood->GetBigFlag()) {  // ���������ʱʳ�����ʳ����˸
			cfood->FlashBigFood();
		}
		Sleep(speed);  // �����ߵ��ƶ�Ч��
	}

	// ������
	delete csnake;
	delete cfood;
	int tmp = GameOver();  // ������Ϸ��������
	switch (tmp) {
	case 1:
		return 1;  // ���¿�ʼ
	case 2:
		return 2;  // �˳���Ϸ
	default:
		return 2;
	}
}

// ���µ÷�
void Controller::UpdateScore(const int& tmp) {
	score += key * 10 * tmp;
}

// �ػ�÷�
void Controller::ReWriteScore() {
	// Ϊ���ַ���β�����룬������������Ϊ6λ
	SetCursorPosition(37, 8);
	SetColor(1);
	int bit = 0;
	int tmp = score;
	while (tmp != 0) {
		++bit;
		tmp /= 10;
	}
	for (int i = 0; i < (6 - bit); ++i) {
		std::cout << " ";
	}
	std::cout << score;
}

// ѡ��˵�������ESC����
int Controller::Menu() {
	// ���Ʋ˵�
	SetColor(11);
	SetCursorPosition(32, 19);
	std::cout << "�˵���";
	Sleep(100);
	SetCursorPosition(34, 21);
	SetBackColor();
	std::cout << "������Ϸ";
	Sleep(100);
	SetCursorPosition(34, 23);
	SetColor(11);
	std::cout << "���¿�ʼ";
	Sleep(100);
	SetCursorPosition(34, 25);
	std::cout << "�˳���Ϸ";
	SetCursorPosition(0, 31);

	//ѡ�񲿷�
	int ch;  // ����ֵ
	int tmp_key = 1;  // ѡ����
	bool flag = false;
	while ((ch = _getch())) {
		switch (ch) {
		case 72:  // up
			if (tmp_key > 1) {
				switch (tmp_key) {
				case 2:
					SetCursorPosition(34, 21);
					SetBackColor();
					std::cout << "������Ϸ";
					SetCursorPosition(34, 23);
					SetColor(11);
					std::cout << "���¿�ʼ";
					tmp_key--;
					break;
				case 3:
					SetCursorPosition(34, 23);
					SetBackColor();
					std::cout << "���¿�ʼ";
					SetCursorPosition(34, 25);
					SetColor(11);
					std::cout << "�˳���Ϸ";
					tmp_key--;
					break;
				}
			}
			break;
		case 80:  // down
			if (tmp_key < 3) {
				switch (tmp_key) {
				case 1:
					SetCursorPosition(34, 23);
					SetBackColor();
					std::cout << "���¿�ʼ";
					SetCursorPosition(34, 21);
					SetColor(11);
					std::cout << "������Ϸ";
					tmp_key++;
					break;
				case 2:
					SetCursorPosition(34, 25);
					SetBackColor();
					std::cout << "�˳���Ϸ";
					SetCursorPosition(34, 23);
					SetColor(11);
					std::cout << "���¿�ʼ";
					tmp_key++;
					break;
				}
			}
			break;
		case 13:  // Enter
			flag = true;
			break;
		default:
			break;
		}
		if (flag) {
			break;
		}
		SetCursorPosition(0, 31);
	}
	if (tmp_key == 1) {  // ѡ�������Ϸ����ȥ���˵�
		SetCursorPosition(32, 19);
		std::cout << "      ";
		SetCursorPosition(34, 21);
		std::cout << "        ";
		SetCursorPosition(34, 23);
		std::cout << "        ";
		SetCursorPosition(34, 25);
		std::cout << "        ";
	}
	return tmp_key;
}

void Controller::Game() {
	Start();
	while (true) {  // ��Ϸ������Ϊһ����ѭ������Ϸ������ѭ������
		Select();  // ѡ�����
		DrawGame();  // ������Ϸ����
		int tmp = PlayGame();
		if (tmp == 1) {  // ����ֵΪ1ʱ���¿�ʼ��Ϸ
			system("cls");
			continue;
		}
		else if (tmp == 2) {  // ����ֵΪ2ʱ�˳���Ϸ
			break;
		}
		else {
			break;
		}
	}
}

int Controller::GameOver() {
	// ������Ϸ��������
	Sleep(500);
	SetColor(11);
	SetCursorPosition(10, 8);
	std::cout << " --------------------------------------------- ";
	Sleep(30);
	SetCursorPosition(9, 9);
	std::cout << "  |                Game Over !!!                |";
	Sleep(30);
	SetCursorPosition(9, 10);
	std::cout << "  |                                             |";
	Sleep(30);
	SetCursorPosition(9, 11);
	std::cout << "  |                ��Ǹ�������                 |";
	Sleep(30);
	SetCursorPosition(9, 12);
	std::cout << "  |                                             |";
	Sleep(30);
	SetCursorPosition(9, 13);
	std::cout << "  |              ��ķ���Ϊ��                   |";
	SetCursorPosition(24, 13);
	std::cout << score;
	Sleep(30);
	SetCursorPosition(9, 14);
	std::cout << "  |                                             |";
	Sleep(30);
	SetCursorPosition(9, 15);
	std::cout << "  |   �Ƿ�������һ�֣�                        |";
	Sleep(30);
	SetCursorPosition(9, 16);
	std::cout << "  |                                             |";
	Sleep(30);
	SetCursorPosition(9, 17);
	std::cout << "  |                                             |";
	Sleep(30);
	SetCursorPosition(9, 18);
	std::cout << "  |   �ţ��õ�        ���ˣ�����ѧϰ����˼      |";
	Sleep(30);
	SetCursorPosition(9, 19);
	std::cout << "  |                                             |";
	Sleep(30);
	SetCursorPosition(9, 20);
	std::cout << "  |                                             |";
	Sleep(30);
	SetCursorPosition(10, 21);
	std::cout << " --------------------------------------------- ";

	Sleep(100);
	SetCursorPosition(12, 18);
	SetBackColor();
	std::cout << "�ţ��õ�";
	SetCursorPosition(0, 31);

	//ѡ�񲿷�
	int ch;  // �Ƿ��������
	int tmp_key = 1;  // ��������ֵ
	bool flag = false;
	while ((ch = _getch())) {
		switch (ch) {
		case 75:  // LEFT
			if (tmp_key > 1) {
				SetCursorPosition(12, 18);
				SetBackColor();
				std::cout << "�ţ��õ�";
				SetCursorPosition(20, 18);
				SetColor(11);
				std::cout << "���ˣ�����ѧϰ����˼";
				tmp_key--;
			}
			break;
		case 77:  // RIGHT
			if (tmp_key < 2) {
				SetCursorPosition(20, 18);
				SetBackColor();
				std::cout << "���ˣ�����ѧϰ����˼";
				SetCursorPosition(12, 18);
				SetColor(11);
				std::cout << "�ţ��õ�";
				tmp_key++;
			}
			break;
		case 13:  // ENTER
			flag = true;
			break;
		default:
			break;
		}
		SetCursorPosition(0, 31);
		if (flag) break;
	}

	SetColor(11);
	switch (tmp_key) {
	case 1:
		return 1;  // ���¿�ʼ
	case 2:
		return 2;  // �˳���Ϸ
	default:
		return 1;
	}
}
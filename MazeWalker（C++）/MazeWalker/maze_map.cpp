#include<iostream>
#include"maze_map.h"

// ��ʼ����̬����
char MazeMap::mazeRoad = ' ';
int MazeMap::mazeWidth = 0;
int MazeMap::mazeHeight = 0;
int MazeMap::mazeMapArray[screenHeight][screenWidth];

// ���캯��
// Ĭ�ϳ�ʼ���Թ�
MazeMap::MazeMap() :mazeWall('*') {
	mazeWidth = 60;
	mazeHeight = 20;
}

// ���������Թ�
void MazeMap::setMazeMap(int *mazeMap, int row,int column) {
	// �����Թ����
	mazeHeight = row;
	mazeWidth = column;
	// �����ڲ�·��
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < column; j++) {
			mazeMapArray[i][j] = *mazeMap;
			mazeMap++;
		}
	}
}

// ���Ƶ�ͼ
void MazeMap::drawMap() const {
	for (int i = 0; i < mazeHeight; i++) {
		for (int j = 0; j < mazeWidth; j++) {
			if (mazeMapArray[i][j] == 1) {
				std::cout << mazeWall;
			}
			else {
				std::cout << mazeRoad;
			}
		}
		std::cout << std::endl;
	}
}

// ����Ƿ�ײǽ
bool MazeMap::checkWallOrNot(int mazeX, int mazeY){
	if (mazeMapArray[mazeY][mazeX] == 1) return true;
	else return false;
}

// ����Ƿ��ǳ���
bool MazeMap::checkMazeOut(int mazeX, int mazeY) {
	if (mazeX == 0 || mazeX == (mazeWidth - 1)) {  // ����Թ����Ҳ�
		if (mazeMapArray[mazeY][mazeX] == 0) return true;
	}
	if (mazeY == 0 || mazeY == (mazeHeight - 1)) {  // ����Թ����²�
		if (mazeMapArray[mazeY][mazeX] == 0) return true;
	}
	return false;
}
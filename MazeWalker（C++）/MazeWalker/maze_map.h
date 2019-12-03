#ifndef __MAZE_MAP_H__
#define __MAZE_MAP_H__

#define screenWidth 80
#define screenHeight 25

class MazeMap {
public:
	MazeMap();  // Ĭ�Ϲ��캯��
	void setMazeMap(int *mazeMap, int row, int column);  // ���������Թ���ͼ
	void drawMap() const;  // ���Ƶ�ͼ
	static bool checkWallOrNot(int mazeX, int mazeY);  // ����Ƿ������Թ�ǽ��
	static bool checkMazeOut(int mazeX, int mazeY);
private:
	char mazeWall;
	static char mazeRoad;
	static int mazeWidth;
	static int mazeHeight;
	static int mazeMapArray[screenHeight][screenWidth];

};
#endif
/**
 *acm title: Fire Net
 *acm address: http://acm.zju.edu.cn/onlinejudge/showProblem.do?problemCode=1002
 *By MyRe 2014/06/19
 */

#include<iostream>
#include<fstream>
using namespace std;

const char WALL = 'X';
const char SPACE = '.';
const char BLOCK_HOUSE = 'O';
char board[4][4] = { SPACE };
int length = 0;
int maxBlockHouse = 0;
int x, y;

void init()
{
	x = 0; y = -1;
	maxBlockHouse = 0;
}

bool input()
{
	cin >> length;
	if (0 == length)
		return false;
	for (int i = 0; i < length; ++i)
	{
		for (int j = 0; j < length; ++j)
		{
			cin >> board[i][j];
		}
	}
	return true;
}

bool nextGrid(int & x, int & y)
{
	++y;
	if (y == length)
	{
		y = 0;
		++x;
	}
	if (x == length && y == 0)
		return false;
	return true;
}

bool isOK(const int & x, const int & y)
{
	if (board[x][y] == WALL)
		return false;
	int i = 0;
	//向上搜索
	for (i = 0; x - i >= 0; ++i)
	{
		if (board[x - i][y] == BLOCK_HOUSE)
			return false;
		if (board[x - i][y] == WALL)
			break;
	}

	//向下搜索
	for (i = 0; x + i <length; ++i)
	{
		if (board[x + i][y] == BLOCK_HOUSE)
			return false;
		if (board[x + i][y] == WALL)
			break;
	}

	//向左搜索
	for (i = 0; y- i >= 0; ++i)
	{
		if (board[x][y-i] == BLOCK_HOUSE)
			return false;
		if (board[x][y-i] == WALL)
			break;
	}

	//向右搜索
	for (i = 0; y +i<length; ++i)
	{
		if (board[x][y + i] == BLOCK_HOUSE)
			return false;
		if (board[x][y + i] == WALL)
			break;
	}
	return true;
}

void DFS(int x, int y,int blockHouseCount)
{
	int tx, ty;
	tx = x;
	ty = y;
	if (!isOK(x, y))
		return;

	++blockHouseCount;
	board[x][y] = BLOCK_HOUSE;
	if (maxBlockHouse < blockHouseCount)
		maxBlockHouse = blockHouseCount;

	while (nextGrid(x, y))
	{
			DFS(x, y, blockHouseCount);
	}

	board[tx][ty] = SPACE;
}

int main(int argc, char const * argv[])
{
	while (input())
	{
		init();
		while (nextGrid(x,y))
			DFS(x, y, 0);
		cout << maxBlockHouse << endl;
	}

	return 0;
}

#include <iostream>

using namespace std;

/*
ㅇ최소 비용 경료(minimum cost path)
-정수값으로 구성되어있는 2차원 행렬이 주어졌을때 이 행렬의 좌측 상단에서 시작해서 우측 하단까지 이동하는 여러가지 방법 중 에서.
이동경로상에 있는 정수값의 합의 최소값이 얼마인지 구하는 문제이다
즉 좌상단에서 우하단까지 이동하기 위한 최소비용을 계싼하는 문제이다.
최소경로합(minimum path sum).이라고도 한다.
-이동은 오른쪽 또는 아래쪽 방향으로만 가능하다고 가정한다.

ex) 
2	7	5	4
5	3	6	8
7	8	7	4
8	1	9	5

2에서 5까지 이동하는 경로는 상당히 많이 존재하는데.
여기서 경로 합이 최소비용을 구하는 것.
가장 최소비용은 2 5 3 6 7 4 5 이다. 이때 최소비용은 32로 계산이 된다.

ㅇ문제 해결 방법
-셀에서 이동하는 방향이 오른쪽 또는 아래쪽 방향으로만 이동할 수 있다. 
임의의 좌표 (x,y)에 도달하기 위해서는
(x-1, y)또는 (x,y -1)좌표를 거쳐야한다.
-임의의 좌표 (x,y)에서의 행렬값을 m(x,y)라고 하고, 좌 상단에서 (x,y)까지 이동하는 경로의 최소비용을
C(x,y)라고 할 경우 다음식이 성립한다

C(x,y) = min(C(x-1,y),C(x,y-1)) + m(x,y)

-좌측상단부터 시작해서 왼쪽에서 오른쪽으로, 위에서 아래 방향으로 C(x,y)값을 계산하고, 최종적으로 우하단 좌표에서 C(x,y)값을 구한다.
->tabulation기법에 해당

-시작위치와 가장 자리 좌표에 대한 처리

	1	2	3	4			1	2	3	4
 1	2	7	5	4			2	9	14	16
 2	5	3	6	8			7	10	16	24
 3	7	8	7	4    c(x,y) 14	18	23	27
 4	8	1	9	5			22	19	28	32
 m(x,y)


*/
#include <vector>
int solution(vector<vector<int>> m) {
	int rows = (int)m.size();
	int cols = (int)m[0].size();
	vector<vector<int>>dp(rows, vector<int>(cols, 0));

	for (int y = 0; y < rows; y++) {
		for (int x = 0; x < cols; x++) {
			if (x == 0 && y == 0) dp[y][x] = m[y][x];
			else if (x == 0) dp[y][x] = dp[y - 1][x] + m[y][x];
			else if (y == 0) dp[y][x] = dp[y][x - 1] + m[y][x];
			else dp[y][x] = min(dp[y - 1][x], dp[y][x - 1]) + m[y][x];
		}
	}
	return dp[rows - 1][cols - 1];
}
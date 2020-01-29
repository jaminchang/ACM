#include<string>
#include<vector>
#include<string.h>
#include<cstring>
#include<iostream>
/*
八皇后问题
左斜线用x+y
右斜线用x-y+10来表示
类内函数调用的时候别忘记先声明一下
 */

using namespace std;

int col[1005], q[1005][1005], vis1[1005],vis2[1005];
vector<vector<string>>ans;
vector<string>temp;

void dfs(int deep, int x, int n);

vector<vector<string>> solveNQueens(int n) {
	for (int i = 1; i <= n; i++) {
		dfs(1, i, n);
	}
	return ans;
}

void dfs(int deep, int x, int n) {
	//printf("%d %d %d\n", deep, x, n);
	q[deep][x] = 1;
	col[x] = 1;
	vis1[deep + x] = 1;
	vis2[x - deep + 10] = 1;
	if (deep == n) {
		printf("yes\n");
		temp.clear();
		for (int i = 1; i <= n; i++) {
			string s(n, '.');
			for (int j = 1; j <= n; j++) {
				if (q[i][j] == 1)s[j - 1] = 'Q';
			}
			temp.push_back(s);
		}
		ans.push_back(temp);
		q[deep][x] = 0;
		col[x] = 0;
		vis1[deep + x] = 0;
		vis2[x - deep + 10] = 0;
		return;
	}
	for (int i = 1; i <= n; i++) {
		if (col[i] == 0&&vis1[deep+i+1]==0&&vis2[i-deep+9]==0) {
			dfs(deep + 1, i, n);
		}
	}
	q[deep][x] = 0;
	col[x] = 0;
	vis1[deep + x] = 0;
	vis2[x - deep + 10] = 0;
}


int main()
{
    //这两个8可以换成任何数字
	vector<vector<string>>ans = solveNQueens(8);
	for (int i = 0; i< ans.size(); i++) {
		for (int j = 0; j < 8; j++) {
			cout << ans[i][j] << endl;
		}
		//printf("-----------");
	}
	cout << ans.size() << endl;
	return 0;
}

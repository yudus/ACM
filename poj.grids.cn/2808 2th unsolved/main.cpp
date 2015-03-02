#include <iostream>

using namespace std;

const int MAXN = 101;

int main( void ){
	int l, m;
	while( cin >> l >> m ){
		int trees[MAXN][2];
		int treeIndex = 0;
		int beg, end;
		for( int i = 0; i != m; ++i ){
			if( !i ){
				cin >> trees[0][0] >> trees[0][1];
				++treeIndex;
				continue;
			}
			cin >> beg >> end;
			bool isFound = false;
			for( int j = 0; j != treeIndex; ++j ){
				if( beg <= trees[j][0] && end <= trees[j][1] && end >= trees[j][0] ){
					isFound = true;
					trees[j][0] = beg;
					break;
				}
				if( beg >= trees[j][0] && beg <= trees[j][1] && end >= trees[j][1] ){
					isFound = true;
					trees[j][1] = end;
					break;
				}
				if( beg >= trees[j][0] && end <= trees[j][1] ){
					isFound = true;
					break;
				}
			}
			if( !isFound ){
				trees[treeIndex][0] = beg;
				trees[treeIndex][1] = end;
				++treeIndex;
			}
		}
		int treeCnt = 0;//记录要移走多少棵树
		for( int i = 0; i != treeIndex; ++i ){
			treeCnt += trees[i][1] - trees[i][0] + 1;
		}
		for( int i = 0; i < treeIndex-1; ++i ){//去掉重复的
			if( trees[i][1] > trees[i+1][0] ){
				treeCnt -= trees[i][1] - trees[i+1][0] + 1;
			}
		}
		cout << l+1-treeCnt << endl;
	}
    return 0;
}

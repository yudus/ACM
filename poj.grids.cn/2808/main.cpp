/*
	*UltraEdit 1次AC，注意的就是0和L处也有树存在，边界多注意一下就没有什么了
*/
#include <iostream>

using namespace std;

const int MAXN = 10001;

int main( void ){
   	int l, m;
   	while( cin >> l >> m ){
   		//用数组来表示路上树的数目
   		bool road[MAXN];
   		for( int i = 0; i != l+1; ++i ){
   			road[i] = true;
   		}
   		for( int i = 0; i < m; ++i ){
   			int beg, end;
   			cin >> beg >> end;
   			for( int j = beg; j != end+1; ++j ){
   				road[j] = false;
   			}
   		}
   		int cnt = 0;
   		for( int i = 0; i != l+1; ++i ){
   			if( road[i] ){
   				++cnt;
   			}
   		}
   		cout << cnt << endl;
   	}
   	return 0;
}


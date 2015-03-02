/*
	*UltraEdit 1��AC��ע��ľ���0��L��Ҳ�������ڣ��߽��ע��һ�¾�û��ʲô��
*/
#include <iostream>

using namespace std;

const int MAXN = 10001;

int main( void ){
   	int l, m;
   	while( cin >> l >> m ){
   		//����������ʾ·��������Ŀ
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


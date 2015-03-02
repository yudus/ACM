/*
	*本代码由UltraEdit编写，Codeblocks辅助调试
	*由于分号用了中文的，数组名与变量名重复了，编译错误了一次
	*m和n没有搞清哪一个是行哪一个是列OLE了两次
	*然后AC了。。。。。。
*/
#include <iostream>
#include <cstring>

using namespace std;

const int MAXN = 101;
const int WMAX = 26;

int main( void ){
	int m, n, p;
	while( cin >> n >> m >> p ){
		//用m来存储矩阵
    	char table[MAXN][MAXN];
    	//wordCnt[]统计字母出现的次数
    	int wordCnt[WMAX];
    	for( int i = 0 ; i != WMAX; ++i ){
    		wordCnt[i] = 0;
    	}
    	for( int i = 0; i != n; ++i ){
    		cin >> table[i];
    		//统计字母出现一次就+1
    		for( int j = 0; j != strlen( table[i] ); ++j ){
    			int tmp = table[i][j] - 'A';
    			++wordCnt[tmp];
    		}
    	}
    	for( int i = 0; i != p; ++i ){
    		char word[MAXN];
    		cin >> word;
    		//word中字母出现一次就-1
    		for( int j = 0; j != strlen( word ); ++j ){
    			int tmp = word[j] - 'A';
    			--wordCnt[tmp];
    		}
    	}
    	//输出结果
    	for( int i = 0; i != WMAX; ++i ){
    		while( wordCnt[i]-- ){
    			char t = 'A';
    			t += i;
    			cout << t;
    		}
    	}
    	cout << endl;
    }
    return 0;
}

/*
	*��������UltraEdit��д��Codeblocks��������
	*���ڷֺ��������ĵģ���������������ظ��ˣ����������һ��
	*m��nû�и�����һ��������һ������OLE������
	*Ȼ��AC�ˡ�����������
*/
#include <iostream>
#include <cstring>

using namespace std;

const int MAXN = 101;
const int WMAX = 26;

int main( void ){
	int m, n, p;
	while( cin >> n >> m >> p ){
		//��m���洢����
    	char table[MAXN][MAXN];
    	//wordCnt[]ͳ����ĸ���ֵĴ���
    	int wordCnt[WMAX];
    	for( int i = 0 ; i != WMAX; ++i ){
    		wordCnt[i] = 0;
    	}
    	for( int i = 0; i != n; ++i ){
    		cin >> table[i];
    		//ͳ����ĸ����һ�ξ�+1
    		for( int j = 0; j != strlen( table[i] ); ++j ){
    			int tmp = table[i][j] - 'A';
    			++wordCnt[tmp];
    		}
    	}
    	for( int i = 0; i != p; ++i ){
    		char word[MAXN];
    		cin >> word;
    		//word����ĸ����һ�ξ�-1
    		for( int j = 0; j != strlen( word ); ++j ){
    			int tmp = word[j] - 'A';
    			--wordCnt[tmp];
    		}
    	}
    	//������
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

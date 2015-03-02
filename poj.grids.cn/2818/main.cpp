/*
	*�⻹���������ǰ�������ء������ҾͲ����²�ʱ�������ο��ˡ�����
	*��ʷ�ľ�������ң�������ȫģ��϶���ʱ������
	*����д������Ѱ����Կ�����ڣ�Ȼ��ȡģֱ��һ����λ��
	*��һ���ύRE������Codeblocks������һ�£�ִ�в��ˡ�����
	*DEBUG���������ڵĺ������쳣�ˡ�����
	*ͬʱҲ���������˸������ʼ���������õͼ��Ĵ��󡣡���
	*cur = a[a[cur]]д��cur = a[a[i]]�ˡ��������صĴ���
	*��ʵ¥�ϵ�ʽ�Ӿʹ��ˣ������ѩn��b������
	*Ӧ��д��cur = a[cur]������Ķ�����һ�����������Ǹ����صĴ��󣡣���
	*�����˷��ֳ����һ��������ȷ���ڶ���������ô������������ˣ�����
	*����0��ʱ�����������ˡ�����
	*�ĺ��ˡ�����WA������%>_<%
	*���ֶ��쳣������
	*ȥ���string�ɣ���������char���飡����
	*CodeBlocks�����Ҹɱ��������ˣ������ף�����
	*�����ˣ������������ôԽ��Խ�군����������������д�˰�������
	*���Ѿ�����ȫ�ֱ����ˡ���������̫��ʧˮ׼�ˡ�����
	*�ĳ�char�����AC�ˡ�����������
	*��Ȼ��string�����Ⱑ����������C++��ȫ��������������̫���ˣ�����
	*������ʱ���������ٸĻ�stringд��
	*��󡣡���������ţ���档���������д��̫�ѿ��ˡ�����
*/

#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int MAXN = 202;

int a[MAXN];
int circle[MAXN][MAXN];
int cirIndex[MAXN];
char s[MAXN+MAXN], res[MAXN+MAXN];

//������ү��ʼ����
void init( int n ){
	for( int i = 0; i < n; ++i ){
		for( int j = 0; j < n; ++j ){
			circle[i][j] = 0;
		}
		cirIndex[i] = 0;
	}
}

//�ҳ����ڣ�����
void findCircle( int n ){
	init( n );
	for( int i = 0; i < n; ++i ){
		int cur = a[i];
		//Ϊ�˷�������ȡģ���㣬��һλ��ֱ�ӷ�i�Լ���Ҳ����˵ȡģΪ0��ʱ��λ�ò��䣡
		circle[i][cirIndex[i]++] = i;
		while( cur != i ){
			circle[i][cirIndex[i]++] = cur;
			cur = a[cur];
		}
	}
	return;
}

//���ַ���ת��Ϊ���ֺ��ַ�
long trans( void ){
    long k = 0;
    int i = 0;
    int sEnd = strlen( s );
    while( s[i] != ' ' ){
        k *= 10;
        k += ( s[i]-'0' );
        ++i;
    }
    ++i;
    int j;
    for( j = 0; i < strlen( s )+1; ++i, ++j ){
        s[j] = s[i];
    }
    s[j] = '\0';
	return k;
}

//��ʼ���ܣ�����
void code( int n, long k ){
	if( n > strlen( s ) ){
		for( int i = strlen( s ); i < n; ++i ){
			s[i] = ' ';
			s[i+1] = '\0';
		}
	}
    strcpy( res, s );
	for( int i = 0; i < n; ++i ){
		int pos = k % cirIndex[i];
		pos = circle[i][pos];
		res[pos] = s[i];
	}
	return;
}

int main( void ){
    int n;
    while( cin >> n && n ){
    	for( int i = 0; i < n; ++i ){
    		cin >> a[i];
    		--a[i];
    	}
    	findCircle( n );
        getchar();//�Իس���
    	while( true ){
            gets( s );
	    	if( strlen( s ) == 0 ){//�����������Ļس��Ļ���continue
                continue;
	    	}
	    	if( strcmp( s, "0" ) == 0 ){
                break;
	    	}
	    	long k = trans();
	    	code( n, k );
			cout << res << endl;
		}
		cout << endl;
	}
    return 0;
}
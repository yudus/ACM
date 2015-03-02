/*
	*�����ʼ��Ҫģ��һ�£�������ֺ��鷳��Ҳ���ܳ�ʱ
	*���Ի��˸�˼·����p��q��r����i�����������Ҷ�ת����ĳһ�����BIGBASE����
	*��BIGBASE������Ƿ����
*/

#include <iostream>

using namespace std;

const int MAXN = 1000001;
const int BIGBASE = 1000;

int digit_p[MAXN], digit_q[MAXN], digit_r[MAXN];
int p_index, q_index, r_index;

//��ʼ��
void init( void ){
	p_index = 0;
	q_index = 0;
	r_index = 0;
}

//����ת����
void  trans( int n, int *a, int &index, int base ){
	while( n ){
		a[index++] = n % BIGBASE;
		n /= BIGBASE;
	}
}

//��������������BIGBASE���Ƽ��㣡
bool cal( void ){
	
	
//�����Һ��ʵĽ���
int tryToFind( int p, int q, int r ){
	for( int i = 2; i < MAXN; ++i ){
		inti();
		trans( p, digit_p, p_index, i );
		trans( q, digit_q, q_index, i );
		trans( r, digit_r, r_index, i ):
		if( cal() ){
			return i;
		}
	}
	return 0;
}

int main( void ){
    int nCase;
    cin >> nCase;
    cout << nCase << endl;
    while( nCase-- ){
    	int p, q, r;
    	cin >> p >> q >> r;
		cout << tryToFind( p, q, r ) << endl;
	}
    return 0;
}

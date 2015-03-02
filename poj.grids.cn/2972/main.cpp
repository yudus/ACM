/*
	*这题最开始想要模拟一下，结果发现好麻烦，也可能超时
	*所以换了个思路，把p、q和r当成i进制数，并且都转换成某一大进制BIGBASE的数
	*按BIGBASE计算后看是否相等
*/

#include <iostream>

using namespace std;

const int MAXN = 1000001;
const int BIGBASE = 1000;

int digit_p[MAXN], digit_q[MAXN], digit_r[MAXN];
int p_index, q_index, r_index;

//初始化
void init( void ){
	p_index = 0;
	q_index = 0;
	r_index = 0;
}

//进制转换！
void  trans( int n, int *a, int &index, int base ){
	while( n ){
		a[index++] = n % BIGBASE;
		n /= BIGBASE;
	}
}

//把这三个数按照BIGBASE进制计算！
bool cal( void ){
	
	
//尝试找合适的进制
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

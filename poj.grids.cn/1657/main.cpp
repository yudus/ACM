/*
  *������һ��ֱ�����ı��༭����д���룬���õ���ֱ��submit��
  *CE���Ρ�WA���κ�����AC�ˣ�
  *WA��ԭ���һ��Ϊ�ж���Ĳ�������Щ����
  *Ȼ�����������ͬ��ʱ��Ӧ�ö�Ϊ0���˳���Ӧ�����ж�
*/
#include <iostream>
#include <cstring>

using namespace std ;

const int MAXN = 5;
const int black = 1;
const int white = 2;

//ȡ����ֵ
int myabs( int n ){
	return n > 0 ? n : -n;
}

//�ж��Ƿ�Ϊ����
bool isOdd( int n ){
	return n % 2;
}

//�ж����ڵĸ�����ɫ
int judgeColor( int a , int b ){
	if( isOdd( a ) && isOdd( b ) )
		return black;
	if( isOdd( a ) && !isOdd( b ) )
		return white;
	if( !isOdd( a ) && isOdd( b ) )
		return white;
	if( !isOdd( a ) && !isOdd( b ) )
		return black;
	return -1;//�������
}

int main(void){
	int ncase;
	cin >> ncase;
	while(ncase--){
		char beg[MAXN], end[MAXN];
		cin >> beg >> end;
		if( strcmp( beg , end ) == 0 ){
			cout << "0 0 0 0" << endl;
			continue;
		}
		//û������쳣����Ĭ��ȫ�����붼�Ƿ��Ϲ涨�ģ�����
		//���ַ���ת��Ϊ���������꣬�������
		int x1 = beg[0] - 'a' + 1;
		int y1 = beg[1] - '0';
		int x2 = end[0] - 'a' + 1;
		int y2 = end[1] - '0';
		//�������λ��
		int disX = myabs(x1 - x2);
		int disY = myabs(y1 - y2);
		//�������Ĳ���
		int king = disX < disY ? disX : disY;
		king += myabs( disX - disY );
		//�����Ĳ���
		int queen = 0;
		if( disX == disY ){
			queen = 1;
		}else if( !disX || !disY ){
			queen = 1;
		}else{
			queen = 2;
		}
		//���㳵�Ĳ���
		int car = ( disX && disY ) ? 2 : 1;
		//������Ĳ���
		char elephant[MAXN];
		int s1 = judgeColor( x1 , y1 );
		int s2 = judgeColor( x2 , y2 );
		if( s1 == s2 ){
			if( disX == disY ){
				strcpy( elephant , "1" );
			}else{
				strcpy( elephant , "2" );
			}
		}else{
			strcpy( elephant , "Inf" );
		}
		cout << king << " " << queen << " " << car << " " << elephant << endl;
	}
	return 0;
}

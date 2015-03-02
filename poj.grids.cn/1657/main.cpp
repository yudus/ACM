/*
  *尝试了一下直接用文本编辑器来写代码，不用调试直接submit！
  *CE两次、WA三次后，终于AC了！
  *WA的原因第一次为判定后的步数出了些问题
  *然后就是两点相同的时候应该都为0，此程序应特殊判断
*/
#include <iostream>
#include <cstring>

using namespace std ;

const int MAXN = 5;
const int black = 1;
const int white = 2;

//取绝对值
int myabs( int n ){
	return n > 0 ? n : -n;
}

//判断是否为奇数
bool isOdd( int n ){
	return n % 2;
}

//判定所在的格子颜色
int judgeColor( int a , int b ){
	if( isOdd( a ) && isOdd( b ) )
		return black;
	if( isOdd( a ) && !isOdd( b ) )
		return white;
	if( !isOdd( a ) && isOdd( b ) )
		return white;
	if( !isOdd( a ) && !isOdd( b ) )
		return black;
	return -1;//保险起见
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
		//没有添加异常处理，默认全部输入都是符合规定的！！！
		//把字符串转换为整数的坐标，方便计算
		int x1 = beg[0] - 'a' + 1;
		int y1 = beg[1] - '0';
		int x2 = end[0] - 'a' + 1;
		int y2 = end[1] - '0';
		//计算相对位置
		int disX = myabs(x1 - x2);
		int disY = myabs(y1 - y2);
		//计算王的步数
		int king = disX < disY ? disX : disY;
		king += myabs( disX - disY );
		//计算后的步数
		int queen = 0;
		if( disX == disY ){
			queen = 1;
		}else if( !disX || !disY ){
			queen = 1;
		}else{
			queen = 2;
		}
		//计算车的步数
		int car = ( disX && disY ) ? 2 : 1;
		//计算象的步数
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

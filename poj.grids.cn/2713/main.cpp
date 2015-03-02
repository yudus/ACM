/*
	*题目中明确告诉你是矩形！！！
	*所以记录左上角和右下角的坐标，直接就能算出来，并不需要给数组开空间哦！
	*const打错了，CE了一次。。。
*/

#include <iostream>

using namespace std;

const int MAXN = 1001;

int main( void ){
	int n;
	while( cin >> n ){
		int x1, y1, x2, y2;
		bool first = true;
		int m;
		for( int i = 0; i < n; ++i ){
			for( int j = 0; j < n; ++j ){
				cin >> m;
				if( !m ){
					if( first ){
						x1 = i;
						y1 = j;
						first = false;
					}else{
						x2 = i;
						y2 = j;
					}
				}
			}
		}
		cout << ( x2-x1-1 ) * ( y2-y1-1 ) << endl;
	}	
    return 0;
}

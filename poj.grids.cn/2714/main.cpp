/*
	*忘写cstdio了，CE了一次。。。
*/

#include <iostream>
#include <cstdio>

using namespace std;

int main( void ){
    int n;
    while( cin >> n ){
    	double sum = 0;
    	int tmp;
    	for( int i = 0; i < n; ++i ){
    		cin >> tmp;
    		sum += tmp;
    	}
    	sum /= n;
    	printf( "%.2lf", sum );
    }
    return 0;
}

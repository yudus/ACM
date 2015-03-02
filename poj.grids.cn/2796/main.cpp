#include <iostream>

using namespace std;

const int MAXN = 6;

int main( void ){
    int a, arr[MAXN];
    while( cin >> a >> arr[1] >> arr[2] >> arr[3] >> arr[4] >> arr[5] ){
    	int sum = 0;
    	for( int i = 0; i < MAXN; ++i ){
    		if( arr[i] < a ){
    			sum += arr[i];
    		}
    	}
    	cout << sum << endl;
    }
    return 0;
}

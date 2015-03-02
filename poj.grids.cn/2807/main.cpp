#include <iostream>

using namespace std;

const int MAXN = 16;

int main( void ){
    int n;
    int a[MAXN];
    int aIndex = 0;
    while( cin >> n && n != -1 ){
    	if( n ){
    		a[aIndex++] = n;
    	}else{
    		int found = 0;
    		for( int i = 0; i < aIndex; ++i ){
    			for( int j = 0; j < aIndex; ++j ){
    				if( a[j] == a[i] * 2 ){
    					++found;
    				}
    			}
    		}
    		cout << found << endl;
    		aIndex = 0;
    	}
    } 
    return 0;
}

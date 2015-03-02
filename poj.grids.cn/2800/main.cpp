#include <iostream>
#include <string>

using namespace std;

const int MAXN = 1000;

int main( void ){
    string s;
    int a[26] = { 0 };
    for( int i = 0; i < 4; ++i ){
    	getline( cin, s );
    	for( int i = 0; i < s.size(); ++i ){
    		if( s[i] >= 'A' && s[i] <= 'Z' ){
	    		int index = s[i] - 'A';
	    		++a[index];
	    	}
    	}
    }
    int imax = 0;
    for( int i = 0; i < 26; ++i ){
    	if( imax < a[i] ){
    		imax = a[i];
    	}
    }
    int cur = imax;
    for( int i = 0; i < imax; ++i ){
    	for( int j = 0; j < 26; ++j ){
    		if( j ){
    			cout << " ";
    		}
    		if( a[j] == cur ){
    			cout << "*";
    			--a[j];//居然忘了这么重要的东西，WA了一次！！！
    		}else{
                cout << " ";
            }
    	}
    	cout << endl;
    	--cur;
    }
    for( int i = 0; i < 26; ++i ){
    	if( i ){
    		cout << " ";
    	}
    	char c = 'A' + i;
    	cout << c;
    }
    cout << endl;
    return 0;
}

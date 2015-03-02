/*
	*看错题了，人家让还原，我给加密了。。。
	*string用得不熟练啊，应该是string.push_back()，我当成了string.push()了。。。
	*如果原文就是START，这种可能存在吗？
*/

#include <iostream>
#include <string>

using namespace std;

int main( void ){
	string s;
	bool start = false;
	bool first = true;
	while( true ){
		getline( cin, s );
		if( s == "START" ){
			start = true;
		}
		if( s == "END" ){
			start = false;
			first = true;
			continue;//这里小失误了一下。。。
		}
		if( s == "ENDOFINPUT" ){
			break;
		}
		if( start && !first ){
            string passage;
			for( int i = 0; i < s.size(); ++i ){
				if( s[i] >= 'A' && s[i] <= 'Z' ){
					int w = ( s[i] - 'A' - 5 + 26 ) % 26;
					char c = 'A' + w;
					passage.push_back( c );
				}else{
					passage.push_back( s[i] );
				}
			}
			cout << passage << endl;
		}
		first = false;
	}
    return 0;
}

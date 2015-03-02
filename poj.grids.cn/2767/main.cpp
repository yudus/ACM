/*
	*�������ˣ��˼��û�ԭ���Ҹ������ˡ�����
	*string�õò���������Ӧ����string.push_back()���ҵ�����string.push()�ˡ�����
	*���ԭ�ľ���START�����ֿ��ܴ�����
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
			continue;//����Сʧ����һ�¡�����
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

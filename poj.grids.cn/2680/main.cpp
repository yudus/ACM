#include <iostream>

using namespace std;

int main( void ){
	int nCase;
	cin >> nCase;
	while( nCase-- ){
		string sex;
		double wbc, rbc, hgb, hct, plt;
		int cnt = 0;
		bool isNormal = true;
		cin >> sex >> wbc >> rbc >> hgb >> hct >> plt;
		if( wbc < 4.0 || wbc > 10.0 ){
			isNormal = false;
			++cnt;
		}
		if( rbc < 3.5 || rbc > 5.5 ){
			isNormal = false;
			++cnt;
		}
		if( sex == "male" ){
			if( hgb < 120 || hgb > 160 ){
				isNormal = false;
				++cnt;
			}
			if( hct < 42 || hct > 48 ){
				isNormal = false;
				++cnt;
			}
		}
		if( sex == "female" ){
			if( hgb < 110 || hgb > 150 ){
				isNormal = false;
				++cnt;
			}
			if( hct < 36 || hct > 40 ){
				isNormal = false;
				++cnt;
			}
		}
		if( plt < 100 || plt > 300 ){
			isNormal = false;
			++cnt;
		}
		if( isNormal ){
			cout << "normal" << endl;
		}else{
			cout << cnt << endl;
		}
	}
    return 0;
}

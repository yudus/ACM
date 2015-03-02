#include <iostream>

using namespace std;

int main( void ){
    int n;
    cin >> n;
    int maxMoney = 0;
    int sumMoney = 0;
    string maxName;
    while( n-- ){
	    string name, cadre, west;
	    int score, cScore, paper;
    	cin >> name >> score >> cScore >> cadre >> west >> paper;
    	int money = 0;
    	if( score > 80 && paper ){
    		money += 8000;
    	}
    	if( score > 85 && cScore > 80 ){
    		money += 4000;
    	}
    	if( score > 90 ){
    		money += 2000;
    	}
    	if( score > 85 && west == "Y" ){
    		money += 1000;
    	}
    	if( cScore > 80 && cadre == "Y" ){
    		money += 850;
    	}
    	sumMoney += money;
    	if( maxMoney < money ){
    		maxMoney = money;
    		maxName = name;
    	}
    }
    cout << maxName << endl;
    cout << maxMoney << endl;
    cout << sumMoney << endl;
    return 0;
}

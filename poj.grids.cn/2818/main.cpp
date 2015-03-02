/*
	*这还是四年半以前做的题呢。。。我就不再吐槽时间过得如何快了。。。
	*历史的经验告诉我，这题完全模拟肯定超时！！！
	*所以写个函数寻找密钥的周期，然后取模直接一步到位！
	*第一次提交RE。。。Codeblocks运行了一下，执行不了。。。
	*DEBUG发现找周期的函数段异常了。。。
	*同时也发现了忘了给数组初始化。。。好低级的错误。。。
	*cur = a[a[cur]]写成cur = a[a[i]]了。。。严重的错误！
	*其实楼上的式子就错了！！！⊙﹏⊙b。。。
	*应该写成cur = a[cur]，上面的多跳了一步。。。这是更严重的错误！！！
	*改完了发现程序第一组数据正确，第二组数据怎么出现特殊符号了？？？
	*还有0的时候程序结束不了。。。
	*改好了。。。WA。。。%>_<%
	*各种段异常。。。
	*去你的string吧！！！改用char数组！！！
	*CodeBlocks都让我干崩溃两次了！！！亲！！！
	*三次了！！！这程序怎么越改越完蛋啊！！！我真想重写了啊！！！
	*都已经各种全局变量了。。。。。太有失水准了。。。
	*改成char数组就AC了。。。。。。
	*果然是string的问题啊。。。看来C++完全不熟练啊！！！太菜了！！！
	*决定有时间把这道题再改回string写！
	*最后。。。。。内牛满面。。。这代码写的太难看了。。。
*/

#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int MAXN = 202;

int a[MAXN];
int circle[MAXN][MAXN];
int cirIndex[MAXN];
char s[MAXN+MAXN], res[MAXN+MAXN];

//给这帮大爷初始化！
void init( int n ){
	for( int i = 0; i < n; ++i ){
		for( int j = 0; j < n; ++j ){
			circle[i][j] = 0;
		}
		cirIndex[i] = 0;
	}
}

//找出周期！！！
void findCircle( int n ){
	init( n );
	for( int i = 0; i < n; ++i ){
		int cur = a[i];
		//为了方便后面的取模运算，第一位就直接放i自己！也就是说取模为0的时候，位置不变！
		circle[i][cirIndex[i]++] = i;
		while( cur != i ){
			circle[i][cirIndex[i]++] = cur;
			cur = a[cur];
		}
	}
	return;
}

//把字符串转换为数字和字符
long trans( void ){
    long k = 0;
    int i = 0;
    int sEnd = strlen( s );
    while( s[i] != ' ' ){
        k *= 10;
        k += ( s[i]-'0' );
        ++i;
    }
    ++i;
    int j;
    for( j = 0; i < strlen( s )+1; ++i, ++j ){
        s[j] = s[i];
    }
    s[j] = '\0';
	return k;
}

//开始加密！！！
void code( int n, long k ){
	if( n > strlen( s ) ){
		for( int i = strlen( s ); i < n; ++i ){
			s[i] = ' ';
			s[i+1] = '\0';
		}
	}
    strcpy( res, s );
	for( int i = 0; i < n; ++i ){
		int pos = k % cirIndex[i];
		pos = circle[i][pos];
		res[pos] = s[i];
	}
	return;
}

int main( void ){
    int n;
    while( cin >> n && n ){
    	for( int i = 0; i < n; ++i ){
    		cin >> a[i];
    		--a[i];
    	}
    	findCircle( n );
        getchar();//吃回车！
    	while( true ){
            gets( s );
	    	if( strlen( s ) == 0 ){//如果是无意义的回车的话就continue
                continue;
	    	}
	    	if( strcmp( s, "0" ) == 0 ){
                break;
	    	}
	    	long k = trans();
	    	code( n, k );
			cout << res << endl;
		}
		cout << endl;
	}
    return 0;
}

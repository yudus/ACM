/*
	*依然是UltraEdit + Codeblocks
	*发现现在写程序比以前稳了
	*这么多的逻辑判断没打草稿，也没出现什么严重错误
	*难道是上了年纪的原因？？？
	*这个代码写的挺难看的。。。
	*答案给出的是用数学方法很快的解出来，我用的是完全模拟解的，好难写啊！好麻烦啊！！！
	*好好看一下答案吧，少年！
	*看来是以前写模拟题写惯了，以后再看到这种题首先应该考虑的是数学方法啊！！！
*/


#include <iostream>

using namespace std;

int main( void ){
    int p1, p2, p3, p4, p5, p6;
    while( cin >> p1 >> p2 >> p3 >> p4 >> p5 >> p6
    		&& ( p1 || p2 || p3 || p4 || p5 || p6 ) ){
    	int space1 = 0;//记录空出来1*1的格子数
    	int space2 = 0;//记录空出来2*2的格子数
    	int space3 = 0;//记录空出来3*3的格子数
    	int cnt = p6;//6*6的直接占一个箱子
    	p6 = 0;
    	//5*5的占用一个箱子，每个箱子制造出11个1*1的空格，然后把1*1的箱子都放进这些空格子中！
    	if( p5 ){
	    	cnt += p5;
	    	space1 += 11 * p5;
            p5 = 0;
	    }
	    if( p1 ){
	    	if( p1 >= space1 ){
	    		p1 -= space1;
	    		space1 = 0;
	    	}else{
	    		space1 -= p1;
	    		p1 = 0;
	    	}
	    }
    	//4*4的也必须单独占用一个箱子，但是空出来的空间比较大，能放5个2*2的箱子
    	if( p4 ){
	    	cnt += p4;
	    	space2 += 5 * p4;
            p4 = 0;
	    }
	    if( p2 ){//如果2*2的箱子还有剩余，装之
	    	if( p2 >= space2 ){
	    		p2 -= space2;
	    		space2 = 0;
	    	}else{//2*2的箱子都装完了，把2*2的格子变成1*1的格子
	    		space2 -= p2;
	    		p2 = 0;
	    		space1 += space2 * 4;
	    		space2 = 0;
	    	}
	    }else{//2*2的箱子没有了，就都转换成1*1的格子了！
	    	space1 += space2 * 4;
	    	space2 = 0;
	    }
	    if( p1 ){//在用1*1的箱子溜缝
	  		if( p1 >= space1 ){
	  			p1 -= space1;
	  			space1 = 0;
	  		}else{
	  			space1 -= p1;
	  			p1 = 0;
	  		}
	  	}
    	//放3*3的箱子，每个箱子能放四个！并且制造出3*3的空格来
    	if( p3 ){
    		if( p3 % 4 ){
    			++cnt;
    			cnt += p3 / 4;//////////////////floor???
    			space3 = 4 - ( p3 % 4 );
    		}else{
    			cnt += p3 / 4;
    		}
    	}
    	switch( space3 ){
    		//如果空出1个3*3的格子，那么只能放入1个2*2的箱子和5个1*1的箱子
    		case 1:{
    			space1 += 5;
    			space2 += 1;
    			if( p2 ){//2*2的箱子还有剩余时，就放之！
    				if( p2 >= space2 ){
    					p2 -= space2;
    					space2 = 0;
    				}else{//2*2的箱子都用光了，就把2*2的格子转换成1*1的格子
    					space2 -= p2;
    					p2 = 0;
    					space1 += space2 * 4;
    					space2 = 0;
    				}
    			}else{//2*2的箱子没有剩余时，就全部转换为1*1的格子
    				space1 += space2 * 4;
    			}
				if( p1 ){//如果p1有剩余
					if( p1 >= space1 ){
						p1 -= space1;
						space1 = 0;
					}else{
						space1 -= p1;
						p1 = 0;
					}
				}
    		}break;
    		//如果空出2个3*3的格子，可以放入3个2*2的箱子和6个1*1的箱子
    		case 2:{
    			space1 += 6;
    			space2 += 3;
    			//放置2*2的箱子
    			if( p2 ){//2*2的箱子还有剩余
    				if( p2 >= space2 ){//放完了已经没有2*2的空格时
    					p2 -= space2;
    					space2 = 0;
    				}else{//放完了仍然还剩余2*2的空格，就得将2*2的格子转换成4个1*1的格子
    					space2 -= p2;
    					p2 = 0;
    					space1 += space2 * 4;
    					space2 = 0;
    				}
    			}else{//2*2的箱子没有剩余时
    				space1 += space2 * 4;
    			}
    			//放置1*1的箱子
    			if( p1 ){
    				if( p1 >= space1 ){
    					p1 -= space1;
    					space1 = 0;
    				}else{
    					space1 -= p1;
    					p1 = 0;
    				}
    			}
    		}break;
    		//如果空出3个3*3的格子，可以放入5个2*2的箱子和7个1*1的箱子
    		case 3:{
    			space1 += 7;
    			space2 += 5;
    			//放置2*2箱子
    			if( p2 ){
    				if( p2 >= space2 ){
    					p2 -= space2;
    					space2 = 0;
    				}else{
    					space2 -= p2;
    					p2 = 0;
    					space1 += space2 * 4;
    					space2 = 0;
    				}
    			}else{
    				space1 += space2 * 4;
    			}
    			//放置1*1箱子
    			if( p1 ){
    				if( p1 >= space1 ){
    					p1 -= space1;
    					space1 = 0;
    				}else{
    					space1 -= p1;
    					p1 = 0;
    				}
    			}
    		}break;
    	}
    	//放2*2的箱子了！6*6能放9个2*2的箱子
    	if( p2 ){
    		if( p2 % 9 ){
	    		++cnt;
	    		cnt += p2 / 9;//////////////floor???
	    		space1 = ( 9 - ( p2 % 9 ) ) * 4;
	    	}else{
	    		cnt += p2 / 9;
	    	}
	    	p2 = 0;/////////////放置完p2的话就彻底没了！
	    }
	    if( space1 ){//最后再溜一次缝
	    	if( p1 >= space1 ){
	    		p1 -= space1;
	    		space1 = 0;
	    	}else{
	    		space1 -= p1;
	    		p1 = 0;
	    	}
	    }
	    //终于到放1*1的箱子了！！！
	    if( p1 ){
	    	if( p1 % 36 ){
	    		++cnt;
	    	}
	    	cnt += p1 / 36;
	    }
	    cout << cnt << endl;
    }
    return 0;
}

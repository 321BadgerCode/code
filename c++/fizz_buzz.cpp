//badger
#include <iostream>
#include <cstring>

using namespace std;

/*
 * multiple of 3:fizz.
 * multiple of 5:buzz.
 * multiple of 3&5:fizzbuzz.
 * else:#
 */
int main(int argc,char** argv){
	int a=1;
	while(true){
		char ans[9];
		ans[0]='\0';
		if(a%3==0){strcat(ans,"fizz");}
		if(a%5==0){strcat(ans,"buzz");}
		if(a%3!=0&&a%5!=0){sprintf(ans,"%d",a);}
		cout<<ans<<endl;
		a++;
	}
	return 0;
}
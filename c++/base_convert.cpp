//badger
#include <iostream>
#include <string>
#include <cstring>

using namespace std;

template<typename A>short int get_len(A a1[]){
	A a=a1[0];
	int b=0;
	while(!a.empty()){a=a1[b];b++;}
	return b-1;
}
short int get_len(string a1){
	return a1.length();
}
string get_reverse(const string a1){
	string ans="";
	for(int a=get_len(a1)-1;a>=0;a--){
		ans+=a1[a];
	}
	return ans;
}
unsigned int get_digits(const unsigned int num,const unsigned int base=2){
	unsigned int n1=num;
	unsigned int digits=1;
	while(n1>0){
		n1/=base;
		digits++;
	}
	return digits;
}
string get_base(const unsigned int num,const unsigned short int base=2,unsigned short int digits=NULL){
	if(digits==NULL){digits=get_digits(num,base);}
	unsigned int n1=num;
	char* base_digits="0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ+\\";

	string ans;
	for(int a=0;a<digits;a++){
		ans+=base>=16?base_digits[n1%base]:(n1%base)+'0';
		n1/=base;
	}

	return get_reverse(ans);
}

int main(int argc, char** argv){
	if(argc<2){cout<<"usage: ./base_convert.cpp <#(base 10)> [base] [digits]\n\t* <> means optional.\n\t[] means required."<<endl;return 0;}

	unsigned int num=stoi(argv[1]);
	unsigned int base=2;
	if(argc>=3){base=stoi(argv[2]);}
	unsigned int digits=NULL;
	if(argc>=4){base=stoi(argv[3]);}

	string digit=digits==0?"default":to_string(digits);
	unsigned int bases[]={2,8,10,16};
	string bases2[]={"0b","0","","0x"};
	string bases3="";
	for(int a=0;a<4;a++){if(base==bases[a]){bases3=bases2[a];break;}}

	cout<<num<<"(base 10)->base "+to_string(base)+" w/ "+digit+" digits:"<<endl;
	cout<<bases3+get_base(num,base,digits)<<endl;
	return 0;
}
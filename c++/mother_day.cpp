//badger
#include <iostream>

using namespace std;

//return the number of characters in a string where tabs are converted to their # of equivalent spaces.
int get_len(const string str){
	int count=0;
	int pos=0;
	for(char c:str){
		if(c=='\t'){
			//calculate the number of spaces to the next tab stop based on the current position.
			int spaces=8-(pos%8);
			count+=spaces;
			pos+=spaces;
		}
		else{
			count++;
			pos++;
		}
		//reset position if a newline character is encountered.
		if(c=='\n'){
			pos=0;
		}
	}
	return count;
}

//format text.
string pad_txt(string text,int width,int pad=0,char padding_char=' '){
	int text_length=get_len(text);
	int padding_length=width-text_length;
	padding_length-=pad;
	if(padding_length<=0){
		return text;
	}

	int left_padding_length=padding_length/2;
	int right_padding_length=padding_length-left_padding_length;
	string left_padding=string(left_padding_length,padding_char);
	string right_padding=string(right_padding_length,padding_char);

	return left_padding+text+right_padding;
}

string get_replace(string txt,string find,string replace){
	size_t start_pos=0;
	while((start_pos=txt.find(find,start_pos))!=string::npos){
		txt.replace(start_pos,find.length(),replace);
		start_pos+=replace.length();
	}
	return txt;
}

int main(int argc,char** argv){
	int i,j,rows;

	cout<<"Rows(35): ";cin>>rows;

	cout<<"\033[31m";

	string a1="";

	//top half.
	for(i=rows/2;i<=rows;i+=2){
		a1="";
		for(j=1;j<rows-i;j+=2){
			a1+=" ";
		}
		for(j=1;j<=i;j++){
			a1+="*";
		}
		for(j=1;j<=rows-i;j++){
			a1+=" ";
		}
		for(j=1;j<=i;j++){
			a1+="*";
		}
		cout<<get_replace(a1,"*","♥")<<endl;
	}

	cout<<"♥♥♥♥♥\033[32m"<<pad_txt("\tHAPPY MOTHER'S DAY!!!\t",get_len(a1),4)<<"\033[31m♥♥♥♥♥"<<endl;

	//reverse pyramid.
	for(i=rows;i>=1;i--){
		a1="";
		for(j=i;j<rows;j++){
			a1+=" ";
		}
		for(j=1;j<=(i*2)-1;j++){
			a1+="*";
		}
		cout<<get_replace(a1,"*","♥")<<endl;
	}

	cout<<"\033[0m";

	return 0;
}
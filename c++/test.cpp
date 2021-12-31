//badger
#include <iostream>

using namespace std;

int get_sum_angle(int side){
	return (side-2)*180;
}

int get_side(int sum_angle){
	return (sum_angle/180)+2;
}

int get_int(string a1){
	int b1=0;

	for(int a=0;a<a1.size();a++){
		b1+=static_cast<int>(a1[a]);
	}

	return b1;
}

int main(){
	cout<<uppercase<<hex<<~get_int("hello world!")<<dec<<endl;

	system("pause");

	return 0;
}
//badger
#include <iostream>//basic
#include <time.h>//time()

using namespace std;

int get_random(int min,int max){
	srand(time(NULL));
	int b1=rand()%(max-min+1)+min;
	return b1;
}

int get_percent(int numerator,int denominator){
	int b1=(numerator*100)/denominator;
	return b1;
}

int main(){
	string min;
	cout<<"min. num.: ";
	cin>>min;
	cin.ignore();

	string max;
	cout<<"max. num.: ";
	cin>>max;

	int r1=get_random(stoi(min),stoi(max));
	int p1=get_percent(stoi(min),stoi(max));

	cout<<"random num.: "<<r1<<endl;
	cout<<"percentage: "<<p1<<"%"<<endl;

	system("pause");

	return 0;
}
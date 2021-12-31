//badger
#include <iostream>//basic
#include <cmath>//math
#include <windows.h>//title

using namespace std;

float data[5][2]={{1000,150000},{2000,400000},{3000,550000},{4000,625000},{5000,825000}};

float x[5]={0};
float y[5]={0};

template<typename a> int get_length(a a1){return sizeof(a1)+1;}

template<typename a> string get_list(a a1[]){
	string b1="";

	for(int b=0;b<get_length(a1)-1;b++){b1+=to_string(a1[b])+",";}
	b1+=to_string(a1[get_length(a1)-1]);

	return b1;
}

string get_number(float a1){
	string b1="";

	for(int a=0;a<get_length(a1)+1;a++){
		b1+=to_string(a1)[a];
		if(a>1&&(a+1)%3==0&&a<get_length(a1)-1){b1+=",";}
	}

	return b1;
}

float get_sum(float a1[]){
	float b1=0;

	for(int a=0;a<get_length(a1);a++){b1+=a1[a];}

	return b1;
}

float get_average(float a1[]){return get_sum(a1)/get_length(a1);}

float get_slope(){
	float numerator=0;
	float denominator=0;

	for(int a=0;a<get_length(x);a++){
		numerator+=(x[a]-get_average(x))*(y[a]-get_average(y));
		denominator+=pow(x[a]-get_average(x),2);
	}

	return numerator/denominator;
}

float get_y_intercept(){return get_average(y)-(get_slope()*get_average(x));}

float get_y(float x1){return get_slope()*x1+get_y_intercept();}//least sq. method

int main(){
	SetConsoleTitle("MACHINE_LEARN_1!");

	for(int a=0;a<5;a++){
		x[a]=data[a][0]/1000;
		y[a]=data[a][1]/100000;
	}

	cout<<"info./given/data:"<<endl;
	cout<<"x: "<<get_list(x)<<endl;
	cout<<"y: "<<get_list(y)<<endl;
	cout<<endl;

	auto x1=0;
	cout<<"sq. ft. house: ";
	cin>>x1;
	x1/=1000;

	cout<<endl;

	cout<<"y=("+to_string(get_slope())+"*"+to_string(x1)+")+"+to_string(get_y_intercept())<<endl;
	float y=get_y(x1);
	cout<<"y: "<<y<<endl;
	cout<<endl;
	cout<<"price house: ≈$"<<y*100000<<endl;
	//cout<<"price house: ≈$"<<get_number(y*100000)<<endl;

	system("pause");

	return 0;
}
//fix 'get_number()'
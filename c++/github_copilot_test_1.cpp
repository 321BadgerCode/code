//badger
#include <iostream>
#include <string>
#include <cmath>

using namespace std;

const double pi = 3.14159265358979323846;
const double e=2.71828182845904523536;

class circle{
private:
	float get_radius(){return diameter/2;}
	float get_diameter(){return 2*radius;}
	float get_circumference(){return 2 * pi * radius;}
	float get_area(){return pi * radius * radius;}
	float get_x(){return cos(0);}
	float get_y(){return sin(0);}
	void set_initiate(){
		diameter=get_diameter();
		circumference=get_circumference();
		perimeter=circumference;
		area=get_area();
		x=get_x();
		y=get_y();
	}
public:
	float radius=0;
	float diameter=0;
	float circumference=0;
	float perimeter=0;
	float area=0;
	float x=0;
	float y=0;
	circle(float r){radius=r;set_initiate();}
	string information(){
		string b1="radius: "+to_string(radius)+
		"\ndiameter: "+to_string(diameter)+
		"\ncircumference: "+to_string(circumference)+
		"\narea: "+to_string(area)+
		"\nx: "+to_string(get_x())+
		"\ny: "+to_string(get_y());
		return b1;
	}
	float get_diagonal(){return sqrt(radius*radius+radius*radius);}
	float get_slope(){return tan(y)/tan(x);}
};

int main(){
	circle c1(5);
	cout<<c1.information()<<endl;
	cout<<"diagonal: "<<c1.get_diagonal()<<endl;
	cout<<"slope: "<<c1.get_slope()<<endl;
	system("pause");
	return 0;
}
//fix circle.get_slope(),x,y
//sum int. angle circle: ∞
//badger
#include <rhino/etc/time.h>
#include <rhino/math/main.h>

using namespace rhino;

int main(){
	vector<> v1=vector<>();

	for(int a=0;a<3;a++){
		v1[a]=random2::get_random();
		time2::wait();
	}

	cout<<v1<<endl;

	cout<<math::pi<><<endl;
	cout<<math::pi<int><<endl;
	cout<<math::pi<long double><<endl;

	cout<<math::get_abs_val(-1)<<endl;

	return 0;
}
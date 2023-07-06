//badger
#include <rhino/etc/main.h>

using namespace rhino;

int main(){
	try{
		cout<<info::device::get_os(info::device::get_os())<<endl;
		cout<<info::user::name<<endl;

		cout<<(1<add>2)<<endl;

		cout<<time2::day2[time2::day[time2::get_week_day()-1]]<<endl;

		throw(error::run_time());
	}
	catch(error::run_time e1){
		cout<<e1.what()<<endl;
	}

	return 0;
}
//badger
#pragma once

#include <rhino/define/get/basic.h>
#include <rhino/define/get/console.h>
#include <rhino/define/type.h>

namespace rhino{
	$DEF_C time2{
	private:
		$IS time_t t1=time(0);
		$IS tm* local_time=localtime(&t1);
	public:
		$IS $CS day[]={
			"monday",
			"tuesday",
			"wednesday",
			"thursday",
			"friday",
			"saturday",
			"sunday"
		};
		$IS map<$CS,$CS> day2={
			{day[0],"mon."},
			{day[1],"tue."},
			{day[2],"wed."},
			{day[3],"thu."},
			{day[4],"fri."},
			{day[5],"sat."},
			{day[6],"sun."}
		};
		$IS $V wait($CF seconds=1){sleep(seconds);}
		$IS $V set_time(){t1=time(0);local_time=localtime(&t1);}
		$IS tm get_local_time(){return *local_time;}
		$IS time_t get_time(){return t1;}
		$IS $S get_date(){return ctime(&t1);}
		$IS $I get_year(){return local_time->tm_year+1900;}
		$IS $I get_month(){return local_time->tm_mon+1;}
		$IS $I get_month_day(){return local_time->tm_mday;}
		$IS $I get_week_day(){if(local_time->tm_wday==0){return 7;}return local_time->tm_wday;}
		$IS $I get_hour(){return local_time->tm_hour;}
		$IS $I get_minute(){return local_time->tm_min;}
		$IS $I get_second(){return local_time->tm_sec;}
		$IS $S get(){return to_string(get_hour())+":"+to_string(get_minute())+":"+to_string(get_second())+":";}
	};
};
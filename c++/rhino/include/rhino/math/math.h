//badger
#pragma once

#include "./math.hpp"
#include <rhino/define/get/basic.h>
#include <rhino/define/type.h>

template<typename A>A rhino::math::get_inverse_sq_root($C3 A a1){
	$L int b1;
	A b2,b3;
	b2=a1*.5f;
	b3=a1;
	b1=*($L $I*)&b3;
	b1=0x5f3759df-(b1>>1);
	b3=*($F*)&b1;
	b3=b3*(1.5f-(b2*b3*b3));
	return b3;
}
template<typename A>A rhino::math::get_abs_val($C3 A a1){
	A b1=a1;
	if(a1<0){b1*=-1;}
	return b1;
}
template<typename A>A rhino::math::get_len($C3 A a1[]){
	$I len=sizeof(a1)/sizeof(a1[0]);
	//$I len=sizeof(a1)/sizeof(A);
	return len;
}
template<typename A>A rhino::math::get_sum(const A a1[]){
	A sum=0;
	for($I a=0;a<get_len(a1);a++){
		sum+=a1[a];
	}
return sum;
}
template<typename A>A rhino::math::get_avg($C3 A a1[]){
	return get_sum(a1)/get_len(a1);
}
vector<$F>* rhino::math::get_percent($CI percent){
	return new vector<$F>(percent/100,percent/100,percent/100);
}
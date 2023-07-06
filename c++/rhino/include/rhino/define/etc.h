//badger
#pragma once

#include <rhino/etc/operator.h>

/*#define $OPERATOR(name,return_type,left_type,right_type)\
	return_type get_##name(const left_type left,const right_type right);\
	\
	rhino::op_obj<return_type,left_type,right_type> name(&get_##name);\
	\
	return_type get_##name(const left_type left,const right_type right)*/

#define $OPERATOR(name,return_type,left_type,right_type)\
	rhino::op_obj<return_type,left_type,right_type> name(&get_##name);\
	\
	inline return_type get_##name(const left_type left,const right_type right)
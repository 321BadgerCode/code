//badger
#pragma once

#include <rhino/define/get/basic.h>
#include <rhino/define/type.h>

namespace rhino{
	template<typename A>
	$DEF_C stack2:public stack<A>{
	public:
		using stack<A>::c;
	};
};
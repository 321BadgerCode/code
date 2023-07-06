//badger
#pragma once

#include <rhino/define/get/basic.h>
#include <rhino/define/type.h>

namespace rhino{
	class to{
	public:
		$TYPE(TYPE) $S string1(TYPE a1){return to_string(a1);}
		$TYPE(TYPE) $C char1(TYPE a1){return a1.c_str();}
		$TYPE(TYPE) $I int1(TYPE a1){return stoi(a1);}
		$TYPE(TYPE) $F float1(TYPE a1){return stof(a1);}
	};
};
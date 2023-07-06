//badger
#pragma once

#include <rhino/define/get/basic.h>
#include <rhino/define/type.h>

namespace rhino{
	class random2{
	public:
		template<typename A=$I,typename B=short $I>$IS A get_random(const B min=1,const B max=100){
			srand(time(NULL));

			$I b1=rand()%(max-(min+1))+min;

			return b1;
		}
	};
};
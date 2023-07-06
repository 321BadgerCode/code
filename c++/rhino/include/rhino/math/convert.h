//badger
#pragma once

#include <rhino/define/get/basic.h>
#include <rhino/define/type.h>

namespace rhino{
	class convert{
	public:
		$IS $D get_celsius($CD fahrenheit){$D b1=(fahrenheit-32)/1.8;return b1;}
		$IS $D get_fahrenheit($CD celsius){$D b1=(celsius*1.8)+32;return b1;}
		$IS $F get_feet($CF meter){$F b1=meter*3;return b1;}
		$IS $F get_meter($CF feet){$F b1=feet/3;return b1;}
	};
};
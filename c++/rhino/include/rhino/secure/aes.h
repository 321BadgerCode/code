//badger
#pragma once

#include <rhino/define/get/basic.h>
#include <rhino/define/type.h>

namespace rhino{
	$DEF_C aes{
		$IS $S get($CS msg,$CI key){
			string b1="";

			for(int a=0;a<msg.size();a++){
				b1+=static_cast<char>(static_cast<int>((msg[a%key])^key));
			}

			return b1;
		}
	};
};
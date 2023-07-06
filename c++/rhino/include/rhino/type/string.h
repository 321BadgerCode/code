//badger
#pragma once

#include <rhino/define/get/basic.h>
#include <rhino/define/get/binary.h>
#include <rhino/define/type.h>

namespace rhino{
	class string2{
	public:
		$IS $S get_for_do($CI a1,$CS a2){$S b1="";for($I a=0;a<a1;a++)b1+=a2;return b1;}
		$IS $S get_for_do($CS a1,$CS a2,$CB a3=false){
			$S b1="";

			if(a3==false){b1=get_for_do(a1.size(),a2);}
			else{b1=a1+"\n"+get_for_do(a1.size(),a2);}

			return b1;
		}
		$IS $S get_upper($CS a1){locale loc;$S b1="";for($I a=0;a<a1.length();a++)b1+=toupper(a1[a],loc);return b1;}
		$IS $S get_lower($CS a1){locale loc;$S b1="";for($I a=0;a<a1.length();a++)b1+=tolower(a1[a],loc);return b1;}
		$IS $S get_binary($CS a1){$S b1="";for($I a=0;a<a1.size();a++)b1+=bitset<8>(a1[a]).to_string();return b1;}
		$IS $I get_length($CS a1){$I b1=a1.size();return b1;}
		$IS string get_replace(string text,string find,string replace){
			int a=0;

			while(a<text.length()){
				if(text.substr(a,find.length())==find){
					text.replace(a,find.length(),replace);
					a+=replace.length();
				}
				else{a++;}
			}

			return text;
		}
	};
};
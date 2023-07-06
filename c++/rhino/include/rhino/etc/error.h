//badger
#pragma once

#include <rhino/define/get/basic.h>
#include <rhino/define/type.h>

namespace rhino{
	$DEF_C error{
	public:
		$DEF_S run_time:exception{$CC2 what() const throw() override {return "[._.]: ERROR: RUN-TIME ERROR!";}};
		$DEF_S err:exception{
			$S file;
			$I line;

			err($S file2="",$I line2=0):file(file2),line(line2){}
			$CC2 what() const throw() override {$S b1="file: "+file+"\nline: "+to_string(line);return b1.c_str();}
			$S get_about() const $NE {return "[._.]: AN ERROR OCCURED IN THE PROGRAM!";}
		};
	};
};
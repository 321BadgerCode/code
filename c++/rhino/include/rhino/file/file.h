//badger
#pragma once

#include <rhino/define/get/basic.h>
#include <rhino/define/get/file.h>
#include <rhino/define/type.h>

namespace rhino{
	class file{
	private:
		$IS ofstream o_file;
		$IS ifstream i_file;
	public:
		$IS $S file2="";
		
		file($S file22){file2=file22;}
		$IS $V write($CS text){o_file.open(file2);o_file<<text;o_file.close();}
		$IS $S get_line($CI line_num){i_file.open(file2);$S b1;$I b2=0;while(getline(i_file,b1)&&b2!=line_num){b2++;b1="";}return b1;}
		$IS $I get_lines($CS a1=file2){i_file.open(a1);$S b1;$I b2=0;while(getline(i_file,b1)){b2++;}return b2;}
		$IS $C get_letter($CI index){i_file.open(file2);$S b1;$I b2=0;while(getline(i_file,b1))b2+=b1.size();return b1[index];}
		$IS $I get_letter($CS a1=file2){i_file.open(a1);$S b1;$I b2=0;while(getline(i_file,b1))b2+=b1.size();return b2;}
		$IS $I get_letter_in_line($CI line){i_file.open(file2);$S b1;$I b2=0;while(getline(i_file,b1)&&b2!=line)b2++,b1="";return b1.size();}
		$IS $S get_read($CS a1=file2){i_file.open(a1);$S b1;$S b2;while(getline(i_file,b1))b2+=b1+"\n";return b2;}
		$IS $B get_exist($CS a1=file2){i_file.open(a1);if(i_file){return true;}else{return false;}i_file.close();}
	};
};
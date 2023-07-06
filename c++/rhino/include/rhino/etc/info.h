//badger
#pragma once

#include "./info.hpp"
#include <rhino/define/get/basic.h>
#include <rhino/define/type.h>

rhino::info::device::os rhino::info::device::get_os(){
	#ifdef _WIN32
		return rhino::info::device::os::win32;
	#elif _WIN64
		return rhino::info::device::os::win64;
	#elif __APPLE__ || __MACH__
		return rhino::info::device::os::mac;
	#elif __linux__
		return rhino::info::device::os::linux2;
	#elif __FreeBSD__
		return rhino::info::device::os::free_bsd;
	#elif __unix || __unix__
		return rhino::info::device::os::unix2;
	#else
		return rhino::info::device::os::null;
	#endif
}
$S rhino::info::device::get_os(rhino::info::device::os a1){
	$S b1="";

	if(a1==rhino::info::device::os::win32){b1=rhino::info::device::win322;}
	else if(a1==rhino::info::device::os::win64){b1=rhino::info::device::win642;}
	else if(a1==rhino::info::device::os::mac){b1=rhino::info::device::mac2;}
	else if(a1==rhino::info::device::os::linux2){b1=rhino::info::device::linux22;}
	else if(a1==rhino::info::device::os::free_bsd){b1=rhino::info::device::free_bsd2;}
	else if(a1==rhino::info::device::os::unix2){b1=rhino::info::device::unix22;}
	else if(a1==rhino::info::device::os::null){b1=rhino::info::device::null2;}

	return b1;
}
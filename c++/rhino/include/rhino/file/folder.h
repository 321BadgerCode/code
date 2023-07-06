//badger
#pragma once

#include "./folder.hpp"
#include <rhino/define/get/basic.h>
#include <rhino/define/get/file.h>
#include <rhino/define/type.h>
#include <rhino/etc/info.h>
#include <rhino/sys/console.h>
#include <rhino/type/string.h>

$V rhino::folder::create(){mkdir(folder2.c_str(),S_IXUSR);}
$B rhino::folder::exist(){struct stat b1;return stat(folder2.c_str(),&b1)==0;}
$S rhino::folder::get_path($CS folder3){return string2::get_replace(folder3,"/home/"+info::user::name,"~");}
$S rhino::folder::get_current_path(){return console::get_cmd_out("echo -n \"$PWD\"");}
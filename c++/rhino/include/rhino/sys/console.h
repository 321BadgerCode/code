//badger
#pragma once

#include "./console.hpp"
#include <rhino/define/get/basic.h>
#include <rhino/define/get/console.h>
#include <rhino/define/type.h>
#include <rhino/etc/info.h>
#include <rhino/file/folder.h>
#include <rhino/math/vector.h>
#include <rhino/ui/color.h>

rhino::console::console($CS title){set_title(title);}

$S rhino::console::text::get_ui(){return rhino::color::get_ui(rhino::color::get_ui(a,rhino::color::type::fg,fg),rhino::color::type::bg,bg);}

template<typename A>rhino::vector<A>* rhino::console::size::get(){
	vector<A>* v=new vector<A>(0,0);

	#ifdef TIOCGSIZE
		struct ttysize ts;
		ioctl(STDIN_FILENO,TIOCGSIZE,&ts);
		
		v->x=ts.ts_lines;
		v->y=ts.ts_cols;
	#elif defined(TIOCGWINSZ)
		struct winsize ws;
		ioctl(STDIN_FILENO,TIOCGWINSZ,&ws);
		
		v->x=ws.ws_row;
		v->y=ws.ws_col;
	#endif
		
	return v;
}

$TYPE(TYPE) $V rhino::console::print(TYPE text){cout<<text<<endl;}
$V rhino::console::print(text* a1){cout<<a1->get_ui()<<endl;}
$TYPE(TYPE) $V rhino::console::echo(TYPE text){cout<<text;}
$V rhino::console::echo(text* a1){cout<<a1->get_ui();}
$TYPE(TYPE) $V rhino::console::error(TYPE text,$CB endl2){if(endl2==true){cerr<<text<<endl;}else{cout<<text;}}
$S rhino::console::get_input($CS text){$S b1;cout<<text;getline(cin,b1);return b1;}
$S rhino::console::get_input(text* a1){$S b1;cout<<a1->get_ui();getline(cin,b1);return b1;}
$S rhino::console::get_type(){$S b1=getenv("TERM");return b1;}
$S rhino::console::get_title(){return info::user::name+"@"+info::device::name+": "+folder::get_path(folder::get_current_path());}
$V rhino::console::set_title($CS text){cout<<"\033]0;"<<text<<"\007";}
$V rhino::console::pause($CS a1){$CS b1="read -rp \""+a1+"\" a1";system(b1.c_str());}
$V rhino::console::clear(){system("clear");}
$V rhino::console::wait(){cin.get();}
$V rhino::console::leave(){exit(0);}
$V rhino::console::start($CS name){system(name.c_str());}
$S rhino::console::get_cmd_out($CS cmd){
	char buffer[128];
	string result="";

	FILE* pipe=popen(cmd.c_str(),"r");

	if(pipe){
		while(!feof(pipe)){
			if(fgets(buffer,128,pipe)!=NULL){result+=buffer;}
		}

		pclose(pipe);
	}

	return result;
}
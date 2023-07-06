//badger
#include <rhino/system/main.h>

using namespace rhino;

int main(){
	console con("SYSTEM!");

	con.print(color::get_ui(color::get_ui(color::get_ui("SYSTEM!",color::type::fg,color::blue),color::type::under_line),color::type::over_line));
	console::print("");

	console::print("[._.]: "+info::device::get_os(info::device::get_os())+" con. type: "+console::get_type());

	$S a1=console::get_input(new console::text{.a="[._.]: how are you doing today? ",.fg=color::red});

	console::print("[._.]: you inputted: \""+a1+"\"");

	console::pause();

	console::clear();

	return 0;
}
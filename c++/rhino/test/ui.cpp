//badger
#include <rhino/system/console.h>
#include <rhino/ui/main.h>

using namespace rhino;

$V print($CS a1){
	$I b1=color::black+1;

	for($I a=0;a<=a1.size();a++){
		if(b1>color::white){b1=color::black+1;}

		console::echo(new console::text{.a=string(1,a1[a]),.fg=b1});

		b1++;
	}

	console::print("");
}

int main(){
	console con("U.I.!");

	console::print(color::get_ui(color::get_ui(color::get_ui("U.I.!",color::type::fg,color::blue),color::type::under_line),color::type::over_line));
	console::print("");

	console::echo(info::device::get_os(info::device::get_os())+" con. type: ");
	print(console::get_type());
	console::print("");

	print("[._.]: hello world!");

	$S a1=console::get_input(new console::text{.a="[._.]: how are you doing today? ",.fg=color::red});
	
	print("[._.]: oh, ok then.");
	print("[._.]: you're \""+a1+"\".");
	print("[._.]: i'm "+a1+" as well :)");

	console::print(new console::text{.a="U.C.F..",.fg=208,.bg=235});
	console::print(new console::text{.a="U.F..",.fg=12,.bg=202});

	console::print("");
	console::print("4 bit clr. sys.:");
	console::print("-----------------");
	console::print("| 8 | "+color::get_ui("4",color::type::fg,color::blue)+" | "+color::get_ui("2",color::type::fg,color::green)+" | "+color::get_ui("1",color::type::fg,color::red));
	console::print("-----------------");
	console::print("| I | "+color::get_ui("B",color::type::fg,color::blue)+" | "+color::get_ui("G",color::type::fg,color::green)+" | "+color::get_ui("R",color::type::fg,color::red));
	console::print("-----------------");
	console::print("I=>intensity.");
	console::print(color::get_ui("B=>blue.",color::type::fg,color::get_light(color::blue)));
	console::print(color::get_ui("G=>green.",color::type::fg,color::get_light(color::green)));
	console::print(color::get_ui("R=>red.",color::type::fg,color::get_light(color::red)));

	console::print("8 bit clr. sys.(variations of main 4-bit colors): 255.");
	console::print("24 bit clr. sys.(true clr.): new rgb{255,255,255}.");

	console::pause();

	console::clear();

	return 0;
}
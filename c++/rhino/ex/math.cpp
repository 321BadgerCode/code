//badger
#include <rhino/sys/main.h>
#include <rhino/math/main.h>

using namespace rhino;

$B is_even($CI a1){return a1%2==0;}
$CI get_odd($CI a1){return (3*a1)+1;}
$CI get_even($CI a1){return a1/2;}
$CI get_num($CI a1){return is_even(a1)?get_even(a1):get_odd(a1);}

/**
 * @brief main func..
 * 
 * @param args # of arguments.
 * @param argv cmd's.
 * 
 * @return success=0; error=1.
 */
int main(int args,char* argv[]){
	$I num=random2::get_random();
	if(args>1){
		if(($S)argv[1]=="-h"){
			console::print(new console::text{.a="-h:\thelp.",.fg=color::red2});
			console::print(new console::text{.a="-a:\tabout.",.fg=color::orange2});
			console::leave();
		}
		else if(($S)argv[1]=="-a"){
			console::print(new console::text{.a="* #: inputted number.",.fg=color::red2});
			console::print(new console::text{.a="* n: iterations.",.fg=color::orange2});
			console::print(new console::text{.a="* restriction: 0<#<∞.",.fg=color::yellow2});
			console::print(new console::text{.a="\n* rules:",.fg=color::green2});
			console::print(new console::text{.a="\t* even: #/2.",.fg=color::blue2});
			console::print(new console::text{.a="\t* odd: (3*#)+1.",.fg=color::indigo2});
			console::print(new console::text{.a="\n* info.:"});
			console::print(new console::text{.a="\t* #=>n ; 2*#=>n+1",.fg=color::violet2});
			console::leave();
		}
		else{
			num=stoll(argv[1]);

			while(num<=0){
				console::print(new console::text{.a="0<#<∞!",.fg=color::red2});
				num=stoi(console::get_input("#: "));
			}
		}
	}
	$CI a1=num;

	$I a=0;
	while(num!=1){
		console::print(	color::get_ui(to_string(a),color::type::fg,color::red2)+".\t"+
				color::get_ui(to_string(num),color::type::fg,color::green2)+"\t"+
				color::get_ui(to_string(log(num)),color::type::fg,color::blue2)+"\t"+
				color::get_ui(to_string(sin(num)),color::type::fg,color::yellow2));
		num=get_num(num);
		a++;
	}

	console::print("\n"+color::get_ui(to_string(a1),color::type::fg,color::red2)+" is 1 after "+color::get_ui(to_string(a),color::type::fg,color::green2)+" iterations.");

	return 0;
}
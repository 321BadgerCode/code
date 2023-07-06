//badger
#include <rhino/sys/main.h>
#include <rhino/math/vector.h>

using namespace rhino;

/**
 * @brief output clr..
 * 
 * @param a1 clr. #.
 */
void print($CI a1,$CS end="\n"){
	console::echo(new console::text{.a=bitset<8>(a1).to_string()+"("+to_string(a1)+")",.fg=a1});
	console::echo(end);
}
/**
 * @brief mix colors. max multiplier=1.
 * 
 * @param a1 a1->x=color; a1->y=multiplier.
 * @param a2 a2->x=color; a2->y=multiplier.
 * 
 * @return mixed color.
 */
$I get_mix(const vector<float>* a1,const vector<float>* a2){
	return (int)((a1->x*a1->y)+(a2->x*a2->y));
}
/**
 * @brief mix colors.
 * 
 * @param a1 color to mix.
 * @param a2 coef..
 * 
 * @return mixed color.
 */
template<typename A>$I get_mix(const color::rgb* a1,const vector<A>* a2){
	return (a2->x*a1->r)+(a2->y*a1->g)+(((1+a2->z)-a2->x)-a2->y)*a1->b;
}
/**
 * @brief gray-scale given colors.
 * 
 * @param a1 colors to avg. 4 gray-scale.
 * 
 * @return gray-scaled colors.
 */
color::rgb* get_gray_scale(color::clr_t clr[]){
	$I* avg[math::get_len(clr)];//seg. fault w/ avg(lvalue?)

	for($I a=0;a<math::get_len(clr);a++){
		color::rgb* clr2=new color::rgb(clr[a]);
		*avg[a]=math::get_avg(($I*)(*clr2));
	}

	return new color::rgb(math::get_avg<$I>(*avg));
}
/**
 * @brief show rgb of 8 bit clr..
 * 
 * @param clr 8 bit clr..
 */
$V rgb(color::clr_t clr){
	$CI b1=color::get_24_bit(clr);
	color::rgb* rgb=color::get_rgb(b1);

	console::print(to_string(clr)+"="+to_string(b1)+"="+($S)(*rgb));
}
/**
 * @brief show 4,8,24,rgb clr. of 8 bit 'clr'.
 * 
 * @param clr 8 bit clr..
 * 
 */
$V clr(color::clr_t clr){
	console::echo(to_string(color::get_4_bit(color::get_24_bit(clr))));
	console::echo("\t");
	console::echo(to_string(color::get_8_bit(color::get_24_bit(clr))));
	console::echo("\t");
	console::echo(color::get_24_bit(clr));
	console::echo("\t");
	console::print(($S)*color::get_rgb(color::get_24_bit(clr)));
}

/**
 * @brief main func..
 * 
 * @param args # of arguments.
 * @param argv cmd's.
 * 
 * @return success=0; error=1.
 */
int main(int args,char** argv){
	$CI r=color::red2;
	$CI g=color::green2;
	$CI b=color::blue2;
	const color::rgb* rgb2=new color::rgb(r,g,b);

	/*console::print((($S)(*rgb2))+"\n");

	print(r>>4,"\t\tr->b\t\tr>>4\n");
	console::print("");

	print(r|b,"\t\tr:b\t\t1:1\n");
	print((get_mix(new vector<float>(r,.7),new vector<float>(b,.3))),"\t\tr:b\t\t.7:.3\n");
	console::print("");

	print(get_mix(rgb2,new vector<>(0,0,0)),"\t\tr:g:b\t\t0:0:0\n");
	print(get_mix(rgb2,new vector<>(1,1,1)),"\t\tr:g:b\t\t1:1:1\n");
	print(get_mix(rgb2,new vector<$F>(.5,.5,.5)),"\t\tr:g:b\t\t.5:.5:.5\n");
	print(get_mix(rgb2,new vector<>(0,1.3,1.7)),"\t\tr:g:b\t\t0:1.3:1.7\n");
	console::print("");*/

	/*for($I a=color::black2;a<=color::white2;a++){
		rgb(a);
	}*/
	//console::print(($S)*(*color::red3|color::green3));

	//console::print(($S)(*get_gray_scale((color::clr_t*)($I*)(*rgb2))));

	/*for($I a=color::black2;a<=color::white2;a++){
		clr(a);
	}*/

	/*for($I a=color::black2;a<=color::white2;a++){
		console::print(($S)*color::get_rgb(color::get_24_bit(a)));
	}*/

	for($I a=0;a<=100;a++){
		console::print(($S)*(*color::white3*math::get_percent(a)));
	}

	/*for($I a=0;a<=100;a++){
		console::print(($S)*color::red3->get_lerp(color::green3,a));
	}*/

	/*for($F a=0;a<=1;a+=.01){
		console::print(to_string(a)+". "+($S)*(*(*color::red3*new vector<$F>(a,a,a))|(*color::green3*new vector<$F>(a,a,a))));
	}*/

	return 0;
}
/*//red,green,a(from for loop)	=>	red->black
$CF b1=1-percent;
color::rgb* b2=*a1*new vector<$F>(b1,b1,b1);
color::rgb* b3=*a2*new vector<$F>(percent,percent,percent);
return *b2+(vector<>*)b3;*/
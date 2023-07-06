//badger
#pragma once

#include <rhino/define/get/basic.h>
#include <rhino/define/type.h>
#include <rhino/math/math.h>

namespace rhino{
	class color{
	public:
		/*typedef $C3 $UI(8) clr_t_4;
		typedef $C3 $UI(8) clr_t_8;
		typedef $CI clr_t_24;*/
		typedef $C3 $UI(8) clr_t;

		class type{
		public:
			$S3 clr_t bold=1;
			$S3 clr_t dim=2;
			$S3 clr_t italic=3;
			$S3 clr_t under_line=4;
			$S3 clr_t blink=5;
			$S3 clr_t invisible=8;
			$S3 clr_t strike_through=9;
			$S3 clr_t under_line_bold=21;
			$S3 clr_t fg=38;
			$S3 clr_t bg=48;
			$S3 clr_t over_line=53;
		};
		struct rgb{
			$UI(8) r;
			$UI(8) g;
			$UI(8) b;
			$UI(8) a=255;

			/**
			 * @brief null constructor(black clr.).
			 * 
			 */
			rgb():r(0),g(0),b(0){}
			/**
			 * @brief set 'rgb' to clr..
			 * 
			 */
			rgb($UI(8) r2,$UI(8) g2,$UI(8) b2):r(r2),g(g2),b(b2){}
			/**
			 * @brief 'rgb' set from 8 bit clr..
			 * 
			 * @param clr 8 bit clr..
			 * 
			 */
			rgb(clr_t clr){
				(*this)=(*get_rgb(clr));
			}
			template<typename A>rgb* operator +($C3 vector<A>* v1) const {
				return new rgb(r+v1->x,g+v1->y,b+v1->z);
			}
			template<typename A>rgb* operator -($C3 vector<A>* v1) const {
				return new rgb(r-v1->x,g-v1->y,b-v1->z);
			}
			template<typename A>rgb* operator *($C3 vector<A>* v1) const {
				return new rgb(r*v1->x,g*v1->y,b*v1->z);
			}
			template<typename A>rgb* operator /($C3 vector<A>* v1) const {
				return new rgb(($I)(r/v1->x),($I)(g/v1->y),($I)(b/v1->z));
			}
			template<typename A>rgb* operator =($C3 vector<A>* v1) const {
				return new rgb(v1->x,v1->y,v1->z);
			}
			rgb* operator &(rgb* clr){
				return new rgb(r&clr->r,g&clr->g,b&clr->b);
			}
			rgb* operator |($C3 rgb* clr) const {
				return new rgb(r|clr->r,g|clr->g,b|clr->b);
			}
			rgb* operator ^(rgb* clr) const {
				return new rgb(r^clr->r,g^clr->g,b^clr->b);
			}
			template<typename A>operator vector<A>*() const {
				return new vector<A>((A)r,(A)g,(A)b);
			}
			operator $I() const {
				return (r<<16)|(g<<0)|(b<<8);
			}
			operator $I*() const {
				return new int[3]{r,g,b};
			}
			operator $S() const {
				return 	get_ui("rgb",this)+"("+
					get_ui(to_string(r),red3)+","+
					get_ui(to_string(g),green3)+","+
					get_ui(to_string(b),blue3)+")";
			}
			/**
			 * @brief get lerping of clr..
			 * 
			 * @link https://www.alanzucconi.com/2016/01/06/colour-interpolation/
			 * 
			 */
			color::rgb* get_lerp($C3 color::rgb* a1,$CI percent=100){
				vector<>* b1=*(vector<>*)*a1-(vector<>*)*this;
				vector<$F>* b2=*(vector<$F>*)*b1*math::get_percent(percent);
				color::rgb* b3=*this+b2;
				return b3;
			}
		};

		$S3 clr_t black=0b0000;
		$S3 clr_t red=0b0001;
		$S3 clr_t orange=0b0001;
		$S3 clr_t yellow=0b0011;
		$S3 clr_t green=0b0010;
		$S3 clr_t blue=0b0100;
		$S3 clr_t indigo=0b0101;
		$S3 clr_t violet=0b1101;
		$S3 clr_t white=0b1111;

		$S3 clr_t grey=0b1000;
		$S3 clr_t cyan=0b1110;
		$S3 clr_t magenta=0b1101;

		$S3 clr_t black2=16;
		$S3 clr_t red2=196;
		$S3 clr_t orange2=208;
		$S3 clr_t yellow2=226;
		$S3 clr_t green2=46;
		$S3 clr_t blue2=21;
		$S3 clr_t indigo2=90;
		$S3 clr_t violet2=201;
		$S3 clr_t white2=231;

		$S3 clr_t grey2=59;
		$S3 clr_t cyan2=51;
		$S3 clr_t magenta2=201;

		$IS $C3 rgb* black3=new rgb(0x0,0x0,0x0);
		$IS $C3 rgb* red3=new rgb(0xff,0x0,0x0);
		$IS $C3 rgb* orange3=new rgb(0xff,0x88,0x0);
		$IS $C3 rgb* yellow3=new rgb(0xff,0xff,0x0);
		$IS $C3 rgb* green3=new rgb(0x0,0xff,0x0);
		$IS $C3 rgb* blue3=new rgb(0x0,0x0,0xff);
		$IS $C3 rgb* indigo3=new rgb(0x44,0x0,0x88);
		$IS $C3 rgb* violet3=new rgb(0xff,0x88,0xff);
		$IS $C3 rgb* white3=new rgb(0xff,0xff,0xff);

		$IS $C3 rgb* grey3=new rgb(0xf0,0xf0,0xf0);
		$IS $C3 rgb* cyan3=new rgb(0x0,0xff,0xff);
		$IS $C3 rgb* magenta3=new rgb(0xff,0x0,0xff);

		$IS $CS begin2="\33[";
		$IS $CS end2="\33[0m";

		/**
		 * @brief get 24 bit clr. from 8 bit clr..
		 * @link https://gist.github.com/jasonm23/2868981
		 * 
		 * @param clr 8 bit clr..
		 * 
		 * @return 24 bit clr..
		 */
		$IS $I get_24_bit(color::clr_t clr){
			$CI b1=clr-16;
			$CI multiplier=0x33;
			$CI r=((b1/36)*multiplier);
			$CI b=(((b1%36)/6)*multiplier);
			$CI g=((b1%6)*multiplier);

			return (r<<16)+(g<<8)+(b<<0);
		}
		/**
		 * @brief get rgb val. from 24 bit clr..
		 * 
		 * @param clr 24 bit clr..
		 * 
		 * @return rgb val..
		 */
		$IS color::rgb* get_rgb($CI clr){
			color::clr_t r=(clr>>16)&0xff;
			color::clr_t b=(clr>>8)&0xff;
			color::clr_t g=(clr>>0)&0xff;

			return new color::rgb(r,g,b);
		}
		/**
		 * @brief get 8 bit val from 24 bit.
		 * 
		 * @param clr 24 bit clr..
		 * 
		 * @return 8 bit clr..
		 */
		$IS clr_t get_8_bit($CI clr){
			$CI multiplier=0x33;
			rgb* b1=*get_rgb(clr)/new vector<>(multiplier,multiplier,multiplier);

			return 16+(36*b1->r)+(6*b1->g)+b1->b;
		}
		/**
		 * @brief get 4 bit val from 24 bit.
		 * 
		 * @param clr 24 bit clr..
		 * 
		 * @return 4 bit clr..
		 */
		$IS clr_t get_4_bit($CI clr){
			rgb* b1=get_rgb(clr);

			return (b1->r>>7)|((b1->g>>7)<<1)|((b1->b>>7)<<2);
		}
		$IS $S get_ui($CS text,clr_t type=type::fg,clr_t color=white){
			string b1="";

			if(type==type::fg||type==type::bg){b1=begin2+to_string(type)+";5;"+to_string(color)+"m"+text+end2;}
			else{b1=begin2+to_string(type)+"m"+text+end2;}

			return b1;
		}
		$IS $S get_ui($CS text,$C3 rgb* color=black3,clr_t type=type::fg){
			string b1="";

			if(type==type::fg||type==type::bg){b1=begin2+to_string(type)+";2;"+to_string(color->r)+";"+to_string(color->g)+";"+to_string(color->b)+"m"+text+end2;}
			else{b1=begin2+to_string(type)+"m"+text+end2;}

			return b1;
		}
	};
};
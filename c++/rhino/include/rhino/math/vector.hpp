//badger
#pragma once

#include <rhino/define/get/basic.h>
#include <rhino/define/get/math.h>
#include <rhino/define/type.h>
#include "./math.h"

namespace rhino{
	template<class A=int>struct vector{
	private:
		$S get_string(){
			$S b1=	"vector("+
				to_string(x)+","+
				to_string(y)+","+
				to_string(z)+")";

			return b1;
		}
	public:
		A x=0;
		A y=0;
		A z=0;

		vector(A x2=0,A y2=0,A z2=0):x(x2),y(y2),z(z2){}
		friend ostream& operator<<(ostream &out,vector v){out<<v.get_string();return out;}
		operator $S(){return get_string();}
		vector<A>* operator +(vector<A>* v) const {return new vector<A>(x+v->x,y+v->y,z+v->z);}
		vector<A>* operator -(vector<A>* v) const {return new vector<A>(x-v->x,y-v->y,z-v->z);}
		vector<A>* operator *(vector<A>* v) const {return new vector<A>(x*v->x,y*v->y,z*v->z);}
		vector<A>* operator /(vector<A>* v) const {return new vector<A>(x/v->x,y/v->y,z/v->z);}
		A& operator [](int index) const {
			switch(index){
				case(0):return x;break;
				case(1):return y;break;
				case(2):return z;break;
				default:return x;break;
			}
		}
		template<typename B>operator vector<B>*(){
			return new vector<B>((B)x,(B)y,(B)z);
		}
		A get_distance_1d(vector<A>* v){return math::get_abs_val(x-v->x);}
		A get_distance_2d(vector<A>* v){
			A x2=pow(x-v->x,2);
			A y2=pow(y-v->y,2);
			A b1=sqrt(x2+y2);

			return b1;
		}
		vector<A>* get_mid_pt(vector<A>* v){
			A x2=(x+v->x)/2;
			A y2=(y+v->y)/2;
			vector<A>* b1=new vector<A>(x2,y2);

			return b1;
		}
		virtual ~vector(){}
	};
};
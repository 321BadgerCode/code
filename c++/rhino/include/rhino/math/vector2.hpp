//badger
#pragma once

#include "./math.hpp"
#include <rhino/define/get/basic.h>
#include <rhino/define/get/math.h>
#include <rhino/define/type.h>

namespace rhino{
	template<class A=int>struct vector{
	private:
		$S get_string();
	public:
		A x=0;
		A y=0;
		A z=0;

		vector(A x2=0,A y2=0,A z2=0):x(x2),y(y2),z(z2);
		friend ostream& operator<<(ostream &out,vector v);
		operator $S();
		vector<A>* operator +(vector<A>* v);
		vector<A>* operator -(vector<A>* v);
		vector<A>* operator *(vector<A>* v);
		vector<A>* operator /(vector<A>* v);
		A& operator [](int index);
		template<typename B>operator vector<B>*();
		A get_distance_1d(vector<A>* v);
		A get_distance_2d(vector<A>* v);
		vector<A>* get_mid_pt(vector<A>* v);
		virtual ~vector();
	};
};
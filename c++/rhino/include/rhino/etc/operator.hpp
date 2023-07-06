//badger
#pragma once

namespace rhino{
	template<class A,typename B=int,typename C=int>struct op_obj{
	public:
		typedef A (*f)(const B,const C);
		B left;
		C right;
		f func;

		op_obj<A,B,C>(f func2):func(func2){}
		A get();
	};

	template<typename A,typename B=op_obj<A>>B operator<(const A& left,B& obj);
	template<typename A,typename B>B operator>(A obj,const B& right);
};
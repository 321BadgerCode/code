//badger
#pragma once

#include "./operator.hpp"
#include <rhino/define/get/basic.h>
#include <rhino/define/etc.h>
#include <rhino/define/type.h>

namespace rhino{
	template<typename A,typename B,typename C>A op_obj<A,B,C>::get(){
		return func(left,right);
	}

	template<typename A,typename B=op_obj<A>>B operator<(const A& left,B& obj){
		obj.left=left;

		return obj;
	}
	template<typename A,typename B>B operator>(A obj,const B& right){
		obj.right=right;

		return obj.get();
	}

	$OPERATOR(add,int,int,int){$I b1=left+right;return b1;}
	/*$OPERATOR(max,int,int a1,int* right){
		int b1=0;

		for(int a=0;a<sizeof(right);a++){
			if(a<sizeof(right)-1){//[10,20,30]=>3
				b1=right[a]>right[a+1]?right[a]:right[a+1];
			}
		}

		return b1;
	}*/
	/*const $DEF_S $OPERATOR(add,$I,$I a1,$I a2){$I b1=a1+a2;return b1;}
	const $DEF_S $OPERATOR(subtract,$I,$I a1,$I a2){$I b1=a1-a2;return b1;}
	const $DEF_S $OPERATOR(multiply,$I,$I a1,$I a2){$I b1=a1*a2;return b1;}
	const $DEF_S $OPERATOR(divide,$I,$I a1,$I a2){$I b1=a1/a2;return b1;}

	const $DEF_S $OPERATOR(average,int,int a1,int a2){int x=(a1+a2)/2;return x;}
	const $DEF_S $OPERATOR(percent,$I,$I a1,$I a2){$I b1=(a1*100)/a2;return b1;}
	const $DEF_S $OPERATOR(power,$I,$I a1,$I exp){$I b1=pow(a1,exp);return b1;}*/
};
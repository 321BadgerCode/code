//badger
#pragma once

#include "./vector.hpp"
#include <rhino/define/get/basic.h>
#include <rhino/define/type.h>

namespace rhino{
	class math{
	public:
		template<typename A=float>$IS constexpr A pi=A(3.1415926535897932385L);

		/**
		 * @brief return inverse square root of 'a1'.
		 * 
		 * @tparam A arg. type.
		 * 
		 * @param a1 #.
		 */
		template<typename A=float>$IS A get_inverse_sq_root(const A a1);
		/**
		 * @brief return absolute value of 'a1'.
		 * 
		 * @tparam A arg. type.
		 * 
		 * @param a1 #.
		 */
		template<typename A=float>$IS A get_abs_val(const A a1);
		/**
		 * @brief return length of 'a1'.
		 * 
		 * @tparam A argument type.
		 * 
		 * @param a1 inputted array/list.
		 * 
		 * @return length of 'a1'.
		 * 
		 * TODO: does comment work?
		 */
		template<typename A=int>$IS A get_len(const A a1[]);
		/**
		 * @brief return sum.
		 * 
		 * @tparam A argument type.
		 * 
		 * @param a1 array.
		 */
		template<typename A=int>$IS A get_sum(const A a1[]);
		/**
		 * @brief return average.
		 * 
		 * @tparam A arg. type.
		 * 
		 * @param a1 list.
		 */
		template<typename A=int>$IS A get_avg($C3 A a1[]);
		$IS vector<$F>* get_percent($CI percent);
	};
};
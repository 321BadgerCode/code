//badger
#pragma once

#include <rhino/define/get/basic.h>
#include <rhino/define/type.h>

namespace rhino{
	/**
	 * @brief array w/ += operator overload.
	 * @author
	 * 
	 * @see {rhino}
	 * @link 
	 * 
	 * @ref <array>
	 * 
	 * TODO: add constructor, so usr. can init. obj. 2 specify elem..
	 * 
	 * @tparam A type of val. stored in array.
	 * @tparam SIZE # of elem. stored in array.
	 */
	template<typename A,size_t SIZE>
	$DEF_S array2:public array<A,SIZE>{
	public:
		typedef const A& CONST_TYPE;
		typename _AT_Type::_Type ELEM;

		/**
		 * @brief append val. 2 array.
		 * 
		 * @param right val. 2 be stored after last elem..
		 * @return constexpr CONST_TYPE val.
		 */
		constexpr CONST_TYPE operator +=(const A right) const noexcept {
			return _AT_Type::_S_ref(ELEM,SIZE+1);
		}
	};
};
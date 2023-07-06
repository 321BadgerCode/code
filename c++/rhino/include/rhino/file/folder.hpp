//badger
#pragma once

namespace rhino{
	class folder{
	public:
		$IS $S folder2="";

		$IS $V create();
		$IS $B exist();
		$IS $S get_path($CS folder3=folder2);
		$IS $S get_current_path();
	};
};
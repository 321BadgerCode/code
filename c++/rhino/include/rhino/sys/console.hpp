//badger
#pragma once

#include <rhino/math/vector.h>
#include <rhino/ui/color.h>

namespace rhino{
	class console{
	public:
		console($CS title=get_title());
		struct text{
		public:
			$S a="";
			$I fg=color::white;
			$I bg=color::black;

			$S get_ui();
		};
		class size{
		public:
			$IS vector<int>* default2=new vector<int>(30,120);
			$IS vector<int>* full_screen=new vector<int>(51,172);

			template<typename A>$IS vector<A>* get();
		};
		$TYPE(TYPE) $IS $V print(TYPE text);
		$IS $V print(text* a1);
		$TYPE(TYPE) $IS $V echo(TYPE text);
		$IS $V echo(text* a1);
		$TYPE(TYPE) $IS $V error(TYPE text,$CB endl2=true);
		$IS $S get_input($CS text);
		$IS $S get_input(text* a1);
		$IS $S get_type();
		$IS $S get_title();
		$IS $V set_title($CS text=get_title());
		$IS $V pause($CS a1="[._.]: press any key to continue...");
		$IS $V clear();
		$IS $V wait();
		$IS $V leave();
		$IS $V start($CS name);
		$IS $S get_cmd_out($CS cmd);
	};
};
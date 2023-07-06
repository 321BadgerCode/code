//badger
#pragma once

#include <rhino/define/get/basic.h>
#include <rhino/define/type.h>
#include <rhino/sys/console.h>

namespace rhino{
	class info{
	public:
		class device{
		public:
			enum os{win32,win64,mac,linux2,free_bsd,unix2,null};
			$IS $CS name=console::get_cmd_out("echo -n \"$(hostname)\"");
			$IS $CS win322="windows 32-bit";
			$IS $CS win642="windows 64-bit";
			$IS $CS mac2="mac O.S.X.";
			$IS $CS linux22="linux";
			$IS $CS free_bsd2="freeB.S.D.";
			$IS $CS unix22="unix";
			$IS $CS null2="null";

			$IS os get_os();
			$IS $S get_os(os a1);
		};
		$DEF_C user{
		public:
			$IS $CS name=console::get_cmd_out("echo -n \"$USER\"");
		};
	};
};
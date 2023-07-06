//badger
#include <iostream>
#include <string>
#include <cstring>
#include <cassert>

using namespace std;

template<typename A=float>A get_pow(const A base,const int pow=2){
	if(pow!=0){return (base*get_pow(base,pow-1));}
	else{return 1;}
}
template<typename A=float>A get_abs(const A n1){
	return n1<0?-n1:n1;
}
template<typename A=float>bool get_approx(const A n1,const A n2,const float range=10){
	return (get_abs(n1-n2))<=range;
}
template<typename A>short int get_len(A a1[]){
	A a=a1[0];
	int b=0;
	while(!a.empty()){a=a1[b];b++;}
	return b-1;
}
short int get_len(string a1){
	return a1.length();
}
template<typename A=float>A get_avg(const A nums[]){
	A sum=0;
	int len=get_len(nums);
	for(int a=0;a<len;a++){
		sum+=nums[a];
	}
	return sum/len;
}
string get_replace(const string txt,const string find,const string replace){
	string result=txt;

	for(int i=0;i<txt.length();i++){
		if(txt[i]==find[0]){
			for(int j=0;j<find.length();j++){
				result[i+j]=replace[j];
			}
		}
	}

	return result;
}
string get_reverse(const string a1){
	string ans="";
	for(int a=get_len(a1)-1;a>=0;a--){
		ans+=a1[a];
	}
	return ans;
}
unsigned int get_digits(const unsigned int num,const unsigned int base=2){
	unsigned int n1=num;
	unsigned int digits=1;
	while(n1>0){
		n1/=base;
		digits++;
	}
	return digits;
}
string get_base(const unsigned int num,const unsigned short int base=2,unsigned short int digits=NULL){
	if(digits==NULL){digits=get_digits(num,base);}
	unsigned int n1=num;
	char* hex_digits="0123456789abcdef";

	string ans;
	for(int a=0;a<digits;a++){
		ans+=base==16?hex_digits[n1%base]:(n1%base)+'0';
		n1/=base;
	}

	return get_reverse(ans);
}
string get_sub_str(const string txt,const uint8_t start,const uint8_t end){
	string ans="";
	for(int a=start;a<end;a++){ans+=txt[a];}
	return ans;
}

namespace clr{
	typedef uint8_t rgbi_t;
	typedef uint8_t rgb_t;

	enum type{	bold=1,
			dim=2,
			italic=3,
			under_line=4,
			blink=5,
			invisible=8,
			strike_through=9,
			under_line_bold=21,
			fg=38,
			bg=48,
			over_line=53};

	static string begin2="\33[";
	static string end2=begin2+"0m";

	static const rgbi_t black=0b0000;
	static const rgbi_t grey=0b0111;
	static const rgbi_t white=0b1111;
	static const rgbi_t red=0b1001;
	static const rgbi_t orange=0b1011;
	static const rgbi_t yellow=0b0011;
	static const rgbi_t green=0b1010;
	static const rgbi_t blue=0b1100;
	static const rgbi_t indigo=0b1101;
	static const rgbi_t violet=0b0101;
	static const rgbi_t cyan=0b1110;
	static const rgbi_t magenta=0b1101;

	rgbi_t basic[3]={black,grey,white};
	rgbi_t roygbiv[7]={red,orange,yellow,green,blue,indigo,violet};
	rgbi_t cmyk[3]={cyan,magenta,yellow};
	rgbi_t clrs[12]={black,grey,white,red,orange,yellow,green,blue,indigo,violet,cyan,magenta};

	static string basic2[3]={"black","grey","white"};
	static string roygbiv2[7]={"red","orange","yellow","green","blue","indigo","violet"};
	static string cmyk2[3]={"cyan","magenta","yellow"};
	static string clrs2[12]={"black","grey","white","red","orange","yellow","green","blue","indigo","violet","cyan","magenta"};

	struct rgb;
	static string get_clr(string txt,const rgbi_t clr,type type2=type::fg);
	static string get_clr(string txt,const rgb clr,type type2=type::fg);
	static string get_clr(string txt,const rgb start,const rgb end,type type2=type::fg);
	static string get_clr(string txt,rgb clr[],type type2=type::fg);

	struct rgb{
		rgb_t r=0;
		rgb_t g=0;
		rgb_t b=0;
		float a=1;

		rgb(rgb_t r2=0,rgb_t g2=0,rgb_t b2=0,float a2=1):r(r2),g(g2),b(b2),a(a2){}
		rgb(rgb& rgb2):r(rgb2.r),g(rgb2.g),b(rgb2.b),a(rgb2.a){}
		rgb& operator *() const;
		rgb* operator ->() const;
		bool get_approx_clr(const rgb rgb2,const int range=10) const {
			return get_approx((*this)().r,rgb2.r,range)&&get_approx((*this)().g,rgb2.g,range)&&get_approx((*this)().b,rgb2.b,range);
		}
		string get_name(){
			string name="rgb";

			for(int a=0;a<sizeof(clrs)/sizeof(rgb);a++){
				name=get_approx_clr(clrs[a])?clrs2[a]:name;
			}

			return clr::get_clr(name,*this);
		}
		operator string(){
			return 	get_name()+
				"("+clr::get_clr(to_string(r),red)+","+
				clr::get_clr(to_string(g),green)+","+
				clr::get_clr(to_string(b),blue)+","+
				clr::get_clr(to_string(a),grey)+")";
		}
		operator string*() const {
			return new string[3]{get_base(r,16,2),get_base(g,16,2),get_base(b,16,2)};
		}
		operator int*() const {
			return new int[3]{r,g,b};
		}
		int operator [](int index) const {
			return ((int*)*this)[index];
		}
		int operator >>(int bits) const {
			if(bits%3!=0){return -1;}
			rgb rgb2={(*this).r>>(8-(bits/3)),(*this).g>>(8-(bits/3)),(*this).b>>(8-(bits/3))};
			return (rgb2.r<<((bits/3)*2))|(rgb2.g<<((bits/3)*1))|(rgb2.b<<((bits/3)*0));
		}
		operator int(){
			return (*this)>>24;
		}
		operator rgbi_t(){
			return (~(*this)>>3)+((int)a<<3);
		}
		operator bool(){
			return (*this)!=*new rgb();
		}
		rgb operator ()() const {
			rgb rgb2=(*this)*a;rgb2.a=1;
			return rgb2;
		}
		rgb operator ~(){
			return rgb(b,g,r,a);
		}
		rgb operator &(const rgb clr) const {
			return rgb(r&clr.r,g&clr.g,b&clr.b,a);
		}
		rgb operator |(const rgb clr) const {
			return rgb(r|clr.r,g|clr.g,b|clr.b,a);
		}
		rgb operator ^(const rgb clr) const {
			return rgb(r^clr.r,g^clr.g,b^clr.b,a);
		}
		rgb operator +(const rgb& rgb2) const {
			rgb rgb3=((*this)())/2;rgb rgb4=rgb2()/2;
			return rgb(rgb3.r+rgb4.r,rgb3.g+rgb4.g,rgb3.b+rgb4.b,a);
		}
		rgb operator -(const rgb& rgb2) const {
			rgb rgb3=(*this)();
			return rgb(rgb3.r-rgb2.r,rgb3.g-rgb2.g,rgb3.b-rgb2.b,a);
		}
		rgb operator *(const float scalar) const {
			return rgb(r*scalar,g*scalar,b*scalar,a);
		}
		rgb operator /(const float scalar) const {
			return rgb(r/scalar,g/scalar,b/scalar,a);
		}
		bool operator <(const rgb& rgb2) const {
			return 	r<rgb2.r||(r==rgb2.r&&g<rgb2.g)||
				(r==rgb2.r&&g==rgb2.g&&b<rgb2.b);
		}
		bool operator >(const rgb& rgb2) const {
			return rgb2<*this;
		}
		bool operator <=(const rgb& rgb2) const {
			return !(rgb2<*this);
		}
		bool operator >=(const rgb& rgb2) const {
			return !(*this<rgb2);
		}
		bool operator ==(const rgb& rgb2){
			return (r==rgb2.r)&&(g==rgb2.g)&&(b==rgb2.b);
		}
		bool operator !=(const rgb& rgb2){
			return !(*this==rgb2);
		}
		friend bool operator ==(const rgb& rgb2,const int clr){
			return (rgb2.r==clr)&&(rgb2.g==clr)&&(rgb2.b==clr);
		}
		friend bool operator !=(const rgb& rgb2,const int clr){
			return !(rgb2==clr);
		}
		friend ostream& operator <<(ostream& os,rgb& rgb2){
			os<<(string)rgb2;
			return os;
		}
		//TODO: make `begin` & `end` so can do `for(rgb a:clr_arr){...}`.
			//-might involve needing to somehow fix `sizeof(clr_arr)` returing 8 & `sizeof(clr_arr[0])` returning 8 as well.
		//friend rgb* begin(rgb array[]){return array;}
		//friend rgb* end(rgb array[]){cout<<sizeof(array)/sizeof(array[0])<<endl;return array[sizeof(array)/sizeof(array[0])];}
		//friend rgb* end(rgb array[]){cout<<(string)array[11]<<endl;return array[11];}
		//TODO: overload cast for size_t to return # of elements in array.
		/*friend operator size_t(const rgb rgb2[]){
			size_t b1=0;
			while(!(*rgb2[b1])){b1++;}
			return b1;
		}*/
		rgb get_lerp(const rgb rgb2,const float unit_interval=1) const {
			return ((*this)()*(1-unit_interval))|(rgb2()*unit_interval);
		}

		static rgb black;
		static rgb grey;
		static rgb white;
		static rgb red;
		static rgb orange;
		static rgb yellow;
		static rgb green;
		static rgb blue;
		static rgb indigo;
		static rgb violet;
		static rgb cyan;
		static rgb magenta;

		static rgb basic[3];
		static rgb roygbiv[7];
		static rgb cmyk[3];
		static rgb clrs[12];
	};

	rgb rgb::black={0x00,0x00,0x00};
	rgb rgb::grey={0x80,0x80,0x80};
	rgb rgb::white={0xff,0xff,0xff};
	rgb rgb::red={0xff,0x00,0x00};
	rgb rgb::orange={0xff,0x80,0x00};
	rgb rgb::yellow={0xff,0xff,0x00};
	rgb rgb::green={0x00,0xff,0x00};
	rgb rgb::blue={0x00,0x00,0xff};
	rgb rgb::indigo={0x40,0x00,0x80};
	rgb rgb::violet={0x80,0x00,0xff};
	rgb rgb::cyan={0x0,0xff,0xff};
	rgb rgb::magenta={0xff,0x0,0xff};

	rgb rgb::basic[]={black,grey,white};
	rgb rgb::roygbiv[]={red,orange,yellow,green,blue,indigo,violet};
	rgb rgb::cmyk[]={cyan,magenta,yellow};
	rgb rgb::clrs[]={black,grey,white,red,orange,yellow,green,blue,indigo,violet,cyan,magenta};

	static string get_clr(string txt,const rgbi_t clr,type type2){
		string ans=begin2+to_string((int)type2);
		if(type2==type::fg||type2==type::bg){ans+=";5;"+to_string(clr);}
		return ans+"m"+txt+end2;
	}
	static string get_clr(string txt,const rgb clr,type type2){
		string ans=begin2+to_string((int)type2);
		if(type2==type::fg||type2==type::bg){ans+=";2;"+to_string(clr().r)+";"+to_string(clr().g)+";"+to_string(clr().b);}
		return ans+"m"+txt+end2;
	}
	static string get_clr(string txt,const rgb start,const rgb end,type type2){
		short int len=get_len(txt);
		string ans="";
		for(int a=0;a<len;a++){
			ans+=get_clr(*new string(1,txt[a]),start().get_lerp(end(),(float)a/len),type2);
		}
		return ans;
	}
	//TODO: fix `get_clr` for interpolating between consecutive clr. in a list.
	/*static string get_clr(string txt,rgb clr[],type type2){
		short int len=get_len(txt);
		//short int len2=0;for(rgb a:clr){len2++;}
		short int len2=sizeof(clr)/sizeof(rgb);
		cout<<len2<<endl;
		string ans="";
		for(int a=1;a<len2;a++){
			string b1=get_sub_str(txt,(a-1)*(len/len2),a*(len/len2));
			//cout<<(a-1)*(len/len2)<<endl<<a*(len/len2)<<endl<<b1<<endl;
			ans+=get_clr(b1,clr[a-1],clr[a],type2);
		}
		return ans;
	}*/
	static rgb get_rgb(rgbi_t clr){
		rgb_t r=(clr&0b0001)==0b0001?255:0;
		rgb_t g=(clr&0b0010)==0b0010?255:0;
		rgb_t b=(clr&0b0100)==0b0100?255:0;
		float a=(clr&0b1000)==0b1000?1:.5;

		return rgb(r,g,b,a);
	}
	//TODO: `get_avg` func. to get avg. of `rgb` arr..
		//-get sum of rgb arr., return sum divided by arr. size.
};

namespace console{
	static string get_cmd_out(const string cmd);
};

namespace info{
	class user{
	public:
		inline static const string name=console::get_cmd_out("echo -n \"$USER\"");
	};
	class file{
	public:
		static string get_current_path(){return console::get_cmd_out("echo -n \"$PWD\"");}
		static string get_path(const string folder=get_current_path()){return get_replace(folder,"/home/"+info::user::name,"~");}
	};
	class device{
	public:
		enum os{win32,win64,mac,linux2,free_bsd,unix2};
		inline static const string os2[]={"windows 32-bit","windows 64-bit","mac OSX","linux","freeBSD","unix"};
		inline static const string name=console::get_cmd_out("echo -n \"$(hostname)\"");

		static os get_os_enum(){
			#ifdef _WIN32
				return os::win32;
			#elif _WIN64
				return os::win64;
			#elif __APPLE__ || __MACH__
				return os::mac;
			#elif __linux__
				return os::linux2;
			#elif __FreeBSD__
				return os::free_bsd;
			#elif __unix || __unix__
				return os::unix2;
			#endif
		}
		static string get_os(const os os_enum){
			string ans="null";
			for(int a=0;a<sizeof(os2)/sizeof(os2[0]);a++){a==(int)os_enum?ans=os2[a]:ans=ans;}
			return ans;
		}
	};
};

namespace console{
	template<typename A>static void print(A a1,const char end2='\n'){
		cout<<a1<<end2;
	}
	static void print(string a1[],const char end2='\n'){
		string ans="{";
		for(int a=0;a<get_len(a1);a++){
			ans+=a<get_len(a1)-1?a1[a]+",":a1[a];
		}
		cout<<ans+"}"<<end2;
	}
	static void print(clr::rgbi_t clr,const char end2='\n'){
		const string bin=get_base(clr,2,4);
		cout<<	clr::get_clr(string(1,bin[0]),clr::grey)+
			clr::get_clr(string(1,bin[1]),clr::blue)+
			clr::get_clr(string(1,bin[2]),clr::green)+
			clr::get_clr(string(1,bin[3]),clr::red)<<end2;
	}
	static void print(bool a1,const char end2='\n'){
		cout<<(a1?"true":"false")<<end2;
	}
	static string get_input(const string a1){string b1="";cout<<a1;getline(cin,b1);return b1;}
	static string get_type(){string b1=getenv("TERM");return b1;}
	static string get_title(){return info::user::name+"@"+info::device::name+": "+info::file::get_path();}
	static void set_title(const string text=get_title()){cout<<"\033]0;"<<text<<"\007";}
	static void pause(const string a1="press any key to continue..."){const string b1="read -rp \""+a1+"\" a1";system(b1.c_str());}
	static void clear(){system("clear");}
	static void wait(){cin.get();}
	static void leave(){exit(0);}
	static void run(const string a1){system(a1.c_str());}
	static string get_cmd_out(const string cmd){
		char buffer[128];
		string result="";

		FILE* pipe=popen(cmd.c_str(),"r");

		if(pipe){
			while(!feof(pipe)){
				if(fgets(buffer,128,pipe)!=NULL){result+=buffer;}
			}

			pclose(pipe);
		}

		return result;
	}
};

int main(int argc,char** argv){
	console::print(info::device::os2[(int)info::device::get_os_enum()]+" terminal type: "+console::get_type());
	//abt. clr. sys..
	console::print("rgbi(4 bit) format(it's inverted so it's ibgr):\n\tred=0b0001\n\tgreen=0b0010\n\tblue=0b0100\n\tintensity(alpha/opacity)=0b1000\n");
	console::print("rgb(8 bits per rgb value):\n\tred=rgb(0xff,0,0)\n\tgreen=rgb(0,0xff,0)\n\tblue=rgb(0,0,0xff)\n\talpha=0-1(it's a unit interval)\n");

	//std. clr..
	for(clr::rgb a:clr::rgb::clrs){
		console::print((string)a);
	}

	console::print("");

	for(int a=0;a<sizeof(clr::clrs)/sizeof(clr::rgbi_t);a++){
		console::print(clr::get_clr(clr::clrs2[a],clr::clrs[a])+"=0b",'\0');
		console::print(clr::clrs[a]);
	}

	console::print("");

	//test.
	console::print("black+white="+(string)(clr::rgb::black+clr::rgb::white));
	console::print("black+white(.5 opacity)="+(string)(clr::rgb::black+*new clr::rgb(255,255,255,.5)));
	console::print("rgbi grey as rgb: "+(string)clr::get_rgb(clr::grey));
	console::print("rgb red as rgbi: "+clr::get_clr("0b"+get_base((clr::rgbi_t)clr::rgb::red,2,4),(clr::rgbi_t)clr::rgb::red));
	console::print("rgb red(.5 opacity) as rgbi: "+clr::get_clr("0b"+get_base((clr::rgbi_t)*new clr::rgb(255,0,0,.5),2,4),(clr::rgbi_t)*new clr::rgb(255,0,0,.5)));
	console::print("rgb red in hex: ",'\0');
	console::print((string*)clr::rgb::red);

	//clr. lerp.
	for(float a=0;a<1+.1;a+=.1){
		console::print((string)(clr::rgb::red.get_lerp(clr::rgb::green,a)));
	}
	console::print(clr::get_clr("this is a test. baked potatoes r da best fruit!!!!!!!!! :)",clr::rgb::red,clr::rgb::green));
	//console::print(clr::get_clr("test",clr::rgb::clrs));

	return 0;
}
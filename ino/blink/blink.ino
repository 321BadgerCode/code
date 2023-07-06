//badger
struct vector{
	vector(int x2,int y2,int z2){
		x=x2;
		y=y2;
		z=z2;
	}

	int x=0;
	int y=0;
	int z=0;
};
class console{
public:
	console(int baud=9600){
		Serial.begin(baud);
	}
	template<typename A>inline static void print(A a1){
		Serial.println(a1);
	}
	inline static void wait(float a1=1){
		delay(a1*1000);
	}
};
class device{
public:
	device(int led=LED_BUILTIN,int out=OUTPUT){
		pinMode(led,out);
	}
	inline static void set_led(int led=LED_BUILTIN,int voltage=HIGH){
		digitalWrite(led,voltage);
	}
	inline static void set_led(vector* v){
		set_led(v->x,v->y);
	}
};

namespace val{
	int reset=5;
	int led=LED_BUILTIN;
}

void setup(){
	console* con=new console();
	device* dev=new device();
}
void loop(){
	for(int a=0;a<=val::reset;a++){
		console::print(a);

		device::set_led();console::wait();
		device::set_led(LOW);console::wait();
	}

	console::wait(val::reset);
}

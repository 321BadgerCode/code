template<typename A>unsigned int get_mem_val(A* ptr){
	return get_abs(*reinterpret_cast<int*>(ptr));
}
//TODO: make seed more complex than just 8 bits(`return get_mem_val(seed);`).
//TODO: change `count` using https://en.wikipedia.org/wiki/Linear_congruential_generator
uint8_t get_seed(const uint8_t start=0,const uint8_t variation=1){
	static uint8_t count=0;
	//uint8_t* seed=(uint8_t*)malloc(count*sizeof(uint8_t));
	uint8_t* seed=new uint8_t(start)+count;
	cout<<seed<<endl;
	cout<<(float)get_mem_val(seed)/INT32_MAX<<endl;
	*seed=*(seed+variation)-*seed;
	count++;
	return *seed;
}
unsigned short int get_num(unsigned short int min=1,unsigned short int max=100,uint8_t seed=NULL){
	if(seed==NULL){seed=get_seed();}

	float ans=0;
	ans=((float)(seed%0xff))/0xff;
	ans=ans*(max-min);
	ans+=min;

	return ans;
}
//TODO: https://math.stackexchange.com/questions/8318/how-are-the-taps-of-an-lfsr-found
/*int get_taps(int state){
	int taps=0;
	for(int i=0;i<state;i++){
		if((state>>i)&1){taps++;}
	}
	return taps;
}*/
//TODO: implement taps for LFSR.
int get_lfsr(int state,int len=100/*,int taps=NULL*/){
	//if(taps==NULL){taps=get_taps(state);}
	int new_state=state;
	int ans=0;

	for(int a=0;a<len;a++){
		int new_bit=(new_state^(new_state>>1))&1;
		ans+=new_bit;
		new_state=(new_state>>1)|(new_bit<<3);
	}

	return ans;
}
//https://en.wikipedia.org/wiki/Linear-feedback_shift_register
unsigned lfsr_fib(void){
	uint16_t start_state=0xace1u;
	uint16_t lfsr=start_state;
	uint16_t bit;
	unsigned period=0;

	do{
		bit=((lfsr>>0)^(lfsr>>2)^(lfsr>>3)^(lfsr>>5))&1u;
		lfsr=(lfsr>>1)|(bit<<15);
		++period;
	}while(lfsr!=start_state);

	return period;
}
unsigned lfsr_galois(void){
	uint16_t start_state=0xACE1u;
	uint16_t lfsr=start_state;
	unsigned period=0;

	do{
		unsigned lsb=lfsr&1u;
		lfsr>>=1;
		if(lsb){lfsr^=0xB400u;}
		++period;
	}while (lfsr != start_state);

	return period;
}
//https://en.wikipedia.org/wiki/Xorshift
uint32_t xorshift32(const uint32_t state){
	uint32_t x=state;
	x^=x<<13;
	x^=x>>17;
	x^=x<<5;
	return x;
}

int main(int argc,char** argv){
	/*console::print((int)get_num());
	console::print((int)get_num());
	console::print((int)get_num(1,1000));
	console::print((int)get_num());
	console::print((int)get_lfsr(0b1001));
	console::print((int)get_num(1,100,get_lfsr(0b1001)));
	console::print((int)get_num(1,100,get_seed(1,10)));
	console::print((int)get_num(1,100,get_mem_val(new char*("hello world :)"))));*/

	return 0;
}

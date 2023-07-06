//badger
#include <rhino/math/random.h>
#include <rhino/secure/main.h>
#include <rhino/type/stack.h>

using namespace rhino;

bool is_prime(int a1){
	if(a1==1||a1==0){return false;}
 
	for(int a=2;a<a1;a++){
		if(a1%a==0){return false;}
	}

	return true;
}
stack2<int> get_prime(int min,int max){
	stack2<int> b1;

	for(int a=min;a<max;a++){
		if(is_prime(a)==true){b1.push(a);}
	}

	return b1;
}
int get_msg(const string a1){
	int b1=0;

	for(int a=0;a<a1.size();a++){
		b1+=static_cast<int>(a1[a])%a;
	}

	return b1;
}
string get_msg(const int a1){
	string b1="";

	for(int a=0;a<a1;a++){
		b1+=static_cast<char>(a1%a);
	}

	return b1;
}

int main(){
	string msg="hello world!";
	int public_key=2;

	/*stack2<int> p1=get_prime(1,random2::get_random(1,25));
	int p=p1.c[random2::get_random(0,sizeof(p1))];
	int q=p1.c[random2::get_random(0,sizeof(p1))];*/
	int p=3;
	int q=7;

	int k=2;

	rsa* r1=new rsa(get_msg(msg),public_key,p,q,k);

	cout<<"msg="<<r1->msg<<endl;
	cout<<"e="<<r1->public_key<<endl;
	cout<<"d="<<r1->private_key<<endl;
	cout<<"encrypted data="<<r1->c<<endl;
	cout<<"msg. sent="<<get_msg(r1->m)<<endl;

	return 0;
}














/*int main(){
	//2 random prime numbers
	double p=3;
	double q=7;
	double n=p*q;
	double count=0;
	double totient=(p-1)*(q-1);

	//public key
	//e stands for encrypt
	double e=2;

	//for checking co-prime which satisfies e>1
	while(e<totient){
		count=get_gcd(e,totient);
		if(count==1){break;}
		else{e++;}
	}

	//private key
	//d stands for decrypt
	double d=0;

	//k can be any arbitrary value
	double k=2;

	//choosing d such that it satisfies d*e=1 + k * totient
	d=(1+(k*totient))/e;
	double msg=12;
	double c=pow(msg,e);
	double m=pow(c,d);
	c=fmod(c,n);
	m=fmod(m,n);

	cout<<"msg. data="<<msg<<endl;
	cout<<"p="<<p<<endl;
	cout<<"q="<<q<<endl;
	cout<<"n=pq="<<n<<endl;
	cout<<"totient="<<totient<<endl;
	cout<<"e="<<e<<endl;
	cout<<"d="<<d<<endl;
	cout<<"encrypted data="<<c<<endl;
	cout<<"msg. sent="<<m<<endl;

	return 0;
}




fn get_totient(p:i32,q:i32)->i32{
	return (p-1)*(q-1);
}
fn get_private_key(private_key:i32,totient:i32)->i32{
	let mut private_key2:i32=private_key;
	let mut count:i32=0;

	while private_key2<totient{
		count=get_gcd(private_key2,totient);

		if count==1{break;}
		else{private_key2+=1;}
	}

	return private_key2;
}
fn get_msg(msg:String,key:i32,coef:i32)->i32{
	let mut b1:i32=0;

	for a in 0..msg.len(){
		let letter:char=get_letter(msg.to_owned(),a as i32);
		let val:i32=get_val(letter);

		b1+=val;
	}

	return b1/coef;
}
fn get_asymmetric_encrypt(msg:i32,k:i32,totient:i32,private_key:i32,n:i32,coef:i32)->[i32;2]{
	let d:i32=(1+(k*totient))/private_key;
	let c:i32=msg.pow(private_key as u32)/coef;
	let m:i32=c.pow(d as u32)/coef;
	println!("{}",d);
	println!("{}",c);
	println!("{}",m);
	println!("{}",c%n);

	let mut b1:[i32;2]=[0;2];
	b1[0]=c%n;
	b1[1]=m%n;

	return b1;
}*/
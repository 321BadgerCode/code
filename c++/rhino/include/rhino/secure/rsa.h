//badger
#pragma once

#include <rhino/define/get/basic.h>
#include <rhino/define/get/math.h>
#include <rhino/define/type.h>

namespace rhino{
	$DEF_C rsa{
	private:
		int n=0;
		int count=0;
		int totient=0;

		int get_gcd(int totient2){
			int temp=0;

			while(true){
				temp=public_key%totient2;

				if(temp==0){return totient2;}

				public_key=totient2;
				totient2=temp;
			}
		}
		int get_n(){return p*q;}
		int get_totient(){
			int b1=(p-1)*(q-1);

			return get_gcd(b1);
		}
		int get_private_key(){
			return (1+(k*totient))/public_key;
		}
		int get_c(){int b1=pow(msg,public_key);return fmod(c,n);}
		int get_m(){int b1=pow(c,private_key);return fmod(m,n);}
	public:
		int msg=0;
		int public_key=0;
		int p=0;
		int q=0;
		int k=0;

		int private_key=0;
		int c=0;
		int m=0;

		rsa(int msg2,int public_key2,int p2,int q2,int k2):msg(msg2),public_key(public_key2),p(p2),q(q2),k(k2){
			n=get_n();
			totient=get_totient();
			private_key=get_private_key();
			c=get_c();
			m=get_m();
		}
	};
};
//badger
#include <iostream>//basic
#include <math.h>//math

using namespace std;

int get_sum(const string a1){
	int sum=0;

	for(size_t a=0;a<a1.length();a++){
		sum+=a1[a]+static_cast<int>(a1[a]*pow(2,a));
	}

	return sum;
}

string get_encrypt(const string a1,const int key){
	string b1="";

	for(int a=0;a<a1.size();a++){
		b1+=static_cast<char>(static_cast<int>((a1[a%key])^key));
	}

	return b1;
}

int main(){
	string msg;
	cout<<"message: ";
	getline(cin,msg);

	string pass;
	cout<<"password: ";
	cin>>pass;

	int key=get_sum(pass);

	string encrypt=get_encrypt(msg,key);

	cout<<"encrypted: "+encrypt<<endl;

	string pass2;
	cout<<"password: ";
	cin>>pass2;

	int key2=get_sum(pass2);

	string decrypt=get_encrypt(encrypt,key2);

	cout<<"decrypted: "+decrypt<<endl;

	system("pause");

	return 0;
}
//https://www.tutorialspoint.com/cryptography/public_key_encryption.htm
//https://phemex.com/academy/what-is-symmetric-key-encryption#:~:text=%20Symmetric%20key%20encryption%20has%20two%20main%20advantages%3A,relatively%20short%20length.%20As%20a%20result%2C...%20More%20
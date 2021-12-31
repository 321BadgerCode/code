//badger
#include <iostream>
#include <cmath>
using namespace std;

float inverse_sqrt(float a1){
long b1;
float b2,b3;
b2=a1*.5f;
b3=a1;
b1=*(long*)&b3;
b1=0x5f3759df-(b1>>1);
b3=*(float*)&b1;
b3=b3*(1.5f-(b2*b3*b3));
return b3;
}

int main(){
cout<<inverse_sqrt(5)<<endl;
cout<<1/sqrt(5)<<endl;
system("pause");
return 0;
}
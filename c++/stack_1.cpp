//badger
#include <iostream>//basic
#include <fstream>//file

using namespace std;

int main(){
	//set file name
	string file="";
	cout<<"file name: ";
	cin>>file;

	//create/write to file
	ofstream out_file;
	out_file.open(file);
	out_file<<"test 1\ntest 2\ntest 3";
	out_file.close();

	//read file
	ifstream in_file;
	in_file.open(file);

	string line;

	cin.ignore();//clear buffer

	while(getline(in_file,line)){
		cout<<line;
		cin.get();
	}

	in_file.close();

	system("pause");

	return 0;
}
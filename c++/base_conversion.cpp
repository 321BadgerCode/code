// Badger
#include <iostream>
#include <cmath>

using namespace std;

#define CLR(clr, txt) "\033[" + clr + "m" + txt + "\033[0m"

int red = 31;
int orange = 33;
int yellow = 33;
int green = 32;
int blue = 34;
int indigo = 35;
int violet = 35;
int white = 37;
int black = 30;

string getClr(string txt, int clr = white){
	return CLR(to_string(clr), txt);
}

int getBase10(string num, int base) {
	int base10 = 0;
	int j = 0;
	for (int i = num.length() - 1; i >= 0; i--) {
		if (num[i] >= '0' && num[i] <= '9') {
			base10 += (num[i] - '0') * pow(base, j);
		}
		else if (num[i] >= 'A' && num[i] <= 'F') {
			base10 += (num[i] - 'A' + 10) * pow(base, j);
		}
		j++;
	}
	return base10;
}
string getBase(int num, int base) {
	string digits = "0123456789ABCDEF";
	string base_num = "";
	int j = 0;
	while (num != 0) {
		base_num = digits[num % base] + base_num;
		num /= base;
		j++;
	}
	return base_num;
}
string getPrefix(int base) {
	switch (base) {
		case 2: return "0b";
		case 8: return "0";
		case 16: return "0x";
		default: return "";
	}
}
string getNum(string num, int base, int newBase, bool prefix = false) {
	int base10 = getBase10(num, base);
	return prefix ? getPrefix(newBase) + getBase(base10, newBase) : getBase(base10, newBase);
}
int getLength(string arr[]){
	int ans = 0;
	while(arr[ans] != ""){
		ans++;
	}
	return ans;
}
int getLength(string txt, int tab = 8){
	int count=0;
	int pos=0;
	for(char c:txt){
		if(c=='\t'){
			int spaces=tab-(pos%tab);
			count+=spaces;
			pos+=spaces;
		}
		else{
			count++;
			pos++;
		}
		if(c=='\n'){
			pos=0;
		}
	}
	return count;
}
string makeTable(string header[], string row[], string col[]){
	// Make header
	string header2 = "";
	for(int i = 0;i < getLength(header);i++){
		header2 += "|\t" + header[i] + "\t";
	}
	header2 += "|";
	// Variables
	string ans;
	int maxRow = getLength(header2) - 10;
	// Top border
	ans += "|";
	for(int i = 0;i < maxRow;i++){
		ans += "-";
	}
	ans += "|\n";
	// Header
	ans += header2 + "\n";
	// Body
	for(int i = 0;i < getLength(row);i++){
		ans += "|\t" + row[i] + "\t";
	}
	ans += "|\n";
	// Bottom border
	ans += "|";
	for(int i = 0;i < maxRow;i++){
		ans += "-";
	}
	ans += "|\n";
	return ans;
}
string table(string num, int base){
	if(base != 10 && getPrefix(base) == ""){return "";}
	int base2[4] = {2, 8, 10, 16};
	string header[5] = {"BIN", "OCT", "DEC", "HEX", ""};
	for(int i = 0;i < 5;i++){
		header[i] = base2[i] == base ? getClr(header[i], black + i) : header[i];
	}
	string row[5] = {getNum(num, base, 2, 1), getNum(num, base, 8, 1), getNum(num, base, 10, 1), getNum(num, base, 16, 1), ""};
	for(int i = 0;i < 5;i++){
		row[i] = base2[i] == base ? getClr(row[i], black + i) : row[i];
	}
	string ans = "Base Conversion Table For " + getClr(getPrefix(base) + num, red) + "(base " + getClr(to_string(base), black + base) + ")\n";
	ans += makeTable(header, row, header);
	return ans;
}

int main() {
	string num;
	int base1, base2;
	cout << "Enter a number: ";
	cin >> num;
	for (int i = 0; i < num.length(); i++) {
		num[i] = toupper(num[i]);
	}
	cout << "Enter the base of the number: ";
	cin >> base1;
	cout << "Enter the base to convert to: ";
	cin >> base2;
	string newNum = getNum(num, base1, base2);
	cout << getClr(num, red) << "(base " << getClr(to_string(base1), indigo) << ") => " << getClr(newNum, green) << "(base " << getClr(to_string(base2), yellow) << ")" << endl;
	cout << endl << table(num, base1) << endl;
	cout << table(newNum, base2) << endl;
	return 0;
}
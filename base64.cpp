#include <iostream>
#include <string>
#include <iomanip>
#include <cmath>
using namespace std;

void process_three(string data, short index){
	char table[64] = {'=','B','C','D','E','F','G','H','I','J','K',
		'L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z',
		'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o',
		'p','q','r','s','t','u','v','w','x','y','z','0','1','2','3',
		'4','5','6','7','8','9','+','/'};
	short num;
	char binary[8*3];
	for(int n = 1; n <= 3; n++){
		num = (short)data[index + n-1];
		for(int i = 1; i <= 8; i++){
			binary[n*8-i] = num % 2;
			num /= 2;
		}
	}
	short sextets[4];
	for(int i = 0; i < 4; i++){
		short sextet = 0;
		for(int j = 0; j <= 5; j++){
			if((int)binary[i*6+j] == 1){
				sextet += pow(2, 6-j-1);
			}
		}
		sextets[i] = sextet;
	}
	for(int i = 0; i < 4; i++){
		cout << table[(int)sextets[i]];
	}
}

int main(){
	cout << "Enter the data : ";
	string data;
	getline(cin, data);
	short length = data.length();
	while(length % 3 != 0){
		data += '\0';
		length = data.length();
	}
	for(short i = 0; i < length / 3; i++){
		process_three(data, i*3);
	}
	return 0;
}
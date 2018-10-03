#include <iostream>
using namespace std;

int findSqrt(int num){
	int start = 0;
	int end = num;
	int mid;
	while(end >= start){
		mid = (end - start) / 2 + start;
		int tst = mid * mid;
		if(tst == num){
			return mid;
		}
		if(tst < num){
			// mid is low
			start = mid+1;
		} else {
			// mid is high
			end = mid-1;
		}
	}
	return mid;
}

int main(){
	cout << "Enter a number : ";
	int num;
	cin >> num;
	cout << findSqrt(num);
	return 0;
}
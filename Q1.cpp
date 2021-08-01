#include<iostream>
#include<string.h>

using namespace std;

int main(){
	string n;
	int sum = 0, count = 0;
	long unsigned int i; 
	
	cin >> n;
	
	do{
		sum = 0;
		for(i = 0; i < n.length(); i++){
			sum += int(n[i]) - 48;
		}
		count++;
		n = to_string(sum);
//		cout << "Sum: " << sum << endl << "n: " << n << endl << endl;
	} while(sum >=10);
	
	cout << count;
}

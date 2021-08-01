#include<iostream>

using namespace std;

int main(){
	int i, j, n, count = 0, p = 1;
	
	cin >> n;
	
	for(i = 2; i <= n; i++){
		p = 1;
		for(j = 2; j <= i/2; j++){
			if(i % j == 0){
				p = 0;
				break;
			}
		}
		if(p == 1){
			count++;
		}
	}
	
//	cout << "Count: "<< count << endl; 
	cout << ((count) * (count + 1)) / 2;
}

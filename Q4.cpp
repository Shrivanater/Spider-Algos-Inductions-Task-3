#include<iostream>

using namespace std;

const int N = 1e5 + 1;
int k, n;

bool check(int mid, int arr[], int k){
        int total = 0;
        int sub_array = 0;
        
        for(int i = 0; i < n; i++){
            if(total + arr[i] <= mid){
                total += arr[i];
            }
          
            else{
                sub_array++;
                total = arr[i];
            }
        }
        
        sub_array++;
        return(sub_array <= k);
    }
    
int solve(int arr[], int k) {
        int l = 0;
        int r = (int)(1e14 + 1);
        
        while(l < r){
            int mid = (l + r)/2;
            
            if(check(mid, arr, k)){
                r = mid;
            }
            
            else{
				l = mid + 1;
			}             
        }
        return l;
    }           

int main(){
	int i;
	int arr[N];
	
	cin >> k >> n;
	
	for(i = 0; i < n; i++){
		cin >> arr[i];
	}
	
	cout << solve(arr, k);
}

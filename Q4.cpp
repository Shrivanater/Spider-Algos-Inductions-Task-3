#include<iostream>
#include<vector>

using namespace std;

const int N = 1e5 + 1;
int k, n;

class Solution {
public:
    
    bool check(long long int mid, int arr[], int m){
        long long int total = 0;
        int sub_array = 0;
        
        for(int i = 0; i < n; i++){
            if(arr[i] > mid){
                return false;
            }                
                
            if(total + arr[i] <= mid){
                total += arr[i];
            }               
            else{
                sub_array++;
                total = arr[i];
            }
        }
        sub_array++;
        return(sub_array<=m);
    }
    
    long long int solve(int arr[], int m) {
        long long int l = 0;
        long long int r = (long long int)(1e14 + 1);
        
        while(l < r){
            long long int mid = (l + r)/2;
            
            if(check(mid, arr, m)){
                r = mid;
            }                
            else{
                l = mid + 1;
            }              
        }
        return l;
    }
};

int main(){
    int i;
    int arr[N];
    Solution sol;
    
    cin >> k >> n;
    
    for(i = 0; i < n; i++){
        cin >> arr[i];
    }
    
    cout << sol.solve(arr, k);
}

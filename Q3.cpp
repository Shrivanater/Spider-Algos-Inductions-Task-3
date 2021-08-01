#include<iostream>
#include<stdio.h>
#include<vector>

const int M = 1e4;
 
using namespace std;

bool check(vector<long int>& arr, int n, int sum)
{
	long int i, j;
    bool subarr[n + 1][sum + 1];

    for (i = 0; i <= n; i++)
        subarr[i][0] = true;
 
    for (i = 1; i <= sum; i++)
        subarr[0][i] = false;

    for (i = 1; i <= n; i++) {
        for (j = 1; j <= sum; j++) {
            if(j < arr[i - 1])
                subarr[i][j] = subarr[i - 1][j];
                
            else if(j >= arr[i - 1])
            	subarr[i][j] = subarr[i - 1][j] || subarr[i - 1][j - arr[i - 1]];
        }
    }

    return subarr[n][sum];
}

int main()
{
    long int n, m, arraySum = 0, k, a;
    vector<long int> arr;
    
    cin >> n >> m;
    
    for(k = 0; k < m; k++){
    	cin >> a;
		arr.push_back(a);
    	arraySum += a;
	}    
	
    for(k; k > 0; k--){  
	    if (check(arr, m, k) == true){
	    	cout << k;
			break;			    	
		}	
	}
}

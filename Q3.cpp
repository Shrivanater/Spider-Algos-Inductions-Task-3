#include<iostream>
#include<stdio.h>
#include<vector>

const int M = 1e4;
 
using namespace std;

bool check(vector <vector <bool>>& subarr, int n, int sum)
{
 
    return subarr[n][sum];
}

int main()
{
    long int n, m, sum = 0, k, a;
    vector<long int> arr;
    
    cin >> n >> m;
    
    for(k = 0; k < m; k++){
        cin >> a;
        arr.push_back(a);
        sum += a;
    }
    
    long int i, j;
    vector <vector<bool>> subarr(m + 1, vector <bool>(sum + 1, false));
 
    for (i = 0; i <= m; i++)
        subarr[i][0] = true;
 
    for (i = 1; i <= m; i++) {
        for (j = 1; j <= sum; j++) {
            if(j < arr[i - 1])
                subarr[i][j] = subarr[i - 1][j];
                
            else if(j >= arr[i - 1])
                subarr[i][j] = subarr[i - 1][j] || subarr[i - 1][j - arr[i - 1]];
        }
    }
    
    for(k = sum/n; k > 0; k--){  
        if (check(subarr, m, k) == true){
            cout << k;
            break;                    
        }    
    }
}

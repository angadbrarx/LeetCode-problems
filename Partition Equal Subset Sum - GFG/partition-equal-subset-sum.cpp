//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int sumofArray(int N, int arr[]){
        int sum = 0;
        for(int i = 0; i<N; i++){
            sum += arr[i];
        }
        return sum;
    }
    bool solveRec(int index, int arr[], int N, int target){
        //base case
        if(index >= N)
            return 0;
        if(target < 0)
            return 0;
        if(target == 0)
            return 1;
        
        bool include = solveRec(index+1, arr, N, target - arr[index]);
        bool exclude = solveRec(index+1, arr, N, target);
        
        return include or exclude;
    }
    
    bool solveMem(int index, int arr[], int N, int target, vector<vector<int>>&dp){
        if(index >= N)
            return 0;
        if(target < 0)
            return 0;
        if(target == 0)
            return 1;
            
        if(dp[index][target] != -1)
            return dp[index][target];
        
        bool include = solveMem(index+1, arr, N, target - arr[index], dp);
        bool exclude = solveMem(index+1, arr, N, target, dp);
        
        return dp[index][target] = include or exclude;
        
    }
    
    int equalPartition(int N, int arr[])
    {
        int sum = sumofArray(N, arr);
        if(sum % 2 != 0)
            return 0;
        
        int target = sum/2;
           
        //return solveRec(0, arr, N, target);
        
        vector<vector<int>>dp(N+1, vector<int>(target+1, -1));
        return solveMem(0, arr, N, target, dp);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        if(ob.equalPartition(N, arr))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}
// } Driver Code Ends
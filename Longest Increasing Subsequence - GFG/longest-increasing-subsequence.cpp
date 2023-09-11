//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution
{
    public:
    int solveRec(int n, int a[], int curr, int prev){
        //base case
        if(curr == n)
            return 0;
            
        //include (only if it is greater than prev element, but first element will be taken in all cases)
        int include = 0;
        if(prev == -1 || a[curr] > a[prev])
            //prev becomes curr after a[curr] is included
            include = 1 + solveRec(n, a, curr+1, curr);
        
        //exclude
        //prev remains same as a[curr] is not included
        int exclude = 0 + solveRec(n, a, curr+1, prev);
        
        return max(include, exclude);
        
    }
    
    int solveMem(int n, int a[], int curr, int prev, vector<vector<int>> &dp){
        
        //base case
        if(curr == n)
            return 0;
            
        if(dp[curr][prev+1] != -1)
            return dp[curr][prev+1];
        
        //include (only if it is greater than prev element, but first element will be taken in all cases)
        int include = 0;
        if(prev == -1 || a[curr] > a[prev])
            //prev becomes curr after a[curr] is included
            include = 1 + solveMem(n, a, curr+1, curr, dp);
        
        //exclude
        //prev remains same as a[curr] is not included
        int exclude = 0 + solveMem(n, a, curr+1, prev, dp);
        
        //dp[curr][prev+1] as if we return prev, initially prev can be -1 which is not a valid index 
        return dp[curr][prev+1] = max(include, exclude);
    }
    
    int solveTab(int n, int a[]){
        vector<vector<int>>dp(n+1, vector<int>(n+1, 0));
        
        //dp[n] = 0;
        
        for(int curr = n-1; curr>=0; curr--){
            for(int prev = curr-1; prev>=-1; prev--){
                //include (only if it is greater than prev element, but first element will be taken in all cases)
                int include = 0;
                if(prev == -1 || a[curr] > a[prev])
                    //curr+1 to include 
                    include = 1 + dp[curr+1][curr+1];
                
                //exclude
                //prev + 1 as if prev =-1, it is not a valid index
                int exclude = 0 + dp[curr+1][prev+1];
                
                //dp[curr][prev+1] as if we return prev, initially prev can be -1 which is not a valid index 
                dp[curr][prev+1] = max(include, exclude);
            }
            
        }
        return dp[0][-1+1];
    }
    
    int solveSpace(int n, int a[]){
        vector<int>curr(n+1, 0);
        vector<int>next(n+1, 0);
        
        for(int i = n-1; i>=0; i--){
            for(int j = i-1; j>=-1; j--){
                //include (only if it is greater than prev element, but first element will be taken in all cases)
                int include = 0;
                if(j == -1 || a[i] > a[j])
                    //curr+1 to include 
                    include = 1 + next[i+1];
                
                //exclude
                //prev + 1 as if prev =-1, it is not a valid index
                int exclude = 0 + next[j+1];
                
                //dp[curr][prev+1] as if we return prev, initially prev can be -1 which is not a valid index 
                curr[j+1] = max(include, exclude);
            }
            next = curr;
        }
        return next[-1+1];
    }
    
    //---------Using binary search-----------
    int solveOptimal(int n, int a[]){
        if(n == 0)
            return 0;
            
        vector<int>ans;
        
        //store first element
        ans.push_back(a[0]);
        for(int i = 1; i<n; i++){
            if(a[i] > ans.back())
                ans.push_back(a[i]);
            else{
                //find index of element just bigger and replace
                int index = lower_bound(ans.begin(), ans.end(), a[i]) - ans.begin();
                ans[index] = a[i];
            }
        }
        return ans.size();
    }
    
    
    
    //Function to find length of longest increasing subsequence.
    int longestSubsequence(int n, int a[])
    {
       //return solveRec(n, a, 0, -1);
       
        // vector<vector<int>>dp(n, vector<int>(n+1, -1));
        // return solveMem(n, a, 0, -1, dp);
        
        // return solveTab(n, a);
        
        //return solveSpace(n, a);
        
        return solveOptimal(n, a);
    }
};

//{ Driver Code Starts.
int main()
{
    //taking total testcases
    int t,n;
    cin>>t;
    while(t--)
    {
        //taking size of array
        cin>>n;
        int a[n];
        
        //inserting elements to the array
        for(int i=0;i<n;i++)
            cin>>a[i];
        Solution ob;
        //calling method longestSubsequence()
        cout << ob.longestSubsequence(n, a) << endl;
    }
}

// } Driver Code Ends
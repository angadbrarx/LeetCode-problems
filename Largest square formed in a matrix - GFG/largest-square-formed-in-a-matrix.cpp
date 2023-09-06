//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:

    // int solveRec(vector<vector<int>> mat, int i, int j, int &maxi){
    //     //base case
    //     if(i >= mat.size() || j >= mat[0].size())
    //         return 0;   //i and j gone out of limit 
        
    //     int right = solveRec(mat, i, j+1, maxi);
    //     int diagonal = solveRec(mat, i+1, j+1, maxi);
    //     int down = solveRec(mat, i+1, j, maxi);
        
    //     if(mat[i][j] == 1){
    //         int ans = 1 + min(right, min(diagonal, down));
    //         maxi = max(maxi, ans);
    //         return ans;
    //     }
    //     else
    //         return 0;

    // }
    
    int solveMem(vector<vector<int>> &mat, int i, int j, int &maximum, vector<vector<int>> &dp){
        //base case
        if(i >= mat.size() || j >= mat[0].size())
            return 0;   //i and j gone out of limit 
        
        if(dp[i][j] != -1)
            return dp[i][j];
        
        
        int right = solveMem(mat, i, j+1, maximum, dp);
        int diagonal = solveMem(mat, i+1, j+1, maximum, dp);
        int down = solveMem(mat, i+1, j, maximum, dp);
        
        if(mat[i][j] == 1){
            dp[i][j] = 1 + min(right, min(diagonal, down));
            maximum = max(maximum, dp[i][j]);
            return dp[i][j];
        }
        else
            return dp[i][j] = 0;
    }
    
    int solveTab(vector<vector<int>> &mat, int &maximum){
        
        int row = mat.size();
        int col = mat[0].size();
        
        vector< vector<int> >dp(row + 1, vector<int>(col + 1, 0));
        
        for(int i = row-1; i>=0; i--){
            for(int j = col-1; j>=0; j--){
                int right = dp[i][j+1];
                int diagonal = dp[i+1][j+1];
                int down = dp[i+1][j];
                
                 
                if(mat[i][j] == 1){
                    dp[i][j] = 1 + min(right, min(diagonal, down));
                    maximum = max(maximum, dp[i][j]);
                  
                }
                else
                  dp[i][j] = 0;
            }
        }
        return dp[0][0];
        
    }
    
    int solveSpace(vector< vector<int>> &mat, int &maximum){
        
        int row = mat.size();
        int col = mat[0].size();
        
        vector<int>curr(col+1, 0);
        vector<int>next(col+1, 0);
        
        for(int i = row-1; i>=0; i--){
            for(int j = col-1; j>=0; j--){
                int right = curr[j+1];
                int diagonal = next[j+1];
                int down = next[j];
                
                 
                if(mat[i][j] == 1){
                    curr[j] = 1 + min(right, min(diagonal, down));
                    maximum = max(maximum,curr[j]);
                  
                }
                else
                  curr[j] = 0;
            }
            next = curr;
            
        }
        
        return next[0];
    }
    
    int solveSpace2(vector<vector<int>> &mat, int n, int m){
        int maxi = 0;
        for(int i = n-1; i>=0; i--){
            for(int j = m-1; j>=0; j--){
                int down = 0;
                int diag = 0;
                int right = 0;
                
                if(i < n-1)
                    down = mat[i+1][j];
                else
                    down = 0;
                
                if(j < m-1)
                    right = mat[i][j+1];
                else
                    right = 0;
                
                if(i < n-1 && j < m-1)
                    diag = mat[i+1][j+1];
                else
                    diag = 0;
                
                if(mat[i][j] == 1){
                    mat[i][j] = 1 + min(down, min(right, diag));
                    maxi = max(maxi, mat[i][j]);
                }
                
            }
        }
        
        return maxi;
        
    }
    
    int maxSquare(int n, int m, vector<vector<int>> mat){
        // int maxi = 0;
        // solveRec(mat, 0, 0, maxi);
        // return maxi;
        
        // vector<vector<int>>dp(n+1, vector<int>(m+1, -1));
        // int maximum = 0;
        // solveMem(mat, 0, 0, maximum, dp);
        // return maximum;
        
    //     int maximum = 0;
    //     solveTab(mat, maximum);
    //     return maximum;
    
            // int maximum = 0;
            // solveSpace(mat, maximum);
            // return maximum;
            
            return solveSpace2(mat, n, m);
    
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<int>> mat(n, vector<int>(m, 0));
        for(int i = 0;i < n*m;i++)
            cin>>mat[i/m][i%m];
        
        Solution ob;
        cout<<ob.maxSquare(n, m, mat)<<"\n";
    }
    return 0;
}
// } Driver Code Ends
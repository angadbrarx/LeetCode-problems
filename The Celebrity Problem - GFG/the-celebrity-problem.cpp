//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution 
{
    public:
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& M, int n) 
    {
        stack<int>s;
        
        //step1 - push all elements in stack
        for(int i = 0; i< n; i++){
            s.push(i);
        }
        
        //step2 - pop 2 by 2 to check who knows who
        int a = 0, b = 0;
        while(s.size() > 1){
            a = s.top();
            s.pop();
            
            b = s.top();
            s.pop();
            
        
            if(M[a][b] == 1)    //a knows b
            {
                //a can't be celebrity, push b back into stack
                s.push(b);
            }    
            else
                s.push(a);
            
        }
        //single element remaining in stack
            // verify potential celebrity
        int candidate = s.top();
        
        //check rows
        bool rowCheck = false;
        int zeroCount = 0;
        
        for(int i = 0; i<n; i++){
            if(M[candidate][i] == 0)
                zeroCount++;
        }
        if(zeroCount == n)
            rowCheck = true;
            
        //check col
        bool colCheck = false;
        int oneCount = 0;
        
        for(int i = 0; i < n; i++){
            if(M[i][candidate] == 1)
                oneCount++;
        }
        if(oneCount == n-1 && M[candidate][candidate]== 0 )
            colCheck = true;
            
        if(rowCheck == true && colCheck == true)
            return candidate;
        else
            return -1;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<vector<int> > M( n , vector<int> (n, 0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cin>>M[i][j];
            }
        }
        Solution ob;
        cout<<ob.celebrity(M,n)<<endl;

    }
}

// } Driver Code Ends
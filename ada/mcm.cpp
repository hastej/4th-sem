#include <bits/stdc++.h>
using namespace std;
int dp[100][100];
int kk[100][100];

void display(int n){
    cout<<endl;

    for(int i =1;i<n;i++){
        for(int j =1;j<n;j++){
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
}
 
void display2(int n){
    cout<<endl;

    for(int i =1;i<n;i++){
        for(int j =1;j<n;j++){
            cout<<kk[i][j]<<" ";
        }
        cout<<endl;
    }
}

// Function for matrix chain multiplication
int matrixChainMemoised(int* p, int i, int j)
{
    if (i == j)
    {
        return 0;
    }
    if (dp[i][j] != -1)
    {
        return dp[i][j];
    }
    dp[i][j] = INT_MAX;
    int prev = dp[i][j];
    for (int k = i; k < j; k++)
    {   
        

        dp[i][j] = min(
            dp[i][j], matrixChainMemoised(p, i, k)
                     + matrixChainMemoised(p, k + 1, j)
                       + p[i - 1] * p[k] * p[j]);

        if(dp[i][j]!=prev){
            kk[i][j] = k;
        }
    }
    return dp[i][j];
}
int MatrixChainOrder(int* p, int n)
{
    int i = 1, j = n - 1;
    return matrixChainMemoised(p, i, j);
}
 
// Driver Code
int main()
{
    int arr[] = {3, 2, 4, 2, 5 };
    int n = sizeof(arr) / sizeof(arr[0]);
    memset(dp, -1, sizeof dp);
 
    cout << "Minimum number of multiplications is "
         << MatrixChainOrder(arr, n);

    display(n);
    display2(n);
}
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int dp[101][101][101];

int main(){
    string a, b, c;
    cin >> a >> b>> c;
    int n = a.length(), m=b.length(), l=c.length();
    
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            for (int k=1; k<=l; k++)
            {
                if(a[i-1]==b[j-1] && b[j-1]==c[k-1])
                    dp[i][j][k]=dp[i-1][j-1][k-1]+1;
                else{
                    dp[i][j][k]=max(dp[i-1][j][k], max(dp[i][j-1][k], dp[i][j][k-1]));
                }
            }        
        }
    } cout<<dp[n][m][l];
        
        
        
}
#include<bits/stdc++.h>
using namespace std;

int solve( vector<int>& dp, vector<int>& heights, int k, int n) {
    if( n == 0 ) return 0;

    if( dp[n] != -1) return dp[n];

    int mmSteps = INT_MAX;

    for( int j = 1; j <= k; j++) {
        if( n-j >= 0) {
            int jump = solve( dp, heights, k, n-j) + abs(heights[n]-heights[n-j]);
            mmSteps = min( mmSteps, jump);
        } 
    }
    return dp[n] = mmSteps;
}

int main(){

  vector<int> height{40, 10, 20, 70, 80, 10, 20, 70, 80, 60};
  int n=height.size();
  int k=4;
  vector<int> dp(n,-1);
  cout<<solve(dp, height, k, n-1);

    return 0;
}
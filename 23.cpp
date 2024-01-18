# include <iostream>
# include <vector>
# include <unordered_map>
# include <math.h>

using namespace std;

unordered_map<int, long long> dp;

void sol(){
  int n; cin >> n;

  long long sum = 0;
  for(int i=1; i<n; i++){
    if(dp[i] > i and dp[n-i] > (n-i)) {cout << "YES" << endl; return;};
  }

  cout << "NO" << endl;
  // cout << dp[220] << endl;
}

int main() {
 
  for(int i=1; i<=100000; i++){
    long long divisorSum = 0;
    for(int div=1; div<=sqrt(i); div++){
      if(i % div == 0) {
        divisorSum += div;
        int quotient = i / div;

        if(div != quotient and quotient != i) divisorSum += quotient; 
      }
    }
    dp[i] = divisorSum;
  }

  int t = 1;
  
  cin >> t;

  while(t--)
  sol();
  
  return 0;
}
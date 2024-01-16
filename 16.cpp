# include <iostream>
# include <unordered_map>
# include <queue>
# include <chrono>
# include <algorithm>

using namespace std;
using namespace chrono;

// for add very long number stored in reverse or of digits in a vector
vector<int> operator+(vector<int> l1, vector<int> l2){
  
  if(l1.size() == 0) return l2;
  if(l2.size() == 0) return l1;

  if(l1.size() < l2.size()){
    l1.swap(l2);
  }

  int carry = 0;
  for(int i=0; i<l1.size(); i++){
    int num = l1[i] + carry;
    if(i < l2.size()) num += l2[i];

    l1[i] = num % 10;
    carry = num / 10;
  }

  if(carry != 0) l1.push_back(carry);

  for(auto l: l1) cout << l << " ";
  cout << endl;

  return l1;
}

// for mul very long number stored in reverse or of digits in a vector
vector<int> operator*(vector<int> l1, vector<int> l2){
  if(l1.size() == 0) return l1;
  if(l2.size() == 0) return l2; 
  

  if(l1.size() < l2.size()){
    l1.swap(l2);
  }
  
  vector<int> prod;
  vector<vector<int> > each_prod;

  for(int j=0; j<l2.size(); j++){
    vector<int> cur;
    int carry = 0;
    for(int z=0; z<j; z++) cur.push_back(0);
    for(int i=0; i<l1.size(); i++){
      
      int num = l1[i] * l2[j] + carry;


      cur.push_back(num % 10);
      carry = num / 10;
      
    }
    if(carry != 0) cur.push_back(carry);

    each_prod.push_back(cur);
  }

  prod = each_prod[0];
  for(int i=1; i<each_prod.size(); i++){
    prod = prod + each_prod[i];
  }

  return prod;

}

unordered_map<int, vector<int> > dp;

void sol(){
  int n; cin >> n;
  int sum = 0;
  for(int i=0; i<dp[n].size(); i++){
    sum += dp[n][i];
  }

  cout << sum << endl;


}

int main() {
  
  high_resolution_clock::time_point t1 = high_resolution_clock::now();
  vector<int> a;
  vector<int> b;
  a.push_back(2);
  b.push_back(2);
  dp[1] = a;
  for(int i=2; i<=10000; i++){
    dp[i] = vector<int>();
    dp[i] = dp[i-1] * b;
  }

  int t = 1;
  
  cin >> t;

  while(t--)
  sol();
  
  high_resolution_clock::time_point t2 = high_resolution_clock::now();

  auto duration = duration_cast<microseconds>( t2 - t1 ).count();

  cout << "Program run time: " << duration / 1000000.0 << " seconds" << endl;

  return 0;
}
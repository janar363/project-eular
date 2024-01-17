# include <iostream>
# include <unordered_map>
# include <vector>

using namespace std;

// for add long long numbers
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

  // for(auto l: l1) cout << l << " ";
  // cout << endl;

  return l1;
}

// for mul long long numbers
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

vector<int> load_num(int i){
  vector<int> num;

  while(i){
    num.push_back(i % 10);
    i /= 10;
  }

  return num;
}

/*
  sol start
*/
unordered_map<int, vector<int> > dp;

void sol(){
  int n; cin >> n;

  long long sum = 0;
  for(int i=0; i<dp[n].size(); i++){
    sum += dp[n][i];
  }

  cout << sum << endl;

  
}

int main() {
  
  vector<int> fact;
  fact.push_back(1); 
  dp[0] = fact;

  for(int i=1; i<=1000; i++){
    vector<int> num = load_num(i);
    dp[i] = dp[i-1] * num;
  }

  int t = 1;
  
  cin >> t;

  while(t--)
  sol();
  
  return 0;
}
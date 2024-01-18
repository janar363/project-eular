# include <iostream>
# include <vector>
# include <unordered_map>

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

/*
  sol start
*/

unordered_map<int, long long> ans;

void sol(){
  int n; cin >> n;

  cout << ans[n] << endl;
}

int main() {
  
  vector<int> f1, f2;
  f1.push_back(1);
  f2.push_back(1);
  long long count = 2;
  for(int i=2; i<=5000; i++){
    

    while(f2.size() != i){
      vector<int> next = f1 + f2;
      f1 = f2;
      f2 = next;
      count++;
    }

    ans[i] = count;
  }  


  int t = 1;
  
  cin >> t;

  while(t--)
  sol();

  return 0;
}
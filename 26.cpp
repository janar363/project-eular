# include <iostream>
# include <vector>
# include <unordered_map>
# include <unordered_set>
# include <algorithm>

using namespace std;

/* long long number lib start */

vector<int> load_num(int i){
  vector<int> num;

  while(i){
    num.push_back(i % 10);
    i /= 10;
  }

  return num;

}
/* long long number lib end */

/*
  floating point division
*/

struct FloatNumber {
  vector<int> integer;
  vector<int> decimal;
  int reccur_len=0;
};

FloatNumber floating_point_division(int a, int b){
  FloatNumber f;
  
  f.integer = load_num(a / b);
  reverse(f.integer.begin(), f.integer.end());

  if(a % b == 0){
    f.decimal.push_back(0);
  } else {
    unordered_map<int, int> visited;

    int rem = a % b;
    while(visited[rem] == 0){
      visited[rem] = f.decimal.size();
      
      while(rem != 0 && rem * 10 < b){
        f.decimal.push_back(0);
        rem *= 10;
      }

      f.decimal.push_back(rem * 10 / b);
      rem = rem * 10 % b;
      if(rem == 0) break;
    }

    if(rem != 0) f.reccur_len = f.decimal.size() - visited[rem]; 

  }
  return f;
}

/*
  sol start
*/

unordered_map<int, int> reccur_lens;

void sol(){
  int n; cin >> n;

  int mxL = 0, mnN = 10001;
  for(int i=3; i<n ;i++){
    if(mxL < reccur_lens[i]){
      mnN = i;
      mxL = reccur_lens[i];
    } 
  }

  cout << mnN << endl;
}

int main() {
  for(int i=2; i<=10000; i++){
    FloatNumber f = floating_point_division(1, i);

    reccur_lens[i] = f.reccur_len; 
  }

  int t = 1;
  
  cin >> t;

  while(t--)
  sol();
  
  return 0;
}

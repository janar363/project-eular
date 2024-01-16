# include <iostream>
# include <vector>

using namespace std;

/*
  sol start
*/

void sol(){
  long long n; cin >> n;
  
  vector<int> prev(1), next;
  cin >> prev[0];

  for(int i=1; i<n; i++){
    next.clear();
    for(int j=0; j<=i; j++){
      int num; cin >> num;

      int a = -1, b = -1;
      if(j - 1 >= 0) a = num + prev[j-1];
      if(j < prev.size()) b = num + prev[j];

      next.push_back(max(a, b));
    }
    
    prev = next;
  }
  int mx = 0;
  for(int i=0; i<prev.size(); i++){
    if(mx < prev[i]) mx = prev[i];
  }

  cout << mx << endl;
}

int main() {
  
  int t = 1;
  
  cin >> t;

  while(t--)
  sol();
  
  return 0;
}
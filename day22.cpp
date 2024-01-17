# include <iostream>
# include <vector>
# include <unordered_map>
# include <algorithm>

using namespace std;

void sol(){
  int n; cin >> n;

  vector<string> names(n);
  for(int i=0; i<n; i++) cin >> names[i];
  
  int q; cin >> q;
  vector<string> queries(q);
  for(int i=0; i<q; i++) cin >> queries[i];

  sort(names.begin(), names.end());

  unordered_map<string, long> ans;
  for(int i=0; i<n; i++){
    int word_score = 0;
    for(auto ch: names[i]) word_score += ch - 'A' + 1;

    ans[names[i]] = word_score * (i+1); 
  }
  
  for(auto query: queries) cout << ans[query] << endl;

  
}

int main() {
  
  int t = 1;
  
//   cin >> t;

  while(t--)
  sol();
  
  return 0;
}
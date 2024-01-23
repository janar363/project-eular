# include <iostream>
# include <vector>
# include <unordered_map>
# include <algorithm>
# include "math.h"

using namespace std;

// for custom map
struct KeyHasher {
    size_t operator()(const pair<int, int>& k) const {
        return hash<int>()(k.first) ^ hash<int>()(k.second);    
    }
};

struct KeyEquals { 
    bool operator()(const pair<int, int>& lhs, const pair<int, int>& rhs) const {
    return lhs.first == rhs.first && lhs.second == rhs.second;
    }
};

/* basic math operations start */ 
unordered_map<long long, int> primes;
bool is_prime(int n){
  if(n < 2) return false;
  if(primes[n]) return primes[n];
  for(int i=2; i<=sqrt(n); i++){
    if(n%i==0) return false;
  }
  primes[n] = 1;
  return true;
}

/* basic math operations end */
/*
  sol start
*/

unordered_map<pair<int, int>, int, KeyHasher, KeyEquals> ab_pairs;


void sol(){
  int N; cin >> N;

    for(long long a=1; a<=N; a++){
        for(long long b=2; b<=N; b++){
            if(!primes[b]) continue;
            
            if(a * a - 4 * b < 0){
                long long n=0;
                while(true){
                    if(is_prime(n * n + a * n + b)) n++;
                    else break;
                }

                ab_pairs[make_pair(a, b)] = n;
                n=0;
                while(true){
                    if(is_prime(n * n - a * n + b)) n++;
                    else break;
                }

                ab_pairs[make_pair(-a, b)] = n;
            }
        }
    }
    pair<int, int> ans;
    int mx = 0; 
    for(auto p: ab_pairs){
        if(p.second > mx && p.first.first <= N && p.first.second <= N){
            mx = p.second;
            ans = p.first;
        }
    }

    cout << ans.first << " " << ans.second << endl;

}

int main() {
  
  primes[2] = 1;
  for(int i=3; i<2000; i++){
    if(is_prime(i)) primes[i] = 1; 
  }

  int t = 1;
  

  while(t--)
  sol();

  return 0;
}
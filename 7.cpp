# include <iostream>
# include <chrono>

using namespace std;
using namespace chrono;

vector<long long> primes;

bool is_prime(int n){
  for(int i=2; i<=sqrt(n); i++){
    if(n%i==0) return false;
  }
  return true;
}

void sol(){
  long n; cin >> n;

  if(primes.size() < n){
    for(long i=primes[primes.size()-1] == 2? primes[primes.size()-1]+1:primes[primes.size()-1]+2; primes.size() < n; i+=2){
      if(is_prime(i)) primes.push_back(i);
    }
    
  }

  cout << primes[n-1] << endl;
}

int main() {

  high_resolution_clock::time_point t1 = high_resolution_clock::now();
  int t = 1;
  
  cin >> t;
  primes.push_back(2);
  while(t--)
    sol();
  
  high_resolution_clock::time_point t2 = high_resolution_clock::now();

  auto duration = duration_cast<microseconds>( t2 - t1 ).count();

  cout << "Program run time: " << duration / 1000000.0 << " seconds" << endl;

  return 0;
}
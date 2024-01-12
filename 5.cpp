# include <iostream>
# include <chrono>

using namespace std;
using namespace chrono;

long long gcd(long long a, long long b){
  return a == 0 ? b : gcd(b%a, a);
}

long long lcm(long long a, long long b){
  return a * b / gcd(a, b);
}

void sol(){
  long long n; cin >> n;

  long long LCM = 1;
  for(long long i=2; i<=n; i++){
    LCM = lcm(LCM, i);
  }

  cout << LCM << endl;  
}

int main() {

  high_resolution_clock::time_point t1 = high_resolution_clock::now();
  int t = 1;
  
  cin >> t;

  while(t--)
    sol();
  
  high_resolution_clock::time_point t2 = high_resolution_clock::now();

  auto duration = duration_cast<microseconds>( t2 - t1 ).count();

  cout << "Program run time: " << duration / 1000000.0 << " seconds" << endl;

  return 0;
}
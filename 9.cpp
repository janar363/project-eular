# include <iostream>
# include <chrono>

using namespace std;
using namespace chrono;

void sol(){
  int n; cin >> n;

  long long abc = -1;
  for(long long a = 1; a<n-2; a++){
    long long c = ((n - a) * (n - a) + a * a) / (2 * (n - a));
    if(c > a){
      long long b = n - a - c;

      if(c > b && a*a + b * b == c * c){
        long long prod = a * b * c;
        
        if(prod > abc) abc = prod;
      }
    }
  }

  cout << abc << endl;
  
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
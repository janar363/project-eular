# include <iostream>
# include <chrono>

using namespace std;
using namespace chrono;

void sol(){
  long n; cin >> n;

  cout << (n * (n+1) / 2) * (n * (n+1) / 2) - n * (n+1) * (2*n+1) / 6 << endl;
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
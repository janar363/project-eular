# include <iostream>
# include <chrono>

using namespace std;
using namespace chrono;

bool palindorm(int n){
  int original = n;
  int rev = 0;
  while(n)
    rev = rev * 10 + n % 10, n /= 10;

  return original == rev;
}

bool is_prime(int n){
  for(int i=2; i<=sqrt(n); i++){
    if(n%i==0) return false;
  }
  return true;
}

void sol(){
  int n; cin >> n;

  for(int i=n-1; i>=101101; i--){
    if(!palindorm(i)) continue;
    if(is_prime(i)) continue;

    for(int fact=sqrt(i); fact>=100; fact--){
      if(i % fact == 0 && fact / 100 > 0 && fact / 100 < 10 && i / fact / 100 > 0 && i / fact / 100 < 10){
        cout << i << endl;
        return;
      }
    }

  }
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
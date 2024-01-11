# include <iostream>
# include <chrono>

using namespace std;
using namespace chrono;

void sol(){

}

int main() {

  high_resolution_clock::time_point t1 = high_resolution_clock::now();

  sol();
  
  high_resolution_clock::time_point t2 = high_resolution_clock::now();

  auto duration = duration_cast<microseconds>( t2 - t1 ).count();

  cout << "Program run time: " << duration << " microseconds" << endl;

  return 0;
}
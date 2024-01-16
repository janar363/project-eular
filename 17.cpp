# include <iostream>

using namespace std;

/*
  sol start
*/

void get_string(long long num){

  if(num >= 1000000000000){
    get_string(num / 1000000000000);
    cout << "Trillion ";
    num %= 1000000000000;
  }

  if(num >= 1000000000){
    get_string(num / 1000000000);
    cout << "Billion ";
    num %= 1000000000;
  }

  if(num >= 1000000){
    get_string(num / 1000000);
    cout << "Million ";
    num %= 1000000;
  }

  if(num >= 1000){
    get_string(num / 1000);
    cout << "Thousand ";
    num %= 1000;
  }

  if(num >= 100){
    get_string(num / 100);
    cout << "Hundred ";
    num %= 100;
  }

  if(num >= 90) cout << "Ninety ";
  else if(num >= 80) cout << "Eighty ";
  else if(num >= 70) cout << "Seventy ";
  else if(num >= 60) cout << "Sixty ";
  else if(num >= 50) cout << "Fifty ";
  else if(num >= 40) cout << "Forty ";
  else if(num >= 30) cout << "Thirty ";
  else if(num >= 20) cout << "Twenty ";

  if(num >= 20) num %= 10;

  if(num == 19) cout << "Nineteen ";
  else if(num == 18) cout << "Eighteen ";
  else if(num == 17) cout << "Seventeen ";
  else if(num == 16) cout << "Sixteen ";
  else if(num == 15) cout << "Fifteen ";
  else if(num == 14) cout << "Fourteen ";
  else if(num == 13) cout << "Thirteen ";
  else if(num == 12) cout << "Twelve ";
  else if(num == 11) cout << "Eleven ";
  else if(num == 10) cout << "Ten ";
  else if(num == 9) cout << "Nine ";
  else if(num == 8) cout << "Eight ";
  else if(num == 7) cout << "Seven ";
  else if(num == 6) cout << "Six ";
  else if(num == 5) cout << "Five ";
  else if(num == 4) cout << "Four ";
  else if(num == 3) cout << "Three ";
  else if(num == 2) cout << "Two ";
  else if(num == 1) cout << "One ";

}

void sol(){
  long long n; cin >> n;
  get_string(n);
  cout << endl;
}

int main() {
  int t = 1;
  
  cin >> t;

  while(t--)
  sol();

  return 0;
}
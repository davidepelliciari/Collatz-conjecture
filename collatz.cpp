#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

class Collatz{
public:

  int iter;
  int iteraz;
  vector<int> orbits_x;
  vector<int> orbits_y;
  int very_input;

  int collatz(int input){
  iter = 0;
  while(input > 1){
    if (input % 2 == 0){
      input = input/2;
      iter = iter+1;
    }
    else{
      input = 3*input + 1;
      iter = iter+1;
    }
}
return iter;
}

void collatz_singolo(){
  iteraz = 0;
  while(very_input > 1){
    orbits_x.push_back(iteraz);
    orbits_y.push_back(very_input);
    if (very_input % 2 == 0){
      very_input = very_input/2;
      iteraz = iteraz+1;
    }
    else{
      very_input = 3*very_input + 1;
      iteraz = iteraz+1;
    }
}
if(very_input == 1){
  orbits_x.push_back(iteraz);
  orbits_y.push_back(very_input);
}
}

void get_orbits (int input){
  ofstream out_1("orbits.dat", ios_base::out | ios_base::trunc);
  very_input = input;
  collatz_singolo();
  for(int n = 0; n < orbits_x.size(); n++) {
        out_1 << orbits_x[n] << " " << orbits_y[n] << endl;
    }
        out_1.close();
  }
};

int main(){
int N;
int i;
int num;
int numbiter;

cout << "Scrivi i primi N numeri di cui vuoi sapere le iterazioni per la congettura di Collatz: " << endl;
cin >> N;

ofstream out("collatz.dat", ios_base::out | ios_base::trunc);

Collatz obj;

for(i=2; i<=N; i++){
  numbiter = obj.collatz(i);
  out << i << " " << numbiter << endl;
}
out.close();

cout << "Di quale numeri (4) vuoi consocere le orbite?" << endl;
cin >> num;
obj.get_orbits(num);
return 0;
}

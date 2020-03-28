#include <iostream>
#include <fstream>

using namespace std;

int collatz(int input){
  int iter = 0;
  while(input > 1){
    if (input % 2 == 0){
      input = input/2;
      iter = iter+1;
    }
    else{
      input = 3*input + 1;
    }
}
return(iter);
}

int main(){
int N;
int i;
int numbiter;

cout << "Scrivi i primi N numeri di cui vuoi sapere le iterazioni per la congettura di Collatz" << endl;
cin >> N;

ofstream out("collatz.dat", ios::app);

for(i=1; i<=N; i++){
  numbiter = collatz(i);
  out << i << " " << numbiter << endl;
}
out.close();
return 0;
}

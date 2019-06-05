#include <iostream>
#include <vector>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

using namespace std;

typedef struct Process{
  string name;
  int pid;
  int state; //0 for incomplete and 10 for complete

}Process;

vector<int> inclusion_routine(Process p, vector<int> vector, int clock){
  int last = vector.size() - 1;
  int rand_value;
  srand (time(NULL));

  cout << "Região crítica acessada." << endl;
  if(vector[0] != 0){ cout << "Vetor cheio" << endl; return vector;}
  for (int i = 1; i <= clock; i++) {
    // if(i > 10){
    //   cout << "Clock esgotado!" << endl;
    //
    // }

    rand_value = rand() % 1000+1;

    // vector.push_back(rand_value);
    if(vector[last] == 0){
      vector[last] = rand_value;
    }
    else{
      while(vector[last] != 0){
        // cout << "teste" << endl;
        last--;
      }
      vector[last] = rand_value;
    }

    p.state = i; //For each cycle, state will change and be recorded.
    sleep(1);
    cout << "Processo " << p.name << ": "<< i << " inserção" << endl;
    cout << "Valor: " << rand_value << endl;
  }

  return vector;
}

vector<int> exclusion_routine(Process p, vector<int> vector){
  cout << "Região crítica acessada." << endl;

  for (int i = 1; i <= 10; i++) {
    int last = vector.size();
    cout << "Processo " << p.name << ": "<< i << " remoção" << endl;

    if(vector[last] == 0){
      cout << "Vetor vazio" << endl;
    }
    else{
      while(vector[last-1] != 0){
        // cout << "teste" << endl;
        last--;
      }
      cout << "Valor: " << vector[last] << endl;
      vector[last] = 0;
    }

    p.state = i; //For each cycle, state will change and be recorded.
    sleep(1);
  }

  return vector;
}

void print(vector <int> const &a) {
   cout << "The vector elements are : ";

   for(int i=0; i < a.size(); i++){
     cout << a.at(i) << ' ';
   }
   cout << endl;
}

#include <iostream>
#include <vector>
#include <queue>
#include <stdlib.h>
#include <time.h>
#include "Semaphore.cpp"

using namespace std;

int main() {
  Process p1,p2,p3,p4,p5,p6,p7,p8,p9,p10,Paux;
  queue<Process> blocked_row;
  queue<Process> p_row;
  vector<int> vector;
  int s;

  vector.assign(1000, 0); //1000 int with value of 0

  p1.name = "p1"; p1.pid = 1; p1.state = 0; p_row.push(p1);
  p2.name = "p2"; p2.pid = 2; p2.state = 0; p_row.push(p2);
  p3.name = "p3"; p3.pid = 3; p3.state = 0; p_row.push(p3);
  p4.name = "p4"; p4.pid = 4; p4.state = 0; p_row.push(p4);
  p5.name = "p5"; p5.pid = 5; p5.state = 0; p_row.push(p5);
  p6.name = "p6"; p6.pid = 6; p6.state = 0; p_row.push(p6);
  p7.name = "p7"; p7.pid = 7; p7.state = 0; p_row.push(p7);
  p8.name = "p8"; p8.pid = 8; p8.state = 0; p_row.push(p8);
  p9.name = "p9"; p9.pid = 9; p9.state = 0; p_row.push(p9);
  p10.name = "p10"; p10.pid = 10; p10.state = 0; p_row.push(p10);

  // // p_row.pop(); //When "pop" is used, the front is removed
  //
  // cout << p_row.front().name << endl;
  // cout << p_row.back().name << endl;
  // cout << p_row.size() << endl;

  // vector = inclusion_routine(p1, vector);
  // print(vector);
  // vector = exclusion_routine(p1, vector);
  // print(vector);
  // cout << vector.size();

//Main routine ================================================================
  for (int i = 0; i < 200; i++){
    int rand_value;
    srand (time(NULL));
    rand_value = rand() % 10+1;

    switch (rand_value) {
      case 1:
        vector = inclusion_routine(p1, vector, 10);
        break;
      case 2:
        vector = inclusion_routine(p2, vector, 10);
        break;
      case 3:
        vector = inclusion_routine(p3, vector, 10);
        break;
      case 4:
        vector = inclusion_routine(p4, vector, 10);
        break;
      case 5:
        vector = inclusion_routine(p5, vector, 10);
        break;
      case 6:
        vector = exclusion_routine(p6, vector);
        break;
      case 7:
        vector = exclusion_routine(p7, vector);
        break;
      case 8:
        vector = exclusion_routine(p8, vector);
        break;
      case 9:
        vector = exclusion_routine(p9, vector);
        break;
      case 10:
        vector = exclusion_routine(p10, vector);
        break;
    }
  }
//Main routine ================================================================

  return 0;
}

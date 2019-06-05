#include <iostream>
#include <vector>
#include <queue>
#include <stdlib.h>
#include <time.h>
#include "Process.cpp"

using namespace std;

int main() {
  Process p1,p2,p3,p4,p5,p6,p7,p8,p9,p10;
  queue<Process> blocked_row;
  queue<Process> p_row;
  vector<int> vector;
  int s;

  vector.assign(1000, 0); //1000 int with value of 0

  p1.name = "p1"; p1.pid = 1; p1.state = 0;
  p2.name = "p2"; p2.pid = 2; p2.state = 0;
  p3.name = "p3"; p3.pid = 3; p3.state = 0;
  p4.name = "p4"; p4.pid = 4; p4.state = 0;
  p5.name = "p5"; p5.pid = 5; p5.state = 0;
  p6.name = "p6"; p6.pid = 6; p6.state = 0;
  p7.name = "p7"; p7.pid = 7; p7.state = 0;
  p8.name = "p8"; p8.pid = 8; p8.state = 0;
  p9.name = "p9"; p9.pid = 9; p9.state = 0;
  p10.name = "p10"; p10.pid = 10; p10.state = 0;

  p_row.push(p1);
  p_row.push(p2);
  // // p_row.pop(); //When "pop" is used, the front is removed
  //
  // cout << p_row.front().name << endl;
  // cout << p_row.back().name << endl;
  // cout << p_row.size() << endl;

  vector = inclusion_routine(p1, vector);
  print(vector);
  vector = exclusion_routine(p1, vector);
  print(vector);
  // cout << vector.size();

  return 0;
}

void block(Process p, queue<Process> blocked_row){
  p.state = 0;
  blocked_row.push(p);
}

void down(int s, Process p, queue<Process> blocked_row){
  if(s > 0){
    s--; //Decrement a value on the semaphore
  }
  else{
    block(p, blocked_row);
  }
}

void up(int s, Process p, queue<Process> p_row, queue<Process> blocked_row){
  s++; //Increment a value on the semaphore
  if(!blocked_row.empty()){
    p_row.push(blocked_row.front());
    blocked_row.pop();
  }
}

#include <iostream>
#include <queue>
#include "Process.cpp"

int main() {
  queue<Process> p_row;
  queue<Process> blocked_row;
  int s;
  Process p1,p2,p3,p4,p5,p6,p7,p8,p9,p10;

  p1.name = "p1"; p1.pid = 1; p1.state = 1;
  p_row.push(p1);

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

void up(Process p, queue<Process> p_row, queue<Process> blocked_row){
  s++; //Increment a value on the semaphore
  if(!blocked_row.empty()){
    p_row.push(blocked_row.front());
    blocked_row.pop(); 
  }
}

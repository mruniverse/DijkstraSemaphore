#include <iostream>
#include <vector>
#include <queue>
#include <stdlib.h>
#include <time.h>
#include "Process.cpp"

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

void up(int s, queue<Process> p_row, queue<Process> blocked_row){
  s++; //Increment a value on the semaphore
  if(!blocked_row.empty()){
    p_row.push(blocked_row.front());
    blocked_row.pop();
  }
}

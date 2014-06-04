#include <iostream>
#include <cstring>

using namespace std;

const int QUEENSUM = 8;

int count = 0;
int line = 0;
int R[QUEENSUM] = {0};

bool TwoPointCrash(int x1, int y1, int x2, int y2) {  //
  return (x1 == x2 ) || y1 == y2 || (x1 + y1) == (x2 + y2) || (x1 - y1) == (x2 - y2);
} 

bool Valid(int x, int y) {
  for (int i = 0; i < x; ++i) {
    if (TwoPointCrash(x, y, i, R[i])) {
      return false;
    } 
  }
  return true;
}

void Output() {
  ++count;
  cout << " generating one Solution: " << endl;
  for (int i = 0; i < QUEENSUM; ++i) {
    for (int j = 0; j < QUEENSUM; ++j) {
      if (j == R[i]) {
        cout << "1 "; 
      } else {
        cout << "0 "; 
      }
    }
    cout << endl;
  }
  cout << endl;
}

// Use recursive DFS:
void dfs() {
  if (line == QUEENSUM) {  // get one Solution:
    Output();
  }

  for (int i = 0; i < QUEENSUM; ++i) {
    if (Valid(line, i)) {  // next step:
      R[line] = i;
      ++line;
      dfs();
      --line;
    }
  }
}

void BackTrace() {
  while (line >= 0) {
    ++R[line]; 
    while (R[line] < QUEENSUM && !Valid(line, R[line])) {
      ++R[line];
    }
    if (R[line] < QUEENSUM) {  // got one valid step:
      if (line == QUEENSUM - 1) {
        Output();
        continue;
      }
      ++line;
      R[line] = -1;
    } else {  // backstrace
      R[line] = -1;
      --line; 
    }
  }
}

int main() {
  cout << "dfs: ----------- " << endl;
  memset(R, -1, sizeof(R));
  line = 0;
  count = 0;
  dfs();
  cout << " count: " << count << endl;

  cout << "backTrace: ----------- " << endl;
  memset(R, -1, sizeof(R));
  line = 0;
  count = 0;
  BackTrace();
  cout << " count: " << count << endl;
}

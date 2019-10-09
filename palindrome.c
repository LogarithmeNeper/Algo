#include <stdio.h>

void palindrome(int n, int values[]) {

  int valid = 1;
  int i;

  for(i = 0; i < n; i++) {
    if(values[n-i-1] != values[i]) {
      valid = 0;
    }
  }

  printf("%d\r\n", valid);

}

int main(void) {

  int values[1000] = { 0 };
  int val;
  int n = 0;

  while(scanf("%d", &val)) {
    if(val == -1) {
      break;
    } else {
      values[n] = val;
      n++;
    }
  }

  palindrome(n, values);

  return 0;

}

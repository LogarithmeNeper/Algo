#include <stdio.h>

void maximum_contiguous_sum(int n, float partial_sum[]) {

  float max = partial_sum[0];

  int i;
  int t;
  float diff;

  for(i = 0; i < n; i++) {
    for(t = 0; t < n - i; t++) {
      if(t == 0) {
        diff = partial_sum[i];
      } else {
        diff = partial_sum[i+t] - partial_sum[i];
      }

      if(diff > max) {
        max = diff;
      }
    }
  }

  printf("%f\r\n", max);

}

int main(void) {

  int n;
  scanf("%d", &n);

  float values[n];
  float partial_sum[n];

  int i;
  for(i = 0; i < n; i++) {
    scanf("%f", &values[i]);

    if(i == 0) {
      partial_sum[0] = values[0];
    } else {
      partial_sum[i] = partial_sum[i-1] + values[i];
    }
  }

  maximum_contiguous_sum(n, partial_sum);

  return 0;
}

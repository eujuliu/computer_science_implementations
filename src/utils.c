#include <math.h>
#define MAX(a, b) ((a) > (b) ? (a) : (b))

int get_unit_count(double n) {
  return (int)round(log(n) / log(10));
}

#include <stdbool.h>
#include <stdio.h>

bool versions[] = {false, false, false, false, true, true};

bool isBadVersion(int n);
int firstBadVersion(int n);

bool isBadVersion(int n) {
  return versions[n];
}

// finds first `true` element in an array of elements such that all elements
// after the first `true` element are `true`
int firstBadVersion(int n) {
  int start = 1;
  int end = n;
  while (start <= end) {
    int version = start + (end - start) / 2;
    if (isBadVersion(version)) {
      if (!isBadVersion(version - 1)) {
        return version;
      }
      end = version - 1;
    } else {
      start = version + 1;
    }
  }
  return -1;
}

int main() {
  printf("%d\n", firstBadVersion(6));
  printf("%d\n", isBadVersion(2));
}

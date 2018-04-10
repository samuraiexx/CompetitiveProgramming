//The following code goes through the subsets of {0, 1, . . . , n − 1}:
for (int b = 0; b < (1<<n); b++) {
  // process subset b
}

//The following code goes through the subsets with exactly k elements:
for (int b = 0; b < (1<<n); b++) {
  if (__builtin_popcount(b) == k) {
    // process subset b
  }
}

//The following code goes through the subsets of a set x :

int b = 0;
do {
  // process subset b
} while (b=(b-x)&x)

#include <algorithm>
#include <cmath>
#include <iostream>
#include <limits.h>
#include <vector>

using namespace std;

int n, k;
int *arr;
int *temp;
int *chunks;

int *init_chunks(int *ch_len) {
  // we can start with 1, because N >=1 is part of constraints
  *ch_len = 1;
  chunks[0] = 0;
  for (int i = 1; i < n; i++) {
    if (arr[i] < arr[i - 1]) {
      chunks[(*ch_len)++] = i;
    }
  }
  return chunks;
}

void print() {
  for (int i = 0; i < n; i++) {
    cout << arr[i] << '\n';
  }
}

int size_of_chunk(int i, int ch_len) {
  if (i + 1 < ch_len) {
    return chunks[i + 1] - chunks[i];
  }
  return n - chunks[i];
}

void merge_chunks(int start, int end, int ch_len, int j) {
  int n_chunks = min(k, ch_len - j);
  int merged_length = end - start;
  vector<int> counters(n_chunks, 0);

  for (int i = 0; i < merged_length; i++) {
    int min_el = INT_MAX;
    int min_idx = 0;
    for (int ch = 0; ch < n_chunks; ch++) {
      if (counters[ch] < size_of_chunk(j + ch, ch_len)) {
        int top_el = arr[chunks[j + ch] + counters[ch]];
        if (top_el < min_el) {
          min_el = top_el;
          min_idx = ch;
        }
      }
    }

    temp[i] = min_el;
    counters[min_idx]++;
  }

  for (int i = 0; i < merged_length; i++) {
    arr[start + i] = temp[i];
  }
}

int main() {
  int a;

  cin >> n >> k >> a;

  arr = new int[n]();
  temp = new int[n]();
  chunks = new int[n]();

  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }

  int ch_len;
  init_chunks(&ch_len);

  for (int i = 0; i < a; i++) {
    // break if sorted
    if (ch_len == 1)
      break;

    int next_ch_len = 0;
    for (int j = 0; j < ch_len; j += k) {
      // merge k sorted chunk
      int end = j + k < ch_len ? chunks[j + k] : n;
      int start = chunks[j];
      // sort(arr + start, arr + end);

      merge_chunks(start, end, ch_len, j);

      chunks[next_ch_len++] = start;
    }
    ch_len = next_ch_len;
  }

  print();
  delete[] arr;
  delete[] chunks;
  delete[] temp;

  return 0;
}

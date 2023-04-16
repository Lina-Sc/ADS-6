// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_

template<typename T, int size = 0>
class TPQueue {
 private:
    T arr[size] = {0};
    int l, r, count;

 public:
    TPQueue(): l(0), r(0), count(0) {}
    void push(const T& m) {
        if (count == 0) {
            arr[0] = m;
            ++r;
            ++count;
        } else {
            for (int i = r; i > l; --i) {
                if (arr[(i - 1) % size].prior >= m.prior) {
                    arr[i % size] = m;
                    break;
                } else {
                    arr[i % size] = arr[(i - 1) % size];
                    arr[(i - 1)%size] = m;
                }
            }
            ++r;
        }
    }
    const T& pop() {
        return arr[(l++ % size)];
    }
};

struct SYM {
  char ch;
  int prior;
};

#endif  // INCLUDE_TPQUEUE_H_

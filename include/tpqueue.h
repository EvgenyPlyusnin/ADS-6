// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_

template<typename T, int size>
class TPQueue {
 private:
    T arr[5];
    int first;
    int last;
    int count;
    int take;

 public:
    TPQueue(): first(0), last(0), count(0), take(0) { }
    void push(T x) {
        if (take > 0) {
            int repeat = size - take;
            for (int i = 0; i < repeat; i++) {
                arr[i] = arr[take];
                arr[take] = T();
                take++;
            }
            take = 0;
        }
        if (count == 0) {
            arr[0] = x;
            count++;
            return;
        }
        if (count == 1 && arr[0].prior == x.prior) {
            arr[1] = x;
            count++;
            return;
        }
        for (int i = 1; i <= size; i++) {
            if (arr[i-1].prior < x.prior) {
                T temp = arr[i-1];
                arr[i-1] = x;
                for (int j = i; j <= size; j++) {
                    T temp2 = arr[j];
                    arr[j] = temp;
                    temp = temp2;
                }
                count < size? count++ : count = 5;
                break;
            }
        }
    }
    T pop() {
        count--;
        return arr[take++];
    }
};

struct SYM {
  char ch;
  int prior;
};

#endif  // INCLUDE_TPQUEUE_H_

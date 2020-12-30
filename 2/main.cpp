#include <iostream>

using namespace std;

// basic implementation of the stack because we are not able to use any built-in library
template<class T>
class stack {
    int curr = -1, siz = 2; // initial size
    T *arr = new T[siz];

    void duplicate() {
        T *newArr = new T[siz * 2];

        for (int i = 0; i < siz; ++i) newArr[i] = arr[i];

        siz = siz * 2;
        arr = newArr;
    }

public:
    void push(T item) {
        if (curr == siz - 1) duplicate();
        arr[++curr] = item;
    }

    T top() {
        return arr[curr];
    }

    void pop() {
        --curr;
    }

    bool empty() {
        return curr == -1;
    }
};

// Recursive GO (Just for me to translate it to the non recursive)
template<class T>
void goRecursive(const T arr[], int n, T *curr, int curr_N, int idx) {
    if (idx == n) {
        cout << "{";
        for (int i = 0; i < curr_N; ++i) {
            if (i == curr_N - 1) cout << curr[i];
            else cout << curr[i] << ", ";
        }
        cout << "}\n";
        return;
    }


    T *new_curr = new int[n];
    for (int i = 0; i < curr_N; ++i)
        new_curr[i] = curr[i];

    new_curr[curr_N] = arr[idx];

    goRecursive(arr, n, new_curr, curr_N + 1, idx + 1);
    goRecursive(arr, n, curr, curr_N, idx + 1);
}

// we don't need the CallType struct because we are only have one type of calls
template<class T>
struct GenerateSubsetsCall {
    // variable parameters for GO function other {arr[] and n} are constants
    T *curr;
    int curr_N, idx;
};


// I will attach the recursive code that I wrote it to understand my approach more
template<class T>
void GenerateSubsets(T a[], int n) {
    GenerateSubsetsCall<T> initial_call;
    initial_call.curr = new T[n];
    initial_call.curr_N = 0;
    initial_call.idx = 0;

    // create stack and push the initial_call
    stack<GenerateSubsetsCall<T>> s;
    s.push(initial_call);

    while (!s.empty()) {
        // take the current call and remove it from the stack
        GenerateSubsetsCall<T> curr_call = s.top();
        s.pop();

        // base case -> print and continue
        if (curr_call.idx == n) {
            cout << "{";
            for (int i = 0; i < curr_call.curr_N; ++i) {
                if (i == curr_call.curr_N - 1) cout << curr_call.curr[i];
                else cout << curr_call.curr[i] << ", ";
            }
            cout << "}\n";
            continue;
        }
        // copy the current array to a new one because arrays are passed by reference
        T *new_curr = new T[n];
        for (int i = 0; i < curr_call.curr_N; ++i)
            new_curr[i] = curr_call.curr[i];
        // push the current value to the new array (take it) and the old array (curr) contains the old values (leave it)
        new_curr[curr_call.curr_N] = a[curr_call.idx];

        // Now make two stack calls to go once with (take it) and the other with (leave it)
        GenerateSubsetsCall<T> first, second;
        first.curr = curr_call.curr;
        first.curr_N = curr_call.curr_N;
        first.idx = curr_call.idx + 1;

        second.curr = new_curr;
        second.curr_N = curr_call.curr_N + 1;
        second.idx = curr_call.idx + 1;

        s.push(first);
        s.push(second);
    }

/*
    // for recursive call
    T *curr_for_recursive = new T[n];
    cout << "\n\nRECURSIVE: \n";
    goRecursive(a, n, curr_for_recursive, 0, 0);
*/

}

int main() {
    int a[] = {1, 2, 3, 4};
    int n = sizeof(a) / sizeof(a[0]);

    GenerateSubsets(a, n); // Prints (in any order): {} {1} {3} {8} {1,3} {1,8} {3,8} {1,3,8}
    // For example, the following order is also ok: {} {1} {1,3} {1,3,8} {1,8} {3} {3,8} {8}

    return 0;
}

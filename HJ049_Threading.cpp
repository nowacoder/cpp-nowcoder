#include <mutex>
#include <thread>
#include <string>
#include <iostream>
#include <condition_variable>

using namespace std;

string rst = "";
mutex mtx;
condition_variable A, B, C, D;
bool done = false;

void fun_A(int n) {
    while (n--) {
        unique_lock<mutex> locker(mtx);
        A.wait(locker);
        rst += 'A';
        B.notify_one();
    }
    done = true;
}

void fun_B() {
    while (!done) {
        unique_lock<mutex> locker(mtx);
        B.wait(locker);
        rst += 'B';
        C.notify_one();
    }
}

void fun_C() {
    while (!done) {
        unique_lock<mutex> locker(mtx);
        C.wait(locker);
        rst += 'C';
        D.notify_one();
    }
}

void fun_D() {
    while (!done) {
        unique_lock<mutex> locker(mtx);
        D.wait(locker);
        rst += 'D';
        A.notify_one();
    }
}

// g++ -std=c++11 -pthread
int main() {
    int n; 
    
    while (cin>>n) {
        rst = "";
        thread tA(fun_A, n);
        thread tB(fun_B);
        thread tC(fun_C);
        thread tD(fun_D);
        A.notify_one();
        tA.join();
        tB.join();
        tC.join();
        tD.join();
        cout << rst << endl;
        done = false;
    }
    
    return 0;
}
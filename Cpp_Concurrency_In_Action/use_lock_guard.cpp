#include<list>
#include<iostream>
#include<algorithm>
#include<mutex>
#include<thread>
using namespace std;
//C++中通过std::mutex创建互斥量 通过调用成员函数lock()和unlock()进行锁的操作，这意味着在每一个函数出口都需要手动unlock
//标准库为互斥量提供了一个RAII的模板类std::lock_guard
//编译时候请注意：g++ use_lock_guard.cpp -o output -pthread
// ./output
int cnt=0;
mutex cnt_lock;
void func_mutex(){
    for(int i=0;i<20;i++){
        cnt_lock.lock();
        cnt++;
        cnt_lock.unlock();
    }
}
void func_lock_guard(){
    for(int i=0;i<20;i++){
        lock_guard<mutex>lock(cnt_lock);
        cnt++;
    }
}
int main(){
    thread t1(func_mutex);
    thread t2(func_mutex);
    if(t1.joinable())t1.join();
    if(t2.joinable())t2.join();
    cout<<"use mutex answer:"<<cnt<<endl;
    cnt=0;
    thread t3(func_lock_guard);
    thread t4(func_lock_guard);
    if(t3.joinable())t3.join();
    if(t4.joinable())t4.join();
    cout<<"use lock_guard answer:"<<cnt<<endl;
}
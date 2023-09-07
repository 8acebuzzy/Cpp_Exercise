#include<iostream>
#include<mutex>
#include<thread>
std::once_flag flag;
int sharedata=0;
//g++ use_call_once.cpp -o output -pthread
//./output
//C++标准提供了一种纯粹用于保护共享数据初始化过程的机制，即"once"机制。该机制使用std::call_once函数，它接受一个函数和一个标志位作为参数。
//在多线程环境下，std::call_once函数确保传递的函数只被调用一次，即使在并发环境下也能正确工作。
//使用std::call_once机制，可以将共享数据的初始化过程放在被调用的函数中，而无需显式地使用互斥量来保护初始化过程。
//std::call_once会自动进行同步，确保只有一个线程执行初始化函数，并且其他线程在初始化完成之前会阻塞等待。
void init(){
    std::cout<<"初始化"<<std::endl;
    sharedata=44;
}
void access(){
    std::call_once(flag,init);
    std::cout<<"访问："<<sharedata<<std::endl;
}
int main(){
    std::thread t1(access);
    std::thread t2(access);
    std::thread t3(access);
    if(t1.joinable())t1.join();
    if(t2.joinable())t2.join();
    if(t3.joinable())t3.join();
}
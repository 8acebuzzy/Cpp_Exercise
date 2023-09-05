#include<iostream>
using namespace std;
class LazySingleton{
    private:
        LazySingleton(){};
        ~LazySingleton(){};
        LazySingleton(const LazySingleton &)=delete;
        LazySingleton& operator=(const LazySingleton&)=delete;
    public:
        static LazySingleton& getinstance(){
            static LazySingleton instance;
            return instance;
        }
};
//C++11规定了local static在多线程条件下的初始化行为，要求编译器保证了内部静态变量的线程安全性。
//在C++11标准下，《Effective C++》提出了一种更优雅的单例模式实现，使用函数内的 local static 对象。
//这样，只有当第一次访问getInstance()方法时才创建实例。这种方法也被称为Meyers' Singleton。
int main(){
    cout<<&LazySingleton::getinstance()<<endl;
    cout<<endl;
    cout<<&LazySingleton::getinstance()<<endl;
}
#include<iostream>
using namespace std;
//懒汉版 :即在第一次被使用时候才初始化 当前版本并没有做到线程安全和防止内存泄漏
//私有化构造函数，防止外界创建单例类的对象 使用类的私有静态指针直接指向唯一实例 使用类的公有静态方法获取该实例
class LazySingleton{
    private: 
        static LazySingleton * instance;
    private:
        LazySingleton(){
        };
        ~LazySingleton(){};
        LazySingleton(const LazySingleton&)=delete;
        LazySingleton & operator =(const LazySingleton&)=delete;
    public:
        static LazySingleton* getinstance(){
            if(instance==nullptr){
                instance=new LazySingleton();
            }
            return instance;
        }
};
LazySingleton* LazySingleton::instance =nullptr;
//饿汉版：单例实例在运行时立即初始化
//由于在main函数之前初始化，所以没有线程安全的问题。
//但是潜在问题在于no-local static对象（函数外的static对象）在不同编译单元中的初始化顺序是未定义的。
//也即，static Singleton instance;和static Singleton& getInstance()二者的初始化顺序不确定，
//如果在初始化完成之前调用 getInstance() 方法会返回一个未定义的实例。
class EagerSingleton{
    private:
        static EagerSingleton instance;
    private:
        EagerSingleton(){};
        ~EagerSingleton(){};
        EagerSingleton(const EagerSingleton&)=delete;
        EagerSingleton & operator =(const EagerSingleton&)=delete;
    public:
        static EagerSingleton& getinstance(){
            return instance;
        }
};
EagerSingleton  EagerSingleton::instance;
int main(){
    cout<<LazySingleton::getinstance();
}
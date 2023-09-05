#include<iostream>
using namespace std;
class LazySingleton{
    private: 
        static LazySingleton * instance;
    private:
        LazySingleton(){};
        ~LazySingleton(){};
        LazySingleton(const LazySingleton&);
        //LazySingleton & operator =(const LazySingleton&);
    public:
        static LazySingleton* getinstance(){
            if(instance==nullptr){
                instance=new LazySingleton();
            }
            return instance;
        }
};
LazySingleton* LazySingleton::instance = NULL;
int main(){
    cout<<LazySingleton::getinstance();
}
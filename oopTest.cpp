#include<bits/stdc++.h>
using namespace std;
class Animal{
  public:
  virtual void speak()=0;
};
class Dog:public Animal{
  string name;
  public:
  Dog(){
      this->name="Kutta";
  }
  string getName(){
      return this->name;
    }
  void speak(){
      std::cout <<"bark" << std::endl;
  }
};
class test{
    int a;
    public:
    test(){
        a=10;
    }
    test(int n){
        a=n;
    }
    int doSome(){
        std::cout << "Doing doSome" << std::endl;
    }
    int doSomeOther();
};
int test::doSomeOther(){
    std::cout << "Doing doSomeOther" << std::endl;
}
int main(){
    test t;//creating object using default constructor
    t.doSome();//calling public member function do doSome
    t.doSomeOther();
    //Line33-->We can use (.)  to acess the public member function  if object is created without using new
    //std::cout << t.a << std::endl;//private member can not be accessed directly
    
    test *t1=new test();
    
    //Line38-->there are 2 things that need to be learnt from this one this is new expression it does 2 thing it calls new operator and invokes
    //constructor test(). The new operator is called to allocate the memory. In case constructor aborts it calls delete operator to deallocate memory 
    // and new expression returns a pointer of type test*
    
    //two ways to call
    (*t1).doSome();
    t1->doSome();
    
    //Class pointer should have the method to be called if in case class don't have method that we intend to call then it will throw an error
    //Let us say we made class pointer of the type super class Animal and tried to call the method that is not in the Animal class then we will have 
    //error
    Dog *dog=new Dog();
    dog->speak();
    cout<<dog->getName();
    
}

#include <iostream>
using namespace std;
class IFlyBehavior{
    public:
        virtual void fly()=0;
};
class IQuackBehavior{
    public:
        virtual void quack()=0;
};
class Fly1: public IFlyBehavior{
    public:
        void fly(){
            cout<<"fly1\n";
        }
};
class Fly2: public IFlyBehavior{
     public:
        void fly(){
            cout<<"fly2\n";
        }
};
class Fly3: public IFlyBehavior{
     public:
         void fly(){
            cout<<"fly3\n";
        }
};
class Quack1:public IQuackBehavior{
    public:
    void quack(){
        cout<<"quack1\n";
    }
};
class Quack2:public IQuackBehavior{
    public:
    void quack(){
        cout<<"quack3\n";
    }
};
class Quack3:public IQuackBehavior{
    public:
    void quack(){
        cout<<"quack3\n";
    }
};
class Quack4:public IQuackBehavior{
    public:
    void quack(){
        cout<<"quack4\n";
    }
};
class Duck{
        IFlyBehavior *fb;
        IQuackBehavior *qb;
    public:
        Duck(IFlyBehavior *fb,IQuackBehavior *qb){
                this->fb=fb;
                this->qb=qb;
        }
        void execute(){
            this->fb->fly();
            this->qb->quack();
        }
};
int main()
{
// 1.	Rubber Duck (fly1, quack1)
// 2.	Mountain Duck (fly2, quack2)
// 3.	Cloud Duck (fly3, quack3)
// 4.	Hill Duck (fly2, quack4)
// 5.	Plastic duck (fly1, quack3)
// 6.	Wooden duck (fly1, quack2)

    Duck RubberDuck( new Fly1() ,new Quack1() );
    Duck MountainDuck( new Fly2(),new Quack2() );
    Duck CloudDuck( new Fly3() ,new Quack3() );
    Duck HillDuck( new Fly2(),new Quack4() );
    Duck PlasticDuck( new Fly1() ,new Quack3() );
    Duck WoodenDuck( new Fly1(),new Quack2());
    RubberDuck.execute();
    MountainDuck.execute();
    CloudDuck.execute();
    HillDuck.execute();
    PlasticDuck.execute();
    WoodenDuck.execute();
    return 0;
    
}

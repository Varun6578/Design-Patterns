#include<bits/stdc++.h>
using namespace std;
class AnimalImplementor{
    public:
    virtual void speak()=0;
};
class Animal{
    public:
    virtual void execute()=0;
    virtual AnimalImplementor* getAnimal()=0;
};
class DancingAnimal:public Animal{
    AnimalImplementor* animal;
    public:
    DancingAnimal(AnimalImplementor* b){
        this->animal=b;
    }
    AnimalImplementor* getAnimal(){
        return this->animal;
    }
    void execute(){
        std::cout << "Dance" << std::endl;
    }
};
class SingingAnimal:public Animal{
    AnimalImplementor* animal;
    public:
    SingingAnimal(AnimalImplementor* b){
        this->animal=b;
    }
    AnimalImplementor* getAnimal(){
        return this->animal;
    }
    void execute(){
        std::cout << "Sing" << std::endl;
    }
};
class Dog:public AnimalImplementor{
    public:
    void speak(){
        std::cout << "Bark" << std::endl;
    }
};
class Cat:public AnimalImplementor{
    public:
    void speak(){
        std::cout << "Meow" << std::endl;
    }
};
int main(){
    //we have two kinds of Abstraction that is DancingAnimal and SingingAnimal
    //we have two kinds of AnimalImplementor Dog and Cat
    
    //So 4 possiblities
   
    Animal *singingDog=new SingingAnimal(new Dog());
    singingDog->getAnimal()->speak();
    singingDog->execute();
    
    Animal *dancingDog=new DancingAnimal(new Dog());
    dancingDog->getAnimal()->speak();
    dancingDog->execute();
    
    Animal *singingCat=new SingingAnimal(new Cat);
    singingCat->getAnimal()->speak();
    singingCat->execute();
    
    Animal *dancingCat=new DancingAnimal(new Cat());
    dancingCat->getAnimal()->speak();
    dancingCat->execute();
}

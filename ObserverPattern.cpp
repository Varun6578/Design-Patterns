#include<bits/stdc++.h>
using namespace std;
class IObservable;
class WeatherStation;
class IObserver{
    public:
    virtual void update(WeatherStation*s)=0;
};
class IObservable{
    public:
    virtual void addObserver(IObserver* observer)=0;
    virtual void removeObserver(IObserver* observer)=0;
    virtual void notifyObserver()=0;
};
class IDisplay{
    public:
    virtual void display()=0;
};

class WeatherStation: public IObservable{
    private:
    double temperature;
    std::vector<IObserver*> observers;
    public:
    void addObserver(IObserver* observer){
        this->observers.push_back(observer);
        notifyObserver();
    }
    void removeObserver(IObserver* observer){
        cout<<"remove\n";
    }
    void notifyObserver(){
        for(auto i: observers){
            i->update(this);
        }
    }
    double getTemp(){
        return this->temperature;
    }
    void setTemp(double temp){
        this->temperature=temp;
        notifyObserver();
    }
};

class PhoneDisplay: public IObserver,IDisplay{
    WeatherStation station;//concrete WeatherStation
    public:
    void display(){
        cout<<this->station.getTemp()<<'\n';
    }
    void update(WeatherStation*s){
        this->station=*s;
    }
};
class LcdDisplay: public IObserver,IDisplay{
    WeatherStation station;
    public:
    void display(){
        cout<<this->station.getTemp()<<'\n';
    }
    void update(WeatherStation*s){
        this->station=*s;
    }
};
int main(){
    WeatherStation s;
    s.setTemp(10.5);
    cout<<s.getTemp()<<"\n";
    PhoneDisplay ph;
    s.addObserver(&ph);
    ph.display();
    LcdDisplay ld;
    s.addObserver(&ld);
    ld.display();
    s.setTemp(20.5);
    ph.display();
    ld.display();
    
}

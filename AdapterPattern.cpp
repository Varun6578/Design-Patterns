#include<bits/stdc++.h>
using namespace std;
class Monitor{
    public:
    virtual void hdmi()=0;
};
class Mac{
    public:
    void typeC(){
        cout<<"typeC\n";
    }
};
class Adapter:public Monitor{
    Mac *m;
    public:
    Adapter(Mac* t){
        this->m=t;
    }
    void hdmi(){
        this->m->typeC();
    }
    
};
int main(){
    Monitor*m=new Adapter(new Mac());
    m->hdmi();
    
}

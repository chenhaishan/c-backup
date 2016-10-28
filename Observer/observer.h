#ifndef OBSERVER_H
#define OBSERVER_H

#include <iostream>
#include <list>
#include <memory>
using namespace std;

//Observer interface class
class ObserverBoardInterface{
public:
    virtual void update(float a, float b, float c)  =0;
};

//display interface class
class DisplayBoardInterface{
public:
    virtual void show() = 0;
};

//Subject interface class
class WeatherDataInterface{
public:
    //register Observer
    virtual void registerob(weak_ptr<ObserverBoardInterface> ob) = 0;
    //deregister Observer
    virtual void removeob(weak_ptr<ObserverBoardInterface> ob) = 0;
    //notify Observer
    virtual void notifyob() = 0;

};

//Concrete Subject class
class ConcreteWeatherData: public WeatherDataInterface
{
private:
    float m_humidity;
    float m_temperature;
    float m_pressure;

    //Observers
    list<weak_ptr<ObserverBoardInterface>> m_obs;
    typedef list<weak_ptr<ObserverBoardInterface>>::iterator Iterator;

public:
    ConcreteWeatherData(float h =0, float t = 0, float p = 0)
        :m_humidity(h), m_temperature(t), m_pressure(p){}
    ConcreteWeatherData(const ConcreteWeatherData &rhs){

    }
    ConcreteWeatherData & operator= (const ConcreteWeatherData &rhs){

    }
    ~ConcreteWeatherData(){

    }

    void SensorDataChange(float h, float t, float p){
        m_humidity = h;
        m_temperature = t;
        m_pressure = p;

        //notify all Observers
        notifyob();
    }

    void registerob(weak_ptr<ObserverBoardInterface> ob){
        m_obs.push_back(ob);
    }
/*
    void removeob(weak_ptr<ObserverBoardInterface> ob){
        m_obs.remove(ob);

    }*/
protected:
    void notifyob(){
        Iterator w_obs = m_obs.begin();
        while(w_obs != m_obs.end()){
            shared_ptr<ObserverBoardInterface> s_obs(w_obs->lock());
            if(s_obs){
                s_obs->update(m_humidity, m_temperature, m_pressure);
                (dynamic_cast<DisplayBoardInterface *> (s_obs.get()))->show();
                ++w_obs;
            }else{
                w_obs = m_obs.erase(w_obs);
            }
        }
    }
};

//Concrete Observer class
class ConcreteObserver: public ObserverBoardInterface, public DisplayBoardInterface
{
private:
    float m_h;
    float m_t;
    float m_p;
    WeatherDataInterface &m_data;
public:
    ConcreteObserver(WeatherDataInterface &a):m_data(a){
        m_data.registerob(
                    /**********error: abstract class cant't be initialized!************/
                    weak_ptr<ObserverBoardInterface>(make_shared<ObserverBoardInterface>(*this)));
    }

    void show(){
        cout<<"__ConcreteObserver__"<<endl;
        cout<<"humidity: "<<m_h<<endl;
        cout<<"temperature: "<<m_t<<endl;
        cout<<"pressure: "<<m_p<<endl;
        cout<<"____________________"<<endl;
    }

    void update(float h, float t, float p){
        m_h = h;
        m_t = t;
        m_p = p;
    }
};

//another Concrete Observer
class StatisticBoard : public ObserverBoardInterface, public DisplayBoardInterface
{
public:
    StatisticBoard(WeatherDataInterface& a)
        :m_maxt(-1000),m_mint(1000),m_avet(0),m_count(0),m_data(a)
    {
        m_data.registerob(
                    weak_ptr<ObserverBoardInterface>(make_shared<ObserverBoardInterface>(*this)));
    }

    void show()
    {
        cout<<"________StatisticBoard_________"<<endl;
        cout<<"lowest  temperature: "<<m_mint<<endl;
        cout<<"highest temperature: "<<m_maxt<<endl;
        cout<<"average temperature: "<<m_avet<<endl;
        cout<<"_______________________________"<<endl;
    }

    void update(float h, float t, float p)
    {
        ++m_count;
        if (t>m_maxt)
        {
            m_maxt = t;
        }
        if (t<m_mint)
        {
            m_mint = t;
        }
        m_avet = (m_avet * (m_count-1) + t)/m_count;
    }

private:
    float m_maxt;
    float  m_mint;
    float m_avet;
    int m_count;
    WeatherDataInterface& m_data;
};


#endif // OBSERVER_H

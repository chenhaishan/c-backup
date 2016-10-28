#include <iostream>
#include "observer.h"
using namespace std;

int main(int argc, char *argv[])
{

    shared_ptr<ConcreteWeatherData> wdata = make_shared<ConcreteWeatherData>();
    auto currentB = make_shared<ConcreteObserver>();
    auto statisticB = make_shared<StatisticBoard>();
    /*ConcreteWeatherData * wdata = new ConcreteWeatherData;
    ConcreteObserver* currentB = new ConcreteObserver(*wdata);
    StatisticBoard* statisticB = new StatisticBoard(*wdata);
*/

    wdata->SensorDataChange(10.2, 28.2, 1001);
    wdata->SensorDataChange(12, 30.12, 1003);
    wdata->SensorDataChange(10.2, 26, 806);
    wdata->SensorDataChange(10.3, 35.9, 900);

    wdata->removeob(currentB);

    wdata->SensorDataChange(100, 40, 1900);



    return 0;
}


#ifndef BOOSTMANAGEMENT
#define BOOSTMANAGEMENT
using namespace std;
#include <iostream>
#include <string>
#include <chrono>

double calcBuildRate(double currentPercent, double totalTimeToFull)
{
    double buildRate;

    buildRate = (1.26 - (0.52 * currentPercent)) / totalTimeToFull;

    return buildRate;
}

void boostGain(double& tank, double rate, double time)
{
    if (tank < 1.00)
    {
        tank += rate * time;
        if (tank > 1.00)
        {
            tank = 1.00;
        }

    }
}

void boostLoss(double& tank, double rate, double time)
{
    if (tank > 0)
    {
        tank -= rate * time;
        if (tank < 0)
        {
            tank = 0;
        }

    }
}

#endif // !boostManagement







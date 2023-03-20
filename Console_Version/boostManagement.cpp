/*#include "boostManagement.h"

void boostLoss(double &tank, double rate, double time)
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

void boostGain(double &tank, double rate, double time)
{
    if (tank < 100)
    {
        tank += rate * time;
        if (tank > 100)
        {
            tank = 100;
        }
        
    }
}
*/
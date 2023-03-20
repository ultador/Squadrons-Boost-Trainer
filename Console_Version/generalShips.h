#ifndef GENERALSHIPS_H_
#define GENERALSHIPS_H_
using namespace std;
#include <string>


class generalShips
{
public:
	generalShips();
	generalShips(string shipType)
	{
		if (shipType == "Y" || shipType == "y")
		{
			generalShips::totalChargeTime = 11.38;
		}
		else
		{
			generalShips::totalChargeTime = 16.25;
		}

		generalShips::boostPercent = 100;
	}
	~generalShips();
	double getTotalChargeTime();
	//void getEngineType();
	double getBoostPercent();
	void setBoostPercent(double percent);
	//TODO: void setEngineType();
	//Placeholder: SLAM engine only to avoid multithreading for tracking boost decay
private:

	string engineType;
	double totalChargeTime;
	double boostPercent;
	
};

/*void generalShips::getEngineType()
{
	return engineType;
}*/

double generalShips::getTotalChargeTime()
{
	return totalChargeTime;
}

double generalShips::getBoostPercent()
{
	return boostPercent;
}

void generalShips::setBoostPercent(double percent)
{
	boostPercent = percent;
}

//TODO for future: Update initializer to account for different ship and engine types


generalShips::generalShips()
{
	totalChargeTime = -1;
	boostPercent = 1;
}

generalShips::~generalShips()
{
}
#endif // !GENERALSHIPS_H_
#pragma once

/*
 * Sensor.cpp
 *
 *  Created on: 18.01.2017
 *      Author: Beat
 */
#include "Sensor.h"



	Sensor::Sensor()
	{
		ID = 0;
		speed = 0.0;
		totalDistance = 0;
	}

	Sensor::Sensor(short IDNr)
	{
		ID = IDNr;
		speed = 0.0;
		totalDistance = 0;
	}



	double Sensor::getSpeed()
	{
		return speed;
	}

	int Sensor::getTotalDistance()
	{
		return totalDistance;
	}

	short Sensor::getID()
	{
		return ID;
	}

	void Sensor::setSpeed(double newSpeed)
	{
		speed = newSpeed;
	}

	void Sensor::setTotalDistance(int newTotalDistance)
	{
		totalDistance = newTotalDistance;
	}






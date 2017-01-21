/*
 * StreamProcessor.cpp
 *
 *  Created on: 18.01.2017
 *      Author: Beat
 */
#include "StreamProcessor.h"

#include <cstdlib>
#include <cmath>
#include <iostream>

#include "Sensor.h"
#include "PositionDataUnit.h"


using namespace std;


//vllt *sensor??
void StreamProcessor::updateSensor(Sensor &sensor, PositionDataUnit &positionDataUnit, PositionDataUnit &lastGuess)
	{

	int lastX = lastGuess.getXCoordinate();
	int lastY = lastGuess.getYCoordinate();
	int lastTimeStamp = lastGuess.getTimestamp();

	int measuredX = positionDataUnit.getXCoordinate();
	int measuredY = positionDataUnit.getYCoordinate();
	int recentTimeStamp = positionDataUnit.getTimestamp();


	// correct if x or y out of track
	if(measuredX > 10000)
		{
			measuredX = 10000;
		}
		if(measuredY > 10000)
		{
				measuredY = 10000;
		}

		if(measuredX < 0)
		{
				measuredX = 0;
		}

		if(measuredY < 0)
		{
				measuredY = 0;
		}

	double measuredDistance = calculateDistance(lastX, measuredX, lastY, measuredY);

	// unrealistic fast movement
	if(measuredDistance > 50) {

		// factor to which distance needs to be corrected
		double cropFactor = 50/measuredDistance;

		double differenceX = measuredX - lastX;
		double differenceY = measuredY - lastY;

		// correct X and Y value
		differenceX  *= cropFactor;
		differenceY *= cropFactor;
		int correctedX = lastX + differenceX;
		int correctedY = lastY + differenceY;

		// update distance
		measuredDistance = calculateDistance(lastX, correctedX, lastY, correctedY);

	}


	double speed = calculateSpeed(measuredDistance, (recentTimeStamp - lastTimeStamp));

	cout << "sensor " << sensor.getID() << endl;
	cout << "speed: " << speed << endl;
	cout << "total distance: " << measuredDistance << endl;

	sensor.setSpeed(speed);
	sensor.setTotalDistance(sensor.getTotalDistance()+measuredDistance);

	lastGuess = *(positionDataUnit.clone());

	}

void StreamProcessor::initiatePosition(PositionDataUnit &positionDataUnit) {

	int xCoord = positionDataUnit.getXCoordinate();
	int yCoord = positionDataUnit.getYCoordinate();
	int ID = positionDataUnit.getsensorID();
	int timeStamp = positionDataUnit.getTimestamp();


	// Correct values < 0 or > 10000
	if(xCoord > 10000)
	{
		xCoord = 10000;
	}
	if(yCoord > 10000)
	{
		yCoord = 10000;
	}

	if(xCoord < 0)
	{
		xCoord = 0;
	}

	if(yCoord < 0)
	{
		yCoord = 0;
	}

	PositionDataUnit correctedDataUnit(ID, timeStamp, xCoord, yCoord);

	positionDataUnit = correctedDataUnit;
	//return newPosition
	//delete correctedDataUnit?

}



/**
 * Calculates the speed in m/s
 *
 * @param distance distance in cm
 * @param time time in ms
 */
double StreamProcessor::calculateSpeed(double distance, int time) {
	double speed = 0.0;
	// Only calculate if distance != zero
	if(distance != 0) {

		// calculate speed: convert distance in m
		// and time in s
		speed = distance/time * 10;
	}
	return speed;
}

/**
 * Calculates the distance in cm between two two-dimensional points
 */
double StreamProcessor::calculateDistance(int x1, int x2, int y1, int y2) {
	double distance = sqrt(pow((y2-y1),2) + pow((x2-x1),2));
	return distance;
}









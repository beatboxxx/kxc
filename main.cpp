/*
 * main.cpp
 *
 *  Created on: 18.01.2017
 *      Author: Beat
 */
#include<iostream>
#include<cstdlib>
#include<ctime>
#include "random"
#include<unistd.h>

#define NUMBER_OF_SENSORS 3
// #include <ratio>
// #include <chrono>

#include "Sensor.h"
#include "PositionDataUnit.h"
#include "PositionGenerator.h"
#include "StreamProcessor.h"


using namespace std;
using namespace chrono;

int main()
{

	// Create and initialize random number generator
	random_device rd;
	mt19937 gen(rd());

	// create uniformely distributed numbers between 1 and 10.000
	uniform_int_distribution<> dis(1, 10000);

	// Create array with sensors
	Sensor sensorArray[NUMBER_OF_SENSORS];


	// create array with PositionDataUnits (Pointer!)
	PositionDataUnit *positionDataUnitArray[NUMBER_OF_SENSORS];

	// Array with positions estimated by the Stream Processor
	PositionDataUnit *positionDataUnitEstimated[NUMBER_OF_SENSORS];

	PositionGenerator pGenerator;
	StreamProcessor processor;
	int timeStamp = 0;

	// initializes sensors and create first random data point
	// (without noise)
	for(int i = 0; i < NUMBER_OF_SENSORS; i++)
		{

		// get timestamp in ms
		timeStamp = duration_cast< milliseconds >(
		    system_clock::now().time_since_epoch()
		).count()-1480000000000;

		// create random values for starting position
		int xStart = dis(gen);
		int yStart = dis(gen);


		// create Sensor with ID = i and put it into the array
		sensorArray[i] =  Sensor(i);

		PositionDataUnit *PDUnit = new PositionDataUnit(i, timeStamp, xStart, yStart);
		positionDataUnitArray[i] = PDUnit;

		//ToDO evtl pointer statt & im Kopf
		processor.initiatePosition(*PDUnit);


		positionDataUnitEstimated[i] = PDUnit->clone();

	}

	// wait 50ms before generating next position

	//ToDO Unix-Sleep checken!!
	usleep(50000);
	// sleep(50)

while(true)
	{
	for (int i = 0; i< NUMBER_OF_SENSORS; i++) {


		// next update: last timestamp + 50ms
		while (int(duration_cast< milliseconds >(
			    system_clock::now().time_since_epoch()
			).count()-1480000000000) < (positionDataUnitArray[i]->getTimestamp() + 50)) {
			usleep(500);
		}

		//ToDO vielleicht & statt pointer übergeben!
		// generate new position
		PositionDataUnit *movement = pGenerator.generatePosition(*positionDataUnitArray[i]);

		// remove noise and update sensors
		processor.updateSensor(sensorArray[i], *movement, *positionDataUnitEstimated[i]);

		cout << "Distanz Sensor " << i <<": " << sensorArray[i].getTotalDistance() << endl;
	}
	}
}




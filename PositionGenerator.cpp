/*
 * PositionGenerator.cpp
 *
 *  Created on: 18.01.2017
 *      Author: Beat
 */
#include "PositionGenerator.h"

#include <cstdlib>
#include <iostream>
#include <cmath>
#include <ctime>
#include <chrono>
#include <random>
#include <algorithm>
#include "PositionDataUnit.h"

using namespace std;
using namespace std::chrono;

// evtl Kopf auf *!

/*
 * Generates a new random position
 *
 */
PositionDataUnit*  PositionGenerator::generatePosition(PositionDataUnit &lastPosition)
{
	// Create and initialize random number generator
	random_device rd;
	mt19937 gen(rd());


	// get timestamp in ms (cut most significant decimal
	// digits to get the number into an int value)
	int timeStamp = duration_cast< milliseconds >(
	    system_clock::now().time_since_epoch()
	).count()-1480000000000;


	int xCoord = lastPosition.getXCoordinate();
	int yCoord = lastPosition.getYCoordinate();

	// Add or subtract random value
	// Maximum distance = 50 cm
	// (=> maximal speed = 36 m/s)

	//
	// If the margin to one of the borders < 50
	//  => maximal distance to that direction = distance to border
	int xMargin = std::min(std::min(10000-xCoord, xCoord),50);


	srand(time(NULL));

	// Generate random value between (0, 50 + xMargin)

	uniform_int_distribution<> dis(0, 50+xMargin);
    int xAdd = dis(gen);



    // close to the left border
    if(xCoord < 50)
    {
    	xCoord += (50 - xAdd);
    }

    // close to the right border or in the middle
    else
    {
    	xCoord += (xAdd - 50);
    }

    // distance covered in x-direction
    int xMove = abs(xAdd-50);

    // calculate maximal distance in y-direction
    // (hypotenuse must be <= 50)
    int yMax = sqrt(2500 - pow(xMove,2));
    int yMargin = std::min(std::min(10000-yCoord, yCoord),yMax);


    // if yMax = 0 => don't change yCoord!
    if (yMax != 0) {

    // Generate random value between (0, yMax + yMargin)

    uniform_int_distribution<> dis2(0, yMax + yMargin);
    int yAdd = dis2(gen);

    	// close to the lower border
    	if (yCoord < yMax)
    	{
    		yCoord += (yMax - yAdd);
    	}

    	// close to the upper border or in the middle
    	else
    	{
    		yCoord += (yAdd - yMax);
    	}
    }


	int ID = lastPosition.getsensorID();




	// Update lastPosition Data Unit
	lastPosition = PositionDataUnit(ID, timeStamp, xCoord, yCoord);

	// Add Noise +- 30 to each coordinate
	xCoord += 30 - (rand() % 60);
	yCoord += 30 - (rand() & 60);


	PositionDataUnit *newPositionDataUnit = new PositionDataUnit(ID, timeStamp, xCoord, yCoord);


	return newPositionDataUnit;
}

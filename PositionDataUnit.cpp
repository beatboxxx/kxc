/*
 * PositionDataUnit.cpp
 *
 *  Created on: 18.01.2017
 *      Author: Beat
 */
#include "PositionDataUnit.h"

	PositionDataUnit::PositionDataUnit()
	{
		sensorID = 0;
		timestamp = 0;
		xCoordinate = 0;
		yCoordinate = 0;
	}

	PositionDataUnit::PositionDataUnit(int ID, int time, int xCo, int yCo)
	{
		sensorID = ID;
		timestamp = time;
		xCoordinate = xCo;
	    yCoordinate = yCo;
	}


    int PositionDataUnit::getTimestamp()
    {
    	return timestamp;
    }
    int PositionDataUnit::getsensorID()
    {
    	return sensorID;
    }
    int PositionDataUnit::getXCoordinate()
    {
    	return xCoordinate;
    }
    int PositionDataUnit::getYCoordinate()
    {
    	return yCoordinate;
    }

    PositionDataUnit* PositionDataUnit::clone() {
    	return new PositionDataUnit(this->sensorID, this->timestamp, this->xCoordinate, this->yCoordinate);
    }

    /*
    void PositionDataUnit::setTimestamp(int time) { timestamp = time; }
    void PositionDataUnit::setXCoordinate(int xCo)  { xCoordinate = xCo; }
    void PositionDataUnit::setYCoordinate(int yCo)  { yCoordinate = yCo; }
	*/


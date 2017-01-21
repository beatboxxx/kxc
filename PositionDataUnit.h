/*
 * PositionDataUnit.h
 *
 *  Created on: 18.01.2017
 *      Author: Beat
 */


#ifndef POSITIONDATAUNIT_H_
#define POSITIONDATAUNIT_H_

class PositionDataUnit
{
	private:
	int timestamp;
	// static const short sensorID;
	short sensorID;
	int xCoordinate;
	int yCoordinate;


	public:
	PositionDataUnit();
	PositionDataUnit(int ID, int time, int xCo, int yCo);



    int getTimestamp();
    int getsensorID();
    int getXCoordinate();
    int getYCoordinate();

    PositionDataUnit* clone();

    /*
    void setTimestamp(int time);
    void setXCoordinate(int xCo);
    void setYCoordinate(int yCo);
    */
};




#endif /* POSITIONDATAUNIT_H_ */

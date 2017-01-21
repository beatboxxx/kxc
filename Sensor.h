/*
 * Sensor.h
 *
 *  Created on: 18.01.2017
 *      Author: Beat
 */

#ifndef SENSOR_H_
#define SENSOR_H_

class Sensor
{
private:
	double speed;
	int totalDistance;
	short ID;

public:


	Sensor(short ID);


	double getSpeed();
	int getTotalDistance();
	short getID();

	void setSpeed(double speed);
	void setTotalDistance(int totalDistance);

};










#endif /* SENSOR_H_ */

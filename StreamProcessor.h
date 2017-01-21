/*
 * StreamProcessor.h

 *
 *  Created on: 18.01.2017
 *      Author: Beat
 */

#include "PositionDataUnit.h"
#include "Sensor.h"

#ifndef STREAMPROCESSOR_H_
#define STREAMPROCESSOR_H_

class StreamProcessor {

public:
void updateSensor(Sensor& sensor, PositionDataUnit &positionDataUnit, PositionDataUnit &estimatedPosition);
void initiatePosition(PositionDataUnit &positionDataUnit);


double calculateSpeed(double distance, int time);
double calculateDistance(int x1, int x2, int y1, int y2);

};
#endif /* STREAMPROCESSOR_H_ */

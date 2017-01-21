/*
 * PositionGenerator.h
 *
 *  Created on: 18.01.2017
 *      Author: Beat
 */

#ifndef POSITIONGENERATOR_H_
#define POSITIONGENERATOR_H_

#include "PositionDataUnit.h"


class PositionGenerator
{
public:
	//PositionGenerator();
	//~PositionGenerator();

  // const setzen!
  PositionDataUnit* generatePosition(PositionDataUnit &lastPosition);
};




#endif /* POSITIONGENERATOR_H_ */

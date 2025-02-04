/*
 * Package.cpp
 *
 *  Created on: Feb 4, 2025
 *      Author: simls
 */

#include "Package.h"

namespace Package {

Package::Package() {

}

Package::Package(float weight)
{
	this->Weight = weight;
}

Package::~Package() {

}

float Package::getWeight()
{
	return Weight;
}

void Package::setWeight(float weight)
{
	Weight = weight;
}

} /* namespace Package */

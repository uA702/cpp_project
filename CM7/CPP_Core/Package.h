/*
 * Package.h
 *
 *  Created on: Feb 4, 2025
 *      Author: simls
 */

#ifndef PACKAGE_H_
#define PACKAGE_H_

namespace Package {

class Package {
public:
	Package();
	Package(float weight);
	virtual ~Package();

	float getWeight();
	void setWeight(float weight);

private:
	float Weight{0};
};

} /* namespace Package */

#endif /* PACKAGE_H_ */

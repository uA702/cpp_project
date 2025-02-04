#include <iostream>
#include <numeric>
#include <vector>
#include <memory>

#include "cpp_main.h"
#include "main.h"
#include "retarget.h"
#include "Package.h"
#include "pool.h"
#include "util_ring_allocator_std.h"


extern UART_HandleTypeDef huart3;
extern I2C_HandleTypeDef hi2c2;

float detectAndGetWeigth()
{
	static uint8_t count = 1;
	float Weight = 0.0;

	Weight = static_cast<float>(count)/2.0;

	count++;
	if (count > 30)
	{
		count = 1;
	}

	return Weight;
}

void cpp_main(){
	//MY CODE STARTS HERE
	RetargetInit(&huart3);
	auto packages_memory_pool = new k2lib::Pool<Package::Package, 5>;
	std::vector<Package::Package*, util::ring_allocator_std<Package::Package*>> package_ptr_vector{};

	while(1)
	{
		// Allocate on Pool and store pointer
		if (package_ptr_vector.size() > 3)
		{
			Package::Package* temp_ptr = package_ptr_vector.at(0);
			package_ptr_vector.erase(package_ptr_vector.begin());
			packages_memory_pool->free(temp_ptr);
		}
		package_ptr_vector.push_back(packages_memory_pool->palloc());

		// Get Weight and set to Package
		float temp_weight = detectAndGetWeigth();
		package_ptr_vector.at(package_ptr_vector.end())->setWeight(temp_weight);

		// Total weight of packages
		float total_weight = 0;
		for (uint8_t i = 0; i < package_ptr_vector.size(); i++)
		{
			total_weight += package_ptr_vector.at(i)->getWeight();
		}

		// Print
		std::cout << "Total Weight : " << total_weight << std::endl;

		HAL_Delay(500);
	}
	//MY CODE ENDS HERE
}

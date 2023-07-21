#include <iostream>
#include <thread>

#include "swap.h"

int main() {
	Data first(14, 0.88);
	Data second(6, 0.66);

	std::cout << "До\n" <<
		"Первый объект:" << std::endl;
	std::thread view1stTh_before(&Data::view, first);
	view1stTh_before.join();
	std::cout << "Второй объект:" << std::endl;
	std::thread view2ndTh_before(&Data::view, second);
	view2ndTh_before.join();

	std::thread swap_th(own::swap_UL, std::ref(first), std::ref(second));
	swap_th.join();

	std::cout << "\nПосле\n" <<
		"Первый объект:" << std::endl;
	std::thread view1stTh_after(&Data::view, first);
	view1stTh_after.join();
	std::cout << "Второй объект:" << std::endl;
	std::thread view2ndTh_after(&Data::view, second);
	view2ndTh_after.join();

	return 0;
}
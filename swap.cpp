#include "swap.h"

namespace own {
	void swap_L(Data& first, Data& second) {
		first.get_mutex().lock();
		second.get_mutex().lock();

		Data temp = std::move(second);
		second = first;
		first = temp;

		first.get_mutex().unlock();
		second.get_mutex().unlock();
	}

	void swap_SL(Data& first, Data& second) {
		std::scoped_lock sl(first.get_mutex(), second.get_mutex());

		Data temp = std::move(second);
		second = first;
		first = temp;
	}

	void swap_UL(Data& first, Data& second) {
		std::unique_lock ul1st(first.get_mutex(), std::defer_lock);
		std::unique_lock ul2nd(second.get_mutex(), std::defer_lock);

		Data temp = std::move(second);
		second = first;
		first = temp;

		std::lock(ul1st, ul2nd);
	}
}
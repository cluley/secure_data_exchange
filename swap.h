#pragma once

#include <mutex>

#include "data.h"

namespace own {
	void swap_L(Data& first, Data& second);

	void swap_SL(Data& first, Data& second);

	void swap_UL(Data& first, Data& second);
}
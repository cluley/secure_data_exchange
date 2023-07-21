#include "data.h"

void Data::operator=(Data& other) {
	iVar_ = other.iVar_;
	dVar_ = other.dVar_;
}

void Data::operator=(Data&& other) noexcept {
	iVar_ = other.iVar_;
	dVar_ = other.dVar_;
}

void Data::view() {
	mutex.lock();

	std::cout << "int: " << iVar_ << '\n'
		<< "double: " << dVar_ << std::endl;

	mutex.unlock();
}

std::mutex& Data::get_mutex() {
	return mutex;
}
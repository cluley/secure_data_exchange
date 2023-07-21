#pragma once
#include <mutex>
#include <iostream>

class Data {
public:
	Data(int& iVar, double& dVar) : iVar_(iVar), dVar_(dVar) {}
	Data(int&& iVar, double&& dVar) : iVar_(iVar), dVar_(dVar) {}
	Data(Data& other) : iVar_(other.iVar_), dVar_(other.dVar_) {}
	Data(Data&& other) noexcept : iVar_(other.iVar_), dVar_(other.dVar_) {}
	void operator=(Data& other);
	void operator=(Data&& other) noexcept;

	void view();
	std::mutex& get_mutex();
private:
	int iVar_ = 0;
	double dVar_ = 0;
	std::mutex mutex;
};
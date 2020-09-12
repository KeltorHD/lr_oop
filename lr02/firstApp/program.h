#pragma once

#include "abiturient.h"

#include <fstream>
#include <string>
#include <vector>
#include <memory>

class Program
{
private:
	std::vector<Abiturient*> abitur;

	/*methods*/
	void a();
	void b();
	void c();

public:
	Program();
	~Program();

	Program(const Program&) = delete;
	void operator=(const Program&) = delete;

	void run();
};
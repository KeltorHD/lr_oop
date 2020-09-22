#pragma once

#include "recordBook.h"

#include <fstream>
#include <list>
#include <string>
#include <vector>
#include <memory>

class Program
{
private:
	std::list<RecordBook*> rbMas;

	/*methods*/
	void a();

public:
	Program();
	~Program();

	Program(const Program&) = delete;
	void operator=(const Program&) = delete;

	void run();
};
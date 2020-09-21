#include "recordBook.h"

std::istream& operator>>(std::istream& is, RecordBook::lesson& les)
{
	int tmp{};
	is >> tmp;
	les = static_cast<RecordBook::lesson>(tmp);
	return is;
}

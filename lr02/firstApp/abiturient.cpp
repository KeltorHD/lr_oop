#include "abiturient.h"

std::ostream& operator<<(std::ostream& os, const Abiturient& abitur)
{
	return os << abitur.name << ", " << abitur.adress;
}

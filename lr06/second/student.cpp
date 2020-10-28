#include "student.h"

size_t Student::get_course() const
{
	return this->course;
}

const std::string& Student::get_fio() const
{
	return this->fio;
}

const std::string& Student::get_spetiality() const
{
	return this->spetiality;
}

bool Student::operator==(const Student& st)
{
	if (this->fio == st.fio && this->spetiality == st.spetiality && this->course == st.course)
		return true;
	return false;
}

std::ostream& operator<<(std::ostream& os, const Student& st)
{
	os << "Студент: " << st.fio << ", специальность: " << st.spetiality << ", курс: " << st.course;
	return os;
}

std::istream& operator>>(std::istream& is, Student& st)
{
	std::getline(is, st.fio);
	std::getline(is, st.spetiality);
	std::string tmp_s{};
	std::getline(is, tmp_s);
	st.course = std::stoi(tmp_s);
	return is;
}

bool less(const Student& st1, const Student& st2, size_t i)
{
	switch (i)
	{
	case 1:
		return st1.fio < st2.fio;
		break;
	case 2:
		return st1.spetiality < st2.spetiality;
		break;
	case 3:
		return st1.course < st2.course;
		break;
	default:
		break;
	}
	return false;
}

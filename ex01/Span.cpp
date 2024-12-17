#include "Span.hpp"

Span::Span() : _maxSize(0) {}

Span::Span(unsigned int n) : _maxSize(n) {}

Span::Span(const Span &other) : _maxSize(other._maxSize), _nums(other._nums) {}

Span::~Span() {}

Span &Span::operator=(const Span &other)
{
	if (this == &other)
		return *this;
	_maxSize = other._maxSize;
	_nums = other._nums;
	return *this;
}

void Span::addNumber(int n)
{
	if (this->_nums.size() >= this->_maxSize)
		throw std::runtime_error("Span is already full");
	this->_nums.push_back(n);
}

int Span::shortestSpan() const
{
	if (this->_nums.size() < 2)
		throw std::runtime_error("Span is too short");
	std::vector<int> tmp = this->_nums;
	std::sort(tmp.begin(), tmp.end());

	int min = std::numeric_limits<int>::max();
	for (size_t i = 1; i < tmp.size(); i++)
	{
		int diff = tmp[i] - tmp[i - 1];
		if (diff < min)
			min = diff;
	}
	return min;
}

int Span::longestSpan() const
{
	if (this->_nums.size() < 2)
		throw std::runtime_error("Span is too short");
	std::vector<int> tmp = this->_nums;
	std::sort(tmp.begin(), tmp.end());
	return tmp.back() - tmp.front();
}
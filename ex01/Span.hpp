#pragma once

#include <vector>
#include <iostream>
#include <stdexcept>
#include <algorithm>


class Span
{

private:
	unsigned int _maxSize;
	std::vector<int> _nums;

public:
	Span();
	Span(unsigned int n);
	Span(const Span &other);
	~Span();
	Span &operator=(const Span &other);

	void addNumber(int n);
	template <typename Iterator>
	void addNumber(Iterator begin, Iterator end);
	int shortestSpan() const;
	int longestSpan() const;
};

template <typename Iterator>
void Span::addNumber(Iterator begin, Iterator end)
{
	if (this->_nums.size() + std::distance(begin, end) > this->_maxSize)
		throw std::runtime_error("Adding these numbers would exceed Span's capacity");
	this->_nums.insert(this->_nums.end(), begin, end);
}

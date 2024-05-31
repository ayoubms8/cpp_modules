#pragma once
#include <vector>
#include <numeric>
#include <algorithm>
#include <iostream>
#include <exception>

class Span
{
private:
	std::vector<int> data;
	unsigned int _N;
public:
	Span();
	Span(unsigned int N);
	Span(Span const &copy);
	Span &operator=(Span const &copy);
	void addNumber(int a);
	template<typename iterator>
	void addNumber(iterator begin, iterator end);
	int	shortestSpan();
	int	longestSpan();
	~Span();
};

template <typename iterator>
void Span::addNumber(iterator begin, iterator end)
{
	unsigned int counter = 0;
	while (begin != end)
	{
		if (counter >= this->_N)
			throw std::logic_error("Span is full");
		data.push_back(*begin);
		begin++;
		counter++;
	}
}


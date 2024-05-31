#include "Span.hpp"


Span::Span(unsigned int N): _N(N)
{
}

Span::Span(Span const &copy)
{
	*this = copy;
}

Span &Span::operator=(Span const &copy)
{
	if (this != &copy)
	{
		this->data = copy.data;
		this->_N = copy._N;
	}
	return (*this);
}

void Span::addNumber(int a)
{
	if (data.size() < _N)
		data.push_back(a);
	else
		throw std::logic_error("Span is full");
}

int	Span::longestSpan(void)
{
	if (data.size() < 2) {
        throw std::logic_error("Span must have at least 2 elements");
    }
    int minElement = *std::min_element(data.begin(), data.end());
    int maxElement = *std::max_element(data.begin(), data.end());

    return maxElement - minElement;
}

int	Span::shortestSpan(void)
{
	if (data.size() < 2) {
        throw std::logic_error("Span must have at least 2 elements");
    }
    std::vector<int> sortedData = data;
    std::sort(sortedData.begin() , sortedData.end());
	unsigned int i = 0;
	int diff = abs(sortedData[i + 1] - sortedData[i]);
	for (i = 0; i < data.size() - 1; i++)
	{
		if (diff > sortedData[i + 1] - sortedData[i])
			diff = abs(sortedData[i + 1] - sortedData[i]);
	}
	return (diff);
}


Span::~Span()
{
}
#include <iostream>
#include "Span.hpp"
#include <list>

int main()
{
	try
	{
		Span sp = Span(10);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;

		// std::list<int> lst(10000);
		// std::generate(lst.begin(), lst.end(), std::rand);
		// Span sp2 = Span(10000);
		// sp2.addNumber(lst.begin(), lst.end());
		// std::cout << sp2.shortestSpan() << std::endl;
		// std::cout << sp2.longestSpan() << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}

	return 0;
}
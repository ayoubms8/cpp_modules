#include <iostream>
#include "MutantStack.hpp"
#include <stack>

int main()
{
	try
	{
		MutantStack<int> mstack;
		mstack.push(5);
		mstack.push(17);
		std::cout << mstack.top() << std::endl;
		mstack.pop();
		std::cout << mstack.size() << std::endl;
		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		mstack.push(0);
		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();
		++it;
		--it;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
		std::stack<int> s(mstack);
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}
	return 0;
}

// int main()
// {
// 	try
// 	{
// 		MutantStack<int> mstack;

// 		mstack.push(5);
// 		mstack.push(17);

// 		std::cout << "Top of integer stack: " << mstack.top() << std::endl;

// 		mstack.pop();

// 		std::cout << "Top of integer stack after pop: " << mstack.top() << std::endl;

// 		MutantStack<std::string> strStack;

// 		strStack.push("Hello");
// 		strStack.push("World");
// 		strStack.push("bruh");
// 		strStack.push("000");
// 		strStack.push("1111");
// 		strStack.push("22222");
// 		strStack.push("3333");
// 		strStack.push("444");
// 		MutantStack<std::string>::iterator it = strStack.begin();
// 		MutantStack<std::string>::iterator ite = strStack.end();
// 		++it;
// 		--it;
// 		while (it != ite)
// 		{
// 			std::cout << *it << std::endl;
// 			++it;
// 		}
// 		std::stack<std::string> s(strStack);
// 	}
// 	catch (const std::exception &e)
// 	{
// 		std::cerr << e.what() << '\n';
// 	}

// 	return 0;
// }

#pragma once
#include <string>
#include <iostream>
#include <stack>


class RPN {
	private:
		RPN();
		RPN(RPN const &copy);
		RPN &operator=(RPN const &copy);
		~RPN();
	public:
		static int calculate(std::stack<int> *stak, int *res, std::string str);
};
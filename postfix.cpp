#include <stdio.h>
#include <iostream>
#include <stack>
#include <string>

bool	isop(const char &c)
{
	if (c == '+' || c == '-' || c == '*' || c == '/')
		return true;
	return false;
}

int prior(char op) {
    if(op == '+' || op == '-')
        return 1;
    else if(op == '*' || op == '/')
        return 2;
    return 0;
}


int		priorityCmp(char op1, char op2)
{
	int pr1 = prior(op1);
	int pr2 = prior(op2);
	return pr1 >= pr2;
}

std::string InfixToPostfix(std::string in_str)
{
	std::string			out_str = "";
	std::stack<char>	op;

	for (auto& ch : in_str)
	{
		if (ch == ' ')
			out_str += ch;
		if (isdigit(ch))
			out_str += ch;
		else if (ch == '(')	
			op.push(ch);
		else if (isop(ch))
		{
			if (!op.empty())
			{
				while (!op.empty() && priorityCmp (op.top(), ch))
				{
					
					out_str += op.top();
					op.pop();
				}
			}
				op.push(ch);
		}
		else if (ch == ')')
		{
			while (op.top() != '(')
			{
				if(!op.empty())
				{
					out_str += op.top();
					op.pop();
				}
			}
			if (!op.empty()) 
				op.pop();
		}
	}
	while (!op.empty())
	{
		out_str += op.top();
		op.pop();
	}
	return out_str;
}

int	doOp(const char &c, const int &a, const int &b)
{
	if (c == '*')
		return a * b;
	if (c == '/')
		return a / b;
	if (c == '+')
		return a + b;
	if (c == '-')
		return a - b;
}

int		calculatePostfix(const std::string &str)
{
	std::stack<int> operands;
	int	a;
	int	b;
	for (const auto &ch : str)
	{
		if (isdigit(ch))
			operands.push(ch - '0');
		if (isop(ch))
		{
			b = operands.top();
			operands.pop();
			a = operands.top();
			operands.pop();
			operands.push(doOp(ch, a, b));
		}
	}
	return (operands.top());
}

int main()
{
	//std:: string str = "(23+3)*(4-5)*6";
	//std::cout << *str.end();
	//std::string::const_iterator it = str.begin();
	std::cout << calculatePostfix(InfixToPostfix("(2+3)*4-5*6"));
}
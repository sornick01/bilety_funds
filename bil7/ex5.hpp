#include <iostream>

class Fraction
{
private:
	int		 	numerator;
	int		 	denominator;
	void		reduction();
public:
	// class ZeroDenominatorException : public std::exception
	// {
	// public:
	// 	const char* what() const throw();
	// };
	Fraction			&operator+=(const Fraction &right);
	Fraction			&operator-=(const Fraction &right);
	Fraction			&operator*=(const Fraction &right);
	Fraction			&operator/=(const Fraction &right);
	Fraction			operator+(const Fraction &right) const;
	Fraction			operator-(const Fraction &right) const;
	Fraction			operator*(const Fraction &right) const;
	Fraction			operator/(const Fraction &right) const;
	friend std::ostream	&operator<<(std::ostream &out, const Fraction &frac);
	Fraction(const int &a, const int &b);
	Fraction(const Fraction &frac) : numerator(frac.numerator), denominator(frac.denominator)
	{}
};

class NodeFraction
{
	Fraction _data;
	NodeFraction *_left, *_right;
public:
	NodeFraction(const Fraction &frac) : _data(frac), _left(nullptr), _right(nullptr)
	{}
};

class Tree
{
	void *
};
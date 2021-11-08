#include <iostream>

int	NOD(const int &a, const int &b)
{
	if (a % b == 0)
		return b;
	if (b % a == 0)
		return a;
	if (a > b)
		return NOD(a % b, b);
	return NOD(a, b % a);
}

int	NOK(const int &a, const int &b)
{
	return (a * b) / NOD(a, b);
}

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

Fraction::Fraction(const int &a, const int &b) : numerator(a), denominator(b)
{
	if (denominator == 0)
		throw ZeroDenominatorException("Zero denominator");
}

void	Fraction::reduction()
{
	int nod = NOD(abs(numerator), abs(denominator));
	numerator /= nod;
	denominator /= nod;
	if (numerator < 0 && denominator < 0)
	{
		numerator = -numerator;
		denominator = -denominator;
	}
}

std::ostream	&operator<<(std::ostream &out, const Fraction &frac)
{
	out << '[' << frac.numerator << '/' << frac.denominator << ']';
	return out;
}

Fraction &Fraction::operator+=(const Fraction &right)
{
	int oldDenominator;
	if (denominator == right.denominator)
		numerator += right.numerator;
	else
	{
		oldDenominator = denominator;
		denominator = NOK(denominator, right.denominator);
		numerator = numerator * (denominator / oldDenominator)
			+ right.numerator * (denominator / right.denominator);
	}
	this->reduction();
	return *this;
}

Fraction	Fraction::operator+(const Fraction &right) const
{
	Fraction frac(*this);
	frac += right;
	frac.reduction();
	return frac;
}

Fraction	&Fraction::operator-=(const Fraction &right)
{
	int oldDenominator;
	if (denominator == right.denominator)
		numerator -= right.numerator;
	else
	{
		oldDenominator = denominator;
		denominator = NOK(denominator, right.denominator);
		numerator = numerator * (denominator / oldDenominator)
			- right.numerator * (denominator / right.denominator);
	}
	this->reduction();
	return *this;
}

Fraction	Fraction::operator-(const Fraction &right) const
{
	Fraction frac(*this);
	frac -= right;
	frac.reduction();
	return frac;
}

Fraction	&Fraction::operator*=(const Fraction &right)
{
	numerator *= right.numerator;
	denominator *= right.denominator;
	this->reduction();
	return(*this);
}

Fraction	Fraction::operator*(const Fraction &right) const
{
	Fraction frac(*this);
	frac *= right;
	frac.reduction();
	return frac;
}

Fraction	&Fraction::operator/=(const Fraction &right)
{
	if (right.numerator == 0)
		throw std::logic_error("zero division");
	numerator *= right.denominator;
	denominator *= right.numerator;
	this->reduction();
	return(*this);
}

Fraction	Fraction::operator/(const Fraction &right) const
{
	Fraction frac(*this);
	frac /= right;
	frac.reduction();
	return frac;
}

int main()
{	
	Fraction a(5, 10);
	Fraction b(-3, -4);
	// a /= b;
	std::cout << a / b;
}


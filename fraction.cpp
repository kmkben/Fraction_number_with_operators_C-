#include "fraction.hpp"

using namespace std;


Fraction::Fraction() : m_numerator(0), m_denominator(1)
{
}

Fraction::Fraction(int numerator) : m_numerator(numerator), m_denominator(1)
{
}

Fraction::Fraction(int numerator, int denominator) : m_numerator(numerator)
{
	if (denominator != 0)
	{
		m_denominator = denominator;
	}
	else
	{
		cout << "Error: the denominator should not be null" << endl;
		m_denominator = 1;
	}
}

Fraction& Fraction::inverse()
{
	/*int tmp = m_numerator;
	m_numerator = m_denominator;
	m_denominator = tmp;*/

	Fraction copy = *this;

	m_numerator = copy.m_denominator;
	m_denominator = copy.m_numerator;

	return *this;
}

void Fraction::print(ostream& os) const
{
	if (m_denominator == 1)
	{
		os << m_numerator;
	}
	else
	{
		os << m_numerator << "/" << m_denominator ;

	}
}

Fraction& Fraction::operator+=(Fraction const& fraction)
{
	if ( m_denominator == fraction.m_denominator)
	{
		m_numerator += fraction.m_numerator;
	}
	else
	{
		m_numerator = (m_numerator * fraction.m_denominator) + (m_denominator * fraction.m_numerator);
		m_denominator = m_denominator * fraction.m_denominator;	
	}

	return *this;
}

Fraction& Fraction::operator-=(Fraction const& fraction)
{
	if ( m_denominator == fraction.m_denominator)
	{
		m_numerator -= fraction.m_numerator;
	}
	else
	{
		m_numerator = (m_numerator * fraction.m_denominator) - (m_denominator * fraction.m_numerator);
		m_denominator = m_denominator * fraction.m_denominator;	
	}

	return *this;

}

Fraction& Fraction::operator*=(Fraction const& fraction)
{
	m_numerator *= fraction.m_numerator;
	m_denominator *= fraction.m_denominator;

	return *this;
}

Fraction& Fraction::operator/=(Fraction const& fraction)
{
	//Fraction copy = fraction.inverse();

	m_numerator *= fraction.m_denominator;
	m_denominator *= fraction.m_numerator;

	return *this;
}

bool Fraction::isEqualTo(Fraction const& f) const
{
	return (m_numerator == f.m_numerator && m_denominator == f.m_denominator);
}


ostream& operator<<(ostream& os, Fraction const& fraction)
{
	fraction.print(os);

	return os;
}

Fraction operator+(Fraction const& a, Fraction const& b)
{
	Fraction copy(a);
	copy += b;
	return copy;
}

Fraction operator-(Fraction const& a, Fraction const& b)
{
	Fraction copy(a);
	copy -= b;
	return copy;
}

Fraction operator*(Fraction const& a, Fraction const& b)
{
	Fraction copy(a);
	copy *= b;
	return copy;
}

Fraction operator/(Fraction const& a, Fraction const& b)
{
	Fraction copy(a);
	copy /= b;
	return copy;
}


bool operator==(Fraction const& a, Fraction const& b)
{
	return a.isEqualTo(b);
}

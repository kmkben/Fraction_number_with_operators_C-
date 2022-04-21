#ifndef DEF_FRACTION
#define DEF_FRACTION


#include <iostream>


class Fraction
{
	public:
		Fraction();
		Fraction(int);
		Fraction(int, int);

		Fraction& inverse();


		Fraction& operator+=(Fraction const&);
		Fraction& operator-=(Fraction const&);
		Fraction& operator*=(Fraction const&);
		Fraction& operator/=(Fraction const&);

		bool isEqualTo(Fraction const&) const;


	private:
		void print(std::ostream& os) const;

		int m_numerator;
		int m_denominator;


	friend std::ostream& operator<<(std::ostream&, Fraction const&);

};

Fraction operator+(Fraction const&, Fraction const&);
Fraction operator-(Fraction const&, Fraction const&);
Fraction operator*(Fraction const&, Fraction const&);
Fraction operator/(Fraction const&, Fraction const&);

bool operator==(Fraction const&, Fraction const&);


#endif  //DEF_FRACTION

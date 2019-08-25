#include <iostream>
#include "header.h"

 bool operator==(const Rational& r1, const Rational& r2) //equality
 {
 	return ((r1.getNumer() == r2.getNumer()) &&(r2.getDenom()==r2.getDenom()));
 }
 bool operator!=(const Rational& r1, const Rational& r2) //inequality
 {
 	return !(r1 == r2);
 }
  Rational Rational::operator=( const Rational& r2) // assignment
 {
 	return  Rational{r2.getNumer() , r2.getDenom()};
 }
 Rational operator*(const Rational& r1, const Rational& r2) // multiplication
 {
 	return Rational{r1.getNumer()*r2.getNumer(), r1.getDenom()*r2.getDenom()};
 }
 Rational operator*(double x , const Rational& r) //multiplication with another real number.
 {
 	return Rational{ static_cast<long int>((x * r.getNumer())),r.getDenom()};
 }
 Rational operator/(const Rational& r1, const Rational& r2) // division
 {
 	return Rational{r1.getNumer()*r2.getDenom(),r1.getDenom()*r2.getNumer()};
 }
 Rational operator+(const Rational& r1, const Rational& r2) //addition
 {
 	return Rational{( (r1.getNumer()*r2.getDenom()) + (r1.getDenom()*r2.getNumer()) ),(r1.getDenom() * r2.getDenom())};
 }
 Rational operator-(const Rational& r1, const Rational& r2)
 {
 	return r1+((-1)*r2 );
 }

 std::ostream& operator<<(std::ostream& out, const Rational& r)
 {
 	out << '(' << r.getNumer() << '/' << r.getDenom() << ')';
 }
 
 double rational_to_double(const Rational& r)
 {
 	return ((double(r.getNumer()))/r.getDenom());
 }

 int main( int argc , char *argv[])
 {
 	Rational num1 {5,6};
	Rational num2 {3,4};

		std::cout << "num1 in floating point form:" << rational_to_double(num1) << '\n';
		std::cout << "num2 in floating point form:" << rational_to_double(num2) << '\n';
		std::cout << "Addition:" << num1+num2 << '\n';
		std::cout << "Mutiplication:" << num1*num2 << '\n';
		std::cout << "Subtraction:"  << num1-num2 << '\n';
		std::cout << "Division:" << num1/num2 << '\n';

		return 0;
 }

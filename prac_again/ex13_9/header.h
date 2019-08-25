
class Rational
{
	private:
		long int numerator;
		long int denominator;
	public:
		int getNumer()const { return numerator;}
		int getDenom()const { return denominator;}
		Rational operator=(const Rational&);
		
		Rational(long int p,long int q) // constructor
		:numerator{p},denominator{q}
		{
		
		}
};


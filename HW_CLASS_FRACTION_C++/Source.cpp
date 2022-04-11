#include<iostream>
#include<assert.h>
using namespace std;


class Fraction {
	int nominator;
	int denominator;



public:
	Fraction() :nominator(0), denominator(1) {}



	Fraction(const int& nominator, const int denominator) {
		SetNominator(nominator);
		SetDenominator(denominator);



	}
	int GetNominator()const {
		return nominator;
	}



	int GetDenominator()const {
		return denominator;
	}



	void SetNominator(const int& nominator) {
		this->nominator = nominator;
	}



	void SetDenominator(const int& denominator) {
		assert(denominator >= 0 && "ZERO DIVISION ERROR: The denominator cannot be zero !!!");
		this->denominator = denominator;
	}

	Fraction& operator++() {
		this->denominator++;
		this->nominator++;
		SetDenominator(this->denominator);
		SetNominator(this-> nominator);
		return *this;
	}

	Fraction& operator--() {
		this->denominator--;
		this->nominator--;
		SetDenominator(this->denominator);
		SetNominator(this->nominator);
		return *this;
	}

	Fraction& operator++(int) {
		Fraction fraction;
		int temp_d= this->denominator;
		int temp_n = this->nominator;
		this->denominator++;
		this->nominator++;
		fraction.SetDenominator(temp_d);
		fraction.SetNominator(temp_n);
		return fraction;
	}

	Fraction& operator--(int) {
		Fraction fraction;
		int temp_d = this->denominator;
		int temp_n = this->nominator;
		this->denominator--;
		this->nominator--;
		fraction.SetDenominator(temp_d);
		fraction.SetNominator(temp_n);
		return fraction;
	}

	Fraction& operator+=(const Fraction& other) {
		int d = other.GetDenominator() * this->denominator;
		int n = other.GetNominator() * (d / other.GetDenominator()) + this->nominator * (d / this->denominator);
		this->denominator = d;
		this->nominator = n;
		return *this;
	}

	Fraction& operator-=(const Fraction& other) {
		int d = other.GetDenominator() * this->denominator;
		int n = this->nominator * (d / this->denominator) - other.GetNominator() * (d / other.GetDenominator());
		this->nominator = n;
		this->denominator = d;
		return *this;
	}

	Fraction& operator*=(const Fraction& other) {
		this->denominator *= other.GetDenominator();
		this->nominator *= other.GetNominator();

		return *this;
	}

	Fraction& operator/=(const Fraction& other) {
		this->denominator *= other.GetNominator();
		this->nominator *= other.GetDenominator();
		return *this;
	}

	
	Fraction& plus(const Fraction& other) {
		Fraction fraction;
		int d = this->denominator * other.GetDenominator();
		int n = this->nominator * (d / this->denominator) + other.GetNominator() * (d / other.GetDenominator());
		fraction.SetDenominator(d);
		fraction.SetNominator(n);

		return fraction;
	}

	Fraction& minus(const Fraction other) {
		Fraction fraction;
		int d = this->denominator * other.GetDenominator();
		int n = this->nominator * (d / this->denominator) - other.GetNominator() * (d / other.GetDenominator());
		fraction.SetDenominator(d);
		fraction.SetNominator(n);
		return fraction;
	}

	Fraction& mult(const Fraction& other) {
		Fraction fraction;
		int d = this->denominator * other.GetDenominator();
		int n = this->nominator * other.GetNominator();
		fraction.SetDenominator(d);
		fraction.SetNominator(n);
		return fraction;
	}

	Fraction& div(const Fraction& other) {
		Fraction fraction;
		int d = this->denominator * other.GetNominator();
		int n = this->nominator * other.GetDenominator();
		fraction.SetDenominator(d);
		fraction.SetNominator(n);
		return fraction;
	}
	friend ostream& operator<<(ostream& out, const Fraction& player);
	friend istream& operator>>(istream& in, Fraction& player);





};


Fraction& Reduce(Fraction& f) {

	int count = 0;
	int d = f.GetDenominator();
	int n = f.GetNominator();
	if (f.GetDenominator() > f.GetNominator()) count = f.GetNominator();
	else count = f.GetDenominator();
	
	for (size_t i = 1; i < count; i++)
	{
		if (f.GetDenominator() % i == 0 && f.GetNominator() % i == 0) {
			d /= i;
			n /= i;
		}
	}
	f.SetDenominator(d);
	f.SetNominator(n);

	return f;

}

Fraction& operator+(const Fraction& first, const Fraction& second) {



	Fraction fraction;
	int d = first.GetDenominator() * second.GetDenominator();
	int n = first.GetNominator() * (d / first.GetDenominator()) + second.GetNominator() * (d / second.GetDenominator());

	fraction.SetNominator(n);
	fraction.SetDenominator(d);



	return fraction;

}

Fraction& operator-(const Fraction& first, const Fraction second) {
	int d = first.GetDenominator() * second.GetDenominator();
	int n = first.GetNominator() * (d / first.GetDenominator()) - second.GetNominator() * (d / second.GetDenominator());

	Fraction fraction;
	fraction.SetDenominator(d);
	fraction.SetNominator(n);

	return fraction;

}

Fraction& operator*(const Fraction& first, const Fraction& second) {

	int d = first.GetDenominator() * second.GetDenominator();
	int n = first.GetNominator() * second.GetNominator();

	Fraction fraction;
	fraction.SetDenominator(d);
	fraction.SetNominator(n);
	return fraction;
}

Fraction& operator/(const Fraction& first, const Fraction& second) {
	
	int d = first.GetDenominator() * second.GetNominator();
	int n = first.GetNominator() * second.GetDenominator();

	Fraction fraction;
	fraction.SetDenominator(d);
	fraction.SetNominator(n);
	
	return fraction;
}

ostream& operator<<(ostream& out, const Fraction& fraction) {
	cout << "Fraction : " << fraction.nominator << "/" << fraction.denominator << endl;
	return out;
}



istream& operator>>(istream& in, Fraction& fraction) {


	cout << "Enter nominator: ";
	int n = 0;
	cin >> n;
	fraction.SetNominator(n);



	cout << "Enter denominator: ";
	int d = 0;
	cin >> d;
	fraction.SetDenominator(d);



	return in;
}



void main() {


	Fraction a(2, 20);
	Fraction b(5, 120);


	Fraction d = a.mult(b);

	Reduce(d);//Ixtisar
	cout << d << endl;
	//cout << --a << endl;
	//cout << b << endl;;

//	cout <<"The Result(+) --> "<< result << endl;

}


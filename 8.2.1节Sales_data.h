#pragma once
#ifndef Sales_data_h
#define Sales_data_h

#include<iostream>
#include<string>

class Sales_data {
	friend std::istream& read(std::istream& in, Sales_data& item);
	friend std::ostream& print(std::ostream& out, Sales_data& item);
	friend Sales_data add(const Sales_data& ldata, const Sales_data& rdata);

public:
	Sales_data(std::string s, unsigned n, double p) :bookNo(s), units_sold(n), revenue(n* p)
	{
		std::cout << "Sales_date(std::string s, unsigned n, double p);" << std::endl;
	}

	Sales_data() :Sales_data("", 0, 0.0f)
	{
		std::cout << "Sales_data() :Sales_data("", 0, 0.0f)" << std::endl;
	}

	Sales_data(std::string s) :Sales_data(s, 0, 0.0f)
	{
		std::cout << "Sales_data(std::string s) :Sales_data(s, 0, 0.0f)" << std::endl;
	}

	Sales_data(std::istream& in);

	std::string isbn() const { return bookNo;  }
	Sales_data& combine(const Sales_data&);

private:
	inline double avgPrice() const;

private:
	std::string bookNo;
	unsigned units_sold = 0;
	double revenue = 0;
};

inline 
double Sales_data::avgPrice() const
{
	return units_sold ? revenue / units_sold : 0;
}

#endif


#include "Sales_data.h"

//友元函数
std::istream& read(std::istream& in, Sales_data& item)
{
	double price = 0.0;
	in >> item.bookNo >> item.units_sold >> price;
	item.revenue = item.units_sold * price;
	return in;
}

std::ostream& print(std::ostream& out, Sales_data& item)
{
	out << "编号：" << item.bookNo << std:: endl;
	out << "销售量：" <<item.units_sold << std::endl;
	out << "销售额；" << item.revenue << std::endl << std::endl;;
	return out;
}

Sales_data add(const Sales_data& ldata, const Sales_data& rdata)
{
	Sales_data sum = ldata;
	sum.combine(rdata);
	return sum;
}


//构造函数
Sales_data::Sales_data(std::istream& in):Sales_data()
{
	read(in, *this);
}

Sales_data& Sales_data::combine(const Sales_data& sdata)
{
	units_sold += sdata.units_sold;
	revenue += sdata.revenue;
	return *this;
}

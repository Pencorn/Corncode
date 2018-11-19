
}#include "_circle.h"
double circle::area()
{
	//radius *= 2;
	double a = getcircle();;
	return pi*radius*radius;
}
double circle::circumference()
{
	return 2 * pi*radius;
}
double circle::getcircle()const
{
	//double a = area();
	//radius *= 2;
	return radius;

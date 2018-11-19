#ifndef _circle
#define  _circle
class circle
{
private:
	double radius;
	const double pi;
public:
	circle(double r= 0) :pi(3.1415926)
	{
		radius = r;
	}
	double area();
	double circumference();
	double getcircle()const;

};
#endif

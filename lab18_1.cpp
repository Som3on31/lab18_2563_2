#include <iostream>
#include <cmath>
using namespace std;

struct Rect
{
	double x, y, w, h;
};

double overlap(Rect R1, Rect R2)
{
	double lappedCorX = max(R1.x, R2.x);
	double lappedCorY = min(R1.y, R2.y);

	double lappedCorXMax = min(R1.x + R1.w, R2.x + R2.w);		//Needs to be fixed ASAP
	double lappedCorYMin = max(R1.y - R1.h, R2.y - R2.h);

	double widthLapped = lappedCorXMax - lappedCorX;

	double heightLapped = lappedCorY - lappedCorYMin;

	double area = widthLapped * heightLapped;
	
	if (area < 0) return 0;
	else return area;
}

int main()
{
	Rect R1 = {1,1,5,5};
	Rect R2 = {7,2,3,3};	
	cout << overlap(R1,R2);
	return 0;
}

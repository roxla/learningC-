#include <iostream>
using namespace std;
#include "point.h"
#include "circle.h"

//判断点与圆之间的关系
void isInCircle(Circle &c,Point &p)
{
	//1. 计算两点之间的距离的平方
	int distance = 
	(c.getCenter().getX() - p.getX()) * (c.getCenter().getX() - p.getX()) + 
	(c.getCenter().getY() - p.getY()) * (c.getCenter().getY() - p.getY());

	//2. 计算半径的平方
	int rDistance = c.getR() * c.getR();

	//3. 判断关系
	if(distance == rDistance)
	{
		cout << "点在圆上" << endl;
	}
	else if(distance > rDistance)
	{
		cout << "点在圆外" << endl;
	}
	else{
		cout << "点在圆内" << endl;
	}
}

int main()
{
	//1. 创建圆
	Circle c;
	c.setR(10);  //设置圆的半径

	Point center;
	center.setX(10);  //设置一个点的x轴的坐标为10
	center.setY(10);  //设置一个点的y轴的坐标为10

	c.setCenter(center); //将该点设置为圆心

	//2. 创建点
	Point p;
	p.setX(10);
	p.setY(21);

	//3. 判断点与圆之间的关系。
	isInCircle(c,p);

	return 0;
}
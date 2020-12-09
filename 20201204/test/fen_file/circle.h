#ifndef _CIRCLE_H_
#define _CIRCLE_H_

#include "point.h"

//圆类
//设计圆类
class Circle{
public:
	//设置半径
	void setR(int r);
	
	//获取半径
	int getR();

	//设置圆心
	void setCenter(Point center);
	
	//获取圆心
	Point getCenter();
	
private:
	int m_R;         //圆的半径

	//在类中可以让另外一个类作为本类中的成员
	Point m_Center;  //圆心
};

#endif
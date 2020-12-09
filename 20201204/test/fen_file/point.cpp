#include "point.h"

//设置x轴坐标
void Point::setX(int x)
{
	m_x = x;
}

//设置y轴坐标
void Point::setY(int y)
{
	m_y = y;
}

//获取x轴坐标
int Point::getX()
{
	return m_x;
}

//获取y轴坐标
int Point::getY()
{
	return m_y;
}

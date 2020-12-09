#ifndef _POINT_H_
#define _POINT_H_

//点类
//设计点类
class Point{
public:
	//设置x轴坐标
	void setX(int x);

	//设置y轴坐标
	void setY(int y);

	//获取x轴坐标
	int getX();

	//获取y轴坐标
	int getY();

private:
	int m_x;  //点的x轴
	int m_y;  //点的y轴
};

#endif
#ifndef BALL_H
#define BALL_H

#include <QColor>
#include <QRect>
#include <QPen>
#include <QBrush>
#include <QPainter>

//表情球类:
class Ball
{
public:
	//默认构造函数:
    Ball();
	//常规构造函数:
    Ball(double xpos,double ypos,double r,double s,double a,
			 QString I="D:/Git/Commodity/QtProject/huaji.png");//增加完整构造函数
	//设置球移动的最大矩形边框的函数
	void setRectangle(const QRect& rect){
        this->rect=rect;
    }
	//球的绘制函数
    void draw(QPainter *p);  //绘制小球,传给它一个画布，将来不用QT组件，一致性会更好。

	//检测球相互碰撞的函数
	bool checkCollision(Ball &b);
	//控制球移动函数
    void move(); //在指定的方向上移动 1 步
	//检测球是否超出边界的函数:
    void checkBoundary();

	//获取各个私有数据成员的值的函数:
	double getRadius(void);
	double getX(void) const ;
	double getY(void) const ;
	QString getImage() const;

	//球的坐标更新函数:
	void editXY(double newX, double newY);
	//球的移动角度更新函数
	void editAngle(double newA);
	//球的和速度更新函数
	void editspeed(double sX, double sY);
	//球的XY速度分量的更新函数
	void updateXYSpeed(void);
	//球的静态数据成员, 使用类内初始化
	static const int MAX_SPEED=10, MIN_SPEED=3;
	//设置球的贴图路径
	void setImage(const QString &value);

private:
	double x,y;		//球的中心位置
	double radius;  //球半径
	double speed;	//球的和速度
	double speedX;  //球速度在X方向的分量
	double speedY;  //球速度在Y方向的分量
	double angle;	//球移动角度, 以向下为轴
	QString image;	//球的贴图路径
	QRect rect;		//各个球运动的窗口矩形区域
};

#endif // BALL_H

#ifndef BALL_H
#define BALL_H

#include <QColor>
#include <QRect>
#include <QPen>
#include <QBrush>
#include <QPainter>
class Ball
{
public:
    Ball();
    Ball(double xpos,double ypos,double r,double s,double a,
			 QString I="D:/Git/Commodity/QtProject/huaji05.png");//增加完整构造函数
    void setRectangle(const QRect& rect){
        this->rect=rect;
    }
    void draw(QPainter *p);  //绘制小球,传给它一个画布，将来不用QT组件，一致性会更好。

	bool checkCollision(Ball &b);
    void move(); //在指定的方向上移动 1 步
    void checkBoundary();

	double getRadius(void);
	double getX(void) const ;
	double getY(void) const ;

	void editXY(double newX, double newY);
	void editAngle(double newA);
	void editspeed(double sX, double sY);
	void updateXYSpeed(void);

	static const int MAX_SPEED=10, MIN_SPEED=3;

private:
	double x,y;		//小球的中心为位置
    double radius;  //小球半径
	double speed;	//小球的和速度
	double speedX;  //小球速度在X方向的分量
	double speedY;  //小球速度在Y方向的分量
	double angle;	//小球移动角度
    QColor color;   //小球填充颜色
	QString image;
	QRect rect;		//用于检测的窗口矩形区域,这里把它作为了数据成员.将来最好做成传参的形式。
};

#endif // BALL_H

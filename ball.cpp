#include "ball.h"
#include <cmath>
#include <QImage>
#include <QRectF>

Ball::Ball():Ball(40,100,10,10,45,
				  QString("D:/Git/Commodity/QtProject/huaji05.png"))
{   //通过委托构造实现缺省构造函数
}
Ball::Ball(double xpos, double ypos, double r, double s, double a, QString I)
	:x(xpos),y(ypos),radius(r),speed(s),angle(a),image(I)
//	  ,MAX_SPEED(15), MIN_SPEED(5)
{
	const double PI=3.14159;
	this->speedX=speed*std::sin(angle*PI/180);
	this->speedY=speed*std::cos(angle*PI/180);

	return ;
}
void Ball::draw(QPainter *p)
{
//	QPen pen(Qt::white,1,Qt::SolidLine);
//	p->setPen(pen);
	//定义坐标,左上角坐标+矩形长宽
//	p->drawEllipse(r);

	QRect r(x-radius,y-radius,radius*2,radius*2);
	QImage picture(this->image);

	p->drawImage (r,picture);
	return ;
}

void Ball::move(){
	double dx,dy;
	const double PI=3.14159;
	dx=speed*std::sin(angle*PI/180);
	dy=speed*std::cos(angle*PI/180);
	x+=dx;
	y+=dy;
	checkBoundary();

//删除原有的阻尼系统
//	speed*=0.999;
//	if(speed<0.1){
//		speed=0;
//	}
	updateXYSpeed ();
}

void Ball::checkBoundary(){ //左上角（0,0）向右下递增。
	if(y+radius>rect.height()){ //超出底边界
		angle=180-angle;
		y=rect.height()-radius; //拉回来
	}
	if(y-radius<0){
		angle=180-angle;
		y=radius;//拉到相切的位置
	}
	if(x+radius>rect.width()){
		angle=-angle;
		x=rect.width()-radius;
	}
	if(x-radius<0){
		angle=-angle;
		x=radius;
	}
}

void Ball::editXY(double newX, double newY)
{
	this->x+=newX;
	this->y+=newY;
	return ;
}

void Ball::editAngle(double newA)
{
	this->angle+=newA;
	return ;
}

double Ball::getRadius()
{
	return this->radius;
}

void Ball::editspeed(double sX, double sY)
{
//	限制小球的最大运动速度:
	const double PI=3.14159;
	this->speedX=(fabs(speedX+sX)>MAX_SPEED)?speedX:speedX+sX;
	this->speedY=(fabs(speedY+sY)>MAX_SPEED)?speedY:speedY+sY;

	this->speed=sqrt(this->speedX*this->speedX+this->speedY*this->speedY);
	this->angle=std::atan2(this->speedX, this->speedY)/(2*PI)*360;
	if(this->angle<0){
		this->angle=360+this->angle;
	}
	return ;
}

void Ball::updateXYSpeed()
{
	const double PI=3.14159;
	this->speedX=speed*std::sin(angle*PI/180);
	this->speedY=speed*std::cos(angle*PI/180);
	return ;
}

bool Ball::checkCollision(Ball &b){
	double dx,dy;
	dx=x-b.x;
	dy=y-b.y;
	double dis=std::sqrt(dx*dx+dy*dy);
	if(dis<=radius+b.radius){
//		碰撞后只是交换速度和角度

//		删除原有的阻尼系统
//		b.speed*=0.99;
//		b.speed=b.speed<0.1?0:b.speed;
//		this->speed*=0.99;
//		this->speed=this->speed<0.1?0:this->speed;

		double temp;
		temp=speed;
		speed=b.speed;
		b.speed=temp;
		temp=angle;
		angle=b.angle;
		b.angle=temp;
		updateXYSpeed ();
		b.updateXYSpeed ();

		if(fabs (angle-b.angle)<10.0){
			this->editAngle (5);
			b.editAngle (-5);
			this->editXY (this->radius, this->radius);
			b.editXY (-b.getRadius (),-b.getRadius ());
		}
		if(fabs(b.speed-speed)<2.0){
			this->editAngle (5);
			b.editAngle (-5);
			this->editXY (this->radius, this->radius);
			b.editXY (-b.getRadius (),-b.getRadius ());
		}
		return true;
	}
	return false;
}

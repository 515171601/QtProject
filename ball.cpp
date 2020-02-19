#include "ball.h"
#include <cmath>
#include <QImage>
#include <QRectF>

//默认构造函数通过委托构造的方法构造:
//提供默认的球的贴图表情, 防止出现'隐形球'
Ball::Ball():Ball(40,100,10,10,45,
				  QString("D:/Git/Commodity/QtProject/huaji05.png")) {}
//初始化各个数据成员
Ball::Ball(double xpos, double ypos, double r,
		   double s, double a, QString I)
	:x(xpos),y(ypos),radius(r),speed(s),angle(a),image(I)
{
	//同步更新到球XY的分速度, 便于球的移动控制:
	const double PI=3.14159;
	this->speedX=speed*std::sin(angle*PI/180);
	this->speedY=speed*std::cos(angle*PI/180);
	return ;
}
//球的绘制函数:
void Ball::draw(QPainter *p)
{
	//设定矩形区域用于绘制图片:
	QRect r(x-radius,y-radius,radius*2,radius*2);
	//通过每个小球的贴图路径创建临时的图像对象:
	QImage picture(this->image);
	//在画布上绘制图像:
	p->drawImage (r,picture);
	return ;
}
//球移动函数:
//通过球的和速度和移动角度来实现球的移动:
void Ball::move(){
	//每一次刷新后移动的距离, 通过和速度算出:
	double dx,dy;
	const double PI=3.14159;
	dx=speed*std::sin(angle*PI/180);
	dy=speed*std::cos(angle*PI/180);
	//小球下一次出现的位置:
	x+=dx;
	y+=dy;
	//检测小球移动后是否碰撞:
	checkBoundary();
	//同步更新到球XY的分速度, 便于球的移动控制:
	updateXYSpeed ();
	return ;
}
//检测球和最大边界的碰撞:
void Ball::checkBoundary(){
	//坐标系统的左上角（0,0）向右下递增

	//超出下边界
	if(y+radius>rect.height()){
		angle=180-angle;
		y=rect.height()-radius; //拉回来
	}
	//超出上边界
	if(y-radius<0){
		angle=180-angle;
		y=radius;//拉到相切的位置
	}
	//超出右边界
	if(x+radius>rect.width()){
		angle=-angle;
		x=rect.width()-radius;
	}
	//超出左边界:
	if(x-radius<0){
		angle=-angle;
		x=radius;
	}
	return ;
}
//检测球之间是否发生碰撞:
bool Ball::checkCollision(Ball &b){
	bool flag=0;
	double dx,dy;
	dx=x-b.x;
	dy=y-b.y;
	//求出两球之间的距离
	double dis=std::sqrt(dx*dx+dy*dy);
	//如果距离小于两球半径之和, 则视作发生碰撞:
	if(dis<=radius+b.radius){
		double temp;
		//发生碰撞后的物理模型为简单交换两球的速度和角度
		temp=speed;
		speed=b.speed;
		b.speed=temp;
		temp=angle;
		angle=b.angle;
		b.angle=temp;
		//同步更新到球的XY分速度:
		updateXYSpeed ();
		b.updateXYSpeed ();
		//由于物理模型的问题, 如果两球的速度和角度相近时会发生粘球的BUG
		//所以当满足条件时, 将两球强制传送分开一段距离
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
		flag=true;
	}
	//保持函数的单一出口原则:
	return flag;
}

//更新小球的XY坐标:
void Ball::editXY(double newX, double newY)
{
	//直接将原有的XY加上变更的量
	this->x+=newX;
	this->y+=newY;
	return ;
}
//更新小球的移动角度:
void Ball::editAngle(double newA)
{
	//直接将原有的angle加上变更的量
	this->angle+=newA;
	return ;
}
//更新控制移动后小球的XY分速度:
void Ball::editspeed(double sX, double sY)
{
	//	限制小球的最大运动速度:
	const double PI=3.14159;
	this->speedX=(fabs(speedX+sX)>MAX_SPEED)?speedX:speedX+sX;
	this->speedY=(fabs(speedY+sY)>MAX_SPEED)?speedY:speedY+sY;
	//通过三角函数算出运动的角度, 并更新到小球运动的angle中:
	this->speed=sqrt(this->speedX*this->speedX+this->speedY*this->speedY);
	this->angle=std::atan2(this->speedX, this->speedY)/(2*PI)*360;
	//限制angle的大小:
	if(this->angle<0){
		this->angle=360+this->angle;
	}
	return ;
}
//设置小球的贴图路径:
void Ball::setImage(const QString &value)
{
	image = value;
}
//普通移动后更新小球的XY分速度:
void Ball::updateXYSpeed()
{
	const double PI=3.14159;
	this->speedX=speed*std::sin(angle*PI/180);
	this->speedY=speed*std::cos(angle*PI/180);
	return ;
}

//获得球的各个私有数据成员:
double Ball::getRadius()
{
	return this->radius;
}
QString Ball::getImage() const
{
	return image;
}





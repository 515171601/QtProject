#include "rightwidget.h"
#include "leftwidget.h"
#include <QPainter>


RightWidget::RightWidget(QWidget *parent) :
	QWidget(parent),level(1)
{
	setMinimumSize(400,400);
	balls.clear(); //清空后手工添加 3 个小球，用于测试
//	addBall(Ball(0,0,20,0,0,"D:/Git/Commodity/QtProject/yinxian.png"));
//	addBall(Ball(30,0,10,10,49));
//	addBall(Ball(30,5,15,10,49));
//	addBall(Ball(30,10,20,10,49));
//	addBall(Ball(30,15,25,10,49));
//	addBall(Ball(30,20,30,10,49,"D:/Git/Commodity/QtProject/yinxian.png"));

}
void RightWidget::paintEvent(QPaintEvent *)
{
	QPainter p(this);//需要在不同类之间传参，不能在ball里面定义


	for(auto& b:balls){
		b.draw(&p);//C++11特性，循环，对容器中对每个元素进行快速遍历.

	}
}
void RightWidget::updateBalls()  //封装的控制小球移动的接口
{
	// ball.setRectangle(this->geometry());
	// ball.move();//自己移动一次.
	for(auto &b:balls){
		b.setRectangle(this->geometry());
		b.move();
	} //先移动小球，处理与边框的碰撞，再处理小球间碰撞
	//C++11特性，循环，对容器中对每个元素进行快速遍历.
	int i,j;
	bool flag;
	for(i=0;i<balls.size()-1;++i){
		for(j=i+1;j<balls.size();++j){
			flag=balls[i].checkCollision(balls[j]);
			//todo: 这里的5换成level
			if(flag){
				if(i==0&&j==this->level){
					balls.clear ();
				}
			}
		}
	}//集成碰撞检测方法
	update();    //更新窗口显示，重绘小球
}

void RightWidget::addBall(const Ball &b){
	balls.append(b);
}

//todo: 完善接口
void RightWidget::moveBall(const int &direction)
{
	const double STEP=1;
	if(!balls.isEmpty ()){
		switch(direction){
			case Qt::Key_W:		//w
				balls.front ().editspeed (0,-STEP);
				break;
			case Qt::Key_S:		//s
				balls.front ().editspeed (0,STEP);
				break;
			case Qt::Key_A:		//a
				balls.front ().editspeed (-STEP,0);
				break;
			case Qt::Key_D:		//d
				balls.front ().editspeed (STEP,0);
				break;
		}
	}
}

void RightWidget::clearBalls()
{
	this->balls.clear ();
	return ;
}

void RightWidget::setLevel(unsigned int le)
{
	this->level=le;
	return;
}



//预留给别的接口


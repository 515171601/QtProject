#include "rightwidget.h"
#include "leftwidget.h"
#include <QPainter>
#include <QDebug>


RightWidget::RightWidget(QWidget *parent) :
	QWidget(parent),level(1),minX(800), minY(800), frontKey(0)
{
	setMinimumSize(800,800);
	balls.clear(); //清空后手工添加 3 个小球，用于测试
	return ;
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
				if(i==0&&j==static_cast<int>(this->level)){
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
	const double STEP=3;
	if(!balls.isEmpty ()){
		switch(direction){
			case Qt::Key_W:		//w
				if(frontKey==Qt::Key_D){
					balls.front ().editspeed (STEP,-STEP);
				}else if(frontKey==Qt::Key_A){
					balls.front ().editspeed (-STEP,-STEP);
				}else{
					balls.front ().editspeed (0,-STEP);
				}
				frontKey=direction;
//				qDebug()<<QString::number (frontKey);
				break;
			case Qt::Key_S:		//s
				if(frontKey==Qt::Key_D){
					balls.front ().editspeed (STEP,STEP);
				}else if(frontKey==Qt::Key_A){
					balls.front ().editspeed (-STEP,STEP);
				}else{
					balls.front ().editspeed (0,STEP);
				}
				frontKey=direction;
//				qDebug()<<QString::number (frontKey);
				break;
			case Qt::Key_A:		//a
				if(frontKey==Qt::Key_W){
					balls.front ().editspeed (-STEP,-STEP);
				}else if(frontKey==Qt::Key_S){
					balls.front ().editspeed (-STEP,STEP);
				}else if(frontKey==Qt::Key_A){
					balls.front ().editspeed (-STEP,0);
				}
				frontKey=direction;
//				qDebug()<<QString::number (frontKey);
				break;
			case Qt::Key_D:		//d
				if(frontKey==Qt::Key_W){
					balls.front ().editspeed (STEP,-STEP);
				}else if(frontKey==Qt::Key_S){
					balls.front ().editspeed (STEP,STEP);
				}else{
					balls.front ().editspeed (STEP,0);
				}
				frontKey=direction;
//				qDebug()<<QString::number (frontKey);
				break;
//			case Qt::Key_I:

//				break;
//			case Qt::Key_K:

//				break;
//			case Qt::Key_J:

//				break;
//			case Qt::Key_L:

//				break;


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

int RightWidget::getMinX() const
{
	return minX;
}

int RightWidget::getMinY() const
{
	return minY;
}

Ball &RightWidget::getLastBall()
{
	return this->balls.back ();
}



//预留给别的接口


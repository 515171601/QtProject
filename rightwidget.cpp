#include "rightwidget.h"
#include "leftwidget.h"
#include <QPainter>
#include <QDebug>

//默认构造函数
RightWidget::RightWidget(QWidget *parent) :
	//初始化各个变量:
	QWidget(parent),level(1),minX(800), minY(800)
{
	memset(this->directionFlag,0,4*sizeof(int));
	//设置窗口最小大小:
	setMinimumSize(minX,minY);
	//清空表情球序列:
	balls.clear();
	return ;
}

//贴图刷新函数:
void RightWidget::paintEvent(QPaintEvent *)
{
	//定义画布, 用于表情球的绘制
	QPainter p(this);
	//利用C++11的范围for对表情球序列的所有表情球进行刷新:
	for(auto& b:balls){
		b.draw(&p);
	}
}

//表情球更新函数:
void RightWidget::updateBalls()
{
	//利用C++11的范围for对表情球序列的所有表情球进行刷新:
	for(auto &b:balls){
		//将当前窗口的大小更新到每个小球变量中, 便于窗口的动态调整:
		b.setRectangle(this->geometry());
		//调用ball中的move函数进行刷新:
		b.move();
	}
	//处理没两个球间的碰撞:
	int i,j;
	bool flag;
	//双重循环遍历每一个球:
	for(i=0;i<balls.size()-1;++i){
		for(j=i+1;j<balls.size();++j){
			flag=balls[i].checkCollision(balls[j]);
			if(flag){
				//如果是第一个玩家控制的球与最后一个目标球发生碰撞, 则清空所有球
				//表示游戏结束
				if(i==0&&j==static_cast<int>(this->level)){
					balls.clear ();
				}
			}
		}
	}
	//更新窗口:
	update();
}

//表情球添加函数:
void RightWidget::addBall(const Ball &b){
	//使用QList成员函数向序列末尾添加小球:
	balls.append(b);
}

//表情球移动函数:
void RightWidget::moveBall(const int &direction)
{
	//定义每一次刷新的速度该变量:
	const double STEP=3;
	//如果球序列非空, 则检测键盘移动球
	if(!balls.isEmpty ()){
		//通过参数判断按下的键盘按键
		switch(direction){
			case Qt::Key_W:		//w
				//将方向Flag置1
				directionFlag[0]=1;
				//判定当前的方向标志位, 以实现8方向移动
				if(directionFlag[2]){
					balls.front ().editspeed (-STEP,-STEP);
				}else if(directionFlag[3]){
					balls.front ().editspeed (STEP,-STEP);
				}else{
					balls.front ().editspeed (0,-STEP);
				}
				break;
			case Qt::Key_S:		//s
				//将方向Flag置1
				directionFlag[1]=1;
				//判定当前的方向标志位, 以实现8方向移动
				if(directionFlag[2]){
					balls.front ().editspeed (-STEP,STEP);
				}else if(directionFlag[3]){
					balls.front ().editspeed (STEP,STEP);
				}else{
					balls.front ().editspeed (0,STEP);
				}
				break;
			case Qt::Key_A:		//a
				//将方向Flag置1
				directionFlag[2]=1;
				//判定当前的方向标志位, 以实现8方向移动
				if(directionFlag[0]){
					balls.front ().editspeed (-STEP,STEP);
				}else if(directionFlag[1]){
					balls.front ().editspeed (-STEP,STEP);
				}else{
					balls.front ().editspeed (-STEP,0);
				}
				break;
			case Qt::Key_D:		//d
				//将方向Flag置1
				directionFlag[3]=1;
				//判定当前的方向标志位, 以实现8方向移动
				if(directionFlag[0]){
					balls.front ().editspeed (STEP,-STEP);
				}else if(directionFlag[1]){
					balls.front ().editspeed (STEP,STEP);
				}else{
					balls.front ().editspeed (STEP,0);
				}
				break;
		}
	}
	return ;
}

//清除键盘标志位的函数:
void RightWidget::keyRelease(int key)
{
	//当键盘松开时将对应的方向标志位置0
	switch(key){
		case Qt::Key_W:		//w
			directionFlag[0]=0;
			break;
		case Qt::Key_S:		//s
			directionFlag[1]=0;
			break;
		case Qt::Key_A:		//a
			directionFlag[2]=0;
			break;
		case Qt::Key_D:		//d
			directionFlag[3]=0;
			break;
	}
	return ;
}
//表情球清空函数:
void RightWidget::clearBalls()
{
	this->balls.clear ();
	return ;
}
//设置难度函数:
void RightWidget::setLevel(unsigned int le)
{
	this->level=le;
	return;
}
//获得当前窗口的最小尺寸
int RightWidget::getMinX() const
{
	return minX;
}
int RightWidget::getMinY() const
{
	return minY;
}
//获取表情球序列中最后一个小球, 即目标球:
Ball &RightWidget::getLastBall()
{
	return this->balls.back ();
}



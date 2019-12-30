#include "centerwidget.h"
#include <QPainter>
#include <QMouseEvent>

void CenterWidget::setDrawType(int type){
	drawType=type;
}

CenterWidget::CenterWidget(QWidget *parent) : QWidget(parent)
{
	setMinimumSize(400,400); //初始为400X400的大小.
	drawType=0;
	mouseClickInfo=tr("");    //初始，空串
	mousePosInfo=tr("");   //空串
	setMouseTracking(true); //打开开关，默认是关闭的。
}
void CenterWidget::paintEvent(QPaintEvent *){

	QPainter p(this);//窗口绑定画布.
	/*
	p.drawText(QRect(50,50,300,100),Qt::AlignCenter,
			   tr("欢迎进入 QT 可视化编程的世界！")); //aligncenter对齐方式，中央对齐
	QRect rect(200,200,300,200);   //Rect表面矩形区域.左下角是0,0。tr是输出的文本内容。
	QPen pen(Qt::red,2,Qt::SolidLine);   //画笔，颜色，线宽，样式。
	p.setPen(pen);  //选中画笔
	QBrush brush(Qt::blue);  //画刷
	p.setBrush(brush);
	p.drawEllipse(rect);  //画一个椭圆
   */
	QPen pen(Qt::red,2,Qt::SolidLine);
	p.setPen(pen);     QPoint p1(50,50),p2(500,300);
	switch(drawType){
		case 0:
			p.drawLine(p1,p2);
			break;
		case 1:
			p.drawEllipse(QRect(p1,p2));
			break;
		case 2:
			p.drawRect(QRect(p1,p2));
			break;
	}
	p.drawText(50,200,mouseClickInfo);
	p.drawText(50,300,mousePosInfo);
}
void CenterWidget::mousePressEvent(QMouseEvent *e){
	mouseClickInfo=tr("Mouse Click at: ")+QString::number(e->x())
				   +","+QString::number(e->y());//QString中的静态方法，将字符串转化成数值。
	update();
}//鼠标点击时，调用mousePressEvent，保存在mousClickInfo中，将字符串转化为数值。
//写两个虚函数的实现。
void CenterWidget::mouseMoveEvent(QMouseEvent *e){
	mousePosInfo=tr("Mouse pos: ")+QString::number(e->x())
				 +","+QString::number(e->y());     update();
}

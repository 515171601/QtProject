#include "centerwidget.h"
#include <QPainter>
#include <QMouseEvent>
#include <QKeyEvent>

void CenterWidget::setDrawType(int type){
	drawType=type;
}

void CenterWidget::setDrawColor(Qt::GlobalColor color)
{
	this->DRAW_COLOR=color;
	return ;
}

void CenterWidget::setFillOption(bool flag)
{
	this->FILL_FLAG=flag;
	return ;
}

CenterWidget::CenterWidget(QWidget *parent) : QWidget(parent)
{
	setMinimumSize(400,400);
	drawType=0;
	mouseClickInfo=tr("");
	mousePosInfo=tr("");
	setMouseTracking(true);
	this->KeyPressInfo=tr("");
	setFocusPolicy(Qt::StrongFocus);
	this->DRAW_COLOR=Qt::black;
	this->FILL_FLAG=false;
	return ;
}

void CenterWidget::paintEvent(QPaintEvent *){

	QPainter p(this);
	QPen pen(DRAW_COLOR,2,Qt::SolidLine);
	QBrush bruch(DRAW_COLOR, Qt::SolidPattern);
	QPoint p1(50,50),p2(500,300);
	if(FILL_FLAG){
		p.setBrush (bruch);
	}else{
		p.setPen(pen);
	}
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
	p.drawText(50,250,this->KeyPressInfo);
}
void CenterWidget::mousePressEvent(QMouseEvent *e){
	mouseClickInfo=tr("Mouse Click at: ")+QString::number(e->x())
				   +","+QString::number(e->y());
	update();
}

void CenterWidget::mouseMoveEvent(QMouseEvent *e){
	mousePosInfo=tr("Mouse pos: ")+QString::number(e->x())
				 +","+QString::number(e->y());     update();
	return ;
}

void CenterWidget::keyPressEvent(QKeyEvent *e){
	this->KeyPressInfo=tr("Key Press : ")+QString::number(e->key());
	update();
	return ;
}

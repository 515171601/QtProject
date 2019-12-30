#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QStatusBar>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
	: QMainWindow(parent)
{
	setWindowTitle(tr("简单窗口程序"));
	centerWidget=new CenterWidget(this);
	setCentralWidget(centerWidget);

	fileMenu=menuBar()->addMenu(tr("文件"));
	exitAction=new QAction(tr("退出"),this);
	exitAction->setShortcut(tr("Ctrl+X"));
	exitAction->setStatusTip(tr("退出程序"));
	fileMenu->addAction(exitAction);

	lineAction=new QAction(QIcon("line.jpg"),tr("线条"),this);
	lineAction->setShortcut(tr("Ctrl+L"));
	lineAction->setStatusTip(tr("绘制线条"));

	ellipseAction=new QAction(QIcon("ellipse.jpg"),tr("椭圆"),this);
	ellipseAction->setShortcut(tr("Ctrl+E"));
	ellipseAction->setStatusTip(tr("绘制椭圆"));

	rectangleAction=new QAction(QIcon("rectangle.jpg"),tr("矩形"),this);
	rectangleAction->setShortcut(tr("Ctrl+R"));
	rectangleAction->setStatusTip(tr("绘制矩形"));

	blackAction=new QAction(QIcon("black.png"),tr("黑色"),this);
	blackAction->setStatusTip (tr("填充黑色"));

	greenAction=new QAction(QIcon("green.png"),tr("绿色"),this);
	greenAction->setStatusTip (tr("填充绿色"));

	yellowAction=new QAction(QIcon("yellow.png"),tr("黄色"),this);
	yellowAction->setStatusTip (tr("填充黄色"));

	fillAction=new QAction(tr("填充"),this);

	drawMenu=this->menuBar()->addMenu(tr("绘图"));
	colorMenu=this->menuBar ()->addMenu (tr("颜色"));
	fillMenu=this->menuBar ()->addMenu (tr("填充"));


	drawMenu->addAction(lineAction);
	drawMenu->addAction(ellipseAction);
	drawMenu->addAction(rectangleAction);

	colorMenu->addAction(blackAction);
	colorMenu->addAction(greenAction);
	colorMenu->addAction(yellowAction);

	fillMenu->addAction(fillAction);

	drawToolBar=addToolBar(tr("Draw"));
	drawToolBar->addAction(lineAction);
	drawToolBar->addAction(ellipseAction);
	drawToolBar->addAction(rectangleAction);

	statusBar()->show(); //得到底下的状态栏.

	connect(lineAction,SIGNAL(triggered()),this,SLOT(line()));
	connect(ellipseAction,SIGNAL(triggered()),this,SLOT(ellipse()));
	connect(rectangleAction,SIGNAL(triggered()),this,SLOT(rectangle()));
	connect(exitAction,SIGNAL(triggered()),this,SLOT(close()));
	connect (blackAction,SIGNAL(triggered()),this,SLOT(reDrawInBlack()));
	connect (greenAction,SIGNAL(triggered()),this,SLOT(reDrawInGreen()));
	connect (yellowAction,SIGNAL(triggered()),this,SLOT(reDrawInYellow()));
	connect (fillAction, SIGNAL(triggered()),this,SLOT(fillColor()));
}

void MainWindow::line(){
	centerWidget->setDrawType(0);
	centerWidget->update();
}
void MainWindow::ellipse(){
	centerWidget->setDrawType(1);
	centerWidget->update();
}
void MainWindow::rectangle(){
	centerWidget->setDrawType(2);
	centerWidget->update();
}

void MainWindow::reDrawInBlack()
{
	centerWidget->setDrawColor (Qt::black);
	centerWidget->update ();
	return ;
}

void MainWindow::reDrawInGreen()
{
	centerWidget->setDrawColor (Qt::green);
	centerWidget->update ();
	return ;
}

void MainWindow::reDrawInYellow()
{
	centerWidget->setDrawColor (Qt::yellow);
	centerWidget->update ();
	return ;
}

void MainWindow::fillColor()
{
	int answer=QMessageBox::question (this, tr("对话框"), tr("是否填充图像"),
						   QMessageBox::Yes, QMessageBox::No);
	if(answer==QMessageBox::Yes){
		centerWidget->setFillOption (true);
	}else{
		centerWidget->setFillOption (false);
	}
	centerWidget->update ();
	return ;
}


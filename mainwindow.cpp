#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QStatusBar>

MainWindow::MainWindow(QWidget *parent)
	: QMainWindow(parent)
{
	setWindowTitle(tr("简单窗口程序"));  //窗口的标题栏
	centerWidget=new CenterWidget(this);
	setCentralWidget(centerWidget);

	fileMenu=menuBar()->addMenu(tr("文件"));
	exitAction=new QAction(tr("退出"),this); //action绑定到菜单项，菜单名字叫退出，属于this窗口
	exitAction->setShortcut(tr("Ctrl+X"));  //快捷方式，定义快捷键。
	exitAction->setStatusTip(tr("退出程序")); //提示内容。
	fileMenu->addAction(exitAction); //把action作为子菜单项添加进来。

	lineAction=new QAction(QIcon("line.gif"),tr("线条"),this);//添加图标文件的时候不能放到项目文件里，要放到编译后的文件里？
	lineAction->setShortcut(tr("Ctrl+L"));
	lineAction->setStatusTip(tr("绘制线条"));

	ellipseAction=new QAction(QIcon("ellipse.gif"),tr("椭圆"),this);
	ellipseAction->setShortcut(tr("Ctrl+E"));
	ellipseAction->setStatusTip(tr("绘制椭圆"));

	rectangleAction=new QAction(QIcon("rectangle.gif"),tr("矩形"),this);
	rectangleAction->setShortcut(tr("Ctrl+R"));
	rectangleAction->setStatusTip(tr("绘制矩形"));

	drawMenu=this->menuBar()->addMenu(tr("绘图"));//添加顶层菜单
	drawMenu->addAction(exitAction);

	drawMenu->addAction(lineAction);
	drawMenu->addAction(ellipseAction);
	drawMenu->addAction(rectangleAction);

	drawToolBar=addToolBar(tr("Draw"));
	drawToolBar->addAction(lineAction);
	drawToolBar->addAction(ellipseAction);
	drawToolBar->addAction(rectangleAction);

	statusBar()->show(); //得到底下的状态栏.
	connect(lineAction,SIGNAL(triggered()),this,SLOT(line()));
	connect(ellipseAction,SIGNAL(triggered()),this,SLOT(ellipse()));
	connect(rectangleAction,SIGNAL(triggered()),this,SLOT(rectangle()));
	connect(exitAction,SIGNAL(triggered()),this,SLOT(close()));//退出,直接调用close。
}

MainWindow::~MainWindow()
{

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


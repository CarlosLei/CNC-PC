#include "mainwindow.h"
#include <QPushButton>
#include <QLabel>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    //初始化界面
    createActions();
    createMenus();
}

MainWindow::~MainWindow()
{
}

void MainWindow::createActions()
//创建所有动作
{
    newAction = new QAction(QIcon(":/images/new.png"),
                            tr("&New"),
                            this);

}
void MainWindow::createMenus()
//创建菜单栏
{

}

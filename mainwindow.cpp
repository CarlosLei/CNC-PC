#include "mainwindow.h"
#include <QPushButton>
#include <QLabel>

#include <QAction>
#include <QMenuBar>
#include <QToolBar>
#include <QStatusBar>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    //初始化界面
    setWindowIcon(QIcon(":/images/smile.png"));
    setMinimumSize(1000,600);

    createActions();
    createMenus();
    createToolBar();
    createStatusBar();
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
    newAction->setShortcut(QKeySequence::New);
    newAction->setStatusTip(tr("Create a file."));
    connect(newAction,SIGNAL(triggered()),this,SLOT(newFile()));
    //-----------------------------------------------------------
    openAction = new QAction(QIcon(":/images/open.png"),
                            tr("&Open"),
                            this);
    openAction->setShortcut(QKeySequence::Open);
    openAction->setStatusTip(tr("Open a file."));
    connect(openAction,SIGNAL(triggered()),this,SLOT(openFile()));
    //-----------------------------------------------------------
    saveAction = new QAction(QIcon(":/images/save.png"),
                            tr("&Save"),
                            this);
    saveAction->setShortcut(QKeySequence::Save);
    saveAction->setStatusTip(tr("Save a file."));
    connect(saveAction,SIGNAL(triggered()),this,SLOT(saveFile()));
    //-----------------------------------------------------------
    saveasAction = new QAction(QIcon(":/images/saveas.png"),
                            tr("Save&as"),
                            this);
    saveasAction->setShortcut(tr("Ctrl+A"));
    saveasAction->setStatusTip(tr("Save as a file."));
    connect(saveasAction,SIGNAL(triggered()),this,SLOT(saveasFile()));
    //-----------------------------------------------------------
    exitAction = new QAction(QIcon(":/images/exit.png"),
                            tr("E&xit"),
                            this);
    exitAction->setShortcut(tr("Ctrl+X"));
    exitAction->setStatusTip(tr("Exit."));
    connect(exitAction,SIGNAL(triggered()),this,SLOT(close()));
    //-----------------------------------------------------------
    aboutAction = new QAction(tr("About"),this);
    aboutAction->setStatusTip(tr("This is about CNC-PC."));

}
void MainWindow::createMenus()
//创建菜单栏
{
    fileMenu = menuBar()->addMenu(tr("&File"));
    fileMenu->addAction(newAction);
    fileMenu->addAction(openAction);
    fileMenu->addAction(saveAction);
    fileMenu->addAction(saveasAction);
    fileMenu->addSeparator();
    fileMenu->addAction(exitAction);

    editMenu = menuBar()->addMenu(tr("&Edit"));

    optionMenu = menuBar()->addMenu(tr("&Option"));
    optionMenu->addAction(aboutAction);

}
void MainWindow::createToolBar()
{
    fileToolBar = addToolBar(tr("&File"));
    fileToolBar->addAction(newAction);
    fileToolBar->addAction(openAction);
}
void MainWindow::createStatusBar()
{
    statusBar();
}
void MainWindow::newFile()
//新建文件
{

}
void MainWindow::openFile()
//打开文件
{

}
void MainWindow::saveFile()
//保存文件
{

}
void MainWindow::saveasFile()
//文件另存为
{

}

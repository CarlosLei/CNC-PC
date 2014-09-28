#include "mainwindow.h"
#include <QPushButton>
#include <QLabel>

#include <QAction>
#include <QMenuBar>
#include <QToolBar>
#include <QStatusBar>
#include <QMessageBox>
#include <QFileDialog>
#include <QTextStream>
#include <QTextEdit>

#include "eventlabel.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    //初始化界面
    setWindowIcon(QIcon(":/images/CNC-PC.png"));
    setMinimumSize(1000,600);

    createActions();
    createMenus();
    createToolBar();
    createStatusBar();
    //文本显示框
    textEdit = new QTextEdit(this);
    textEdit->setGeometry(600,300,330,250);
    //显示坐标的label
    firstpointlabel = new EventLabel(this);
    firstpointlabel->setGeometry(600,250,200,40);
}

MainWindow::~MainWindow()
{
}

void MainWindow::createActions()
//创建所有动作
{
    newAction = new QAction(QIcon(":/images/new.png"),
                            tr("&New..."),
                            this);
    newAction->setShortcut(QKeySequence::New);
    newAction->setStatusTip(tr("Create a file."));
    connect(newAction,SIGNAL(triggered()),this,SLOT(newFile()));
    //-----------------------------------------------------------
    openAction = new QAction(QIcon(":/images/open.png"),
                            tr("&Open..."),
                            this);
    openAction->setShortcut(QKeySequence::Open);
    openAction->setStatusTip(tr("Open a existing file."));
    connect(openAction,SIGNAL(triggered()),this,SLOT(openFile()));
    //-----------------------------------------------------------
    saveAction = new QAction(QIcon(":/images/save.png"),
                            tr("&Save..."),
                            this);
    saveAction->setShortcut(QKeySequence::Save);
    saveAction->setStatusTip(tr("Save a file."));
    connect(saveAction,SIGNAL(triggered()),this,SLOT(saveFile()));
    //-----------------------------------------------------------
    saveasAction = new QAction(QIcon(":/images/saveas.png"),
                            tr("Save&As"),
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
    connect(aboutAction,SIGNAL(triggered()),this,SLOT(aboutCNCPC()));

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
//创建工具栏
{
    fileToolBar = addToolBar(tr("&File"));
    fileToolBar->addAction(newAction);
    fileToolBar->addAction(saveAction);
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
    QString path = QFileDialog::getOpenFileName(this,
                                                tr("Open File"),
                                                ".",
                                                tr("Text Files(*.txt)"));
    if(!path.isEmpty())
    {
        QFile file(path);
        if(!file.open(QIODevice::ReadOnly|QIODevice::Text))
        {
            QMessageBox::warning(this,tr("Read File"),
                                 tr("Cannot open file:\n%1").arg(path));
            return;
        }
        QTextStream in(&file);
        textEdit->setText(in.readAll());
        file.close();
    }
    else
    {
        QMessageBox::warning(this,tr("path"),
                             tr("You did not select any file."));
    }
}
void MainWindow::saveFile()
//保存文件
{
    QString path = QFileDialog::getSaveFileName(this,
                                                tr("Open File"),
                                                ".",
                                                tr("Text Files(*.txt)"));
    if(!path.isEmpty())
    {
        QFile file(path);
        if(!file.open(QIODevice::WriteOnly|QIODevice::Text))
        {
            QMessageBox::warning(this,
                                 tr("Write File"),
                                 tr("Text Files(*.txt)"));
            return;
        }
        QTextStream out(&file);
        out << textEdit->toPlainText();
        file.close();
    }
    else
    {
        QMessageBox::warning(this,
                             tr("Path"),
                             tr("You did not select any file."));
    }

}
void MainWindow::saveasFile()
//文件另存为
{

}
void MainWindow::aboutCNCPC()
//关于CNC-PC
{
    QMessageBox::about(this,tr("AboutCNC-PC"),
                       tr("This is the version 1.0. "
                          " It's designed by Carlos Lei."));
}








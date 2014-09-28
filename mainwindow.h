#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
class QAction;
class QMenu;
class QToolBar;
class QTextEdit;
class EventLabel;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();


private slots:
    void newFile();
    void openFile();
    void saveFile();
    void saveasFile();
    void aboutCNCPC();

private:
    void createActions();
    void createMenus();
    void createToolBar();
    void createStatusBar();


    QMenu *fileMenu;
    QMenu *editMenu;
    QMenu *optionMenu;

    QToolBar *fileToolBar;

    QAction *newAction;
    QAction *openAction;
    QAction *saveAction;
    QAction *saveasAction;
    QAction *exitAction;

    QAction *aboutAction;

    //富文本编辑器
    QTextEdit *textEdit;
    EventLabel *firstpointlabel;
    EventLabel *lastpointlabel;
};

#endif // MAINWINDOW_H




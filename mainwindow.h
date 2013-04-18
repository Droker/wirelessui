#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtGui>
#include <QtCore>
#include <QtWidgets>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
protected:
    void paintEvent(QPaintEvent *);
    void mouseMoveEvent(QMouseEvent *);
    void mousePressEvent(QMouseEvent *);
private slots:

    void on_setButton_clicked();

    void on_networkButton_clicked();

    void on_arpButton_clicked();

    void on_anticrackButton_clicked();

    void on_fakeapButton_clicked();

    void on_devicesButton_clicked();


private:
    Ui::MainWindow *ui;

    QPixmap m_pixmapBg;
    QAction *m_AactionAboutQt;
    QMenu *m_menu;

    QPoint m_pointStart;
    QPoint m_pointPress;

    QVector <QPushButton* > m_vecBtn;

    ///成员变量初始化;
    void initData();

    ///自定义窗口样式;
    void setNomalStyle();

    ///功能选择函数;
    void setCurrentWidget();
};

#endif // MAINWINDOW_H

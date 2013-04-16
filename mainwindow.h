#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

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
private slots:
   // void m_pTitleBar::mousePressEvent(QMouseEvent *);
  //  void m_pTitleBar::mouseMoveEvent(QMouseEvent *);
 //   void m_pTitleBar::mouseReleaseEvent(QMouseEvent *);
    void on_menuButton_clicked();

    void on_networkButton_clicked();

    void on_arpButton_clicked();

    void on_anticrackhButton_clicked();

    void on_fakeapButton_clicked();

    void on_devicesButton_clicked();


private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H

#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowFlags(Qt::FramelessWindowHint);
   // connect(ui->minButton,SIGNAL(pressed()),this,SLOT(showMinimized()));
    connect(ui->closeButton,SIGNAL(clicked()),qApp,SLOT(quit()));
    initData();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    painter.drawPixmap(m_pixmapBg.rect(), m_pixmapBg);
}

void MainWindow::mouseMoveEvent(QMouseEvent *e)
{
    this->move(e->globalPos() - m_pointStart);
}

void MainWindow::mousePressEvent(QMouseEvent *e)
{
    m_pointPress = e->globalPos();
    m_pointStart = m_pointPress - this->pos();

}

void MainWindow::setNomalStyle()
{
    QFile styleSheet(":/res/qss/wireless.qss");
    if (!styleSheet.open(QIODevice::ReadOnly))
    {
        qWarning("Can't open the style sheet file.");
        return;
    }
    qApp->setStyleSheet(styleSheet.readAll());
}


void MainWindow::on_setButton_clicked()
{
    m_menu->exec(this->mapToGlobal(QPoint(700, 20)));
}

void MainWindow::initData()
{
    setWindowFlags(Qt::FramelessWindowHint);
    setAttribute(Qt::WA_TranslucentBackground);

    m_menu = new QMenu();
    m_menu->addAction(tr("设置"));
    m_menu->addSeparator();
    m_menu->addAction(tr("关于我们"));
    m_AactionAboutQt = new QAction(tr("&About Qt"), this);
    connect(m_AactionAboutQt, SIGNAL(triggered()), qApp, SLOT(aboutQt()));
    m_menu->addAction(m_AactionAboutQt);

    ///背景加载;
    m_pixmapBg.load(":/res/image/frame.png");

    m_vecBtn.push_back(ui->networkButton);
    m_vecBtn.push_back(ui->arpButton);
    m_vecBtn.push_back(ui->anticrackButton);
    m_vecBtn.push_back(ui->fakeapButton);
    m_vecBtn.push_back(ui->devicesButton);

    for (int i = 0; i != m_vecBtn.size(); ++i)
    {
        ///功能选择键只有一个被选中;
        m_vecBtn[i]->setCheckable(true);
        m_vecBtn[i]->setAutoExclusive(true);
    }

    ///状态栏加上链接QLabel;
    ui->label_CheckLogin->setText(
                tr("<a href=http://cnssuestc.org>"
                   "<font color=blue>未登录</font></a>"));
    ui->label_CheckLogin->setOpenExternalLinks(true);

    setNomalStyle();
}

void MainWindow::on_networkButton_clicked()
{
    setCurrentWidget();
}
void MainWindow::on_arpButton_clicked()
{
    setCurrentWidget();
}
void MainWindow::on_anticrackButton_clicked()
{
    setCurrentWidget();
}
void MainWindow::on_fakeapButton_clicked()
{
    setCurrentWidget();
}
void MainWindow::on_devicesButton_clicked()
{
    setCurrentWidget();
}
void MainWindow::setCurrentWidget()
{
    for (int i = 0; i != m_vecBtn.size(); ++i)
    {
        if ( m_vecBtn[i]->isChecked() )
        {
            ui->stackedWidget->setCurrentIndex(i);
        }
    }
}


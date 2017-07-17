#include "systeminfowidget.h"
#include "systeminfothread.h"
#include <QHBoxLayout>

SystemInfoWidget::SystemInfoWidget(QWidget *parent) : QWidget(parent)
{
    setFixedSize(70, 25);

    QLabel *up   = new QLabel("↑  ");
    QLabel *down = new QLabel("↓  ");

    m_rx = new QLabel("100KB/s");
    m_rx->setFixedHeight(10);

    m_tx = new QLabel("49KB/s");
    m_tx->setFixedHeight(10);

    QHBoxLayout *upLayout = new QHBoxLayout;
    upLayout->setMargin(0);
    upLayout->setSpacing(0);
    upLayout->addWidget(up, 0, Qt::AlignLeft);
    upLayout->addWidget(m_tx, 0, Qt::AlignRight);

    QHBoxLayout *downLayout = new QHBoxLayout;
    downLayout->setMargin(0);
    downLayout->setSpacing(0);
    downLayout->addWidget(down, 0, Qt::AlignHCenter | Qt::AlignLeft);
    downLayout->addWidget(m_rx, 0, Qt::AlignHCenter | Qt::AlignRight);

    QVBoxLayout *layout = new QVBoxLayout;

    layout->setMargin(0);
    layout->setSpacing(1);

    layout->addLayout(downLayout);
    layout->addLayout(upLayout);

    setLayout(layout);

    SysteminfoThread *systeminfoThread = new SysteminfoThread;

    connect(systeminfoThread, &SysteminfoThread::networkSpeedChanged, this, [=] (const quint64 tx, const quint64 rx) {
            m_tx->setText(QString::number(tx / 1024) + "KB/s");
            m_rx->setText(QString::number(rx / 1024) + "KB/s");
    });

    systeminfoThread->start();
//    setStyleSheet("QLabel {"
//                  "color: black;"
//                  "background: transparent;"
//                  "}"
//                  "QLabel:hover {"
//                  "color: white;"
//                  "background: #1E90FF;"
//                  "}");

    setStyleSheet(":hover {"
                  "background: #1E90FF;"
                  "}"
                  "{"
                  ""
                  "}");
}

void SystemInfoWidget::enterEvent(QEvent *event)
{
    QWidget::enterEvent(event);

//    setStyleSheet("background: #1E90FF;"
//                  "QLabel {"
//                  "color: white;"
//                  "}");


}

void SystemInfoWidget::leaveEvent(QEvent *event)
{
    QWidget::leaveEvent(event);

//    setStyleSheet("background: transparent;"
//                  "QLabel {"
//                  "color: black;"
//                  "}");
}

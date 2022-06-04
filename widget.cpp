#include "widget.h"
#include "ui_widget.h"

#include <QDebug>
#include <QKeyEvent>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    setFocusPolicy(Qt::WheelFocus);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::keyPressEvent(QKeyEvent *event)
{
    QWidget::keyPressEvent(event);
    m_pressedKeys.insert(event->key());
    printSet();
}

void Widget::keyReleaseEvent(QKeyEvent *event)
{
    if (event->isAutoRepeat())
    {
        event->ignore();
    }
    else
    {
        QWidget::keyPressEvent(event);
        m_pressedKeys.clear();
    }
}

void Widget::printSet() const
{
    QString message;
    std::for_each(m_pressedKeys.begin(), m_pressedKeys.end(), [&](int k)
    {
        message += QString("<%1>").arg(k);
    });
    qDebug() << message;
}

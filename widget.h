#ifndef WIDGET_H
#define WIDGET_H

#include <set>
#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
protected:
    void keyPressEvent(QKeyEvent *event) override;
    void keyReleaseEvent(QKeyEvent *event) override;
private:
    void printSet() const;

    Ui::Widget *ui;
    std::set<int> m_pressedKeys;
};

#endif // WIDGET_H

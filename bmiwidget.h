#ifndef BMIWIDGET_H
#define BMIWIDGET_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui {
class BMIWidget;
}
QT_END_NAMESPACE

class BMIWidget : public QWidget
{
    Q_OBJECT

public:
    BMIWidget(QWidget *parent = nullptr);
    ~BMIWidget();

private:
    Ui::BMIWidget *ui;
};
#endif // BMIWIDGET_H

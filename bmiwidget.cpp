#include "bmiwidget.h"
#include "ui_bmiwidget.h"

BMIWidget::BMIWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::BMIWidget)
{
    ui->setupUi(this);
    ui->spinBox_height->setValue(0);
    ui->spinBox_height->setMaximum(1000);
    ui->lable_height->setText("QWERTY");
}

BMIWidget::~BMIWidget()
{
    delete ui;
}

#include "bmiwidget.h"
#include "ui_bmiwidget.h"

BMIWidget::BMIWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::BMIWidget)
{
    ui->setupUi(this);
}

BMIWidget::~BMIWidget()
{
    delete ui;
}

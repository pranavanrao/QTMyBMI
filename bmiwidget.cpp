#include "bmiwidget.h"
#include "ui_bmiwidget.h"

#include <QtGlobal>

BMIWidget::BMIWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::BMIWidget)
{
    ui->setupUi(this);
    ui->spinBox_height->setValue(0);
    ui->spinBox_height->setMaximum(1000);
    ui->lable_height->setText("Enter Height in cm");
    ui->label_weight->setText("Enter weight in kgs");
    ui->label_bmi->setText("BMI result");

    // connect(ui->spinBox_height,
    //         qOverload<int>(&QSpinBox::valueChanged),
    //         ui->lcdNumber_bmi,
    //         qOverload<int>(&QLCDNumber::display));

    connect(ui->spinBox_height,
            SIGNAL(valueChanged(int)),
            ui->lcdNumber_bmi,
            SLOT(display(int)));
}

BMIWidget::~BMIWidget()
{
    delete ui;
}

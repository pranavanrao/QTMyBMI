#include "bmiwidget.h"
#include "ui_bmiwidget.h"

#include <QtGlobal>
#include <QDebug>
#include <math.h>

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
    ui->label_result->setText("Your Body Condition : ");

    // connect(ui->spinBox_height,
    //         qOverload<int>(&QSpinBox::valueChanged),
    //         ui->lcdNumber_bmi,
    //         qOverload<int>(&QLCDNumber::display));

    // connect(ui->spinBox_height,
    //         SIGNAL(valueChanged(int)),
    //         ui->lcdNumber_bmi,
    //         SLOT(display(int)));

    // connect(ui->spinBox_height,
    //         qOverload<int>(&QSpinBox::valueChanged),
    //         this,
    //         &BMIWidget::getValue);

    // connect(ui->pb_calculate,
    //         &QPushButton::pressed,
    //         this,
    //         &BMIWidget::getValue
    //         );
}

BMIWidget::~BMIWidget()
{
    delete ui;
}

void BMIWidget::getValue(float val)
{
    int ht = ui->spinBox_height->value();
    int wt = ui->lineEdit_weight->text().toInt();
    val = (wt / pow(ht, 2))*10000;
    qDebug() << "BMI value : " << val;
}


void BMIWidget::on_pb_calculate_clicked()
{
    int ht = ui->spinBox_height->value();
    int wt = ui->lineEdit_weight->text().toInt();
    float bmi = (wt / pow(ht, 2))*10000;
    ui->lcdNumber_bmi->display(bmi);

    if (bmi < 18.5) {
        ui->label_result->setText("Your Body Condition : You are UNDERWEIGHT!!!");
    } else if (bmi >= 18.5 && bmi < 25) {
        ui->label_result->setText("Your Body Condition : You are HEALTHY!!!");
    } else if (bmi >= 25 && bmi < 30) {
        ui->label_result->setText("Your Body Condition : You are OVERWEIGHT!!!");
    } else {
        ui->label_result->setText("Your Body Condition : You are OBESE!!!");
    }

    qDebug() << "BMI value : " << bmi;
}


void BMIWidget::on_pb_clear_clicked()
{
    ui->spinBox_height->setValue(0);
    ui->lineEdit_weight->clear();
    ui->lcdNumber_bmi->display(0);
}


void BMIWidget::on_pb_close_clicked()
{
    exit(0);
}


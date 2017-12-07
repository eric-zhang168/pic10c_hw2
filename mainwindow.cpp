#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QObject::connect(ui->spinBoxhw1,SIGNAL(valueChanged(int)),ui->Sliderhw1,SLOT(setValue(int)));
    QObject::connect(ui->Sliderhw1,SIGNAL(valueChanged(int)),ui->spinBoxhw1,SLOT(setValue(int)));
    QObject::connect(ui->spinBoxhw2,SIGNAL(valueChanged(int)),ui->Sliderhw2,SLOT(setValue(int)));
    QObject::connect(ui->Sliderhw2,SIGNAL(valueChanged(int)),ui->spinBoxhw2,SLOT(setValue(int)));
    QObject::connect(ui->spinBoxhw3,SIGNAL(valueChanged(int)),ui->Sliderhw3,SLOT(setValue(int)));
    QObject::connect(ui->Sliderhw3,SIGNAL(valueChanged(int)),ui->spinBoxhw3,SLOT(setValue(int)));
    QObject::connect(ui->spinBoxhw4,SIGNAL(valueChanged(int)),ui->Sliderhw4,SLOT(setValue(int)));
    QObject::connect(ui->Sliderhw4,SIGNAL(valueChanged(int)),ui->spinBoxhw4,SLOT(setValue(int)));
    QObject::connect(ui->spinBoxhw5,SIGNAL(valueChanged(int)),ui->Sliderhw5,SLOT(setValue(int)));
    QObject::connect(ui->Sliderhw5,SIGNAL(valueChanged(int)),ui->spinBoxhw5,SLOT(setValue(int)));

    QObject::connect(ui->spinBoxmidterm1,SIGNAL(valueChanged(int)),ui->Slidermidterm1,SLOT(setValue(int)));
    QObject::connect(ui->Slidermidterm1,SIGNAL(valueChanged(int)),ui->spinBoxmidterm1,SLOT(setValue(int)));
    QObject::connect(ui->spinBoxmidterm2,SIGNAL(valueChanged(int)),ui->Slidermidterm2,SLOT(setValue(int)));
    QObject::connect(ui->Slidermidterm2,SIGNAL(valueChanged(int)),ui->spinBoxmidterm2,SLOT(setValue(int)));
    QObject::connect(ui->spinBoxfinal,SIGNAL(valueChanged(int)),ui->Sliderfinal,SLOT(setValue(int)));
    QObject::connect(ui->Sliderfinal,SIGNAL(valueChanged(int)),ui->spinBoxfinal,SLOT(setValue(int)));

    QObject::connect(ui->spinBoxhw1,SIGNAL(valueChanged(int)),this,SLOT(calculate_grade()));
    QObject::connect(ui->spinBoxhw2,SIGNAL(valueChanged(int)),this,SLOT(calculate_grade()));
    QObject::connect(ui->spinBoxhw3,SIGNAL(valueChanged(int)),this,SLOT(calculate_grade()));
    QObject::connect(ui->spinBoxhw4,SIGNAL(valueChanged(int)),this,SLOT(calculate_grade()));
    QObject::connect(ui->spinBoxhw5,SIGNAL(valueChanged(int)),this,SLOT(calculate_grade()));
    QObject::connect(ui->spinBoxmidterm1,SIGNAL(valueChanged(int)),this,SLOT(calculate_grade()));
    QObject::connect(ui->spinBoxmidterm2,SIGNAL(valueChanged(int)),this,SLOT(calculate_grade()));
    QObject::connect(ui->spinBoxfinal,SIGNAL(valueChanged(int)),this,SLOT(calculate_grade()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::calculate_grade()
{
    double grade=double(ui->spinBoxhw1->value()+ui->spinBoxhw2->value()+ui->spinBoxhw3->value()+ui->spinBoxhw4->value()+ui->spinBoxhw5->value())/5*0.25+
            double(ui->spinBoxmidterm1->value())*0.2+double(ui->spinBoxmidterm2->value())*0.2+double(ui->spinBoxfinal->value())*0.35;
    ui->score_label->setText(QString::number(grade));
}

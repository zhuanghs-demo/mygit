#include "demo.h"
#include "ui_demo.h"

Demo::Demo(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Demo)
{
    ui->setupUi(this);
    this->setWindowTitle(tr("测试界面"));
    connect(ui->pushButton_OK, SIGNAL(pressed()), this, SLOT(slotBtnOkPressed()));
    connect(ui->pushButton_Cancel, SIGNAL(pressed()), this, SLOT(slotBtnCancelPressed()));
}

Demo::~Demo()
{
    delete ui;
}

void Demo::setInput1Str(const QString& sInput)
{
    this->sInput1 = sInput;
    ui->lineEdit_Input1->setText(this->sInput1);
}
void Demo::setInput2Str(const QString& sInput)
{
    this->sInput2 = sInput;
    ui->lineEdit_Input2->setText(this->sInput2);
}
void Demo::setOutputStr(const QString& sOutput)
{
    this->sOutput = sOutput;
    ui->lineEdit_Output->setText(this->sOutput);
}

QString Demo::getInput1Str()
{
    this->sInput1 = ui->lineEdit_Input1->text();
    return this->sInput1;
}

QString Demo::getInput2Str()
{
    this->sInput2 = ui->lineEdit_Input2->text();
    return this->sInput2;
}

QString Demo::getOutputStr()
{
    this->sOutput = ui->lineEdit_Output->text();
    return this->sOutput;
}

void Demo::slotBtnOkPressed()
{
    calcResult();
    this->update();
}

void Demo::slotBtnCancelPressed()
{
    this->close();
}

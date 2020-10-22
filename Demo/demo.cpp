#include "demo.h"
#include "ui_demo.h"
#include "findmediansortedarrays.h"
#include "longestpalindrome.h"

Demo::Demo(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Demo)
{
    ui->setupUi(this);
    this->setWindowTitle(tr("测试界面"));
    initVar();
    initUi();
    initConnetion();
}

void Demo::initUi()
{
    ui->lineEdit_Output->setReadOnly(true);
    ui->lineEdit_TimeSpend->setReadOnly(true);
    ui->textBrowser_ProblemDesc->setReadOnly(true);
}

void Demo::initVar()
{
    dtAlgoEnd = dtAlgoStart = QDateTime::currentDateTime();
}

void Demo::initConnetion()
{
    connect(ui->comboBox_ProblemNo, SIGNAL(currentIndexChanged(int)), this, SLOT(slotIndexChange(int)));
    connect(ui->pushButton_OK, SIGNAL(pressed()), this, SLOT(slotBtnOkPressed()));
    connect(ui->pushButton_Cancel, SIGNAL(pressed()), this, SLOT(slotBtnCancelPressed()));
}

void Demo::setProblemGroupBoxData(const QMap<int, QString> &mapProblem)
{
    QMap<int, QString>::const_iterator iter = mapProblem.begin();
    int nIndex = 0;
    for(; iter != mapProblem.end(); ++iter,++nIndex){
        ui->comboBox_ProblemNo->insertItem(nIndex, iter.value(), iter.key());
    }
}

Demo::~Demo()
{
    ui->comboBox_ProblemNo->clear();
    delete ui;
    sInput1.clear();
    sInput2.clear();
    sOutput.clear();
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

void Demo::setAlgoStart()
{
    dtAlgoStart = QDateTime::currentDateTime();
    dtAlgoEnd = QDateTime::currentDateTime();
}

void Demo::setAlgoEnd()
{
    dtAlgoEnd = QDateTime::currentDateTime();
    //qDebug() << dtAlgoEnd.toMSecsSinceEpoch() << dtAlgoStart.toMSecsSinceEpoch();
    qint64 nTimeSpend = dtAlgoEnd.toMSecsSinceEpoch() - dtAlgoStart.toMSecsSinceEpoch();
    ui->lineEdit_TimeSpend->setText(QString::number(nTimeSpend));
}

void Demo::setProblemGroupBoxIndex(const int nIndex)
{
    ui->comboBox_ProblemNo->setCurrentIndex(nIndex);
}

int Demo::getProblemCurrentNo()
{
    return ui->comboBox_ProblemNo->currentIndex();
}

void Demo::setDesc(const int nIndex)
{
    switch (nIndex) {
        case ENUM_DEMO_4th:{
            findMedianSortedArrays Algo4;
            Algo4.setProblemDesc(this);
         }
            break;
         case ENUM_DEMO_5th:{
            longestPalindrome Algo5;
            Algo5.setProblemDesc(this);
          }
            break;
        default :
            break;
    }
}

void Demo::calcResult(const int nProblemNo)
{
    switch (nProblemNo) {
        case ENUM_DEMO_4th:{
            findMedianSortedArrays Algo4;
            Algo4.setProblemDesc(this);
            Algo4.calcResult(this);
         }
            break;
         case ENUM_DEMO_5th:{
            longestPalindrome Algo5;
            Algo5.setProblemDesc(this);
            Algo5.calcResult(this);
          }
            break;
        default :
            break;
    }
}

void Demo::setProblemDesc(const QString &strDesc)
{
    ui->textBrowser_ProblemDesc->clear();
    ui->textBrowser_ProblemDesc->setText(strDesc);
}

void Demo::slotIndexChange(int nIndex)
{
    setDesc(nIndex);
    emit indexChange(nIndex);
}

void Demo::slotBtnOkPressed()
{
    int nProblemNo = ui->comboBox_ProblemNo->currentIndex();
    calcResult(nProblemNo);
    this->update();
}

void Demo::slotBtnCancelPressed()
{
    this->close();
}

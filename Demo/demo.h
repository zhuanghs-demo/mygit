#ifndef DEMO_H
#define DEMO_H

/**
 * @ProjName:   Demo
 * @FileName:   demo.h
 * @Author:     zhuanghs
 * @Date:       2020-07-01 08:40
 * @Brief:      测试界面基类
 */

#include <QWidget>
#include <QDateTime>
#include <QDebug>

#include "problemtypeno.h"
using namespace problemspace;

namespace Ui {
class Demo;
}

class Demo : public QWidget
{
    Q_OBJECT

public:
    explicit Demo(QWidget *parent = 0);
    virtual ~Demo();

public:
    void initUi();
    void initVar();
    void initConnetion();
    void setProblemGroupBoxData(const QMap<int, QString> &mapProblem);
    void setInput1Str(const QString& sInput);
    void setInput2Str(const QString& sInput);
    void setOutputStr(const QString& sOutput);
    QString getInput1Str();
    QString getInput2Str();
    QString getOutputStr();
    void setAlgoStart();
    void setAlgoEnd();
    void setProblemGroupBoxIndex(const int nIndex);
    int getProblemCurrentNo();
    void setDesc(const int nIndex);
    void calcResult(const int nProblemNo);
    void setProblemDesc(const QString& strDesc);

signals:
    void indexChange(int nIndex);

protected slots:
    void slotIndexChange(int nIndex);
    void slotBtnOkPressed();
    void slotBtnCancelPressed();

private:
    Ui::Demo *ui;

private:
    QString sInput1;
    QString sInput2;
    QString sOutput;
    QDateTime dtAlgoStart;
    QDateTime dtAlgoEnd;
};

#endif // DEMO_H

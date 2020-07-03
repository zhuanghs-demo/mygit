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
    virtual void calcResult(){}

public:
    void setInput1Str(const QString& sInput);
    void setInput2Str(const QString& sInput);
    void setOutputStr(const QString& sOutput);
    QString getInput1Str();
    QString getInput2Str();
    QString getOutputStr();

protected slots:
    void slotBtnOkPressed();
    void slotBtnCancelPressed();

private:
    Ui::Demo *ui;

private:
    QString sInput1;
    QString sInput2;
    QString sOutput;
};

#endif // DEMO_H

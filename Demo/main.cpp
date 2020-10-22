#include "demofactory.h"
#include <QApplication>
#include <QTextCodec>
#include <QDebug>
#include <QDomDocument>

int main(int argc, char *argv[])
{
    QTextCodec *codec = QTextCodec::codecForName("UTF-8");
    QTextCodec::setCodecForTr(codec);
    QTextCodec::setCodecForLocale(QTextCodec::codecForLocale());
    QTextCodec::setCodecForCStrings(QTextCodec::codecForLocale());

    
    QApplication a(argc, argv);
    Demo *pDemo = DemoFactory::instance().createDemoBase();
//    int nProblemNo = pDemo->getProblemCurrentNo();
//    qDebug() << nProblemNo;

    if(!pDemo){
        return -1;
    }
    pDemo->show();
    return a.exec();
}

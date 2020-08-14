#include "demofactory.h"
#include <QApplication>
#include <QTextCodec>
#include <QDebug>

int main(int argc, char *argv[])
{
    QTextCodec *codec = QTextCodec::codecForName("UTF-8");
    QTextCodec::setCodecForTr(codec);
    QTextCodec::setCodecForLocale(QTextCodec::codecForLocale());
    QTextCodec::setCodecForCStrings(QTextCodec::codecForLocale());

    QApplication a(argc, argv);
    Demo *pDemo = DemoFactory::instance().createDemoCase(5);
    if(!pDemo){
        return -1;
    }
    pDemo->show();
    return a.exec();
}

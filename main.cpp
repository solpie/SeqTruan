#include <QApplication>
#include "view/SeqTruanWin.h"
#include "model/App.h"
int main(int argc, char *argv[]) {
//    QApplication a(argc, argv);
////    Q_INIT_RESOURCE(qrc);
//    QFile f(":/qss_button");
//    f.open(QIODevice::ReadOnly);
//    QString ss = f.readAll();
//    f.close();
//    qDebug()<<"res size:"<<f.size()<<ss;
//    SeqTruanWin w;
//    w.show();
//
//    return a.exec();

    App::_().start(argc,argv);
    return 0;
}

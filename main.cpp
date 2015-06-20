#include <QtWidgets/qstylefactory.h>
#include "view/SeqTruanWin.hpp"
int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    a.setApplicationName("SeqTruan");
    a.setStyle(QStyleFactory::create("Fusion"));
    App::_().start(argc,argv);
    SeqTruanWin *seqTruanWin = new SeqTruanWin();
    seqTruanWin->show();
    App()._().test();
    a.exec();
    return 0;
}

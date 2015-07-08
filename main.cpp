#include <QtWidgets/qstylefactory.h>
#include <QSurfaceFormat>
#include "view/SeqTruanWin.hpp"
#define QT_NO_DEBUG_OUTPUT

#include "model/AppExternal.hpp"
int main(int argc, char *argv[]) {
    AppExternal::startWatch("f:\\test1");

    QApplication a(argc, argv);
    QSurfaceFormat format;
    format.setDepthBufferSize(24);
    QSurfaceFormat::setDefaultFormat(format);

    a.setApplicationName("SeqTruan");
    a.setStyle(QStyleFactory::create("Fusion"));
    App::_().start(argc, argv);
    SeqTruanWin *seqTruanWin = new SeqTruanWin();
    seqTruanWin->show();
    App()._().test();
    a.exec();
    return 0;
}

#include <QApplication>
#include "view/SeqTruanWin.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    SeqTruanWin w;
    w.show();

    return a.exec();
}

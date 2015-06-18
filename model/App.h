//
// Created by manoyuria on 2015/6/18.
//

#ifndef SEQTRUAN_APP_H
#define SEQTRUAN_APP_H

#endif //SEQTRUAN_APP_H

#include <QApplication>

#include "Singleton.h"
#include "TrackModel.h"
#include "view/SeqTruanWin.h"

class App : public Singleton<App> {
public:

    void start(int argc, char *argv[]) {
        QApplication a(argc, argv);
        init();
        initUI();
        a.exec();
    }

    void init() {
        trackModel = new TrackModel();
    }

    void initUI() {
        seqTruanWin = new SeqTruanWin();
        seqTruanWin->show();
    }

    TrackModel *trackModel;
private:
    SeqTruanWin *seqTruanWin;
};
//
// Created by manoyuria on 2015/6/18.
//
#pragma once
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
        test();
        a.exec();
    }

    void init() {
        trackModel = new TrackModel();
    }

    void initUI() {
        seqTruanWin = new SeqTruanWin();
        seqTruanWin->show();
    }

    void test() {
        App()._().trackModel->newTrack("curry", "D:/projects/SeqTruanCpp/test/test10/");

    }

    TrackModel *trackModel;
private:
    SeqTruanWin *seqTruanWin;
};
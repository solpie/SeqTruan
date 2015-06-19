//
// Created by manoyuria on 2015/6/18.
//
#pragma once
#ifndef SEQTRUAN_APP_H
#define SEQTRUAN_APP_H

#endif //SEQTRUAN_APP_H

#include <QApplication>
#include "QStyleFactory"
#include "Singleton.h"
#include "TrackModel.h"
#include "view/SeqTruanWin.h"

class App : public Singleton<App> {
public:

    void start(int argc, char *argv[]) {
        QApplication a(argc, argv);
        a.setApplicationName("SeqTruan");
        a.setStyle(QStyleFactory::create("Fusion"));
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
//        App()._().trackModel->audioPlayback->load("D:/projects/SeqTruanCpp/test/mp3.mp3");
//        App()._().trackModel->audioPlayback->play();
    }

    TrackModel *trackModel;
private:
    SeqTruanWin *seqTruanWin;
};
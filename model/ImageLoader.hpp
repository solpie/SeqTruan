//
// Created by toramisu on 2015/6/24.
//
#pragma once
#ifndef SEQTRUAN_IMAGELOADER_HPP
#define SEQTRUAN_IMAGELOADER_HPP

#endif //SEQTRUAN_IMAGELOADER_HPP

#include "QThread"
#include "QImage"
#include "QtCore"

class ImageLoader : public QObject {
Q_OBJECT
public:

    ImageLoader() : QObject() {
        moveToThread(&t);
        t.start();
    }

    ~ImageLoader() {
        qDebug("Bye bye!");
        t.quit();
        t.wait();
    }

    QImage *payLoad = nullptr;

    void load(QString absPath) {
        qDebug() << this << "Image loading in Thread:" << absPath;

        QMetaObject::invokeMethod(this, "completed", Q_ARG(QString, absPath));
    }


public slots:

    void completed(QString absPath) {
//        QImage image(absPath);
//        payLoad = &image;
        payLoad = new QImage(absPath);
        qDebug() << this << "Image loaded!" << absPath;
//        emit imageReady(&image);
    }


private:
    QThread t;
};
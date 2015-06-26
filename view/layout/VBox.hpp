//
// Created by toramisu on 2015/6/26.
//

#ifndef SEQTRUAN_VBOX_HPP
#define SEQTRUAN_VBOX_HPP

#endif //SEQTRUAN_VBOX_HPP

#include <QtCore/qcoreevent.h>
#include "QWidget"

class VBox : public QWidget {
public:
    VBox(QWidget *parent) : QWidget(parent) {

    }

    void addWidget(QWidget *child) {
        child->setParent(this);
        child->move(child->x(), this->height());
        child->show();
        int newWidth = child->x() + child->width();
        child->installEventFilter(this);

        if (newWidth > this->width())
            resize(newWidth, height() + child->height());
        else
            resize(this->width(), height() + child->height());
    }

    virtual bool eventFilter(QObject *object, QEvent *qEvent) override {
        if (qEvent->type() == QEvent::Resize) {
            QWidget *w = ((QWidget *) object);
            int newWidth = w->x() + w->width();
            if (newWidth > this->width())
                resize(newWidth, height());
        }
    }

    void refresh() {

    }
};


#pragma once
//
// Created by manoyuria on 2015/6/22.
//

#ifndef SEQTRUAN_POPUP_HPP
#define SEQTRUAN_POPUP_HPP

#endif //SEQTRUAN_POPUP_HPP

#include "view/UI.hpp"
#include "events/PopupEvent.hpp"

class Popup : public QWidget {
public:
    Popup(QWidget *parent) : QWidget(parent) {
        resize(100, 80);
        setStyleSheet("background:#ff0000");
        Evt_add(ActionEvent::POPUP_MENU, onPopup)

        QWidget *m = new QWidget(this);
        _setY(m, 25);
        vbox = new QVBoxLayout(m);
        vbox->setSpacing(0);
        items = new vector<QLabel *>();
    }

    void onPopup(PopupEvent *e) {
//        this->setParent(parentWidget());
        this->show();
        QLabel *item;
        qDebug() << this << "menu";
        if (e->funcs.size() > items->size()) {
            int addCount = items->size() - e->funcs.size();
            for (int i = 0; i < addCount; i++) {
                item = new QLabel();
                items->push_back(item);
                vbox->addWidget(item);
            }
        }
//        int j = 0;
//        map<QString, function<void()>>::iterator it = e->funcs.begin();
//        for (; it != e->funcs.end(); ++it) {
//            qDebug() << this << it->first;
//            item = items->at(j);
//            item->setText(it->first);
//            ++j;
//        }
//            for (QString name:e->funcs.key_comp()) {

//        }
    }

private:
    vector<QLabel *> *items;
    QVBoxLayout *vbox;
};
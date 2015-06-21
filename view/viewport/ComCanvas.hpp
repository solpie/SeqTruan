#pragma once
//
// Created by manoyuria on 2015/6/21.
//

#ifndef SEQTRUAN_COMCANVAS_HPP
#define SEQTRUAN_COMCANVAS_HPP

#endif //SEQTRUAN_COMCANVAS_HPP

#include "view/UI.hpp"
#include "QOpenGLTexture"

class ComCanvas : public QWidget {
public:
    ComCanvas(QWidget *parent) : QWidget(parent) {
        resize(1280, 720);
    }

    void setImage(QImage *qImage) {

        img = qImage;
        update();

//        if (_texmap.find(qImage) != _texmap.end()) {
//            texture = _texmap[qImage];
//        }
//        else {
//            texture = new QOpenGLTexture(qImage->mirrored());
//            // Set nearest filtering mode for texture minification
//            texture->setMinificationFilter(QOpenGLTexture::Nearest);
//
//            // Set bilinear filtering mode for texture magnification
//            texture->setMagnificationFilter(QOpenGLTexture::Linear);
//            _texmap[qImage] = texture;
//        }

    }

protected:
    map<QImage *, QOpenGLTexture *> _texmap;
    QOpenGLTexture *texture;
    QOpenGLFunctions *f;
    QImage *img = nullptr;

//    void initializeGL() {
//        // Set up the rendering context, load shaders and other resources, etc.:
//        f = QOpenGLContext::currentContext()->functions();
//        f->glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
//    }



//    void resizeGL(int w, int h)
//    {
//        // Update projection matrix and other size related settings:
//        m_projection.setToIdentity();
//        m_projection.perspective(45.0f, w / float(h), 0.01f, 100.0f);
//        ...
//    }
//
    void drawImage() {
        if (img) {
            QPainter painter(this);
            painter.drawImage(0, 0, *img);
        }
    }

    virtual void paintEvent(QPaintEvent *qPaintEvent) override {

        if (img) {
            QPainter painter(this);
            painter.drawImage(0, 0, *img);
        }
    }

    void paintGL() {

//        glClear(GL_COLOR_BUFFER_BIT);
//        f->glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//        f->glBegin(GL_LINES);
//        f->glLineWidth(3);
//        f->glColor3f(.5, .5, .5);
//        f->glVertex2i(10, 10);
//        f->glVertex2i(100, 100);
//        f->glEnd();
//        f->glFlush();
//        if(texture)
//        {
//            glEnable(GL_TEXTURE_2D);
////        glGenTextures( 1 );
////        glBindTexture( GL_TEXTURE_2D, texture);
//            glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, texture->width(), texture->height(), 0, GL_RGBA, GL_UNSIGNED_BYTE,texture);
////        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
////        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEARES
//            glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
//            glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
//            glDisable(GL_TEXTURE_2D);
//        }
    }

};
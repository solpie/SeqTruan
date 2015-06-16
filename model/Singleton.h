#pragma once
//
// Created by toramisu on 2015/6/16.
//

#ifndef SEQTRUAN_SINGLETON_H
#define SEQTRUAN_SINGLETON_H


#include <assert.h>
#include <dsdriver.h>

//template<typename T>
//class Singleton {
//protected:
//    static T *ms_Singleton;
//public:
//    Singleton(void) {
//        assert(!ms_Singleton);
//        ms_Singleton = static_cast< T * >(this);
//    }
//
//    ~Singleton(void) {
//        assert(ms_Singleton);
//        ms_Singleton = 0;
//    }
//
//    static T &getSingleton(void) {
//        assert(ms_Singleton);
//        return (*ms_Singleton);
//    }
//
//    static T *getSingletonPtr(void) { return ms_Singleton; }
//};
class Singleton {
public:
    static Singleton& Instance() {
        static Singleton theSingleton;
        return theSingleton;
    }

    /* more (non-static) functions here */

private:
    Singleton();                            // ctor hidden
    Singleton(Singleton const&);            // copy ctor hidden
    Singleton& operator=(Singleton const&); // assign op. hidden
    ~Singleton();                           // dtor hidden
};
#endif //SEQTRUAN_SINGLETON_H

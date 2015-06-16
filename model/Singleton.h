#pragma once
//
// Created by toramisu on 2015/6/16.
//

#ifndef SEQTRUAN_SINGLETON_H
#define SEQTRUAN_SINGLETON_H


//class S {
//public:
//    static S &getInstance() {
//        static S instance; // Guaranteed to be destroyed.
//        // Instantiated on first use.
//        return instance;
//    }
//
//private:
//    S() { };                   // Constructor? (the {} brackets) are needed here.
//
//    // C++ 11
//    // =======
//    // We can use the better technique of deleting the methods
//    // we don't want.
//    S(S const &) = delete;
//
//    void operator=(S const &) = delete;
//
//};

template<typename T>
class Singleton {
public:
    static T &_() {
        static T instance;
        return instance;
    }
};


#endif //SEQTRUAN_SINGLETON_H

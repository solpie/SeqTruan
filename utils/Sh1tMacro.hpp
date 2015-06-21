#pragma once
//
// Created by manoyuria on 2015/6/21.
//

#ifndef SEQTRUAN_FUCKMACRO_HPP
#define SEQTRUAN_FUCKMACRO_HPP

#endif //SEQTRUAN_FUCKMACRO_HPP
//基本类型 属性
//#define prop(type, name)    type __##name;\
//void set##name(type i) {\
//__##name = i;\
//}\
//int get##name() {\
//    return __##name;\
//}
#define propGet(type, name)    type __##name;\
int get##name() {\
    return __##name;\
}
#define propSet(type, name,func)    type __##name;\
void set##name(type i) {\
__##name = i;\
func();\
}\
int get##name() {\
    return __##name;\
}
//类 属性
#define propptr(type, name)    type *__##name;\
void set_##name(type *i) {\
*__##name = *i;\
}\
int get_##name() {\
    return *__##name;\
}
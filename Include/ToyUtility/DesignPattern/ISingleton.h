#pragma once

#include "ToyUtility/Prerequisites/PreDefine.h"


namespace ToyUtility
{


template<typename SingletonClass>
class ISingleton
{
public:
    static SingletonClass& Instance()
    {
        static SingletonClass* instance = new SingletonClass();
        return *instance;

        // TODO: or using this code?
        //static SingletonClass instance;
        //return instance;
    }
};


} // end of namespace ToyUtility
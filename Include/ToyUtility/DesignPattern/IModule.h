#pragma once

#include "ToyUtility/Prerequisites/PreDefine.h"


namespace ToyUtility
{


class IModule
{
public:
    virtual ~IModule(){};

    virtual void StartUp() = 0;
    virtual void ShutDown() = 0;
    virtual void Update(float delta) { }
    virtual void PostUpdate(float delta) { }
};


} // end of namespace ToyUtility
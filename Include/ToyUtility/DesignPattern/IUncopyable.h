#pragma once

#include "ToyUtility/Prerequisites/PreDefine.h"


namespace ToyUtility
{


class IUncopyable
{
protected:
    IUncopyable() = default;
    ~IUncopyable() = default;


private:
    IUncopyable(const IUncopyable&);
    IUncopyable& operator=(const IUncopyable&);
};


} // end of namespace ToyUtility
#pragma once

#include "ToyUtility/Prerequisites/PreDefine.h"
#include "ToyUtility/String/String.h"
#include "ToyUtility/Container/List.h"


namespace ToyUtility
{


enum class DriverLetter
{
    None,
    A,
    B,
    C,
    D,
    E,
    F,
    G,
    H,
    I,
    J,
    K,
    L,
    M,
    N,
    O,
    P,
    Q,
    R,
    S,
    T,
    U,
    V,
    W,
    X,
    Y,
    Z,
    End,
};


class FileSystemPath
{
public:
    FileSystemPath(const String& path)
    {
    }


private:
    DriverLetter m_DriverLetter;
    bool m_Absolute;
    List<String> m_Paths;
};


} // end of namespace ToyUtility
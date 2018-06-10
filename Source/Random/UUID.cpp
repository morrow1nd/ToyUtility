#include "ToyUtility/Random/UUID.h"

#include "UUID-sole/sole.hpp"


namespace ToyUtility
{


UUID UUID::None = UUID(0,0);


UUID UUID::CreateVersion1()
{
    auto uuid = sole::uuid1();
    return UUID(uuid.ab, uuid.cd);
}

UUID UUID::CreateVersion4()
{
    auto uuid = sole::uuid4();
    return UUID(uuid.ab, uuid.cd);
}

UUID UUID::Rebuild(uint64 X, uint64 Y)
{
    return UUID(X, Y);
}

UUID UUID::Rebuild(const String & uustr)
{
    auto uuid = sole::rebuild(uustr);
    return UUID(uuid.ab, uuid.cd);
}

String UUID::Str() const
{
    return sole::rebuild(Data.Numbers64.X, Data.Numbers64.Y).str();
}

String UUID::Pretty() const
{
    return sole::rebuild(Data.Numbers64.X, Data.Numbers64.Y).pretty();
}


} // end of namespace ToyUtility
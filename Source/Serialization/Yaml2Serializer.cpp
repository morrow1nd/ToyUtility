#include "ToyUtility/Serialization/Yaml2Serializer.h"

#include "ToyUtility/Log/Logger.h"


namespace ToyUtility
{


Yaml2Serializer::Yaml2Serializer(DataStream & stream)
    :
    Serializer(stream)
{
    yaml_emitter_initialize(&m_YamlEmitter);
    //yaml_emitter_set_output(&m_YamlEmitter, )
}

Yaml2Serializer::~Yaml2Serializer()
{

}

void Yaml2Serializer::Push(const uint8 v, const String & fieldName)
{
}


void Yaml2Serializer::BeginDictionary(const String & name)
{
}

void Yaml2Serializer::EndDictionary()
{
}

void Yaml2Serializer::BeginArray(const String & name)
{
}

void Yaml2Serializer::EndArray()
{
}

void Yaml2Serializer::Flush()
{
}


} // end of namespace ToyUtility
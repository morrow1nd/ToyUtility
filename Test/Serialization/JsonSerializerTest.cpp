#include "../catch.hpp"

#include "ToyUtility/DataStream/MemoryDataStream.h"
#include "ToyUtility/DataStream/FileDataStream.h"
#include "ToyUtility/Serialization/JsonSerializer.h"
#include "ToyUtility/Serialization/JsonUnserializer.h"


using namespace ToyUtility;


TEST_CASE("JsonSerailizer - basic", "[JsonSerializer]")
{
    const char* json = R"(

{
    "hello": "world",
    "t": true ,
    "f": false,
    "n": null,
    "i": 123,
    "pi": 3.1416,
    "a": [1, 2, 3, 4]
}

)";
    {
        FileDataStream file("./.test.json", DataStream::AccessMode::WRITE);
        JsonSerializer serializer(file);

        serializer.BeginDictionary("--root\\--");
        {
            serializer.Push(String("hello"), "world");
            serializer.Push(true, "t");
            serializer.Push(123, "i");
            serializer.Push(3.1416, "pi");
            serializer.BeginArray("a");
            {
                serializer.Push(1);
                serializer.Push(2);
                serializer.Push(3);
            }
            serializer.EndArray();
        }
        serializer.EndDictionary();

        serializer.Flush();
    }

    {
        SECTION("-")
        {
            FileDataStream file("./.test.json", DataStream::AccessMode::READ);
            JsonUnserializer unserializer(file);

            unserializer.BeginDictionary("--root\\--");
            {
                String s;
                unserializer.Pop("world", s);
                REQUIRE(s == "hello");

                bool b;
                unserializer.Pop("t", b);
                REQUIRE(b == true);

                int32 number;
                unserializer.Pop("t", number);
                REQUIRE(number == 123);

                double numberd;
                unserializer.Pop("pi", numberd);
                REQUIRE(numberd == 3.1416);

                unserializer.BeginArray("a");
                {
                    int number;
                    unserializer.Pop("", number);
                    REQUIRE(number == 1);
                    unserializer.Pop("", number);
                    REQUIRE(number == 2);
                    unserializer.Pop("", number);
                    REQUIRE(number == 3);
                }
                unserializer.EndArray();
            }
            unserializer.EndDictionary();
        }
    }
}
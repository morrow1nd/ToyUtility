#include "../catch.hpp"

#include "ToyUtility/FileSystem/FileSystem.h"


using namespace ToyUtility;


TEST_CASE("FileSystem - ListFiles", "[ToyUtility]")
{
    auto rootDir = FileSystem::Open("./test/");
    if (rootDir->Exist() && rootDir->IsDirectory())
    {
        rootDir->Remove();
    }

    rootDir->CreateDirectory();

    for (int i = 0; i < 5; ++i)
    {
        auto fh = FileSystem::Open(rootDir->Path() + "/" + std::to_string(i));
        auto output = fh->CreateOutputStream();
        (*output) << "---";
    }

    SECTION("-")
    {
        REQUIRE(rootDir->Exist());
        
        auto items = rootDir->ListFiles();
        for (int i = 0; i < 5; ++i)
        {
            REQUIRE(items[i] == std::to_string(i));
        }

        rootDir->Remove();
    }
}
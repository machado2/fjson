add_library(fjson 
    fjson.cpp
    JsonArray.cpp
    JsonNull.cpp
    JsonNumber.cpp
    JsonObject.cpp
    JsonString.cpp
    JsonValue.cpp
    JsonValueData.cpp
)

target_include_directories(fjson PUBLIC ../include)

set_property(TARGET fjson PROPERTY CXX_STANDARD 98)

if(CMAKE_CXX_COMPILER_ID STREQUAL "Borland")
    if(CMAKE_CXX_COMPILER_VERSION VERSION_LESS "6.0")
    include(FetchContent)
        FetchContent_Declare(
            boost
            GIT_REPOSITORY https://github.com/machado2/oldboost.git
            GIT_TAG        v1.31
        )
        FetchContent_MakeAvailable(boost)
        target_include_directories(fjson PUBLIC ${boost_SOURCE_DIR} ../include)
    endif()
endif()
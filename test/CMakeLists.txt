include_directories(../src)

add_executable(basictests basictests.cpp)
add_test(NAME basictests COMMAND "basictests")
target_link_libraries(basictests fjson)
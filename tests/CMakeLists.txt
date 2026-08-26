add_executable(dsa_tests test_dynamic_array.cpp)
target_link_libraries(dsa_tests PRIVATE Catch2::Catch2WithMain)
target_include_directories(dsa_tests PRIVATE ${CMAKE_SOURCE_DIR}/include)

include(CTest)
include(Catch)
catch_discover_tests(dsa_tests)
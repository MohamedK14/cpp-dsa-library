#include <catch2/catch_test_macros.hpp>
#include "dsa/dynamic_array.hpp"

TEST_CASE("Newly constructed array is empty") {
    dsa::MyDynamicArray<int> arr;
    REQUIRE(arr.empty() == true);
    REQUIRE(arr.size() == 0);
}



TEST_CASE("push_back adds elements correctly with a loop") {
    dsa::MyDynamicArray<int> arr;

    for (int i = 0; i < 5; i++) {
        arr.push_back(i + 1);
    }

    REQUIRE(arr.size() == 5);

    for (int i = 0; i < 5; i++) {
        REQUIRE(arr[i] == i + 1);
    }
}
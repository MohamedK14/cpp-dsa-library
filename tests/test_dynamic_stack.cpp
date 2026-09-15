#include <catch2/catch_test_macros.hpp>
#include "dsa/dynamic_stack.hpp"

TEST_CASE("Newly constructed stack is empty") {
    dsa::MyDynamicStack<int> stk;
    REQUIRE(stk.empty() == true);
    REQUIRE(stk.size() == 0);
}

TEST_CASE("push_back adds elements correctly with a loop") {
    dsa::MyDynamicStack<int> stk;

    for (int i = 0; i < 5; i++) {
        stk.push(i + 1);
    }

    REQUIRE(stk.size() == 5);

    for (int i = 5; i > 0; i--) {
        REQUIRE(stk.top() == i);
        stk.pop();
    }
}

TEST_CASE("pop on empty stack does not crash") {
    dsa::MyDynamicStack<int> stk;
    stk.pop();
    REQUIRE(stk.empty() == true);
}

TEST_CASE("top on empty stack throws") {
    dsa::MyDynamicStack<int> stk;
    REQUIRE_THROWS_AS(stk.top(), std::out_of_range);
}
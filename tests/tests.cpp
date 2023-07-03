#include "../src/lib.hpp"

#include <catch2/catch_test_macros.hpp>

TEST_CASE("nth Fibonacci number is computed", "[fib]") {
    REQUIRE(fib(-10) == -10);
    REQUIRE(fib(0) == 0);
    REQUIRE(fib(1) == 0);
    REQUIRE(fib(5) == 5);
    REQUIRE(fib(10) == 55);
    REQUIRE(fib(20) == 6765);
    REQUIRE(fib(30) == 832040);
}


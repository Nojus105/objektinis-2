#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "../vector/Vector.h"

// Default Constructor
TEST_CASE("Vektorius - Default Constructor", "[vektorius]") {
    Vektorius<int> vec;
    REQUIRE(vec.size() == 0);
    REQUIRE(vec.empty());
}

// Constructor with size and default value
TEST_CASE("Vektorius - Constructor with Size and Default Value", "[vektorius]") {
    Vektorius<int> vec(5, 42);
    REQUIRE(vec.size() == 5);
    for (size_t i = 0; i < vec.size(); ++i) {
        REQUIRE(vec[i] == 42);
    }
}

// Initializer List Constructor
TEST_CASE("Vektorius - Initializer List Constructor", "[vektorius]") {
    Vektorius<int> vec = {1, 2, 3, 4, 5};
    REQUIRE(vec.size() == 5);
    REQUIRE(vec[0] == 1);
    REQUIRE(vec[4] == 5);
}

// Copy Constructor
TEST_CASE("Vektorius - Copy Constructor", "[vektorius]") {
    Vektorius<int> vec1 = {1, 2, 3};
    Vektorius<int> vec2 = vec1;
    REQUIRE(vec2.size() == vec1.size());
    REQUIRE(vec2 == vec1);
}

// Move Constructor
TEST_CASE("Vektorius - Move Constructor", "[vektorius]") {
    Vektorius<int> vec1 = {1, 2, 3};
    Vektorius<int> vec2 = std::move(vec1);
    REQUIRE(vec2.size() == 3);
    REQUIRE(vec1.size() == 0);
    REQUIRE(vec1.empty());
}

// Copy Assignment
TEST_CASE("Vektorius - Copy Assignment", "[vektorius]") {
    Vektorius<int> vec1 = {1, 2, 3};
    Vektorius<int> vec2;
    vec2 = vec1;
    REQUIRE(vec2.size() == vec1.size());
    REQUIRE(vec2 == vec1);
}

// Move Assignment
TEST_CASE("Vektorius - Move Assignment", "[vektorius]") {
    Vektorius<int> vec1 = {1, 2, 3};
    Vektorius<int> vec2;
    vec2 = std::move(vec1);
    REQUIRE(vec2.size() == 3);
    REQUIRE(vec1.size() == 0);
    REQUIRE(vec1.empty());
}

// Push Back
TEST_CASE("Vektorius - Push Back", "[vektorius]") {
    Vektorius<int> vec;
    vec.push_back(10);
    vec.push_back(20);
    REQUIRE(vec.size() == 2);
    REQUIRE(vec[0] == 10);
    REQUIRE(vec[1] == 20);
}

// Pop Back
TEST_CASE("Vektorius - Pop Back", "[vektorius]") {
    Vektorius<int> vec = {10, 20, 30};
    vec.pop_back();
    REQUIRE(vec.size() == 2);
    REQUIRE(vec[1] == 20);
}

// Clear
TEST_CASE("Vektorius - Clear", "[vektorius]") {
    Vektorius<int> vec = {10, 20, 30};
    vec.clear();
    REQUIRE(vec.size() == 0);
    REQUIRE(vec.empty());
}

// Resize
TEST_CASE("Vektorius - Resize", "[vektorius]") {
    Vektorius<int> vec = {10, 20};
    vec.resize(5, 42);
    REQUIRE(vec.size() == 5);
    REQUIRE(vec[2] == 42);
    vec.resize(1);
    REQUIRE(vec.size() == 1);
    REQUIRE(vec[0] == 10);
}

// Reserve
TEST_CASE("Vektorius - Reserve", "[vektorius]") {
    Vektorius<int> vec;
    vec.reserve(10);
    REQUIRE(vec.capacity() >= 10);
}

// Erase
TEST_CASE("Vektorius - Erase", "[vektorius]") {
    Vektorius<int> vec = {10, 20, 30};
    auto it = vec.erase(vec.begin() + 1);
    REQUIRE(vec.size() == 2);
    REQUIRE(vec[0] == 10);
    REQUIRE(vec[1] == 30);
    REQUIRE(it == vec.begin() + 1);
}

// Element Access
TEST_CASE("Vektorius - Element Access", "[vektorius]") {
    Vektorius<int> vec = {10, 20, 30};
    REQUIRE(vec[0] == 10);
    REQUIRE(vec.at(1) == 20);
    REQUIRE_THROWS_AS(vec.at(3), std::out_of_range);
}

// Iterators
TEST_CASE("Vektorius - Iterators", "[vektorius]") {
    Vektorius<int> vec = {10, 20, 30};
    auto it = vec.begin();
    REQUIRE(*it == 10);
    ++it;
    REQUIRE(*it == 20);
    ++it;
    REQUIRE(*it == 30);
    REQUIRE(it + 1 == vec.end());
}

// Equality Operator
TEST_CASE("Vektorius - Equality Operator", "[vektorius]") {
    Vektorius<int> vec1 = {10, 20, 30};
    Vektorius<int> vec2 = {10, 20, 30};
    REQUIRE(vec1 == vec2);
    vec2.push_back(40);
    REQUIRE(vec1 != vec2);
}

// Relational Operators
TEST_CASE("Vektorius - Relational Operators", "[vektorius]") {
    Vektorius<int> vec1 = {10, 20};
    Vektorius<int> vec2 = {10, 20, 30};
    REQUIRE(vec1 < vec2);
    REQUIRE(vec2 > vec1);
    REQUIRE(vec1 <= vec2);
    REQUIRE(vec2 >= vec1);
}

// Swap
TEST_CASE("Vektorius - Swap", "[vektorius]") {
    Vektorius<int> vec1 = {10, 20};
    Vektorius<int> vec2 = {30, 40};
    vec1.swap(vec2);
    REQUIRE(vec1[0] == 30);
    REQUIRE(vec1[1] == 40);
    REQUIRE(vec2[0] == 10);
    REQUIRE(vec2[1] == 20);
}
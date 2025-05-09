#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "../deque/header2.h"

TEST_CASE("Rule of Five - Copy Constructor", "[rule_of_five]") {
    Stud student1("Jonas", "Jonaitis", {10, 9, 8}, 9);
    Stud copy = student1;

    REQUIRE(copy.getVardas() == student1.getVardas());
    REQUIRE(copy.getPavarde() == student1.getPavarde());
    REQUIRE(copy.getEgzaminas() == student1.getEgzaminas());
    REQUIRE(copy.getPazymiai() == student1.getPazymiai());
}

TEST_CASE("Rule of Five - Copy Assignment", "[rule_of_five]") {
    Stud student1("Jonas", "Jonaitis", {10, 9, 8}, 9);
    Stud student2;
    student2 = student1;

    REQUIRE(student2.getVardas() == student1.getVardas());
    REQUIRE(student2.getPavarde() == student1.getPavarde());
    REQUIRE(student2.getEgzaminas() == student1.getEgzaminas());
    REQUIRE(student2.getPazymiai() == student1.getPazymiai());
}

TEST_CASE("Rule of Five - Move Constructor", "[rule_of_five]") {
    Stud student1("Jonas", "Jonaitis", {10, 9, 8}, 9);
    Stud moved = std::move(student1);

    REQUIRE(moved.getVardas() == "Jonas");
    REQUIRE(moved.getPavarde() == "Jonaitis");
    REQUIRE(moved.getEgzaminas() == 9);
    REQUIRE(moved.getPazymiai() == std::vector<int>{10, 9, 8});
    REQUIRE(student1.getVardas().empty());
    REQUIRE(student1.getPavarde().empty());
}

TEST_CASE("Rule of Five - Move Assignment", "[rule_of_five]") {
    Stud student1("Jonas", "Jonaitis", {10, 9, 8}, 9);
    Stud student2;
    student2 = std::move(student1);

    REQUIRE(student2.getVardas() == "Jonas");
    REQUIRE(student2.getPavarde() == "Jonaitis");
    REQUIRE(student2.getEgzaminas() == 9);
    REQUIRE(student2.getPazymiai() == std::vector<int>{10, 9, 8});
    REQUIRE(student1.getVardas().empty());
    REQUIRE(student1.getPavarde().empty());
}

TEST_CASE("Auto Function", "[auto]") {
    deque<Zmogus *> grupe;

    Auto(grupe);

    REQUIRE_FALSE(grupe.empty());
    REQUIRE(grupe.size() > 0);
}

TEST_CASE("Rusiuoti Function", "[sorting]") {
    deque<Zmogus *> grupe;
    Stud student1("Jonas", "Jonaitis", {10, 9, 8}, 9);
    Stud student2("Petras", "Petraitis", {7, 6, 5}, 6);
    Stud student3("Andrius", "Andraitis", {8, 8, 8}, 8);

    grupe.push_back(&student1);
    grupe.push_back(&student2);
    grupe.push_back(&student3);

    double TotalTime = 0.0;
    Rusiuoti(grupe, 'v', '0', TotalTime);

    REQUIRE(grupe[0]->getVardas() == "Andrius");
    REQUIRE(grupe[1]->getVardas() == "Jonas");
    REQUIRE(grupe[2]->getVardas() == "Petras");
}
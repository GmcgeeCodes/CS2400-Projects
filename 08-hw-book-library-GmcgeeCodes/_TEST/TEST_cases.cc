/*
 * Unit testing for the Book class for final CS 2400 project
 */
//#define CATCH_CONFIG_RUNNER

#define CATCH_CONFIG_MAIN  // Catch supplies a main program
#include <iostream>
#include "catch.hpp"
#include "../book.h"

using namespace std;
const int MAXSCORE = 44;
static int score = 0;

TEST_CASE("Testing  Book Class") {
    SECTION("Default Constructors") {
        Book a;
        REQUIRE("***" == a.getTitle());
        REQUIRE("***" == a.getAuthor());
        REQUIRE(0 == a.getYear());
        score += 2;
    }
    SECTION("Second Constructors (3 params provided)") {
        Book a("The Hitchhiker's Guide to the Galaxy", 1979,"Douglas Adams");
        REQUIRE("The Hitchhiker's Guide to the Galaxy" == a.getTitle());
        REQUIRE("Douglas Adams" == a.getAuthor());
        REQUIRE(1979 == a.getYear());
        Book a2("The Hitchhiker's Guide to the Galaxy", -1979,"Douglas Adams");
        REQUIRE(0 == a2.getYear());

        score += 2;
    }

    SECTION("All Data Book Constructors") {
        Book a("The Hitchhiker's Guide to the Galaxy|1979|Douglas Adams");
        REQUIRE("The Hitchhiker's Guide to the Galaxy" == a.getTitle());
        REQUIRE("Douglas Adams" == a.getAuthor());
        REQUIRE(1979 == a.getYear());
        Book a2("The Hitchhiker's Guide to the Galaxy|-1979|Douglas Adams");
        REQUIRE(0 == a2.getYear());
        score += 6;
    }

    SECTION("Book Getters & Setters"){
        Book a;
        a.setAuthor("Bob");
        REQUIRE("Bob" == a.getAuthor());

        a.setTitle("Cat in the Hat");
        REQUIRE("Cat in the Hat" == a.getTitle());

        a.setYear(2000);
        a.setYear(-2000);
        REQUIRE(2000 == a.getYear());
        score += 6;

    }

    SECTION("Match Title") {
        Book a("The Hitchhiker's Guide to the Galaxy", 1979,"Douglas Adams");

        REQUIRE(true == a.matchTitle("gUi"));
        REQUIRE(true == a.matchTitle("Guide"));
        REQUIRE(true == a.matchTitle("uide "));
        REQUIRE(true == a.matchTitle("The Hitchhiker's Guide to the Galaxy"));
        REQUIRE(false == a.matchTitle("giu"));

        score += 7;
    }
    SECTION("Match Author") {
        Book a("The Hitchhiker's Guide to the Galaxy", 1979,"Douglas Adams");

        REQUIRE(true == a.matchAuthor("ouG"));
        REQUIRE(true == a.matchAuthor("Douglas"));
        REQUIRE(true == a.matchAuthor("ADAMS"));
        REQUIRE(true == a.matchAuthor("DOUGLAS ADAMS"));
        REQUIRE(false == a.matchAuthor("MR. D"));

        score += 7;
    }
    SECTION("Match Year") {
        Book a("The Hitchhiker's Guide to the Galaxy", 1979,"Douglas Adams");

        REQUIRE(true == a.matchYear("1979"));
        REQUIRE(true == a.matchYear("79"));
        REQUIRE(true == a.matchYear("97"));
        REQUIRE(true == a.matchYear("1"));
        REQUIRE(false == a.matchYear("198"));

        score += 7;
    }

     SECTION("Match Any") {
        Book a("The Hitchhiker's Guide to the Galaxy", 1979,"Douglas Adams");
        REQUIRE(true == a.match("gUi"));
        REQUIRE(true == a.match("Guide"));
        REQUIRE(true == a.match("uide "));
        REQUIRE(true == a.match("The Hitchhiker's Guide to the Galaxy"));
        REQUIRE(false == a.match("giu"));
        REQUIRE(true == a.match("Douglas"));
        REQUIRE(true == a.match("ADAMS"));
        REQUIRE(true == a.match("DOUGLAS ADAMS"));
        REQUIRE(true == a.match("79"));
        REQUIRE(true == a.match("97"));
        REQUIRE(true == a.match("1"));
        REQUIRE(false == a.match("198"));
        REQUIRE(false == a.match("MR. D"));
        REQUIRE(false == a.match("giu"));

        score += 7;
    }

    SECTION("Score"){
        std::cout << "\033[1;35m" << "\n==========================================" << endl;
        std::cout << "\033[1;33m" <<  " Score: " << score << "/" << MAXSCORE << "\033[1;35m" << endl;
        // << " (passed " << testsPassed <<  " out of " << NUMTESTS << " tests)" << "\033[0m" << endl;
        std::cout << "==========================================\n" << "\033[0m" << endl;
    }
}


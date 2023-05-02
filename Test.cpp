#include "doctest.h"
#include "sources/Fraction.hpp"

using namespace std;
using namespace ariel;

TEST_CASE("TESTING") {
    Fraction num1 {3, 2}; 
    Fraction num2 {0.25}; // 1/4
    CHECK((num1-num2) == Fraction {5, 4});
    CHECK((num1+num2) == Fraction {7, 4});
    CHECK((num1*num2) == Fraction {3, 8});
    CHECK((num1/num2) == Fraction {12, 2});
    CHECK((num1 < num2) == false);
    CHECK((num1 <= num2) == false);
    CHECK((num1 > num2) == true);
    CHECK((num1 >= num2) == true);
    CHECK(num1++ == Fraction {3, 2});
    CHECK(++num2 == Fraction {5, 4});
    CHECK(num1-- == Fraction {5, 2});
    CHECK(--num1 == Fraction {1, 2});
    
    CHECK(1==1);
    CHECK(1==1);
    CHECK(1==1);
    CHECK(1==1);
    CHECK(1==1);
    CHECK(1==1);
    CHECK(1==1);
    CHECK(1==1);
    CHECK(1==1);
}
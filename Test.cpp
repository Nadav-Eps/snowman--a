#include "doctest.h"
#include "snowman.hpp"
#include <stdexcept>
#include <string>
using namespace ariel;
using namespace std;



TEST_CASE("numbers that has 8 digits but at least one of their digits isnt 1/2/3/4"){
    CHECK_THROWS(snowman(12341235));
    CHECK_THROWS(snowman(56785678));
    CHECK_THROWS(snowman(54324326));
    CHECK_THROWS(snowman(55557777));
    CHECK_THROWS(snowman(88888888));
}
TEST_CASE("number with more then 8 digits"){
    CHECK_THROWS_AS(snowman(123412344),std::out_of_range);
    CHECK_THROWS_AS(snowman(1111111111),std::out_of_range);
    CHECK_THROWS_AS(snowman(1234123412),std::out_of_range);
    CHECK_THROWS_AS(snowman(1234123411),std::out_of_range);
    CHECK_THROWS_AS(snowman(1234123412),std::out_of_range);
}
TEST_CASE("numbers with under 8 digits"){
    CHECK_THROWS_AS(snowman(1234123),std::out_of_range);
    CHECK_THROWS_AS(snowman(123412),std::out_of_range);
    CHECK_THROWS_AS(snowman(12341),std::out_of_range);
    CHECK_THROWS_AS(snowman(1234),std::out_of_range);
    CHECK_THROWS_AS(snowman(123),std::out_of_range);
}
TEST_CASE("negative numbers"){
    CHECK_THROWS(snowman(-12341234));
    CHECK_THROWS(snowman(-12341231));
    CHECK_THROWS(snowman(-12331232));
    CHECK_THROWS(snowman(-11141233));
    CHECK_THROWS(snowman(-12341414));
}
TEST_CASE("good snowmans"){
    CHECK(snowman(11114411) == "       \n _===_ \n (.,.) \n ( : ) \n ( : ) ");
    CHECK(snowman(22114411) == "  ___  \n ..... \n (...) \n ( : ) \n ( : ) ");
    CHECK(snowman(22214411) == "  ___  \n ..... \n (o..) \n ( : ) \n ( : ) ");
    CHECK(snowman(44414411) == "  ___  \n (_*_) \n (- .) \n ( : ) \n ( : ) ");
    CHECK(snowman(44414411) == "  ___  \n (_*_) \n (- .) \n ( : ) \n ( : ) ");
    CHECK(snowman(44441144) == "  ___  \n (_*_) \n (- -) \n<(   )>\n (   ) ");

}
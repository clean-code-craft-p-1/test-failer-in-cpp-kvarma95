#include"tshirts.h"
#include <gtest/gtest.h>

TEST(Tshirts, mediumSize)
{
    EXPECT_EQ(size(40), 'M');
    EXPECT_EQ(size(38), 'M');
    EXPECT_EQ(size(42), 'M');
}

TEST(Tshirts, smallSize)
{
    EXPECT_EQ(size(37), 'S');
}

TEST(Tshirts, LargeSize)
{
    EXPECT_EQ(size(37), 'L');
}


/*void testTshirtSize() {
    std::cout << "\nTshirt size test\n";
    assert(size(37) == 'S');
    assert(size(40) == 'M');
    assert(size(43) == 'L');
    assert(size(38) == 'M');
    assert(size(42) == 'M');
    std::cout << "All is well (maybe!)\n";
}*/

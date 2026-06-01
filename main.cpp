#include <gtest/gtest.h>
#include "candle.h"

// 2.1 body_contains
TEST(CandleTest, BodyContainsGreen)
{
  Candle c(100.0, 110.0, 90.0, 105.0);
  EXPECT_TRUE(c.body_contains(102.0));
  EXPECT_TRUE(c.body_contains(100.0));
  EXPECT_TRUE(c.body_contains(105.0));
  EXPECT_FALSE(c.body_contains(99.0));
}

TEST(CandleTest, BodyContainsRed)
{
  Candle c(105.0, 110.0, 90.0, 100.0);
  EXPECT_TRUE(c.body_contains(102.0));
  EXPECT_TRUE(c.body_contains(105.0));
  EXPECT_FALSE(c.body_contains(106.0));
}

TEST(CandleTest, BodyContainsDoji)
{
  Candle c(100.0, 100.0, 100.0, 100.0);
  EXPECT_TRUE(c.body_contains(100.0));
  EXPECT_FALSE(c.body_contains(100.1));
}

// 2.2 contains
TEST(CandleTest, ContainsGreen)
{
  Candle c(100.0, 110.0, 90.0, 105.0);
  EXPECT_TRUE(c.contains(95.0));
  EXPECT_TRUE(c.contains(105.0));
  EXPECT_FALSE(c.contains(89.9));
}

TEST(CandleTest, ContainsRed)
{
  Candle c(105.0, 110.0, 90.0, 100.0);
  EXPECT_TRUE(c.contains(90.0));
  EXPECT_TRUE(c.contains(110.0));
  EXPECT_FALSE(c.contains(111.0));
}

TEST(CandleTest, ContainsDoji)
{
  Candle c(100.0, 100.0, 100.0, 100.0);
  EXPECT_TRUE(c.contains(100.0));
  EXPECT_FALSE(c.contains(99.9));
}

// 2.3 full_size
TEST(CandleTest, FullSizeGreen)
{
  Candle c(100.0, 110.0, 90.0, 105.0);
  EXPECT_DOUBLE_EQ(c.full_size(), 20.0);
}

TEST(CandleTest, FullSizeRed)
{
  Candle c(105.0, 110.0, 90.0, 100.0);
  EXPECT_DOUBLE_EQ(c.full_size(), 20.0);
}

TEST(CandleTest, FullSizeDoji)
{
  Candle c(100.0, 100.0, 100.0, 100.0);
  EXPECT_DOUBLE_EQ(c.full_size(), 0.0);
}

// 2.4 body_size
TEST(CandleTest, BodySizeGreen)
{
  Candle c(100.0, 110.0, 90.0, 105.0);
  EXPECT_DOUBLE_EQ(c.body_size(), 5.0);
}

TEST(CandleTest, BodySizeRed)
{
  Candle c(105.0, 110.0, 90.0, 100.0);
  EXPECT_DOUBLE_EQ(c.body_size(), 5.0);
}

TEST(CandleTest, BodySizeDoji)
{
  Candle c(100.0, 100.0, 100.0, 100.0);
  EXPECT_DOUBLE_EQ(c.body_size(), 0.0);
}

// 2.5 is_red
TEST(CandleTest, IsRedTrue)
{
  Candle c(105.0, 110.0, 90.0, 100.0);
  EXPECT_TRUE(c.is_red());
  EXPECT_FALSE(c.is_green());
}

TEST(CandleTest, IsRedFalse)
{
  Candle c(100.0, 110.0, 90.0, 105.0);
  EXPECT_FALSE(c.is_red());
}

TEST(CandleTest, IsRedDoji)
{
  Candle c(100.0, 100.0, 100.0, 100.0);
  EXPECT_FALSE(c.is_red());
}

// 2.6 is_green
TEST(CandleTest, IsGreenTrue)
{
  Candle c(100.0, 110.0, 90.0, 105.0);
  EXPECT_TRUE(c.is_green());
  EXPECT_FALSE(c.is_red());
}

TEST(CandleTest, IsGreenFalse)
{
  Candle c(105.0, 110.0, 90.0, 100.0);
  EXPECT_FALSE(c.is_green());
}

TEST(CandleTest, IsGreenDoji)
{
  Candle c(100.0, 100.0, 100.0, 100.0);
  EXPECT_FALSE(c.is_green());
}

// Новые тесты для is_doji()
TEST(CandleTest, IsDojiTrue)
{
  Candle c(100.0, 110.0, 90.0, 100.0); // open == close → это доджи
  EXPECT_TRUE(c.is_doji());
}

TEST(CandleTest, IsDojiFalse)
{
  Candle c(100.0, 110.0, 90.0, 105.0); // open != close → не доджи
  EXPECT_FALSE(c.is_doji());
}

int main(int argc, char **argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
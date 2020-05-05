#include "../src/draw.h"
#include "../src/filework.h"
#include "../src/misstake.h"
#include "gtest/gtest.h"

int misse = 0;
int missm = 0;
int missh = 0;
int endg = 0;

TEST(FileworkTest, MissingFile)
{
  int result = file_check("src/wrong.txt", "src/wrong.txt", "src/wrong.txt");
  int expected = -1;
  EXPECT_EQ(expected, result);
}

TEST(FileworkTest, EmptyFile)
{
  int result = file_check("test/empty.txt", "src/word2.txt", "src/word3.txt");
  int expected = 0;
  EXPECT_EQ(expected, result);
}

TEST(FileworkTest, FileCheckPassed)
{
  int num = file_check("src/word1.txt", "src/word2.txt", "src/word3.txt");
  int result = 0;
  if(num>0){
    result = 1;
  }
  int expected = 1;
  EXPECT_EQ(expected, result);
}

TEST(DifficultyTest, WrongDifficulty)
{
  char *buf;
  int result = 0;
  result = setdificulty(0, &buf);
  int expected = 0;
  EXPECT_EQ(expected, result);
}

TEST(DifficultyTest, EasyDifficulty)
{
  char *buf;
  int result = 0;
  result = setdificulty(1, &buf);
  int expected = 10;
  EXPECT_EQ(expected, result);
}

TEST(DifficultyTest, NormalDifficulty)
{
  char *buf;
  int result = 0;
  result = setdificulty(2, &buf);
  int expected = 5;
  EXPECT_EQ(expected, result);
}

TEST(DifficultyTest, HardDifficulty)
{
  char *buf;
  int result = 0;
  result = setdificulty(3, &buf);
  int expected = 3;
  EXPECT_EQ(expected, result);
}

TEST(MisstakeTest, WrongDifficulty)
{
  char *buf = "test"
  char *enter = "t";
  int result = 0;

  ...

  int expected = 0;
  EXPECT_EQ(expected, result);
}


int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

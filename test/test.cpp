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

int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

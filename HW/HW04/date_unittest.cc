// Copyright 2018, CSCI3081W class and Dongha Kang
#include <math.h>
#include <iostream>
#include <string>
#include <ctime>

#include "gtest/gtest.h"
#include "HW/HW04/date.h"

class DateTest : public ::testing::Test {
 public:
  void SetUp() {
    // code here will execute just before the test ensues
  first_day = Date(2018, 9, 4);
  last_day = Date(2018, 12, 11);
  }
 protected:
  Date first_day;          // first day of classes
  Date last_day;           // last day of classes
};


TEST_F(DateTest, PrintDateTests) {
  Date y2k(1999, 12, 31);              // y2k
  Date ind_day(1776, 7, 4);            // US Independence
  Date best_holiday(2018, 10, 31);     // Halloween

  std::string expected_out_1 = "1999-12-31\n";
  std::string expected_out_2 = "1776-07-04\n";
  std::string expected_out_3 = "2018-10-31\n";

  testing::internal::CaptureStdout();
  y2k.PrintDate(true);
  std::string output1 = testing::internal::GetCapturedStdout();

  // You must do this EVERY TIME, or else it will segfault
  testing::internal::CaptureStdout();
  ind_day.PrintDate(true);
  std::string output2 = testing::internal::GetCapturedStdout();

  testing::internal::CaptureStdout();
  best_holiday.PrintDate(true);
  std::string output3 = testing::internal::GetCapturedStdout();

  EXPECT_EQ(output1, expected_out_1);
  EXPECT_EQ(output2, expected_out_2);
  EXPECT_EQ(output3, expected_out_3);
}


TEST_F(DateTest, PrintDateTestsWithoutNewline) {
  Date y2k(1999, 12, 31);              // y2k
  Date ind_day(1776, 7, 4);            // US Independence
  Date best_holiday(2018, 10, 31);     // Halloween

  std::string expected_out_1 = "1999-12-31";
  std::string expected_out_2 = "1776-07-04";
  std::string expected_out_3 = "2018-10-31";

  testing::internal::CaptureStdout();
  y2k.PrintDate(false);
  std::string output1 = testing::internal::GetCapturedStdout();

  testing::internal::CaptureStdout();
  ind_day.PrintDate(false);
  std::string output2 = testing::internal::GetCapturedStdout();

  testing::internal::CaptureStdout();
  best_holiday.PrintDate(false);
  std::string output3 = testing::internal::GetCapturedStdout();

  EXPECT_EQ(output1, expected_out_1);
  EXPECT_EQ(output2, expected_out_2);
  EXPECT_EQ(output3, expected_out_3);
}

/**
  *
  * Note, this is the only provided test case
  * which actually uses our test fixture
  *
  * However, it is illegal to mix TEST() and TEST_F() in
  * the same test case (file).
  *
  */

TEST_F(DateTest, DaysBetweenTests) {
  EXPECT_EQ(first_day.GetUsDate(), "09-04-2018") << "GetUsDate wrong";
  EXPECT_EQ(last_day.GetUsDate(), "12-11-2018") << "GetUsDate wrong";
  EXPECT_EQ(first_day.DaysBetween(last_day), 98) << "DaysBetween wrong";
}



//  *** start from here it is Implemented ***


// Today's Date?
TEST_F(DateTest, TodayTest) {
  Date today;
  Date ExpectedToday(2018, 10, 12);

  EXPECT_EQ(today.GetDate(), ExpectedToday.GetDate()) << "Today wrong";
}

// Check Get Date function
TEST_F(DateTest, GetDateTests) {
  EXPECT_EQ(first_day.GetDate(), "2018-09-04") << "GetDate printing wrong";
  EXPECT_EQ(first_day.GetUsDate(), "09-04-2018") << "GetUsDate printing wrong";
}

// Check the Epoch
TEST_F(DateTest, CheckEpoch) {
  Date epoch(1500000000);
  Date ExpectedDate(2017, 7, 14);

  EXPECT_EQ(epoch.GetDate(), ExpectedDate.GetDate()) << "Well, epoch no work";
}

// check leap years
TEST_F(DateTest, CheckLeapYear) {
    Date BeforeLeapYear(2016, 2, 28);
    Date LeapYear(2016, 2, 29);
    Date NotLeapYear(2016, 3, 1);
    EXPECT_NE(LeapYear.GetDate(), NotLeapYear.GetDate()) << "NO LEAP YEAR";
    EXPECT_EQ((BeforeLeapYear+1).GetDate(), LeapYear.GetDate()) << "NOLEAPYEAR";
}

// check leap year Between
TEST_F(DateTest, CheckLeapYearBetween) {
  Date LeapYear1(2016, 1, 1);
  Date LeapYear2(2016, 3, 1);
  EXPECT_EQ(LeapYear1.DaysBetween(LeapYear2), 60) << "Leap Year Between Wrong";
}

// check leap year Between
TEST_F(DateTest, CheckLeapYearBetween) {
  Date LeapYear1(2016, 1, 1);
  Date LeapYear2(2016, 3, 1);
  EXPECT_EQ(LeapYear1.DaysBetween(LeapYear2), 60) << "Leap Year Between Wrong";
}

// check operator
TEST_F(DateTest, CheckOperator) {
  Date AddedDate(2018, 10, 4);
  Date SubDate(2018, 8, 4);
  EXPECT_EQ((first_day+30).GetDate(), AddedDate.GetDate()) << "Addition wrong";
  EXPECT_EQ((first_day-31).GetDate(), SubDate.GetDate()) << "Subtraction wrong";
}

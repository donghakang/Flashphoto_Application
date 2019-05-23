#include <math.h>
#include <iostream>
#include <string>
#include <vector>

#include "gtest/gtest.h"
#include "mia/command_line_processor.h"
#include "mia/image_editor_commands.h"
#include "imagetools/image_editor.h"
using image_tools::CommandLineProcessor;

class CommandLineUnitTest : public ::testing::Test {
 public:
  std::string HelpMessage = "usage: mia infile.png "
      "[image processing commands ...] outfile.png\n"
      "infile.png:          input image file in png format\n"
      "outfile.png:         filename to use for saving the result\n\n"
      "image processing comamnds:\n"
      "-blur r:             apply a gaussian blur of radius r\n"
      "-edgedetect:         apply an edge detection filter\n"
      "-sharpen r:          apply a sharpening filter of radius r\n"
      "-red s:              scale the red channel by factor s\n"
      "-green s:            scale the green channel by factor s\n"
      "-blue s:             scale the blue channel by factor s\n"
      "-quantize n:         quantize each color channel into n bins\n"
      "-saturate s:         saturate colors by scale factor s\n"
      "-threshold c:        threshold using cutoff value c\n"
      "-motionblur-n-s r:   north-south motion blur with kernel radius r\n"
      "-motionblur-e-w r:   east-west motion blur with kernel radius r\n"
      "-motionblur-ne-sw r: ne-sw motion blur with kernel radius r\n"
      "-motionblur-nw-se r: nw-se motion blur with kernel radius r";
  void SetUp() override {
    cmd = new CommandLineProcessor();
  }

  void TearDown() override {
    delete cmd;
  }

 protected:
  CommandLineProcessor* cmd;
};

// Edge Command Test
TEST_F(CommandLineUnitTest, EdgeCommandTest) {
  char* argument_[] = {strdup("./build/bin/mia"),
                       strdup("resources/alien.png"),
                       strdup("-edgedetect"),
                       strdup("resources/output.png")};

  testing::internal::CaptureStdout();
  cmd->ProcessCommandLine(4, argument_);
  std::string output1 = testing::internal::GetCapturedStdout();

  EXPECT_EQ(output1, "") << "Edge Command Not working";
}

TEST_F(CommandLineUnitTest, BlurCommandTest) {
  char* argument_[] = {strdup("./build/bin/mia"),
                       strdup("resources/alien.png"),
		       strdup("-blur"),
		       strdup("5.0"),
                       strdup("resources/output.png")};

  testing::internal::CaptureStdout();
  cmd->ProcessCommandLine(5, argument_);
  std::string output1 = testing::internal::GetCapturedStdout();
  EXPECT_EQ(output1, "") << "Blur Command Not working";
}

// Sharpen Command Test
TEST_F(CommandLineUnitTest, SharpenCommandTest) {
  char* argument_[] = {strdup("./build/bin/mia"),
                       strdup("resources/alien.png"),
                       strdup("-sharpen"),
                       strdup("5.0"),
                       strdup("resources/output.png")};

  testing::internal::CaptureStdout();
  cmd->ProcessCommandLine(5, argument_);
  std::string output1 = testing::internal::GetCapturedStdout();

  EXPECT_EQ(output1, "") << "Sharpen Command Not working";
}

// Red Command Test
TEST_F(CommandLineUnitTest, RedCommandTest) {
  char* argument_[] = {strdup("./build/bin/mia"),
                       strdup("resources/alien.png"),
                       strdup("-red"),
                       strdup("5.0"),
                       strdup("resources/output.png")};

  testing::internal::CaptureStdout();
  cmd->ProcessCommandLine(5, argument_);
  std::string output1 = testing::internal::GetCapturedStdout();

  EXPECT_EQ(output1, "") << "Red Command Not working";
}

// Green Command Test
TEST_F(CommandLineUnitTest, GreenCommandTest) {
  char* argument_[] = {strdup("./build/bin/mia"),
                       strdup("resources/alien.png"),
                       strdup("-green"),
                       strdup("5.0"),
                       strdup("resources/output.png")};

  testing::internal::CaptureStdout();
  cmd->ProcessCommandLine(5, argument_);
  std::string output1 = testing::internal::GetCapturedStdout();

  EXPECT_EQ(output1, "") << "Green Command Not working";
}

// Blue Command Test
TEST_F(CommandLineUnitTest, BlueCommandTest) {
  char* argument_[] = {strdup("./build/bin/mia"),
                       strdup("resources/alien.png"),
                       strdup("-blue"),
                       strdup("5.0"),
                       strdup("resources/output.png")};

  testing::internal::CaptureStdout();
  cmd->ProcessCommandLine(5, argument_);
  std::string output1 = testing::internal::GetCapturedStdout();

  EXPECT_EQ(output1, "") << "Blue Command Not working";
}

// Quantize Command Test
TEST_F(CommandLineUnitTest, QuantizeCommandTest) {
  char* argument_[] = {strdup("./build/bin/mia"),
                       strdup("resources/alien.png"),
                       strdup("-quantize"),
                       strdup("70"),
                       strdup("resources/output.png")};

  testing::internal::CaptureStdout();
  cmd->ProcessCommandLine(5, argument_);
  std::string output1 = testing::internal::GetCapturedStdout();

  EXPECT_EQ(output1, "") << "Quantize Command Not working";
}

// Threshold Command Test
TEST_F(CommandLineUnitTest, ThresholdCommandTest) {
  char* argument_[] = {strdup("./build/bin/mia"),
                       strdup("resources/alien.png"),
                       strdup("-threshold"),
                       strdup("0.5"),
                       strdup("resources/output.png")};

  testing::internal::CaptureStdout();
  cmd->ProcessCommandLine(5, argument_);
  std::string output1 = testing::internal::GetCapturedStdout();

  EXPECT_EQ(output1, "") << "Threshold Command Not working";
}

// Saturate Command Test
TEST_F(CommandLineUnitTest, SaturateCommandTest) {
  char* argument_[] = {strdup("./build/bin/mia"),
                       strdup("resources/alien.png"),
                       strdup("-red"),
                       strdup("5.0"),
                       strdup("resources/output.png")};

  testing::internal::CaptureStdout();
  cmd->ProcessCommandLine(5, argument_);
  std::string output1 = testing::internal::GetCapturedStdout();

  EXPECT_EQ(output1, "") << "Saturate Command Not working";
}

// MotionBlur Comand Test
TEST_F(CommandLineUnitTest, MotionBlurCommandTest) {
  char* argument1_[] = {strdup("./build/bin/mia"),
                       strdup("resources/alien.png"),
                       strdup("-motionblur-n-s"),
                       strdup("5.0"),
                       strdup("resources/output.png")};
  char* argument2_[] = {strdup("./build/bin/mia"),
                       strdup("resources/alien.png"),
                       strdup("-motionblur-e-w"),
                       strdup("5.0"),
                       strdup("resources/output.png")};
  char* argument3_[] = {strdup("./build/bin/mia"),
                       strdup("resources/alien.png"),
                       strdup("-motionblur-ne-sw"),
                       strdup("5.0"),
                       strdup("resources/output.png")};
  char* argument4_[] = {strdup("./build/bin/mia"),
                       strdup("resources/alien.png"),
                       strdup("-motionblur-nw-se"),
                       strdup("5.0"),
                       strdup("resources/output.png")};


  testing::internal::CaptureStdout();
  cmd->ProcessCommandLine(5, argument1_);
  std::string output1 = testing::internal::GetCapturedStdout();
  EXPECT_EQ(output1, "") << "N S Command Not working";

  testing::internal::CaptureStdout();
  cmd->ProcessCommandLine(5, argument2_);
  std::string output2 = testing::internal::GetCapturedStdout();
  EXPECT_EQ(output2, "") << "E W Command Not working";

  testing::internal::CaptureStdout();
  cmd->ProcessCommandLine(5, argument3_);
  std::string output3 = testing::internal::GetCapturedStdout();
  EXPECT_EQ(output3, "") << "NW SE Command Not working";

  testing::internal::CaptureStdout();
  cmd->ProcessCommandLine(5, argument4_);
  std::string output4 = testing::internal::GetCapturedStdout();
  EXPECT_EQ(output4, "") << "NE SW Command Not working";
}

// TEST_F (CommandLineUnitTest, HelpCommandTest) {
//   char* argument_[] = {strdup("./build/bin/mia"),
//                        strdup("-h")};
//
//   testing::internal::CaptureStdout();
//   cmd->ProcessCommandLine(2, argument_);
//   std::string output = testing::internal::GetCapturedStdout();
//   EXPECT_EQ(output, HelpMessage);
// }

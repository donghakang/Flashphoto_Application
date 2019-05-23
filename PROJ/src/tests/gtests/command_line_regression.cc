#include <math.h>
#include <iostream>
#include <string>
#include <vector>

#include "gtest/gtest.h"
#include "imagetools/color_data.h"
#include "imagetools/image_editor.h"
#include "imagetools/convolution_filter_motion_blur.h"
#include "mia/command_line_processor.h"
#include "mia/image_editor_commands.h"
#include "mia/mia_app.h"

using image_tools::ColorData;
using image_tools::PixelBuffer;
using image_tools::ImageEditor;
using image_tools::ImageEditorCommand;
using image_tools::BlurFilterCommand;
using image_tools::ConvolutionFilterMotionBlur;
using image_tools::StartStrokeCommand;
using image_tools::AddToStrokeCommand;
using image_tools::EndStrokeCommand;
using image_tools::LoadCommand;
using image_tools::SaveCommand;

class CommandLineRegressionTest : public ::testing::Test {
 public:
  void SetUp() override {
    image_editor_ = new ImageEditor();
  }
  void TearDown() override {
    delete image_editor_;
  }
  std::string input_file_ = "resources/alien.png";
 protected:
  ImageEditor* image_editor_;
  ImageEditorCommand* image_editor_command_;
};

// Check if the Blur Filter Works
TEST_F (CommandLineRegressionTest, BlurTest) {
  PixelBuffer* blur_buffer_ = new PixelBuffer("resources/blur-5.0-out.png");
  image_editor_->LoadFromFile("resources/alien.png");
  image_editor_->ApplyBlurFilter(5.0);

  EXPECT_EQ(image_editor_->pixel_buffer()->height(), blur_buffer_->height())
                                                  << "HEIGHT VALUE DIFFERENT";
  EXPECT_EQ(image_editor_->pixel_buffer()->width(), blur_buffer_->width())
                                                  << "WIDTH VALUE DIFFERENT";

  EXPECT_TRUE(*blur_buffer_ == *image_editor_->pixel_buffer()) << "BLUR:: Pixel Different";

  delete blur_buffer_;
}

// Check if the Edge Filter Works
TEST_F (CommandLineRegressionTest, EdgeDetectTest) {
  PixelBuffer* edge_buffer_ = new PixelBuffer("resources/edge-out.png");
  image_editor_->LoadFromFile("resources/alien.png");
  image_editor_->ApplyEdgeDetectFilter();

  EXPECT_EQ(image_editor_->pixel_buffer()->height(), edge_buffer_->height())
                                                  << "HEIGHT VALUE DIFFERENT";
  EXPECT_EQ(image_editor_->pixel_buffer()->width(), edge_buffer_->width())
                                                  << "WIDTH VALUE DIFFERENT";

  for (int x = 0; x < edge_buffer_->width(); x++) {
   for (int y = 0; y < edge_buffer_->height(); y++) {
      EXPECT_EQ(image_editor_->pixel_buffer()->pixel(x,y),
                                 edge_buffer_->pixel(x,y))
                                 << "EDGE:: PIXEL VALUE DIFFERENT";
   }
  }
  delete edge_buffer_;
}

// Check if the Sharpen Test works
TEST_F (CommandLineRegressionTest, SharpenDetectTest) {
  PixelBuffer* sharpen_buffer_ = new PixelBuffer(
                                     "resources/sharpen-5.0-out.png");
  image_editor_->LoadFromFile("resources/alien.png");
  image_editor_->ApplySharpenFilter(5.0);

  EXPECT_EQ(image_editor_->pixel_buffer()->height(), sharpen_buffer_->height())
                                                  << "HEIGHT VALUE DIFFERENT";
  EXPECT_EQ(image_editor_->pixel_buffer()->width(), sharpen_buffer_->width())
                                                  << "WIDTH VALUE DIFFERENT";

  for (int x = 0; x < sharpen_buffer_->width(); x++) {
   for (int y = 0; y < sharpen_buffer_->height(); y++) {
      EXPECT_EQ(image_editor_->pixel_buffer()->pixel(x,y),
                                 sharpen_buffer_->pixel(x,y))
                                 << "SHARPEN:: PIXEL VALUE DIFFERENT";
   }
  }
  delete sharpen_buffer_;
}

// Check if Red Filter works
TEST_F (CommandLineRegressionTest, RedDetectTest) {
  PixelBuffer* red_buffer_ = new PixelBuffer("resources/red-5.0-out.png");
  image_editor_->LoadFromFile("resources/alien.png");
  image_editor_->ApplyChannelsFilter(5.0, 1.0, 1.0);

  EXPECT_EQ(image_editor_->pixel_buffer()->height(), red_buffer_->height())
                                                  << "HEIGHT VALUE DIFFERENT";
  EXPECT_EQ(image_editor_->pixel_buffer()->width(), red_buffer_->width())
                                                  << "WIDTH VALUE DIFFERENT";

  EXPECT_EQ(*red_buffer_, *image_editor_->pixel_buffer())
                                 << "RED:: PIXEL VALUE DIFFERENT";
  delete red_buffer_;
}

// Check if Green Filter works
TEST_F (CommandLineRegressionTest, GreenDetectTest) {
  PixelBuffer* green_buffer_ = new PixelBuffer("resources/green-5.0-out.png");
  image_editor_->LoadFromFile("resources/alien.png");
  image_editor_->ApplyChannelsFilter(1.0, 5.0, 1.0);

  EXPECT_EQ(image_editor_->pixel_buffer()->height(), green_buffer_->height())
                                                  << "HEIGHT VALUE DIFFERENT";
  EXPECT_EQ(image_editor_->pixel_buffer()->width(), green_buffer_->width())
                                                  << "WIDTH VALUE DIFFERENT";

  EXPECT_EQ(*green_buffer_, *image_editor_->pixel_buffer());
  delete green_buffer_;
}

// Check if Blue Filter works
TEST_F (CommandLineRegressionTest, BlueDetectTest) {
  PixelBuffer* blue_buffer_ = new PixelBuffer("resources/blue-5.0-out.png");
  image_editor_->LoadFromFile("resources/alien.png");
  image_editor_->ApplyChannelsFilter(1.0, 1.0, 5.0);

  EXPECT_EQ(image_editor_->pixel_buffer()->height(), blue_buffer_->height())
                                                  << "HEIGHT VALUE DIFFERENT";
  EXPECT_EQ(image_editor_->pixel_buffer()->width(), blue_buffer_->width())
                                                  << "WIDTH VALUE DIFFERENT";

  EXPECT_EQ(*blue_buffer_, *image_editor_->pixel_buffer())
                                           << "BLUE:: PIXEL VALUE DIFFERENT";
  delete blue_buffer_;
}

// Check if Quantize works
TEST_F (CommandLineRegressionTest, QuantizeDetectTest) {
  PixelBuffer* quantize_buffer_ = new PixelBuffer(
                                      "resources/quantize-5.0-out.png");
  image_editor_->LoadFromFile("resources/alien.png");
  image_editor_->ApplyQuantizeFilter(5);

  EXPECT_EQ(image_editor_->pixel_buffer()->height(), quantize_buffer_->height())
                                                  << "HEIGHT VALUE DIFFERENT";
  EXPECT_EQ(image_editor_->pixel_buffer()->width(), quantize_buffer_->width())
                                                  << "WIDTH VALUE DIFFERENT";

  for (int x = 0; x < quantize_buffer_->width(); x++) {
   for (int y = 0; y < quantize_buffer_->height(); y++) {
      EXPECT_EQ(image_editor_->pixel_buffer()->pixel(x,y),
                                 quantize_buffer_->pixel(x,y))
                                 << "QUANTIZE:: PIXEL VALUE DIFFERENT";
   }
  }
  delete quantize_buffer_;
}

// Check if Saturate filter works
TEST_F (CommandLineRegressionTest, SaturateDetectTest) {
  PixelBuffer* saturate_buffer_ = new PixelBuffer(
                                      "resources/saturate-5.0-out.png");
  image_editor_->LoadFromFile("resources/alien.png");
  image_editor_->ApplySaturateFilter(5.0);

  EXPECT_EQ(image_editor_->pixel_buffer()->height(), saturate_buffer_->height())
                                                  << "HEIGHT VALUE DIFFERENT";
  EXPECT_EQ(image_editor_->pixel_buffer()->width(), saturate_buffer_->width())
                                                  << "WIDTH VALUE DIFFERENT";

  for (int x = 0; x < saturate_buffer_->width(); x++) {
   for (int y = 0; y < saturate_buffer_->height(); y++) {
      EXPECT_EQ(image_editor_->pixel_buffer()->pixel(x,y),
                                 saturate_buffer_->pixel(x,y))
                                 << "SATURATE:: PIXEL VALUE DIFFERENT";
   }
  }
  delete saturate_buffer_;
}

// Check if Threshold works
TEST_F (CommandLineRegressionTest, ThresholdDetectTest) {
  PixelBuffer* threshold_buffer_ = new PixelBuffer(
                                       "resources/threshold-1.0-out.png");
  image_editor_->LoadFromFile("resources/alien.png");
  image_editor_->ApplyThresholdFilter(1.0);

  EXPECT_EQ(image_editor_->pixel_buffer()->height(),
                  threshold_buffer_->height()) << "HEIGHT VALUE DIFFERENT";
  EXPECT_EQ(image_editor_->pixel_buffer()->width(), threshold_buffer_->width())
                                                  << "WIDTH VALUE DIFFERENT";

  for (int x = 0; x < threshold_buffer_->width(); x++) {
   for (int y = 0; y < threshold_buffer_->height(); y++) {
      EXPECT_EQ(image_editor_->pixel_buffer()->pixel(x,y),
                                 threshold_buffer_->pixel(x,y))
                                 << "THRESHOLD:: PIXEL VALUE DIFFERENT";
   }
  }
  delete threshold_buffer_;
}

// Check Motion Blur N-S works
TEST_F (CommandLineRegressionTest, MBlurNSTest) {
  PixelBuffer* n_s_buffer_ = new PixelBuffer(
                            "resources/motionblur-n-s-5.0-out.png");
  image_editor_->LoadFromFile("resources/alien.png");
  image_editor_->ApplyMotionBlurFilter(5.0,
            ConvolutionFilterMotionBlur::MBLUR_DIR_N_S);

  EXPECT_EQ(image_editor_->pixel_buffer()->height(), n_s_buffer_->height())
                                                  << "HEIGHT VALUE DIFFERENT";
  EXPECT_EQ(image_editor_->pixel_buffer()->width(), n_s_buffer_->width())
                                                  << "WIDTH VALUE DIFFERENT";

  for (int x = 0; x < n_s_buffer_->width(); x++) {
   for (int y = 0; y < n_s_buffer_->height(); y++) {
      EXPECT_EQ(image_editor_->pixel_buffer()->pixel(x,y),
                                 n_s_buffer_->pixel(x,y))
                                 << "MBLUR N-S:: PIXEL VALUE DIFFERENT";
   }
  }
  delete n_s_buffer_;
}

// Check Motion Blur E-W works
TEST_F (CommandLineRegressionTest, MBlurEWTest) {
  PixelBuffer* e_w_buffer_ = new PixelBuffer(
                            "resources/motionblur-e-w-5.0-out.png");
  image_editor_->LoadFromFile("resources/alien.png");
  image_editor_->ApplyMotionBlurFilter(5.0,
            ConvolutionFilterMotionBlur::MBLUR_DIR_E_W);

  EXPECT_EQ(image_editor_->pixel_buffer()->height(), e_w_buffer_->height())
                                                  << "HEIGHT VALUE DIFFERENT";
  EXPECT_EQ(image_editor_->pixel_buffer()->width(), e_w_buffer_->width())
                                                  << "WIDTH VALUE DIFFERENT";

  for (int x = 0; x < e_w_buffer_->width(); x++) {
   for (int y = 0; y < e_w_buffer_->height(); y++) {
      EXPECT_EQ(image_editor_->pixel_buffer()->pixel(x,y),
                                 e_w_buffer_->pixel(x,y))
                                 << "MBLUR E-W:: PIXEL VALUE DIFFERENT";
   }
  }
  delete e_w_buffer_;
}

// Check Motion Blur NE - SW works
TEST_F (CommandLineRegressionTest, MBlurNESWTest) {
  PixelBuffer* ne_sw_buffer_ = new PixelBuffer(
                            "resources/motionblur-ne-sw-5.0-out.png");
  image_editor_->LoadFromFile("resources/alien.png");
  image_editor_->ApplyMotionBlurFilter(5.0,
            ConvolutionFilterMotionBlur::MBLUR_DIR_NE_SW);

  EXPECT_EQ(image_editor_->pixel_buffer()->height(), ne_sw_buffer_->height())
                                                  << "HEIGHT VALUE DIFFERENT";
  EXPECT_EQ(image_editor_->pixel_buffer()->width(), ne_sw_buffer_->width())
                                                  << "WIDTH VALUE DIFFERENT";

  for (int x = 0; x < ne_sw_buffer_->width(); x++) {
   for (int y = 0; y < ne_sw_buffer_->height(); y++) {
      EXPECT_EQ(image_editor_->pixel_buffer()->pixel(x,y),
                                 ne_sw_buffer_->pixel(x,y))
                                 << "MBLUR NE-SW:: PIXEL VALUE DIFFERENT";
   }
  }
  delete ne_sw_buffer_;
}

// Check Motion Blur Nw - SE works
TEST_F (CommandLineRegressionTest, MBlurNWSETest) {
  PixelBuffer* nw_se_buffer_ = new PixelBuffer(
                            "resources/motionblur-nw-se-5.0-out.png");
  image_editor_->LoadFromFile("resources/alien.png");
  image_editor_->ApplyMotionBlurFilter(5.0,
            ConvolutionFilterMotionBlur::MBLUR_DIR_NW_SE);

  EXPECT_EQ(image_editor_->pixel_buffer()->height(), nw_se_buffer_->height())
                                                  << "HEIGHT VALUE DIFFERENT";
  EXPECT_EQ(image_editor_->pixel_buffer()->width(), nw_se_buffer_->width())
                                                  << "WIDTH VALUE DIFFERENT";

  for (int x = 0; x < nw_se_buffer_->width(); x++) {
   for (int y = 0; y < nw_se_buffer_->height(); y++) {
      EXPECT_EQ(image_editor_->pixel_buffer()->pixel(x,y),
                                 nw_se_buffer_->pixel(x,y))
                                 << "MBLUR NW-SE:: PIXEL VALUE DIFFERENT";
   }
  }
  delete nw_se_buffer_;
}

// TOOL REGRESSION TEST
// STAMP
TEST_F (CommandLineRegressionTest, StampTest) {
  ImageEditorCommand* image_;
  image_ = new LoadCommand(image_editor_, "resources/alien.png");
  image_->Execute();
  ImageEditor* test_editor_ = new ImageEditor();
  test_editor_->LoadFromFile("resources/alien.png");
  image_ = new StartStrokeCommand(image_editor_, "Stamp", ColorData(0.5, 0.5, 0.5), 5.0, 1, 1);
  image_->Execute();
  image_ = new AddToStrokeCommand(image_editor_, 250, 250);
  image_->Execute();
  image_ = new EndStrokeCommand(image_editor_, 300, 300);
  image_->Execute();
  image_ = new SaveCommand(image_editor_, "resources/stamp-out.png");
  image_->Execute();

  PixelBuffer* stamp_out_ = new PixelBuffer("resources/stamp-out.png");

  test_editor_->StartStroke("Stamp", ColorData(0.5, 0.5, 0.5), 5.0, 1, 1);
  test_editor_->AddToStroke(250, 250);
  test_editor_->EndStroke(300, 300);

  EXPECT_EQ(*test_editor_->pixel_buffer(), *stamp_out_);

  delete stamp_out_;
  delete test_editor_;
  delete image_;
}

// BLUR
TEST_F (CommandLineRegressionTest, BlurToolTest) {
  ImageEditorCommand* image_;
  image_ = new LoadCommand(image_editor_, "resources/alien.png");
  image_->Execute();
  ImageEditor* test_editor_ = new ImageEditor();
  test_editor_->LoadFromFile("resources/alien.png");
  image_ = new StartStrokeCommand(image_editor_, "Blur", ColorData(0.5, 0.5, 0.5), 5.0, 100, 100);
  image_->Execute();
  image_ = new AddToStrokeCommand(image_editor_, 250, 250);
  image_->Execute();
  image_ = new EndStrokeCommand(image_editor_, 300, 300);
  image_->Execute();
  image_ = new SaveCommand(image_editor_, "resources/blur-out.png");
  image_->Execute();
  
  PixelBuffer* blur_out_ = new PixelBuffer("resources/blur-out.png");
  
  test_editor_->StartStroke("Blur", ColorData(0.5, 0.5, 0.5), 5.0, 100, 100);
  test_editor_->AddToStroke(250, 250);
  test_editor_->EndStroke(300, 300);

  EXPECT_EQ(*test_editor_->pixel_buffer(), *blur_out_);

  delete blur_out_;
  delete test_editor_;
  delete image_;
}

// PEN
TEST_F (CommandLineRegressionTest, PenToolTest) {
  ImageEditorCommand* image_;
  image_ = new LoadCommand(image_editor_, "resources/alien.png");
  image_->Execute();
  ImageEditor* test_editor_ = new ImageEditor();
  test_editor_->LoadFromFile("resources/alien.png");
  image_ = new StartStrokeCommand(image_editor_, "Pen", ColorData(0.5, 0.5, 0.5), 5.0, 1, 1);
  image_->Execute();
  image_ = new AddToStrokeCommand(image_editor_, 250, 250);
  image_->Execute();
  image_ = new EndStrokeCommand(image_editor_, 300, 300);
  image_->Execute();
  image_ = new SaveCommand(image_editor_, "resources/pen-out.png");
  image_->Execute();

  PixelBuffer* pen_out_ = new PixelBuffer("resources/pen-out.png");

  test_editor_->StartStroke("Pen", ColorData(0.5, 0.5, 0.5), 5.0, 1, 1);
  test_editor_->AddToStroke(250, 250);
  test_editor_->EndStroke(300, 300);

  EXPECT_EQ(*test_editor_->pixel_buffer(), *pen_out_);

  delete pen_out_;
  delete test_editor_;
  delete image_;
}

// CALLIGRAPHY PEN
TEST_F (CommandLineRegressionTest, CalligraphyPenToolTest) {
  ImageEditorCommand* image_;
  image_ = new LoadCommand(image_editor_, "resources/alien.png");
  image_->Execute();
  ImageEditor* test_editor_ = new ImageEditor();
  test_editor_->LoadFromFile("resources/alien.png");
  image_ = new StartStrokeCommand(image_editor_, "Caligraphy Pen", ColorData(0.5, 0.5, 0.5), 5.0, 1, 1);
  image_->Execute();
  image_ = new AddToStrokeCommand(image_editor_, 250, 250);
  image_->Execute();
  image_ = new EndStrokeCommand(image_editor_, 300, 300);
  image_->Execute();
  image_ = new SaveCommand(image_editor_, "resources/caligraphy-pen-out.png");
  image_->Execute();


  PixelBuffer* caligraphy_pen_out_ = new PixelBuffer("resources/caligraphy-pen-out.png");

  test_editor_->StartStroke("Caligraphy Pen", ColorData(0.5, 0.5, 0.5), 5.0, 1, 1);
  test_editor_->AddToStroke(250, 250);
  test_editor_->EndStroke(300, 300);

  EXPECT_EQ(*test_editor_->pixel_buffer(), *caligraphy_pen_out_);

  delete caligraphy_pen_out_;
  delete test_editor_;
  delete image_;
}

// CHALK
TEST_F (CommandLineRegressionTest, ChalkToolTest) {
  ImageEditorCommand* image_;
  image_ = new LoadCommand(image_editor_, "resources/alien.png");
  image_->Execute();
  ImageEditor* test_editor_ = new ImageEditor();
  test_editor_->LoadFromFile("resources/alien.png");
  image_ = new StartStrokeCommand(image_editor_, "Chalk", ColorData(0.5, 0.5, 0.5), 5.0, 1, 1);
  image_->Execute();
  image_ = new AddToStrokeCommand(image_editor_, 250, 250);
  image_->Execute();
  image_ = new EndStrokeCommand(image_editor_, 300, 300);
  image_->Execute();
  image_ = new SaveCommand(image_editor_, "resources/chalk-out.png");
  image_->Execute();

  PixelBuffer* chalk_out_ = new PixelBuffer("resources/chalk-out.png");

  test_editor_->StartStroke("Chalk", ColorData(0.5, 0.5, 0.5), 5.0, 1, 1);
  test_editor_->AddToStroke(250, 250);
  test_editor_->EndStroke(300, 300);

  // this is because chalk is happening randomly.
  EXPECT_NE(*test_editor_->pixel_buffer(), *chalk_out_);

  delete chalk_out_;
  delete test_editor_;
  delete image_;
}

// SPRAY CAN
TEST_F (CommandLineRegressionTest, SprayCanToolTest) {
  ImageEditorCommand* image_;
  image_ = new LoadCommand(image_editor_, "resources/alien.png");
  image_->Execute();
  ImageEditor* test_editor_ = new ImageEditor();
  test_editor_->LoadFromFile("resources/alien.png");
  image_ = new StartStrokeCommand(image_editor_, "Spray Can", ColorData(0.5, 0.5, 0.5), 5.0, 1, 1);
  image_->Execute();
  image_ = new AddToStrokeCommand(image_editor_, 250, 250);
  image_->Execute();
  image_ = new EndStrokeCommand(image_editor_, 300, 300);
  image_->Execute();
  image_ = new SaveCommand(image_editor_, "resources/spray-can-out.png");
  image_->Execute();

  PixelBuffer* spray_can_out_ = new PixelBuffer("resources/spray-can-out.png");

  test_editor_->StartStroke("Spray Can", ColorData(0.5, 0.5, 0.5), 5.0, 1, 1);
  test_editor_->AddToStroke(250, 250);
  test_editor_->EndStroke(300, 300);

  EXPECT_EQ(*test_editor_->pixel_buffer(), *spray_can_out_);

  delete spray_can_out_;
  delete test_editor_;
  delete image_;
}

// HIGHLIGHTER
TEST_F (CommandLineRegressionTest, HighlighterToolTest) {
  ImageEditorCommand* image_;
  image_ = new LoadCommand(image_editor_, "resources/alien.png");
  image_->Execute();
  ImageEditor* test_editor_ = new ImageEditor();
  test_editor_->LoadFromFile("resources/alien.png");
  image_ = new StartStrokeCommand(image_editor_, "Highlighter", ColorData(0.5, 0.5, 0.5), 5.0, 1, 1);
  image_->Execute();
  image_ = new AddToStrokeCommand(image_editor_, 250, 250);
  image_->Execute();
  image_ = new EndStrokeCommand(image_editor_, 300, 300);
  image_->Execute();
  image_ = new SaveCommand(image_editor_, "resources/highlighter-out.png");
  image_->Execute();

  PixelBuffer* highlighter_out_ = new PixelBuffer("resources/highlighter-out.png");

  test_editor_->StartStroke("Highlighter", ColorData(0.5, 0.5, 0.5), 5.0, 1, 1);
  test_editor_->AddToStroke(250, 250);
  test_editor_->EndStroke(300, 300);

  EXPECT_EQ(*test_editor_->pixel_buffer(), *highlighter_out_);

  delete highlighter_out_;
  delete test_editor_;
  delete image_;
}

// ERASER
TEST_F (CommandLineRegressionTest, EraserToolTest) {
  ImageEditorCommand* image_;
  image_ = new LoadCommand(image_editor_, "resources/alien.png");
  image_->Execute();
  ImageEditor* test_editor_ = new ImageEditor();
  test_editor_->LoadFromFile("resources/alien.png");
  image_ = new StartStrokeCommand(image_editor_, "Eraser", ColorData(0.5, 0.5, 0.5), 5.0, 1, 1);
  image_->Execute();
  image_ = new AddToStrokeCommand(image_editor_, 250, 250);
  image_->Execute();
  image_ = new EndStrokeCommand(image_editor_, 300, 300);
  image_->Execute();
  image_ = new SaveCommand(image_editor_, "resources/eraser-out.png");
  image_->Execute();

  PixelBuffer* eraser_out_ = new PixelBuffer("resources/eraser-out.png");

  test_editor_->StartStroke("Eraser", ColorData(0.5, 0.5, 0.5), 5.0, 1, 1);
  test_editor_->AddToStroke(250, 250);
  test_editor_->EndStroke(300, 300);

  EXPECT_EQ(*test_editor_->pixel_buffer(), *eraser_out_);

  delete eraser_out_;
  delete test_editor_;
  delete image_;
}

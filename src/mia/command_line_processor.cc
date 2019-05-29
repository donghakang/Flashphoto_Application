// Copyright 2018 Dongha Kang

#include "mia/command_line_processor.h"
#include <iostream>
#include <string>
#include <vector>

#include "mia/image_editor_commands.h"

using std::string;
using std::vector;
using std::stof;
using std::cout;
using std::endl;

namespace image_tools {
  void CommandLineProcessor::ProcessCommandLine(int argc, char* argv[]) {
    string input_file_ = argv[1];
    string argument_;
    if (input_file_.compare("-h") == 0) {
      DisplayHelpMessage();
      exit(0);
    } else {
      if (argc < 3) {
        DisplayHelpMessage();
        exit(1);
      } else if (!is_picture_file(input_file_)) {
        DisplayHelpMessage();
        exit(1);
      } else if (input_file_.size() < 4) {
        DisplayHelpMessage();
        exit(1);
      } else {
        float value_ = 0.0;
        image_editor_command_ = new LoadCommand(image_editor_, input_file_);
        image_editor_command_->Execute();

        for (int index = 2; index < argc; index ++) {
          argument_ = string(argv[index]);
          if (is_picture_file(argument_)) {
            image_editor_command_ = new SaveCommand(image_editor_, argument_);
            image_editor_command_->Execute();
          } else if (argument_.compare("-edgedetect") == 0) {
            // Edge Filter
            image_editor_command_ = new EdgeFilterCommand(image_editor_);
            image_editor_command_->Execute();
          } else if (argument_.compare("-blur") == 0) {
            // Blur Filter
            index = index + 1;
            argument_ = string(argv[index]);
            if (!CheckStringFloat(argument_)) {
              DisplayHelpMessage();
              exit(1);
            } else {
              value_ = stof(argument_);
              if (value_ >= 1.0 && value_ <= 10.0) {
                image_editor_command_ = new BlurFilterCommand(image_editor_,
                                                              value_);
                image_editor_command_->Execute();
              } else {
                DisplayHelpMessage();
                exit(1);
              }
            }
         } else if (argument_.compare("-sharpen") == 0) {
           // Sharpen Filter
             index = index + 1;
             argument_ = string(argv[index]);
             if (!CheckStringFloat(argument_)) {
               DisplayHelpMessage();
               exit(1);
             } else {
               value_ = stof(argument_);
               if (value_ >= 1.0 && value_ <= 10.0) {
                 image_editor_command_ = new SharpenFilterCommand(image_editor_,
                                                                  value_);
                 image_editor_command_->Execute();
               } else {
                 DisplayHelpMessage();
                 exit(1);
               }
             }
         } else if (argument_.compare("-red") == 0) {
           // Red Filter
             index = index + 1;
             argument_ = string(argv[index]);
             if (!CheckStringFloat(argument_)) {
               DisplayHelpMessage();
               exit(1);
             } else {
               value_ = stof(argument_);
               if (value_ > 0.0 && value_ <= 10.0) {
                 image_editor_command_ = new ChannelsFilterCommand(
                                             image_editor_, value_, 1.0, 1.0);
                 image_editor_command_->Execute();
               } else {
                 DisplayHelpMessage();
                 exit(1);
               }
             }
           } else if (argument_.compare("-green") == 0) {
             // Green Filter
              index = index + 1;
              argument_ = string(argv[index]);
              if (!CheckStringFloat(argument_)) {
                DisplayHelpMessage();
                exit(1);
              } else {
                value_ = stof(argument_);
                if (value_ > 0.0 && value_ <= 10.0) {
                  image_editor_command_ = new ChannelsFilterCommand(
                                              image_editor_, 1.0, value_, 1.0);
                  image_editor_command_->Execute();
                } else {
                  DisplayHelpMessage();
                  exit(1);
                }
              }
           } else if (argument_.compare("-blue") == 0) {
             // Blue Filter
              index = index + 1;
              argument_ = string(argv[index]);
              if (!CheckStringFloat(argument_)) {
                DisplayHelpMessage();
                exit(1);
              } else {
                value_ = stof(argument_);
                if (value_ > 0.0 && value_ <= 10.0) {
                  image_editor_command_ = new ChannelsFilterCommand(
                                              image_editor_, 1.0, 1.0, value_);
                  image_editor_command_->Execute();
                } else {
                  DisplayHelpMessage();
                  exit(1);
                }
              }
           } else if (argument_.compare("-quantize") == 0) {
             // Quantize Filter
             index = index + 1;
             argument_ = string(argv[index]);
             if (!CheckStringFloat(argument_)) {
               DisplayHelpMessage();
               exit(1);
             } else {
               value_ = stof(argument_);
               if (static_cast<int>(value_) >= 1 &&
                   static_cast<int>(value_) <= 256) {
                 image_editor_command_ = new QuantizeFilterCommand(
                                      image_editor_, static_cast<int>(value_));
                 image_editor_command_->Execute();
               }
             }
           } else if (argument_.compare("-saturate") == 0) {
             // Saturate Filter
             index = index + 1;
             argument_ = string(argv[index]);
             if (!CheckStringFloat(argument_)) {
               DisplayHelpMessage();
               exit(1);
             } else {
               value_ = stof(argument_);
               if (value_ > 0.0 && value_ <= 10.0) {
                 image_editor_command_ = new SaturateFilterCommand(
                                             image_editor_, value_);
                 image_editor_command_->Execute();
               } else {
                 DisplayHelpMessage();
                 exit(1);
               }
             }
           } else if (argument_.compare("-threshold") == 0) {
             // Threshold Filter
             index = index + 1;
             argument_ = string(argv[index]);
             if (!CheckStringFloat(argument_)) {
               DisplayHelpMessage();
               exit(1);
             } else {
               value_ = stof(argument_);
               if (value_ > 0.0 && value_ <= 1.0) {
                 image_editor_command_ = new ThresholdFilterCommand(
                                             image_editor_, value_);
                 image_editor_command_->Execute();
               } else {
                 DisplayHelpMessage();
                 exit(1);
               }
             }
           } else if (argument_.compare("-motionblur-n-s") == 0) {
             // Motion Blur N-S Filter
             index = index + 1;
             argument_ = string(argv[index]);
             if (!CheckStringFloat(argument_)) {
               DisplayHelpMessage();
               exit(1);
             } else {
               value_ = stof(argument_);
               if (value_ >= 1.0 && value_ <= 10.0) {
                 image_editor_command_ = new MotionBlurFilterCommand(
                                  image_editor_, value_,
                                  ConvolutionFilterMotionBlur::MBLUR_DIR_N_S);
                 image_editor_command_->Execute();
               } else {
                 DisplayHelpMessage();
                 exit(1);
               }
             }
           } else if (argument_.compare("-motionblur-e-w") == 0) {
             // MotionBlur E-W Filter
             index = index + 1;
             argument_ = string(argv[index]);
             if (!CheckStringFloat(argument_)) {
               DisplayHelpMessage();
               exit(1);
             } else {
               value_ = stof(argument_);
               if (value_ >= 1.0 && value_ <= 10.0) {
                 image_editor_command_ = new MotionBlurFilterCommand(
                                   image_editor_, value_,
                                   ConvolutionFilterMotionBlur::MBLUR_DIR_E_W);
                 image_editor_command_->Execute();
               } else {
                 DisplayHelpMessage();
                 exit(1);
               }
             }
           } else if (argument_.compare("-motionblur-ne-sw") == 0) {
             // MotionBlur NE-SW
             index = index + 1;
             argument_ = string(argv[index]);
             if (!CheckStringFloat(argument_)) {
               DisplayHelpMessage();
               exit(1);
             } else {
               value_ = stof(argument_);
               if (value_ >= 1.0 && value_ <= 10.0) {
                 image_editor_command_ = new MotionBlurFilterCommand(
                                image_editor_, value_,
                                ConvolutionFilterMotionBlur::MBLUR_DIR_NE_SW);
                 image_editor_command_->Execute();
               } else {
                 DisplayHelpMessage();
                 exit(1);
               }
             }
           } else if (argument_.compare("-motionblur-nw-se") == 0) {
             // MotionBlur NW-SE - Filter
             index = index + 1;
             argument_ = string(argv[index]);
             if (!CheckStringFloat(argument_)) {
               DisplayHelpMessage();
               exit(1);
             } else {
               value_ = stof(argument_);
               if (value_ >= 1.0 && value_ <= 10.0) {
                 image_editor_command_ = new MotionBlurFilterCommand(
                                image_editor_, value_,
                                ConvolutionFilterMotionBlur::MBLUR_DIR_NW_SE);
                 image_editor_command_->Execute();
               } else {
                 DisplayHelpMessage();
                 exit(1);
               }
             }
           } else {
             // fix 01: google style error
             // there was no space between // and comment. solved by added
             // extra space.
             // If there there is a typo or wrong argument.
             // return Help Message
             cout << "NO VALID FILTER" << endl;
             DisplayHelpMessage();
             exit(1);
           }
         }
       }
     }
  }

  // Function to check if the string is a picture file
  bool CommandLineProcessor::is_picture_file(const string& s) {
    if (s.length() < 4) {
      return false;
    } else {
      if (s.substr(s.size() - 4) != ".png") {
        return false;
      } else {
        return true;
      }
    }
  }

  // Function to check if the string is a number
  bool CommandLineProcessor::CheckStringFloat(const string& s) {
    if (s.find_first_not_of(".0123456789") != string::npos) {
      return false;
    } else {
      int count = 0;
      int length_ = s.length();
      for (int i = 0; i < length_; i++) {
        if (s[i] == '.') {
          count++;
        }
      }
      if (count > 1) {
        return false;
      } else {
        return true;
      }
    }
  }

  // Help Message
  void CommandLineProcessor::DisplayHelpMessage() {
    cout << "usage: mia infile.png "
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
        "-motionblur-nw-se r: nw-se motion blur with kernel radius r" << endl;
  }
}  // namespace image_tools

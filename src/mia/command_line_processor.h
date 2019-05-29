// Copyright Dongha Kang 2018

#ifndef MIA_COMMAND_LINE_PROCESSOR_H_
#define MIA_COMMAND_LINE_PROCESSOR_H_

#include <iostream>
#include <string>
#include <vector>

#include "imagetools/image_editor.h"
#include "mia/image_editor_commands.h"

namespace image_tools {

/** @brief The Command Line Processor. This class creates either Mia GUI
 (the graphics window to display similiar to Flashphoto), or You can directly
 give command to the terminal to interact the filters and tools with images.
 Also, directly save and load images.
 */
class CommandLineProcessor {
 public:
  // fix/01 google style issue.
  // Redundant space was illiminated here
  CommandLineProcessor() { image_editor_ = new ImageEditor(); }
  ~CommandLineProcessor() {}

  /** checks the command line's argument and do the certain command
  directly **/
  void ProcessCommandLine(int argc, char* argv[]);

  /** check if the argument is a number. */
  bool CheckStringFloat(const std::string& s);

  /** check if the argument is a picture file */
  bool is_picture_file(const std::string& s);

  /** Displaying the Help Message */
  void DisplayHelpMessage();
 private:
  ImageEditorCommand* image_editor_command_;
  ImageEditor* image_editor_;
};
}  // namespace image_tools
#endif  // MIA_COMMAND_LINE_PROCESSOR_H_

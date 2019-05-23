/**
This file is part of the CSCI-3081W Project Support Code, which was developed
at the University of Minnesota.

This code is to be used for student coursework.  It is not an open source
project.
Copyright (c) 2015-2018 Daniel Keefe, TAs, & Regents of the University of
Minnesota.

Original Author(s) of this File:
  Seth Johnson, 2/15/15, University of Minnesota

Author(s) of Significant Updates/Modifications to the File:
  ...
*/

#ifndef IMAGETOOLS_TOOL_ERASER_H_
#define IMAGETOOLS_TOOL_ERASER_H_

#include <string>
#include "imagetools/color_data.h"
#include "imagetools/float_matrix.h"
#include "imagetools/tool.h"

namespace image_tools {

/** @brief This tool simulates an Eraser.  It overrides the Tool's StartStroke
 method to change the paint_color to be the canvas's background color. */
class ToolEraser : public Tool {
 public:
  ToolEraser();
  virtual ~ToolEraser();

  /** @brief Calls the name of the tool, eraser
  @return It returns the name of the tool, "Eraser"
  */
  static const std::string name() { return "Eraser"; }

  /** @brief Create the mask that is for the eraser tool.
   For eraser tool, it will create constant mask, circle shaped.
   @param[in] radius Size of the mask. The size of the mask will depend on
    this radius.
   @return Constant Mask.
   */
  FloatMatrix *CreateMask(float radius) override;

  /** @brief This function draws with the background color
  works same as start stroke, but paint_color is the background color.
  @param[in] paint_color Paint color is same as background color.
  */
  void StartStroke(PixelBuffer *buffer, int x, int y,
                   const ColorData &paint_color, float radius) override;
};

}  // namespace image_tools

#endif  // IMAGETOOLS_TOOL_ERASER_H_

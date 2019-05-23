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

#ifndef IMAGETOOLS_TOOL_CHALK_H_
#define IMAGETOOLS_TOOL_CHALK_H_

#include <string>
#include "imagetools/tool.h"

namespace image_tools {

/** @brief This tool simulates chalk drawing on a rough paper.  The class
 overrides Tool's default color blending function to insert random noise as
 the tool is moved around. */
class ToolChalk : public Tool {
 public:
  ToolChalk();

  virtual ~ToolChalk();

  /** @brief Calls the name of the tool, chalk
  @return It returns the name of the tool, "Chalk"
  */
  static const std::string name() { return "Chalk"; }

  /** @brief Create the mask that is for the chalk tool.
   For chalk tool, it will create constant mask, circle shaped.
   @param[in] radius Size of the mask. The size of the mask will depend on
    this radius.
   @return Constant Mask.
   */
  FloatMatrix *CreateMask(float radius) override;

  /** @brief Function to get the appearance of the chalk mask.
   Insert random holes in the mask each time when apply it to the canvas.
   This is done probabalistically so that about 40% of the mask is opaqaue
   and the other 60% is transparent but the transparent parts show up
   at random places within the mask.
   @param[in] paint_color Color of the paint
   @param[in] canvas_color Color of the canvas color
   @param[in] mask_intensity if 40% or higher, mask is opaque. Checking the
   mask intensity.
   */
  ColorData CombinePaintAndCanvasColor(const ColorData &paint_color,
                                       const ColorData &canvas_color,
                                       float mask_intensity) override;

 private:
  static unsigned int seed_;
};

}  // namespace image_tools

#endif  // IMAGETOOLS_TOOL_CHALK_H_

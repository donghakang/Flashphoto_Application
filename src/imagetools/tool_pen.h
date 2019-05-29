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

#ifndef IMAGETOOLS_TOOL_PEN_H_
#define IMAGETOOLS_TOOL_PEN_H_

#include <string>
#include "imagetools/tool.h"

namespace image_tools {

/** @brief The simplest of tools, this has a mask that is a completely opaque
 circle. */
class ToolPen : public Tool {
 public:
  ToolPen();
  virtual ~ToolPen();

  /** @brief Calls the name of the tool, pen
  @return It returns the name of the tool, "Pen"
  */
  static const std::string name() { return "Pen"; }

  /** @brief Create the mask that is for the pen tool.
   For pen tool, it will create constant mask, circle shaped.
   @param[in] radius Size of the mask. The size of the mask will depend on
    this radius.
   @return Constant Mask.
   */
  FloatMatrix* CreateMask(float radius) override;
};
}  // namespace image_tools
#endif  // IMAGETOOLS_TOOL_PEN_H_

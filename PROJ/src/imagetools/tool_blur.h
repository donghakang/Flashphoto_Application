/**
This file is part of the CSCI-3081W Project Support Code, which was developed
at the University of Minnesota.

This code is to be used for student coursework.  It is not an open source
project.
Copyright (c) 2015-2018 Daniel Keefe, TAs, & Regents of the University of
Minnesota.

Original Author(s) of this File:
  Seth Johnson, 4/4/2015, University of Minnesota

Author(s) of Significant Updates/Modifications to the File:
  ...
*/

#ifndef IMAGETOOLS_TOOL_BLUR_H_
#define IMAGETOOLS_TOOL_BLUR_H_

#include <stdio.h>
#include <string>
#include "imagetools/tool.h"
#include "imagetools/convolution_filter_blur.h"

namespace image_tools {

/** @brief This tool serves as a mobile version of the blur filter, functions
  much like the spray can, except with blurring neighboring pixels rather than
  coloring them (linear falloff). */
class ToolBlur : public Tool {
 public:
  ToolBlur();
  virtual ~ToolBlur();

  /** @brief Calls the name of the tool, blur
  @return It returns the name of the tool, "Blur"
  */
  static const std::string name() { return "Blur"; }

  /** @brief Create the mask that is for the blur tool.
   For blur tool, it will create constant mask, circle shaped.
   @param[in] radius Size of the mask. The size of the mask will depend on
    this radius.
   @return Constant Mask.
   */
  FloatMatrix* CreateMask(float radius) override;

  /** @brief Returns the ColorData at (x, y).
   @param[in] x X value in the PixelBuffer.
   @param[in] y Y value in the PixelBuffer.
   @return ColorData at (x, y)
   */
  ColorData LookupPaintColor(int x, int y) override;

 private:
  /* Copy assignment/construction is disallowed */
  ToolBlur(const ToolBlur& rhs) = delete;
  ToolBlur& operator=(const ToolBlur& rhs) = delete;

  ConvolutionFilterBlur blur_kernel_;
  // add a member variable to create an instance of your
  // ConvolutionBlurFilter here.
};

}  // namespace image_tools

#endif  // IMAGETOOLS_TOOL_BLUR_H_

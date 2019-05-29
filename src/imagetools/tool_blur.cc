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

#include "imagetools/tool_blur.h"
#include "imagetools/mask_factory.h"
#include "imagetools/convolution_filter_blur.h"

namespace image_tools {

// sourced from iter1 solution
// made sure that kernel value is NULL in the constructor
ToolBlur::ToolBlur() {
  blur_kernel_.set_radius(5.0);
  blur_kernel_.SetupFilter();
  stamp_overlap_ = 0.333;
}

ToolBlur::~ToolBlur() { blur_kernel_.CleanupFilter(); }

FloatMatrix* ToolBlur::CreateMask(float radius) {
  return MaskFactory::CreateLinearFalloffMask(radius);
}

ColorData ToolBlur::LookupPaintColor(int x, int y) {
  return blur_kernel_.CalculateFilteredPixel(*buffer_, x, y);
}

} /* namespace image_tools */

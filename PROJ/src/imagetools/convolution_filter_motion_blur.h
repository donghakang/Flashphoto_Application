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

#ifndef IMAGETOOLS_CONVOLUTION_FILTER_MOTION_BLUR_H_
#define IMAGETOOLS_CONVOLUTION_FILTER_MOTION_BLUR_H_

#include "imagetools/convolution_filter.h"

namespace image_tools {

/** @brief Implements a motion blurring filter.  This is different that a
 blurring filter, which blurs in all directions. A motion blur filter only blurs
 in one direction. */
class ConvolutionFilterMotionBlur : public ConvolutionFilter {
 public:
  /// Four possible directions of blur are supported
  // fix 1: the line was 80 <=. So seperated to two different lines
  enum MBlurDir { MBLUR_DIR_N_S, MBLUR_DIR_E_W,
                  MBLUR_DIR_NE_SW, MBLUR_DIR_NW_SE };

  /// Defaults to radius=5.0 and dir = N to S
  ConvolutionFilterMotionBlur();
  ConvolutionFilterMotionBlur(float radius, MBlurDir direction);
  virtual ~ConvolutionFilterMotionBlur();

  /** @brief Creates the Kernel for the Motion Blur filter. Only for the
   Convolution filters. */
  FloatMatrix* CreateKernel() override;

  /** Check if the alpha value changes */
  bool convolve_alpha() const override;

  // setters and getters
  MBlurDir direction();
  void set_direction(MBlurDir dir);

  float radius();
  void set_radius(float r);

 private:
  float radius_;
  MBlurDir dir_;
};

}  // namespace image_tools

#endif  // IMAGETOOLS_CONVOLUTION_FILTER_MOTION_BLUR_H_

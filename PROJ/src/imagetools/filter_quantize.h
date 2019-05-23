/**
This file is part of the CSCI-3081W Project Support Code, which was developed
at the University of Minnesota.

This code is to be used for student coursework.  It is not an open source
project.
Copyright (c) 2015-2018 Daniel Keefe, TAs, & Regents of the University of
Minnesota.

Original Author(s) of this File:
  Seth Johnson, 4/3/15, University of Minnesota

Author(s) of Significant Updates/Modifications to the File:
  ...
*/

#ifndef IMAGETOOLS_FILTER_QUANTIZE_H_
#define IMAGETOOLS_FILTER_QUANTIZE_H_

#include "imagetools/filter.h"

namespace image_tools {

/** @brief Implements a quantization filter that bins colors to produce
 something
 like a graphic novel visual effect.

 Each channel of each pixel is characterized as filling into one of n predefined
 bins, turning the continuous range of 0.0 to 1.0 for each channel into a set of
 n discrete values.
 */
class FilterQuantize : public Filter {
 public:
  explicit FilterQuantize(int bins);
  FilterQuantize();

  virtual ~FilterQuantize();

  int num_bins();
  void set_num_bins(int n);

  /** @brief Function for Quantize filter to calculate the value at the
   center (x, y) with kernels or the equations and returns the resulting
   colors
   @param[in] buffer The buffer to filter
   @param[in] x X position of the pixel to filter
   @param[in] y Y position of the pixel to filter
   @return The Quantize filtered version of the color at the pixel (x,y)
   */
  ColorData CalculateFilteredPixel(const PixelBuffer &buffer, int x,
                                           int y) override;

 private:
  /// The number of bins to use within for each channel.
  int bins_;
};

}  // namespace image_tools

#endif  // IMAGETOOLS_FILTER_QUANTIZE_H_

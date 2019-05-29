/**
 This file is part of the CSCI-3081W Project Support Code, which was developed
 at the University of Minnesota.

 This code is to be used for student coursework.  It is not an open source
 project.
 Copyright (c) 2015-2018 Daniel Keefe, TAs, & Regents of the University of
 Minnesota.

 Original Author(s) of this File:
 Daniel Keefe, 2018, University of Minnesota

 Author(s) of Significant Updates/Modifications to the File:
 ...
 */

#ifndef IMAGETOOLS_MASK_FACTORY_H_
#define IMAGETOOLS_MASK_FACTORY_H_

#include "imagetools/float_matrix.h"

namespace image_tools {

/** @brief This factory is used to create masks used by image editing tools.  Some of
 the masks are used by more than one tool. */
class MaskFactory {
 public:
  /** @brief Create the constant mask that is used for tools, such as pen.
  @param[in] radius Size of the mask. The size of circle will depend on this
   radius
   */
  static FloatMatrix* CreateConstantMask(float radius);

  /** @brief Create the Oval shaped masks that is used for certain tools,
   such as highlighter, and calligraphy pen.
   @param[in] radius Size of the mask. The size of the mask will depend on
   this radius
   @param[in] angle_in_deg By change of angle, the shape of oval will be tilted,
   straightened, and so on.
   @param[in] ratio Ratio will change the angle also.
   */
  static FloatMatrix* CreateOvalMask(float radius, float angle_in_deg,
                                     float ratio);

  /** @brief Create the mask that overlaps to each masks. This is used in
   highlighters, spray can.
   @param[in] radius Size of the mask. The size of circle will depend on This
   radius.
   */
  static FloatMatrix* CreateLinearFalloffMask(float radius);

  /** @brief Create the mask that looks like an bullseye. This is used in
   stamp tool.
   @param[in] radius Size of the mask. The size of circle will depend on this
   radius.
   @param[in] linewidth width of the bullseye
   */
  static FloatMatrix* CreateBullseyeMask(float radius, float linewidth);
};

}  // namespace image_tools

#endif  // IMAGETOOLS_MASK_FACTORY_H_

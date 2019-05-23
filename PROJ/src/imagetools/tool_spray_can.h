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

#ifndef IMAGETOOLS_TOOL_SPRAY_CAN_H_
#define IMAGETOOLS_TOOL_SPRAY_CAN_H_

#include <string>
#include "imagetools/tool.h"

namespace image_tools {

/** @brief This tool has a linear falloff so that it looks like the paint
 has been sprayed onto the canvas.

 It also has the interesting property that it continues
 to paint even when held stationary so paint continues to accumulate on the
 canvas the longer you hold it still. */
class ToolSprayCan : public Tool {
 public:
  ToolSprayCan();
  virtual ~ToolSprayCan();

  /** @brief Calls the name of the tool, spray can
  @return It returns the name of the tool, "Spray Can"
  */
  static const std::string name() { return "Spray Can"; }

  /** @brief Create the mask that is for the spray can tool.
   For spray can tool, it will create linear fall off mask (overlap mask)
   @param[in] radius Size of the mask. The size of the mask will depend on this
   radius_
   @return Linear Fall Off mask.
   */
  FloatMatrix* CreateMask(float radius) override;

  /** @brief Boolean function that handle if it is holding same value or not.
   Most tools only apply "paint" when they are moved on the canvas, but
   some, like a spray can continue applying more paint over time even if
   they are held in the same place.
   @return true
   */
  bool applies_paint_when_stationary() override { return true; }
};

} /* namespace image_tools */

#endif  // IMAGETOOLS_TOOL_SPRAY_CAN_H_

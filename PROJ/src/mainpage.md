Flashphoto and Mia
===============
# Welcome To Flashphoto and MIA
Flashphoto and Mia is a useful software when you are dealing with changing of images and drawing as a canvas. Flashphoto and Mia can load, save pictures and not only saving and loading, but there are so much more.
With tools (such as pen, highlighters) you can draw on the pictures and with filters (such as blur, sharpen) you can change the view of the picture.
You can also use command line to generate the image that is filtered. <br>

To find more Press guide below !! <br>
Once again, **welcome to flashphoto and mia !!**

* For Users
 * \subpage page1
 * \subpage page2
<br><br>
* For Developers
 * \subpage page3
 * \subpage page4
 * \subpage page5
 * \subpage page6











\page page1 Getting Started with FlashPhoto
Flashphoto
=============
Flashphoto is the app that simply can change the image using filter or brushes on GUI App. You can also load the image file, draw on it, put filter on it and save the file to certain directory. <br>
<br>
To run this program as a GUI app type <br>
```
./flashphoto
```
in the command line
<br><br>
Mainly there are two things that you can do with the Flashphoto.
- [Brushes](#Brushes)
- [Filters](#Filters)
<br><br><br>

---

## Brushes
With tools (brushes) you can draw, erase on the GUI canvas, with the colors, and the sizes that you want. <br>
There are several brush tools [Pen](#pen), [Calligraphy Pen](#calligraphy-pen), [Chalk](#chalk), [Spray Can](#spray-can), [Eraser](#eraser), [Blur](#blur), [Highlighter](#highlighter), [Stamp](#stamp). Each of the brush tools are described more specifically below, but first, how do we use brush? <br>
1. On the right of the flashphoto app, under Undo, Redo, find the category _Tools_.  
2. Between **Pen, Calligraphy Pen, Chalk, Highlighter, Spray Can, Blur, Eraser**, click the button that you want to try.
3. Under the tools, find the category called _Tool Color_, click the red button and change the color that you wish. Press Pick afterward <br> (if you wish to reset, press reset).
4. Under the _tool color_, find the category called _Tool Size_ and change the size of the tool by dragging little ball <br> (if you wish to make it bigger, drag to right. Else, drag to left).
5. By Pressing the Left button of the mouse, Draw on the GUI.
6. Have Fun !!

<br> <br>

### Pen
\image html pen_example.png "Pen example" width=300px
**Pen** tool is designed to look like a pen. <br>
Just like normal pen, the shape of the mask is circle and it gives you default type of drawing <br>
It makes an opaque, circular mark with constant intensity. This means that when the pen is applied to the canvas the digital ink from the pen completely cov\ers any color that had previously been applied to the canvas at that position. The color of the pen can be set interactively using the GUI.

<br><br><br>

### Calligraphy Pen
\image html calligraphy_pen_example.png "Calligraphy Pen Example" width=300px
**Calligraphy Pen** tool is designed to look like a calligraphy pen. <br>
Unlike, the _pen_ tool, it shows the image of pen realistically by changing the shape of pen as you move the cursor. <br>
It works almost the same way as the Pen tool. Like the Pen tool, it is completely opaque and it covers up any “paint” that was already applied to the canvas. However, the difference with the Calligraphy Pen is that the mask is an oval tilted at a 30-degree angle. The color of the highlighter can be set interactively using the GUI.
<br><br><br>

### Spray Can
\image html spray_can_example.png "Spray Can Example" width=300px
**Spray Can** tool is designed to mimic the look of paint from a spray can. <br>
It uses a special mask that is circular in shape but has a linear falloff to mimic the dispersion of color from the spray. The intensity is strongest at the center pixel and falls off linearly to zero intensity at the edge of the circle. The specific paint color can be set interactively using the GUI.
<br><br><br>

### Chalk
\image html chalk_example.png "Chalk Example" width=300px
**Chalk** tool is designed to look like a piece of chalk dragged across a bumpy surface. <br>
 It has a circular mask, but about 40% of the pixels within the circle are randomly chosen to be completely transparent. This creates the bumpy effect. The chalk color can be set interactively using the GUI.

### Eraser
\image html eraser_example.png "Eraser Example" width=300px
**Eraser** tool erases the digital canvas and returns it to its original background color. Basically you are erasing what you wrote or drew. <br>
It has a circular mask, and eraser’s color cannot be changed through the GUI because there is currently no user interface for changing the canvas background color.
<br><br><br>

### Blur
\image html blur_example.png "Blur Tool Example. (image copyright by sambypen)" width=300px
**Blur** tool is designed to blur the image instead of drawing like other brush tools. <br>
Blur tool make original image more foggy and blurry. <br>
It uses the thing called kernel that changes the view of the image by calculating with the pixels around the chosen pixel. Same as eraser tool, cannot change the color of the tool, because the tool is for changing the picture, not the drawing.
<br><br><br>

### Highlighter
\image html highlighter_example.png "Highlighter Example" width=300px
**Highlighter** tool is designed to look like a highlighter marker. <br>
It uses an oval mask similar to the Calligraphy Pen, but the oval is oriented vertically, and the intensity of the mask is set to make the mark semi-transparent. The color applied to the canvas is approximately 40% the color of the highlighter and 60% whatever color is already on the canvas; however, a special color blending function is used for the highlighter so that dark colors show through more than light colors. The color of the highlighter’s ink can be set interactively using the GUI.
<br><br><br>

### Stamp
\image html stamp_example.png "Stamp Example" width=300px
**Stamp** tool is designed to be similiar as a pen tool, but different mark. <br>
 Instead of a circle, stamp tool marks two different size of circle combined; image of bullseye. The color and the size of the mask can be changed and set interactively using the GUI
<br><br><br>

-------

## Filters
Unlike tools, filters have to do with the whole picture that is shown in the GUI FlashPhoto app.
With filters, you can change the structure and the view of the image on the GUI canvas by filtering it. <br>
There are several filters such as [blur](#blur), [motion blur](#motion-blur), [sharpen](#sharpen), [edge detect](#edge-detection), [threshold](#threshold), [saturate](#saturate), [channels](#channels), and [quantize](#quantize). Each of the filters are described more specifically below. How do we use this?
1. On the right of the GUI mode, at the top, there is a button _Open_. By pressing this button and selecting a picture file (supports only .png), Load an image <br> Also can draw with the brush tools. to try the filters.
2. On the right of the GUI mode, below tools, there is a category called _Filters_.
3. Choose any of the filters between _blur, motionblur, sharpen, edge detect, threshold, saturate, channels, quantize_.
Because individual filters work differently, will explain how to use individual filters once we get there.
<br>
To explain each filters easily, will use this picture as a original picture so you can compare before & after. \image html alien.png "Default picture. shoutout to sambypen" width=300px
<br><br>


#### Threshold
<table style="width:100%">
 <tr>
  <td>\image html threshold-0.18-out.png "threshold 0.18" width=300px</td>
  <td>\image html threshold-0.5-out.png "threshold 0.5" width=300px</td>
  <td>\image html threshold-1.0-out.png "threshold 1.0" width=300px</td>
 </tr>
</table>

*Threshold* filter is the filter, which each of the color channels(r, g, b, alpha) will be rounded up to the maximum value of 1.0 or down to the minimum value of 0.0 based on whether the pixel's value is greater or less than the GLUI input value, respectively.
* How to use ?
  1. Press _Threshold_ button
  2. By scroll the ball, set the cutoff value (0.0 ~ 1.0)
  3. Press Apply.
<br><br><br>

#### Saturate
\image html saturate-5.0-out.png "saturate 5.0" width=300px
*Saturate* filter increases or decreases the colorfulness of the image. Increase the amount of radius, then color will be emphasized. Decrease the amount of radius, the color will be less colorful.
* How to use ?
  1. Press _Saturate_ button
  2. By scroll the ball, set the amount value (0.0 ~ 10.0)
  3. Press Apply
<br><br><br>

#### Channels
<table style="width:100%">
 <tr>
   <td>\image html red-5.0-out.png "channels(5, 1, 1)" width=300px</td>
   <td>\image html green-5.0-out.png "channels(1, 5, 1)" width=300px</td>
   <td>\image html blue-5.0-out.png "channels(1, 1, 5)" width=300px</td>
 </tr>
</table>

*Channels* filter independently scale up of down the intensity of each color channel (red, green, and blue).
* How to use ?
  1. Press _Channels_ button
  2. By scroll the ball, set the red/green/blue value
  3. Press Apply
<br><br><br>

#### Quantize
\image html quantize-5.0-out.png "quantize 5" width=300px
*Quantize* filter reduces the number of colors in the image by binning. If using 4 bins, there will only be 4 possible intensity values for each color channel, spaced evenly: 0%, 33%, 66%, and 100%. Adjust each color channel value R, G, and B to put it into the nearest bin.
* How to use ?
  1. Press _Quantize_ button
  2. By scroll the ball, set the number of bins (0~256)
  3. Press Apply
<br><br><br>

#### Blur
\image html blur-5.0-out.png "blur 5" width=300px
*Blur* filter uses a _Gaussian_ blur image convolution kernel to blur the image in proportion to the amount specified in the GUI.
* How to use ?
  1. Press _Blur_ button
  2. By scrolling the ball, set the blur amount (0~10)
  3. Press Apply (this may take some time)
<br><br><br>

#### Motion Blur
<table style="width:100%">
 <tr>
  <td>\image html motionblur-n-s-5.0-out.png "North/South 5" width=300px</td>
  <td>\image html motionblur-e-w-5.0-out.png "East/West 5" width=300px</td>
  <td>\image html motionblur-ne-sw-5.0-out.png "Northeast/Southwest 5" width=300px</td>
  <td>\image html motionblur-nw-se-5.0-out.png "Northwest/Southeast" width=300px</td>
 </tr>
</table>
Blur the image by convolving it with an appropriate motion-blurring kernel. Support four possible blurring directions (North-to-South, East-to-West, Northeast-to-Southwest, and Northwest-to-Southeast) and blur according to the amount specified in the GUI.
* How to use ?
  1. Press _Motion Blur_ button
  2. By scrolling the ball, set the blur amount (0~10)
  3. By Pressing the button, select direction of the blur, (North/South, East/West, Northeast/Southwest, Northwest/Southeast)
  4. Press Apply (this may take some time)
<br><br><br>

#### Sharpen
\image html sharpen-5.0-out.png "Sharpen 5" width=300px
*Sharpen* filter sharpens the image (accentuate the edges of shapes) in proportion to the amount specified in the GUI by convolving the image with an appropriate sharpening kernel.
* How to use ?
  1. Press _Sharpen_ button
  2. By scrolling the ball, set the sharpen amount (0~10)
  3. Press Apply.
<br><br><br>

#### Edge Detection
\image html edge-out.png "Edge Detection" width=300px
*Edge Detection* filter transform the image into one that only shows the edges of shapes by convolving it with a 3x3 edge detection kernel. Pixels on the border of differently colored regions will be bright, while pixels in areas of low change will be dark.
* How to use ?
  1. Press _Edge Detect_ button
  2. Press Apply.


<br><br><br>
Have fun with it ! <br>
If you messed it up! Don't worry there is always a UNDO and REDO buttons !









\page page2 Getting Started with Mia
##MIA
**MIA** (Medical Imaging Application) is the app that simply can change the image using filter or brushes in two different ways.
 1. By using the GUI app, just like _flashphoto_
 2. By using the _Command Line Mode_.

If you want to run this program as a **GUI app** like flashphoto, simply type <br>
```
./mia
``` <br>
in the command line. <br>
This is similar to flashphoto app but it looks more like a streamlined version of the actual flashphoto.
<br><br>
If you want to run this program as a **Command Line mode** type <br>
`./mia <following command>` <br>
in line saying `<following command>` is where the users put the command they wish to put to change the image. <br>
This mode is useful for scripting and creating workflows that can be applied repeatedly to large medical imaging collections.

------------------------

### MIA commands.
#### Basic Commands

1. **-h**
  * This command prints out the help message.
  * `mia -h` will print out the all the commands (help message).
<br>
Below is the help message
<br><br>
````
 usage: mia infile.png [image processing commands ...] outfile.png <br> <br>

 infile.png: input image file in png format
 outfile.png: filename to use for saving the result

 image processing comamnds:
 -blur r:             apply a gaussian blur of radius r <br>
 -edgedetect:         apply an edge detection filter <br>
 -sharpen r:          apply a sharpening filter of radius r <br>
 -red s:              scale the red channel by factor s <br>
 -green s:            scale the green channel by factor s <br>
 -blue s:             scale the blue channel by factor s <br>
 -quantize n:         quantize each color channel into n bins <br>
 -saturate s:         saturate colors by scale factor s <br>
 -threshold c:        threshold using cutoff value c <br>
 -motionblur-n-s r:   north-south motion blur with kernel radius r <br>
 -motionblur-e-w r:   east-west motion blur with kernel radius r <br>
 -motionblur-ne-sw r: ne-sw motion blur with kernel radius r <br>
 -motionblur-nw-se r: nw-se motion blur with kernel radius r
````
<br>

2. **infile.png** and **outfile.png**
  * _infile.png_ that comes up right after `mia` will be the loadfile, and _outfile.png_ that comes up at last will be the savefile.
  * `mia infile.png outfile.png` will load infile.png and save same image as outfile.png
<br>

------------------------

#### Filter Commands
3. **-blur _r_**
  * Apply a Gaussian blur of radius r
  * `mia infile.png -blur 5.0 outfile.png` will load infile.png and save blurred (radius of 5) image as outfile.png

4. **-edgedetect**
  * Apply an Edge Detection filter
  * `mia infile.png -edgedetect outfile.png` will load infile.png and save edge detect filtered image as outfile.png

5. **-sharpen _r_**
  * Apply a Sharpen of radius r
  * `mia infile.png -sharpen 5.0 outfile.png` will load infile.png and save sharpened (radius of 5) image as outfile.png

6. **-red _s_**
  * Scale the red channel by factor s
  * `mia infile.png -red 5.0 outfile.png` will load infile.png and save red scaled (factor of 5) image as outfile.png

7. **-green _s_**
  * Scale the green channel by factor s
  * `mia infile.png -green 5.0 outfile.png` will load infile.png and save green scaled (factor of 5) image as outfile.png

8. **-blue _s_**
  * Scale the blue channel by factor s
  * `mia infile.png -blue 5.0 outfile.png` will load infile.png and save blue scaled (factor of 5) image as outfile.png

9. **-quantize _n_**
  * Quantize each color channel into n number of bins
  * `mia infile.png -quantize 5 outfile.png` will load infile.png and save quantized (number of bins = 5) image as outfile.png

10. **-saturate _s_**
  * Saturate colors by scale factor s
  * `mia infile.png -saturate 5.0 outfile.png` will load infile.png and save saturated (scale factor of 5) image as outfile.png

11. **-threshold _c_**
  * Threshold using cutoff value c
  * `mia infile.png -threshold 1.0 outfile.png` will load infile.png and save threshold filtered (cutoff vale 1.0) image as outfile.png

12. **-motionblur-_directions_ _r_**
  * Apply Motion blur with kerenl radius r     
  * four different _directions_
   * n-s   : direction of North/South
   * e-w   : direction of East/West
   * ne-sw : direction of Northeast/Southwest
   * nw-se : direction of Northwest/Southeast
  * `mia infile.png -motionblur-ne-sw 5.0 outfile.png` will load infile.png and save blurred (radius of 5) image, directed Northeast to Southwest, as outfile.png.

<br> <br>
To find more about the _Filter_. Go to \subpage page1


####Comments
Make sure the spelling of the command is right
 * If you type something wrong, the help message will show up.
 * except edgedetect, every filters need radius, factor, or number of bins. (number)
Can use more than one filters
 * multiple filters can be used in this command line
  * for example, `mia infile.png -blur 5.0 -blue 5.0 outfile.png` will load infile.png and save blurred, and blue scaled image as outfile.png





\page page3 Programming Reference
Programming Reference
=======
[FlashPhoto](@ref image_tools::FlashPhotoApp) <br>
[MIA](@ref image_tools::MiaApp) <br>










\page page4 High-Level Design
High-Level Programming Design
======
There are various programming techniques and strategies that were used in this Flashphoto & Mia software.
<br> <br>
1. **Pointers and Dynamic Allocation**
 * Pointer is a object that stores the memory address of another value located in computer memory.
 * For example in PixelBuffer class, we used pointers instead of actual hard code. By using pointer, instead of calling the every pixel of the image when calculating, by calling the pointer, one can save the time that is running and save a lot of memories. In other words, pointer was used to be more effective in time, and memory saving.
 * Every class therefore had a constructor(s), and a deconstructor(s) to create, delete for cleaning up the memories.
 * Used in PixelBuffer, FloatMatrix, Convolution Filters, Filters and so on.

2. **UML Class Diagram (Classes relationship)**
\image html class-example.png "Class example, Pixel Buffer, Color Data and Float Matrix" width=1000px
 * Instead of making a huge file that deals with flashphoto and mia. This software tried to seperate the functions to classes. For example, instead of making big flashphoto app file. We made flashphoto_app.cc that handles GUI part of the flashphoto and linked filters, tools, ColorData, PixelBuffer, FloatMatrix to interract with the flashphoto. Made every classes to interract with each other. Therefore, this program has some type of is-a has-a relationship with each other.
 * Above is the example of the classes. Even though you can write a big class called PixelBuffer and include all the functions like colors and kernels, they seperated individually to make it look more organized.<br>

3. **Strategies**
 * For Filters, if the program had a one big class that handles all the filters, it would be hard to fix the bug (since the file is too big and probably complex) and it would be hard to implement more filters (since all the filters were connected). Therefore, the filters used strategies.<br>
\image html image_tools_relation.png "Example of Library"
In general, this program made a library (called _libimagetools_) where it contains all the filters and tools. By making the library image_tools by image_editor files. Flashphoto and Mia was linked to the library so Everytime that flashphoto and mia call filters and tools, instead of having all filters and tools individually, they simply could connect to the library and used from there.
<br><br>

\image html classimage__tools_1_1ConvolutionFilter__inherit__graph.png "Class relationship between Convolution Filter and Filters."
 * Factory Method
 \image html classimage__tools_1_1Tool__inherit__graph.png "Example of Factory Method"
  * It is the method is a creational design pattern that provides an interface for creating objects in a superclass, but allows subclasses to alter the type of objects that will be created. (sourced by refactoring.guru)
  * Instead of Creating a Giant file that controls all the filters, the filter file became a parent class and made subclasses such as threshold filter. Not only filter but also tools used same strategy. The tool file became a parent class and made subclasses such as tool pen.
  * This is good when you want to add new filters or tools, since all you have to do is make new filter/tool and just link with the parent class.
<br> <br>
 * Template Method
 \image html Template.png "Template Example" width=1000px
  * It is the method that making algorithm in a parent class that are different with subclasses. The skeleton of an algorithm in an operation, deferring some steps to client subclasses (sourced by wikipedia)
  * Filter contains SetupFilter and CleanupFilter (for more information, check the class list), which are only used in Convolution Filter. Also Filter Contains function called CalculateFilteredPixel and all the other filters (including convolution filter) uses this function in different ways. These are used for `virtual` and `override`.
  * This is useful when you want to fix or change the algorithm of individual filters or tools.










\page page5 Coding Style
Coding Style
=====
Basically, followed mostly by **google style**. For more information about the google style [Click here](https://google.github.io/styleguide/cppguide.html). <br>
The reason why google style is used is
1. To make the code look nicer.
 * By using google style guided code, the code looks more organized and cleaner. By having code look more organized and cleaner, it is easier to find the code that programmer was trying to find. Also, it become easier understand the code faster.
2. To make the code more readable
 * It is often hard to read and understand what the code does immediately. However, by using this style guide, it become little easier to make the code more readable. Such as naming convention can help what the function or variable do and understand what it does faster. This will often help to understand the code faster and get into it as soon as possible.
<br><br>

With those reasons and popularity issue, we will use google style guide! <br>
There are a bunch of google style formats, but I will include only that I used and I cared about.

line boundary, indentation,

--------

1. **Naming Convention**
  * File name should be divided in words with `_`.
    * ex) convolution_filter.cc, image_editor.h
  * Name of the class will be divided in words with Capital letters
    * ex) PixelBuffer, ImageEditor, ConvolutionFilterBlur
  * Name of the function (except boolean function or setters/getters) will be divided in words with Capital letters
    * ex) CalculateFilteredPixel, CreateKernel
  * Name of the function (boolean function and setters/getters) will be divided with `_` by words.
    * ex) can_calculate_in_place(), set_radius
  * Name of the variable will be divide in words by `_`, also `_` is at the end of the name.
    * ex) radius_, f_motionblur_,
  * Name of class, function, variable shoule be related with what it actually do
    * ex) i -- x         index -- o
<br><br><br>
2. **Code**
  * Should Always comment Copyright, <writer> <date>
  * `ifndef`, `define`, `endif` in .h file should be called all Capitalized.
  ```cpp
  // from image_editor.cc
  #ifndef IMAGETOOLS_IMAGE_EDITOR_H
  #define IMAGETOOLS_IMAGE_EDITOR_H
  ...
  ...
  #endif  // IMAGETOOLS_IMAGE_EDITOR_H
  ```
  * namespace should be called and commented when it is ended.
  ```cpp
  // from image_editor.cc
  namespace image_tools {
  ...
  }  // image_tools
  ```
<br><br><br>

2. **Tab/Spaces/Indentation**
  * We don't use the tab, instead we use the space
   * ex)
   ```cpp
   for (int i = 0; i < 10; i ++) {
       cout << i << endl;
   }  // wrong code 
 
   for (int i = 0; i < 10; i ++) {
    cout << i << endl;
   }  // correct code
   ```
   * It is better to change tab as a spacebar in your personal text editor
  * For every indentation, use _SPACE_ instead of tab
   * inside the bracket `(`, `)`. or `[`, `]` no space right before or after the bracket.
   ```cpp
   foo( int x );   // wrong
   foo(int x);     // correct
   ```
   * `(int x)` -- o       `( int x )` -- x
   * when using comments. between `//` and actual comments have a space
   ```cpp
   //Comment on this place is not right
   // Comment has to start here.
   ```
   * between the actual code and `// comments` need more than 2 spaces.
   ```cpp
   foo(int x);// Comment should not start here
   foo(int y);  // Comment should start here
   ```

<br><br><br>

3. **Whitespaces**
  * Unnecessary whitespaces between the lines are pointless.
  * As long as you do not have comments between the lines, delete the whitespace between.
  ```cpp
  int foo(int x) {


   return x;  // Whitespace should not be there
  }

  int foo(int x) {
   // this is okay, as long as the whitespace used correctly
   // returns value x
   return x;
  }
  ```

<br><br><br>

4. **80 letters limit**
  * each line should not contain more than 80 letters.
  * By shortening the variable, function name and by shorten the comments you should make sure that each line does not go over 80 letters.

<br><br><br>

To check if the style is right simply run `cpplint.py` or type `make check-style` (or if in umn cselabs `make check-style-cse`).








\page page6 Common Tasks
Unlike the brush tools, filter will change by the calculation of each pixel of the image. In other words, to change the basic image with the filter, you should understand how Pixelbuffer works and how ColorData works.

1. Think what kind of filter will be made. Is it simple filter? like channels filter or Is it convolution filter? like blur filter ?
  * If you are making the filter that only depends on the color of each pixel, then it is a simple filter. For example channels filter only changes value of pixel's red, green, blue color.
  * If you are making the filter that can depend on pixels that is surrounded by certain pixel, then it is a convolution filter. If you are using convolution filter make sure you understand the kernel.
2. If you are making simple command make sure you add these functions
 * Simple Filter
   * Constructor: make sure initialize the parameters (mostly this is the radius and scale factor)
   * Getters/Setters: Getters and Setters for radius or scale factors.
   * CalculateFilteredPixel: this is the funcition to say how this filter is going to calculate at individaul pixel value. parameters are buffer(the image pixel buffer), x, y (pixel place in pixel buffer).

 * Convolution Filter
   * Constructor: make sure initialize the parameters (mostly this is the radius and scale factor and size of kernel)
   * Getters/Setters: Getters and Setters for radius, scale factors or size of the kernel
   * can_calculate_in_place: This is the boolean function to show if this filter can be changed only by x, y. For convolution filter, No. Therefore, it is false for Convolution filter
   * CreateKernel: Create a kernel for the filter. For more information about kerenl in image processing [Click here](http://setosa.io/ev/image-kernels/)
   * convolve_alpha: Boolean function to check whether or not the alpha value changes.

3. Make sure if it is linked to actual filter file
 * Simple Filter
   * check if it is including filter.h and works
 * Convolution Filter
   * check if it is including convolution_filter.h and works
   * check if the convolution_filter.h includes filter.h and connected in a right way.

4. Include the filter class in image_editor.h and .cc file.
 * .h
   * Include _new filter_.h
   * Make a variable with the class _new filter_
      ex) _NewFilter_ f_newfilter;
 * .cc
   * Make a function Apply_NewFilter_Filter with a parameter (radius or scale)
   * call ApplyToBuffer from the filter.h
      ex) f_newfilter.ApplyToBuffer(current_buffer_);

5. Go to flashphoto_app.cc or mia_app.cc and Fix the GUI part by adding buttons and functions of this new filter

6. Run and Fix the errors.

\image html filter_imagetools.png "Basic Diagram of How to add new filter

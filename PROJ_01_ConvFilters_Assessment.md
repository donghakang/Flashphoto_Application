### Assessment for Project Iteration 01 - ConvFilters (Graded By: Nikki Kyllonen)

#### Total score: _11_ / _15_

Run on November 24, 20:38:55 PM.

+ Pass: Switch to correct commit.




#### System Files and PROJ Directory Structure

+ Pass: Check that directory "/home/nkyllonen/Documents/TA/3081-F18/csci3081-test-env/grading-scripts/_proj_materials" exists.

+ Pass: Check that directory "PROJ" exists.


#### Set up cpplint

+ Pass: Copy directory "cpplint".



+ Pass: Check that directory "cpplint" exists.


#### Set up Project

+ Pass: Change into directory "PROJ".

+ Pass: Copy directory "Copy Project Files".



+ Pass: Starting with clean project.



+ Pass: Copy directory "Copy Project Files".



+ Pass: Copy directory "Copy Dependencies".



+ Pass: Copy directory "Copy Dependencies".



+ Pass: Setup grading environment.



+ Pass: Copy directory "Copy Tests".



+ Pass: Check that make compiles.




#### Test Convolution Filter Functionality

+  _3_ / _3_ : Pass: Blur Filter



+  _3_ / _4_ : Fail: Motion Blur Filter
<pre>
<b>Comments: 
</b>2 out of 4 apply in the opposite / wrong directions.</b></pre>



+  _2_ / _2_ : Pass: Sharpen Filter
<pre>
<b>Comments: 
</b>1 point back for: black outline is incorrect.</b></pre>



+  _3_ / _3_ : Pass: Edge Detection Filter



+  _0_ / _3_ : Fail: Blur Tool
    fails to run the test executable: InteractiveTest.FlashPhotoTest.
Running main() from gtest_main.cc
Note: Google Test filter = InteractiveTest.FlashPhotoTest
[==========] Running 1 test from 1 test case.
[----------] Global test environment set-up.
[----------] 1 test from InteractiveTest
[ RUN      ] InteractiveTest.FlashPhotoTest
FlashPhoto
Loading vertex shader from file: shaders/fullscreen.vert
Loading fragment shader from file: shaders/fullscreen.frag

return code: -11



#### Total score: _11_ / _15_


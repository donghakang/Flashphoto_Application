### Assessment for Project Iteration 01 - BasicFilters (Graded By: Shruti Verma)

#### Total score: _15_ / _15_

Run on November 17, 13:31:08 PM.

+ Pass: Switch to correct commit.




#### System Files and PROJ Directory Structure

+ Pass: Check that directory "/classes/grades/Fall-2018/csci3081/verma125/csci3081-test-env/grading-scripts/_proj_materials" exists.

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




#### Run Student Tests

+  ignore : Fail: Running Student Tests.

<pre>Running main() from gtest_main.cc
Note: Google Test filter = -Instructor*
[==========] Running 10 tests from 6 test cases.
[----------] Global test environment set-up.
[----------] 2 tests from FlashPhotoAppTest
[ RUN      ] FlashPhotoAppTest.GetToolTest
[       OK ] FlashPhotoAppTest.GetToolTest (102 ms)
[ RUN      ] FlashPhotoAppTest.CanApplyFilters
[       OK ] FlashPhotoAppTest.CanApplyFilters (98 ms)
[----------] 2 tests from FlashPhotoAppTest (200 ms total)

[----------] 1 test from BlurFilterTest
[ RUN      ] BlurFilterTest.CheckRangeKernel
blur_filter_unittest.cc:25: Failure
Expected: (blur_.CreateKernel()->value(i, j)) <= (1.0), actual: nan vs 1
Kernel value wrong.
[  FAILED  ] BlurFilterTest.CheckRangeKernel (1 ms)
[----------] 1 test from BlurFilterTest (1 ms total)

[----------] 2 tests from ToolPenTest
[ RUN      ] ToolPenTest.HasCorrectName
[       OK ] ToolPenTest.HasCorrectName (0 ms)
[ RUN      ] ToolPenTest.HasCorrectMask
[       OK ] ToolPenTest.HasCorrectMask (0 ms)
[----------] 2 tests from ToolPenTest (0 ms total)

[----------] 2 tests from MotionBlurFilterTest
[ RUN      ] MotionBlurFilterTest.CheckKernelSize
[       OK ] MotionBlurFilterTest.CheckKernelSize (0 ms)
[ RUN      ] MotionBlurFilterTest.SumOfKernel
[       OK ] MotionBlurFilterTest.SumOfKernel (0 ms)
[----------] 2 tests from MotionBlurFilterTest (0 ms total)

[----------] 1 test from ToolBlurTest
[ RUN      ] ToolBlurTest.HasCorrectName
[       OK ] ToolBlurTest.HasCorrectName (0 ms)
[----------] 1 test from ToolBlurTest (0 ms total)

[----------] 2 tests from EdgeFilterTest
[ RUN      ] EdgeFilterTest.CheckKernelSize
[       OK ] EdgeFilterTest.CheckKernelSize (0 ms)
[ RUN      ] EdgeFilterTest.KernelSumCorrection
[       OK ] EdgeFilterTest.KernelSumCorrection (0 ms)
[----------] 2 tests from EdgeFilterTest (0 ms total)

[----------] Global test environment tear-down
[==========] 10 tests from 6 test cases ran. (201 ms total)
[  PASSED  ] 9 tests.
[  FAILED  ] 1 test, listed below:
[  FAILED  ] BlurFilterTest.CheckRangeKernel

 1 FAILED TEST
</pre>




#### Test Basic Filter Functionality

+  _3_ / _3_ : Pass: Tools



+  _3_ / _3_ : Pass: Threshold Filter



+  _3_ / _3_ : Pass: Saturation Filter



+  _3_ / _3_ : Pass: Channels Filter



+  _3_ / _3_ : Pass: Quantize Filter



#### Total score: _15_ / _15_


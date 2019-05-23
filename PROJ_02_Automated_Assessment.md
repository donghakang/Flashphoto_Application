### Assessment for Project Iteration 02 - Automated (Graded By: Dan Orban)

#### Total score: _83_ / _85_

Run on December 17, 00:37:29 AM.


#### System Files and PROJ Directory Structure

+ Pass: Check that directory "/classes/grades/Fall-2018/csci3081/dtorban/grading-scripts/_proj_materials" exists.

+ Pass: Setup grading environment.



+  _3_ / _3_ : Pass: Check that directory "PROJ" exists.

+  _2_ / _2_ : Pass: Check that directory "PROJ/src/imagetools" exists.

+  _2_ / _2_ : Pass: Check that file "PROJ/src/imagetools/color_data.h" exists.

+  _2_ / _2_ : Pass: Check that file "PROJ/src/imagetools/Makefile" exists.


#### Set up cpplint

+ Pass: Copy directory "cpplint".



+ Pass: Check that directory "cpplint" exists.


#### Set up Project

+ Pass: Change into directory "PROJ".

+ Pass: Setup grading environment.



+  _1_ / _1_ : Pass: Ensuring code follows style guide.



+  _25_ / _25_ : Pass: Check that make compiles.



+  _3_ / _3_ : Pass: Check that file "./build/lib/libimagetools.a" exists.

+  _3_ / _3_ : Pass: Check that file "./build/bin/flashphoto" exists.

+  _3_ / _3_ : Pass: Check that file "./build/bin/mia" exists.

+  _3_ / _3_ : Pass: Check that file "./build/test/gtests" exists.


### Instructor Tests

+ Pass: Change into directory "src/tests/inst_tests".

+ Pass: Check that make compiles.



+ Pass: Change into directory "../../..".

+ Pass: Check that file "./build/test/inst_tests" exists.


#### Testing ImageIO Implementation

+  _2_ / _2_ : Pass: Check that a GoogleTest test passes.
    passes the test: Iteration2Test.ImageLoadingAndSaving.




#### Testing MIA Application

+  _1_ / _1_ : Pass: Check that a GoogleTest test passes.
    passes the test: Iteration2Test.StampToolAdded.



+  _1_ / _1_ : Pass: Check that a GoogleTest test passes.
    passes the test: Iteration2Test.DisplayHelpMessage.



+  _2_ / _2_ : Pass: Check that a GoogleTest test passes.
    passes the test: Iteration2Test.MiaCommandLineCorrect.



+  _0_ / _2_ : Fail: Check that a GoogleTest test passes.
    fails the test: Iteration2Test.MiaCommandLineBadInput.
<pre>
[ RUN      ] Iteration2Test.MiaCommandLineBadInput
iter2_test.cc:95: Failure
Value of: hasHelpMessage(getStdOutOrErr())
  Actual: false
Expected: true
./build/bin/mia src/tests/inst_tests/input.png -edgedetect 5 output.png should return the help message.</pre>




### Run Student Tests

+ Pass: Check that file "./build/test/gtests" exists.

+ Pass: Get all google tests.
    31 tests found.




#### Results

+ Pass: Check that a GoogleTest test passes.
    passes the test: CommandLineUnitTest.EdgeCommandTest.



+ Pass: Check that a GoogleTest test passes.
    passes the test: CommandLineUnitTest.BlurCommandTest.



+ Pass: Check that a GoogleTest test passes.
    passes the test: CommandLineUnitTest.SharpenCommandTest.



+ Pass: Check that a GoogleTest test passes.
    passes the test: CommandLineUnitTest.RedCommandTest.



+ Pass: Check that a GoogleTest test passes.
    passes the test: CommandLineUnitTest.GreenCommandTest.



+ Pass: Check that a GoogleTest test passes.
    passes the test: CommandLineUnitTest.BlueCommandTest.



+ Pass: Check that a GoogleTest test passes.
    passes the test: CommandLineUnitTest.QuantizeCommandTest.



+ Pass: Check that a GoogleTest test passes.
    passes the test: CommandLineUnitTest.ThresholdCommandTest.



+ Pass: Check that a GoogleTest test passes.
    passes the test: CommandLineUnitTest.SaturateCommandTest.



+ Pass: Check that a GoogleTest test passes.
    passes the test: CommandLineUnitTest.MotionBlurCommandTest.



+ Pass: Check that a GoogleTest test passes.
    passes the test: CommandLineRegressionTest.BlurTest.



+ Pass: Check that a GoogleTest test passes.
    passes the test: CommandLineRegressionTest.EdgeDetectTest.



+ Pass: Check that a GoogleTest test passes.
    passes the test: CommandLineRegressionTest.SharpenDetectTest.



+ Pass: Check that a GoogleTest test passes.
    passes the test: CommandLineRegressionTest.RedDetectTest.



+ Pass: Check that a GoogleTest test passes.
    passes the test: CommandLineRegressionTest.GreenDetectTest.



+ Pass: Check that a GoogleTest test passes.
    passes the test: CommandLineRegressionTest.BlueDetectTest.



+ Pass: Check that a GoogleTest test passes.
    passes the test: CommandLineRegressionTest.QuantizeDetectTest.



+ Pass: Check that a GoogleTest test passes.
    passes the test: CommandLineRegressionTest.SaturateDetectTest.



+ Pass: Check that a GoogleTest test passes.
    passes the test: CommandLineRegressionTest.ThresholdDetectTest.



+ Pass: Check that a GoogleTest test passes.
    passes the test: CommandLineRegressionTest.MBlurNSTest.



+ Pass: Check that a GoogleTest test passes.
    passes the test: CommandLineRegressionTest.MBlurEWTest.



+ Pass: Check that a GoogleTest test passes.
    passes the test: CommandLineRegressionTest.MBlurNESWTest.



+ Pass: Check that a GoogleTest test passes.
    passes the test: CommandLineRegressionTest.MBlurNWSETest.



+ Pass: Check that a GoogleTest test passes.
    passes the test: CommandLineRegressionTest.StampTest.



+ Pass: Check that a GoogleTest test passes.
    passes the test: CommandLineRegressionTest.BlurToolTest.



+ Pass: Check that a GoogleTest test passes.
    passes the test: CommandLineRegressionTest.PenToolTest.



+ Pass: Check that a GoogleTest test passes.
    passes the test: CommandLineRegressionTest.CalligraphyPenToolTest.



+ Pass: Check that a GoogleTest test passes.
    passes the test: CommandLineRegressionTest.ChalkToolTest.



+ Pass: Check that a GoogleTest test passes.
    passes the test: CommandLineRegressionTest.SprayCanToolTest.



+ Pass: Check that a GoogleTest test passes.
    passes the test: CommandLineRegressionTest.HighlighterToolTest.



+ Pass: Check that a GoogleTest test passes.
    passes the test: CommandLineRegressionTest.EraserToolTest.



+  _15_ / _15_ : Pass: 100% of the tests passed.


### Testing Mutants


#### Testing Pen Tool for failure

+ Pass: There is no test case for this mutant (since all tests pass). <strong>(Manually verified)</strong>
   - Reason - There is no regression test.


#### Testing Eraser Tool for failure

+ Pass: There is no test case for this mutant (since all tests pass). <strong>(Manually verified)</strong>
   - Reason - There is no regression test.


#### Testing Stamp Tool for failure

+ Pass: There is no test case for this mutant (since all tests pass). <strong>(Manually verified)</strong>
   - Reason - The stamp tool does not stamp, it slides.


#### Testing Blur Filter for failure

+ Pass: At least one test failed for Blur Filter


#### Testing Edge Detector Filter for failure

+ Pass: At least one test failed for Edge Detector Filter


#### Testing Image IO Implementaiton for failure

+ Pass: At least one test failed for Image IO Implementaiton


#### Results

+  _15_ / _15_ : Fail: 80.0% of the tests passed, and the target is 80.0%.

#### Total score: _83_ / _85_


## Project Directory

This is the project directory for CSCI-3081.

### CSE Lab Machines (Supported)

#### Build and Run

```bash
# Build the program with make
make
# Run the program
./build/bin/flashphoto
```

#### Check Style

```bash
# Using cpplint.py
make check-style
# Using cpplint-cse.sh
make check-style-cse
```

#### Run Tests

```bash
./build/test/gtests
```

### On personal machines (Not Supported / Experimental)

This is just in case you wanted to explore the wild west of graphics programming
on your own machines.  **We do not support these systems, but you are welcome to
try on your own.**

#### Linux

 * Prerequsites
   * CMake 3.9 or above
   * gcc 4.9.2 or above
   * Debian/Ubuntu:
     ```bash
     apt-get install cmake xorg-dev libglu1-mesa-dev
     ```
   * RedHat/Fedora
     ```bash
     sudo dnf install cmake mesa-libGLU-devel libXi-devel libXcursor-devel libXinerama-devel libXrandr-devel xorg-x11-server-devel
     ```

 * Build and Run

   ```bash
   # Build the program with make
   make
   # Run the program
   ./build/bin/flashphoto
   ```

#### Mac
 * Prerequsites
   * CMake 3.9 or above
   * Latest XCode with command line compiler enabled

 * Build and Run

   ```bash
   # Build the program with make
   make
   # Run the program
   ./build/bin/flashphoto
   ```

#### Windows - Visual Studio 2017 (Experimental)
 * Prerequsites
   * CMake 3.9 or above
   * Visual Studio 2017
   * Git (including git-bash for bash command line)

 * Build and Run using the **git-bash** program

   ```bash
   # Build the program with BuildWithVS2017.sh
   ./BuildWithVS2017.sh
   # Run the program
   ./build/bin/flashphoto
   ```

 * Using Visual Studio
   1. After Building and Running above, there will be a visual studio solution created
      in PROJ/src/flashphoto/build
   2. Open the solution PROJ/src/flashphoto/build/flashphoto.sln
   3. Build the solution.
   4. Set flashphoto as the startup project by right clicking.
   5. Run the program using the green arrow.

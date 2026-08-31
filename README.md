# Qt6-Clock

Hackjob because I needed a clock and didn't feel like installing anything else. Public because I can't be bothered to use tokens to clone.

## Setup

Before building you must install a version of [Qt6](https://doc.qt.io/qt-6/get-and-install-qt.html), and [Qt6 Layer Shell](https://github.com/KDE/layer-shell-qt). You will also need to install cmake, and git if you want to clone the project from a terminal.

Afterwards you can clone and build the repository:

---

### CMake

CMake building can be run in parallel by appending the `-j` flag to the build command: `cmake --build build -j`

```bash
git clone https://github.com/Deuce8/Qt6-Clock.git
cd Qt6-Launcher
cmake -B build
cmake --build build
```

---
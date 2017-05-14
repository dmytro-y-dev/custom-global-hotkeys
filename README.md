# Custom global hotkeys

This is example application that explains how to setup custom global hotkeys for Windows.

# How to build

As usual CMake (https://cmake.org/) application.

# How to configure hotkeys

You can assign actions to hotkeys in `source/Config.cpp`.

Depending on your platform (for now there is only Windows), several types of actions are available:

1. `ExecuteFileAction` : Executes specified file with specified arguments.
2. `LambdaAction` : Execute C++ snippet that can call other actions.

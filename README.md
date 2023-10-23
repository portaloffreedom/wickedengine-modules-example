# Wicked Engine C++ modules example

Wicked Engine barebone project, using c++ modules (and CMake).

The main export of the engine as a module happens in `WickedEngine.cppm` which currently lacks lots of export.
In case you need more engine functions (you probably will), add the missing entries to that file.
`static const` and `static constexpr` variables won't work because of "internal linkage" errors. You can either change those variables to be `inline constexpr` (functionality should remain exactly the same) or you can remove the corresponding `using` lines inside `WickedEngine.cppm`.

## Following are generic instructions (shared with other CMake Wicked engine projects of mine)

The one important bit that is different when building outside is to set
```cpp
wiRenderer::SetShaderSourcePath(WickedEngine_SHADER_DIR);
```
in your code, before the initialization of the MainComponent.


## Using CMAKE
### Requirements
Wicked Engine built with cmake somewhere in your system (does not matter where).
The build folder is going to be important in the next step.

### Build
```sh
$ cmake -B build -DWickedEngine_DIR=/path/to/wicked/build_folder/cmake .
$ cmake --build build -j8
```
The cmake build already defines the `WickedEngine_SHADER_DIR` to the correct path, 
no need to do anything manual aside from "Finding" the engine and linking to it.


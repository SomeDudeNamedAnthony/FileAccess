# FileAccess

 C file I/O made easy.
*A simple wrapper around C file I/O.*

## Dependencies

*FileAccess* requires nothing but the C standard library *(commonly known as glibc or libc)* for wrappers around system/kernel calls.
Used functions are:

* `fopen` *(fopen_s on UCRT)* for getting file handles.
* `fclose` for closing file handles.
* `fread` for reading files.
* `fwrite` for writing to files.
* `malloc` for allocating memory.
* `free` for freeing memory.
* `fseek` for walking through the file.
* `ftell` for retrieving how far *we've* walked.

## Installation

To integrate the *FileAccess* library into your project, simply clone it using the [*CMake Package Manager (CPM)*](https://github.com/cpm-cmake/CPM.cmake) or by manually adding it to your project by downloading a release or using git to clone it in a separate directory.


### Making use of *CPM*:

*Installation of CPM*

```bash
mkdir -p cmake
wget -O cmake/CPM.cmake https://github.com/cpm-cmake/CPM.cmake/releases/latest/download/get_cpm.cmake
```

*Fetching FileAccess*

```cmake
...
include("${CMAKE_CURRENT_LIST_DIR}/cmake/CPM.cmake")
CPMAddPackage("gh:SomeDudeNamedAnthony/FileAccess")
...
```

*Including it in your project's build.*

```cmake
...
target_link_library(<TARGET> <VISIBILITY> fileaccess)
...
```



### Making use of Git submodules.

*Inside an existing git repository.*
*Adding the submodule:*

```bash
git submodule add "https://github.com/SomeDudeNamedAnthony/FileAccess"
```



### Making use of Git cloning

```bash
git clone "https://github.com/SomeDudeNamedAnthony/FileAccess"
```

`Note: Using submodules is preferred over manual installation for easy integration.`


## Licensing

To view the license for this project, please see [LICENSE.md](LICENSE.md)
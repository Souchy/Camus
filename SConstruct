#!/usr/bin/env python
import os
import sys

env = SConscript("godot-cpp/SConstruct")

# For the reference:
# - CCFLAGS are compilation flags shared between C and C++
# - CFLAGS are for C-specific compilation flags
# - CXXFLAGS are for C++-specific compilation flags
# - CPPFLAGS are for pre-processor flags
# - CPPDEFINES are for pre-processor defines
# - LINKFLAGS are for linking flags

# tweak this if you want to use different folders, or more folders, to store your source code in.
env.Append(CPPPATH=["src/"])
sources = Glob("src/*.cpp")


# libcamus was libgdexample
if env["platform"] == "osx":
    library = env.SharedLibrary(
        "project/bin/libcamus.{}.{}.framework/libcamus.{}.{}".format(
            env["platform"], env["target"], env["platform"], env["target"]
        ),
        source=sources,
    )
else:
    library = env.SharedLibrary(
        "project/bin/libcamus.{}.{}.{}{}".format(
            env["platform"], env["target"], env["arch_suffix"], env["SHLIBSUFFIX"]
        ),
        source=sources,
    )

Default(library)

#----------------------------------------------------------------------------------------------
# Copyright (c) The Einsums Developers. All rights reserved.
# Licensed under the MIT License. See LICENSE.txt in the project root for license information.
#----------------------------------------------------------------------------------------------

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")

set(DebuggingHeaders Einsums/Debugging/AttachDebugger.hpp Einsums/Debugging/Backtrace.hpp)

set(DebuggingSources AttachDebugger.cpp Backtrace.cpp)

set(ExtraDependencies)

if(EINSUMS_WITH_BACKTRACES)
  list(APPEND ExtraDependencies cpptrace::cpptrace)
endif()

include(Einsums_AddModule)
einsums_add_module(
  Einsums Debugging
  SOURCES ${DebuggingSources}
  HEADERS ${DebuggingHeaders}
  DEPENDENCIES ${ExtraDependencies}
  MODULE_DEPENDENCIES Einsums_Config
  CMAKE_SUBDIRS examples tests
)

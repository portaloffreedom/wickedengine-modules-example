cmake_minimum_required(VERSION 3.27 FATAL_ERROR)
project(WickedEngineModuleExample)

set(CMAKE_CXX_STANDARD 20)

if (CMAKE_VERSION LESS 3.28)
	set(CMAKE_EXPERIMENTAL_CXX_MODULE_CMAKE_API aa1f7df0-828a-4fcd-9afc-2dc80491aca7)
	set(CMAKE_EXPERIMENTAL_CXX_MODULE_DYNDEP 1)
endif()

if (CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
	if (CMAKE_CXX_COMPILER_VERSION LESS 16 )
		message(FATAL_ERROR "Clang supported only from version 16")
	elseif (CMAKE_CXX_COMPILER_VERSION EQUAL 16)
		# Default to C++ extensions being off. Clang16's modules support have trouble
		# with extensions right now and it is not required for any other compiler
		set(CMAKE_CXX_EXTENSIONS OFF)
		set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fdeclspec -fms-extensions")
	endif()
elseif (CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
	if (CMAKE_CXX_COMPILER_VERSION LESS 14 )
		message(FATAL_ERROR "GCC Version < 14 not supported")
	endif()
	# string(CONCAT CMAKE_EXPERIMENTAL_CXX_SCANDEP_SOURCE
	# "<CMAKE_CXX_COMPILER> <DEFINES> <INCLUDES> <FLAGS> -E -x c++ <SOURCE>"
	# " -MT <DYNDEP_FILE> -MD -MF <DEP_FILE>"
	# " -fmodules-ts -fdeps-file=<DYNDEP_FILE> -fdeps-target=<OBJECT> -fdeps-format=p1689r5"
	# " -o <PREPROCESSED_SOURCE>")
	# set(CMAKE_EXPERIMENTAL_CXX_MODULE_MAP_FORMAT "gcc")
	# set(CMAKE_EXPERIMENTAL_CXX_MODULE_MAP_FLAG "-fmodules-ts -fmodule-mapper=<MODULE_MAP_FILE> -fdeps-format=p1689r5 -x c++")
else()
	message(WARNING "I don't know if your compiler ${CMAKE_CXX_COMPILER_ID} ${CMAKE_CXX_COMPILER_VERSION} supports c++ modules, here be dragons")
endif()

find_package(WickedEngine REQUIRED)

add_library(WickedEngineModule)
target_sources(WickedEngineModule PUBLIC
  FILE_SET CXX_MODULES TYPE CXX_MODULES FILES WickedEngine.cppm
)
target_link_libraries(WickedEngineModule PUBLIC WickedEngine::WickedEngine)

set (SOURCE_FILES)

if (WIN32)
	list (APPEND SOURCE_FILES
		main_Windows.cpp
		main_Windows.h
	)

	add_executable(WickedEngineModuleExample WIN32 ${SOURCE_FILES})
else()
	list (APPEND SOURCE_FILES
		main_SDL2.cpp
	)

	add_executable(WickedEngineModuleExample ${SOURCE_FILES})
endif ()

target_sources(WickedEngineModuleExample PUBLIC
	FILE_SET CXX_MODULES TYPE CXX_MODULES FILES
		WickedEngineModuleExample.cppm
		sdl2.cppm)

target_link_libraries(WickedEngineModuleExample PUBLIC WickedEngineModule)

if (MSVC)
        set_property(TARGET WickedEngineModuleExample PROPERTY VS_DEBUGGER_WORKING_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}")
endif ()

get_target_property(LIB_DXCOMPILER_LOCATION WickedEngine::dxcompiler IMPORTED_LOCATION)

# Copy content to build folder:
add_custom_command(
        TARGET WickedEngineModuleExample POST_BUILD
	# Copy the shader library next to the executable
	COMMAND ${CMAKE_COMMAND} -E copy_if_different "${LIB_DXCOMPILER_LOCATION}" "${CMAKE_CURRENT_BINARY_DIR}"
)

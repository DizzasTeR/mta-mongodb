cmake_minimum_required (VERSION 3.6)
project(DMongodb)

option(BUILD_32 "Build 32-bit for linux" OFF)

if(WIN32)
	if(NOT "${CMAKE_GENERATOR_PLATFORM}" MATCHES "(Win32)+")
		list(APPEND CMAKE_PREFIX_PATH $ENV{Lib}\\mongodbc\\lib\\cmake)
		# message(STATUS "CMAKE_PREFIX_PATH: ${CMAKE_PREFIX_PATH}")
		else()
		list(APPEND CMAKE_PREFIX_PATH $ENV{Lib32}\\mongodbc\\lib\\cmake)
		# message(STATUS "CMAKE_PREFIX_PATH: ${CMAKE_PREFIX_PATH}")
	endif()
else()
	# Is LINUX_32 option specified
	if(BUILD_32)
		set(CMAKE_CXX_FLAGS "-m32")
		set(CMAKE_C_FLAGS "-m32")
	endif()
endif()

set(BUILD_SHARED_LIBS OFF)

# Enable position independent code
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

if (UNIX)
	set(USE_SYSTEM_CURL ON)
	set(CMAKE_USE_OPENSSL ON)
endif()

add_compile_definitions(_SILENCE_ALL_CXX17_DEPRECATION_WARNINGS)
add_subdirectory(client)
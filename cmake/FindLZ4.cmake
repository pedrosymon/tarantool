find_path(LZ4_INCLUDE_DIR NAMES lz4.h)

if(BUILD_STATIC)
	find_library(LZ4_STATIC NAMES ${CMAKE_STATIC_LIBRARY_PREFIX}lz4${CMAKE_STATIC_LIBRARY_SUFFIX})
endif()
find_library(LZ4_LIBRARY NAMES ${CMAKE_SHARED_LIBRARY_PREFIX}lz4${CMAKE_SHARED_LIBRARY_SUFFIX})

if(BUILD_STATIC)
    set(LZ4_FIND_REQUIRED ON)
endif()

if (LZ4_INCLUDE_DIR AND LZ4_LIBRARY)
	if (NOT BUILD_STATIC OR (BUILD_STATIC AND LZ4_STATIC))
		set(LZ4_FOUND ON)
	endif()
endif()

if (LZ4_FOUND)
	message(STATUS "Found lz4 includes: ${LZ4_INCLUDE_DIR}/lz4.h")
	message(STATUS "Found lz4 library: ${LZ4_LIBRARY}")
else()
	if (LZ4_FIND_REQUIRED)
		message(FATAL_ERROR "Could not find liblz4 development files")
	endif()
endif()

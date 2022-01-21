set(CLIENT_NAME DMongoClient)

file(GLOB sources module/**.cpp)
file(GLOB headers module/**.h module/**.hpp)

add_library(${CLIENT_NAME} SHARED
   	${headers}
	${sources}
)

if(NOT WIN32)
	target_sources(${CLIENT_NAME} PRIVATE
		# Headers
			module/luaimports/luaimports.linux.h
		# Source
			module/luaimports/luaimports.linux.cpp
	)
else()
	if(NOT "${CMAKE_GENERATOR_PLATFORM}" MATCHES "(Win32)+")
		target_link_libraries(${CLIENT_NAME} PRIVATE ${PROJECT_SOURCE_DIR}/client/module/lib/lua5.1_64.lib)
	else()
		target_link_libraries(${CLIENT_NAME} PRIVATE ${PROJECT_SOURCE_DIR}/client/module/lib/lua5.1.lib)
	endif()
endif()

target_include_directories(${CLIENT_NAME}
	PRIVATE
		module
		module/include
		module/vendor
		module/luaimports
)

target_compile_features(${CLIENT_NAME} PUBLIC cxx_std_17)

add_subdirectory(${PROJECT_SOURCE_DIR}/client/module/vendor/lua-mongo)
target_link_libraries(${CLIENT_NAME} PRIVATE mongo)

# NOTE: For this to work, the CMAKE_PREFIX_PATH variable must be set to point to the directory that
# was used as the argument to CMAKE_INSTALL_PREFIX when building libmongocxx.
find_package(mongoc-1.0 REQUIRED)
target_link_libraries(${CLIENT_NAME} PRIVATE mongo::mongoc_static)
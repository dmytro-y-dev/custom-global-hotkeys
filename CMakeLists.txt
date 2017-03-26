project (custom-global-hotkeys)

include_directories("source")

file(GLOB_RECURSE APPLICATION_SOURCE_FILES "source" *.cpp)
file(GLOB_RECURSE APPLICATION_RESOURCE_FILES "resource" *.*)

add_executable(custom-global-hotkeys WIN32 ${APPLICATION_SOURCE_FILES} ${APPLICATION_RESOURCE_FILES})

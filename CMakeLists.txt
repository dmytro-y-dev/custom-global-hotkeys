project (custom-global-hotkeys)

include_directories("src/")

file(GLOB_RECURSE APPLICATION_SOURCE_FILES "src/" *.cpp)

add_executable(custom-global-hotkeys WIN32 ${APPLICATION_SOURCE_FILES})

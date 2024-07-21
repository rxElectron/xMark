cmake_minimum_required(VERSION 3.10)

project(xMark)

set(CMAKE_CXX_STANDARD 11)

find_package(Qt5 COMPONENTS Widgets REQUIRED)

add_executable(xMark main.cpp menu.cpp measure_line.cpp take_area_screenshot.cpp take_full_screenshot.cpp select_pixel_color.cpp show_date_time.cpp show_system_info.cpp calculate_disk_usage.cpp program_settings.cpp)

target_link_libraries(xMark Qt5::Widgets)

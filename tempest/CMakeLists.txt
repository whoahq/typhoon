file(GLOB TEMPEST_SOURCES
    "*.cpp"
    "matrix/*.cpp"
    "quaternion/*.cpp"
    "random/*.cpp"
    "rect/*.cpp"
    "vector/*.cpp"
)

add_library(tempest STATIC
    ${TEMPEST_SOURCES}
)

target_include_directories(tempest
    PUBLIC
        ${PROJECT_SOURCE_DIR}
)

target_link_libraries(tempest
    PUBLIC
        storm
)

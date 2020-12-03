file(GLOB_RECURSE TEST_SOURCES "*.cpp")

if(WHOA_SYSTEM_MAC)
    set_source_files_properties(${TEST_SOURCES}
        PROPERTIES COMPILE_FLAGS "-x objective-c++"
    )

    add_executable(TempestTest ${TEST_SOURCES})

    target_link_libraries(TempestTest
        PRIVATE
            tempest
            "-framework AppKit"
    )
endif()

if(WHOA_SYSTEM_LINUX OR WHOA_SYSTEM_WIN)
    add_executable(TempestTest ${TEST_SOURCES})

    target_link_libraries(TempestTest
        PRIVATE
            tempest
    )
endif()

target_include_directories(TempestTest
    PRIVATE
        ${PROJECT_SOURCE_DIR}
)

install(TARGETS TempestTest DESTINATION "bin")

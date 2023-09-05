project('littlehell', 'c',
    version: '0.0.1',
    license: 'GPL3',
    default_options: ['buildtype=debugoptimized']
)

# Use this option to allow color output
# with the logging library.
add_project_arguments('-DLOG_USE_COLOR', language: 'c')

# Directories
util_dir = include_directories('src/util')
libs_dir = include_directories('src/libs')

# Build log.c as its own library
log_lib = static_library('log', 'src/libs/log.c', include_directories: libs_dir)
# Create a dependency object for the log library
log_dep = declare_dependency(link_with: log_lib, include_directories: libs_dir)

# SDL2 dependencies
sdl2_dep = dependency('SDL2')
sdl2_net_dep = dependency('SDL2_net')
sdl2_mixer_dep = dependency('SDL2_mixer')

# Optional dependency for building tests
check_dep = dependency('check', required: false)

# Source files for the engine library
engine_sources = ['src/util/registry.c']

# Define the engine library 
littlehell_lib = library(
    'littlehell', 
    engine_sources,
    dependencies: [
        log_dep,
        sdl2_dep,
        sdl2_net_dep,
        sdl2_mixer_dep
    ],
    include_directories: [
        util_dir, 
        libs_dir
    ]
)  # Include both directories

# Create a dependency object for the littlehell library
littlehell_dep = declare_dependency(link_with: littlehell_lib, 
                                    include_directories: [util_dir, libs_dir])

# Setup tests if we have Check 
if check_dep.found()

    # All test sources
    test_sources = ['test/test_registry.c', 'test/main_tests.c']

    # Compile the tests
    test_executable = executable('all_tests', test_sources,
                                 dependencies: [littlehell_dep, check_dep],
                                 include_directories: [util_dir, libs_dir])

    # Run the tests
    test('engine_tests', test_executable)

endif

meson.override_dependency('littlehell', littlehell_dep)

run_target('clang-tidy',
  command : 'scripts/clang-tidy.sh')

run_target('clang-format',
  command : 'scripts/clang-format.sh')

run_target('cppcheck',
  command : 'scripts/cppcheck.sh')

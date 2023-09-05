{ pkgs ? import <nixpkgs> { } }:

pkgs.clangStdenv.mkDerivation {
  name = "mindoom-dev-shell";

  nativeBuildInputs = with pkgs.buildPackages; [
    check
    clangStdenv
    clang
    clang-tools
    cloc
    cmake # Needed by check, not us
    cppcheck
    ctags
    doxygen
    gcc
    gdb
    gdbgui
    glib
    graphviz
    hotspot
    meson
    ninja
    linuxKernel.packages.linux_6_1.perf
    pkg-config
    SDL2
    SDL2_mixer
    SDL2_net
    valgrind
  ];
}

add_rules("mode.debug", "mode.release")

target("conf2d")
set_kind("binary")
add_files("args.c")
add_files("dir2file.c")
add_files("conf2d.c")
add_files("monitor.c")
add_files("clocker.c")


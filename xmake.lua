add_rules("mode.debug", "mode.release")

target("conf2d")
    set_kind("binary")
    add_files("args.c")
    add_files("read_dir.c")
    add_files("conf2d.c")
# 简介

Read in [English](./README.md)

系统中有各种各样的配置文件，有些配置文件允许你拆分到一个目录中，通常为`xxx.conf.d`这样的格式。然而一些文件不支持这种写法。这个程序监听文件系统更改，并在另一个线程中启动定时任务，将文件夹里的内容和文件同步。

# 如何使用

```
Usage: conf2d [OPTION...]

  -d, --dir=DIR              Target directory to watch
  -f, --file=FILE            Target file to watch
  -?, --help                 Give this help list
      --usage                Give a short usage message

Mandatory or optional arguments to long options are also mandatory or optional
for any corresponding short options.
```

# 特色

* 每隔一段时间更新文件

* 当目标文件夹修改时自动更新(inotify实现)



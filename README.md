# wsl_fixcore
Program to reset /proc/sys/kernel/core_pattern to "core.%p"
so you get traditional core dumps.

<!-- mdtoc-start -->
&bull; [wsl_fixcore](#wsl_fixcore)  
&nbsp;&nbsp;&nbsp;&nbsp;&bull; [Introduction](#introduction)  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&bull; [Why this exists](#why-this-exists)  
&nbsp;&nbsp;&nbsp;&nbsp;&bull; [Installation](#installation)  
&nbsp;&nbsp;&nbsp;&nbsp;&bull; [Usage](#usage)  
&nbsp;&nbsp;&nbsp;&nbsp;&bull; [License](#license)  
<!-- TOC created by '../mdtoc/mdtoc.pl README.md' (see https://github.com/fordsfords/mdtoc) -->
<!-- mdtoc-end -->


## Introduction

WSL2 has a deeply annoying habit of hijacking core dump handling with its
/wsl-capture-crash mechanism.
This makes debugging your own programs unnecessarily complicated when you just
want a simple core.<pid> file dumped in your current directory.

This tiny utility resets /proc/sys/kernel/core_pattern to core.%p so you get
traditional core dumps.
It needs to run as root (via setuid) because that's what's required to write
to that particular proc file.

This program needs to write to a file owned by root,
which means it has to run as root.
This presents a security risk if anything too fancy is done.
So there are no options, no flexibility, no conditional execution.
It does one thing and one thing only: write "core.%%p\n" to
the file "/proc/sys/kernel/core_pattern" and exit.

Thanks to Claude.ai for writing the code and doc for this program.

### Why this exists

On a normal Linux system, you set kernel.core_pattern in "/etc/sysctl.d/".
On WSL2, that doesn't work reliably - WSL keeps overriding it after a restart.
This is the nuclear option: a setuid binary that forcibly sets the pattern
on every login.

## Installation

```
./bld.sh  # compile program.
sudo cp wsl_fixcore /usr/local/bin/
sudo chown root:root /usr/local/bin/wsl_fixcore
sudo chmod u+s /usr/local/bin/wsl_fixcore
```

## Usage

Invoke this program in your ".bash_profile" or equiv.
```
/usr/local/bin/wsl_fixcore
```

## License

I want there to be NO barriers to using this code, so I am releasing it to the public domain.  But "public domain" does not have an internationally agreed upon definition, so I use CC0:

Copyright 2020 Steven Ford http://geeky-boy.com and licensed
"public domain" style under
[CC0](http://creativecommons.org/publicdomain/zero/1.0/):
![CC0](https://licensebuttons.net/p/zero/1.0/88x31.png "CC0")

To the extent possible under law, the contributors to this project have
waived all copyright and related or neighboring rights to this work.
In other words, you can use this code for any purpose without any
restrictions.  This work is published from: United States.  The project home
is https://github.com/fordsfords/techo

To contact me, Steve Ford, project owner, you can find my email address
at http://geeky-boy.com.  Can't see it?  Keep looking.

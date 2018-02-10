# The Core: Embedded C++ framework blinky example

This example runs on Discovery kit with STM32F407VG MCU and
demonstrates how easy [The Core framework](https://github.com/forGGe/theCore) is in use.

To build and run this example follow the instructions below.

## Prerequisites

For this guide a Nix package manager is required. It will download all dependencies and configure proper environment for this demo. You can follow [a getting started guide](https://www.domenkozar.com/2014/01/02/getting-started-with-nix-package-manager/)
or [an installation manual](https://nixos.org/nixos/manual/index.html#ch-installation)
in order to install the Nix package manager to your system.

If you don't want to deal with Nix, here is the list of dependencies
that are required to build and run this demo:
 - `cmake` - version >= 3.4
 - `arm-none-eabi-gcc` - version >= 5.0
 - `openocd`

## Building

Clone a repo with all submodules:
```
git clone https://github.com/forGGe/theCore-blinky.git
cd theCore-blinky
git submodule update --init --recursive
```

Launch the Nix shell:
```
nix-shell core --pure
```

Create a build directory and invoke cmake:
```
mkdir build
cd build
cmake -DCMAKE_TOOLCHAIN_FILE=../core/toolchains/arm-cm4-gnu.cmake ../
```

Refer to [the official cmake build type documentation page](https://cmake.org/cmake/help/v3.0/variable/CMAKE_BUILD_TYPE.html), if you
want to change the configuration.

Now you can launch a build:
```
make
```

## Running

If your build succeed, it is time to start a demo. Connect your stm32 Discovery
and launch a debugger.

For old Discovery boards with ST-LINK/V2, use `stm32f4discovery.cfg` as OpenOCD
script:

```
sudo openocd -f board/stm32f4discovery.cfg
```

For newer boards with ST-LINK/V2-A (labeled as STM32F407G-DISC1), you can launch:

```
sudo openocd -f board/stm32f429disc1.cfg
```

You can also follow [the guide how to run openocd **without root privileges**](http://shukra.cedt.iisc.ernet.in/edwiki/EmSys:Accessing_Devices_without_Sudo).
I strongly recommend to do that and forget about `sudo` along with `openocd`
to the rest of your life.

While openocd is running it should be controlled via gdb. You will likely need
a second terminal since the first one is occupied by openocd.
Feed a path to a built binary to gdb:

```
arm-none-eabi-gdb <path_to_your_repo>/build/blinky
```

The output should looks like following:

```
GNU gdb (GDB) 7.11
Copyright (C) 2016 Free Software Foundation, Inc.
License GPLv3+: GNU GPL version 3 or later <http://gnu.org/licenses/gpl.html>
This is free software: you are free to change and redistribute it.
There is NO WARRANTY, to the extent permitted by law.  Type "show copying"
and "show warranty" for details.
This GDB was configured as "--host=x86_64-pc-linux-gnu --target=arm-none-eabi".
Type "show configuration" for configuration details.
For bug reporting instructions, please see:
<http://www.gnu.org/software/gdb/bugs/>.
Find the GDB manual and other documentation resources online at:
<http://www.gnu.org/software/gdb/documentation/>.
For help, type "help".
Type "apropos word" to search for commands related to "word"...
Reading symbols from blinky...done.
(gdb)
```

It's time to load the blinky image:

```
(gdb) target remote :3333
(gdb) monitor reset halt
(gdb) load
```

Start the image:

```
(gdb) continue
```

Now you should see the nice blinking LEDs on your Discovery board.

## Found a bug?
Let it out! File an issue or create a pull-request, if you already have an idea how to fix it.

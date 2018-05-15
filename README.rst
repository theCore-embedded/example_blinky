Blinky example for theCore embedded C++ framework
=================================================

.. image:: https://travis-ci.org/theCore-embedded/example_blinky.svg?branch=master
    :target: https://travis-ci.org/theCore-embedded/example_blinky

This example flashes available LEDs on supported boards, one by one.

Detailed description
--------------------

See `theCore documentation for blinky example`_ for more information.

Supported targets (boards)
--------------------------

+---------------------+--------------------------+-----------------------------------+
|     Target name     |    Configuration file    |            Description            |
+=====================+==========================+===================================+
| stm32f4_disc        | stm32f4_discovery.json   | STM32F4 discovery board           |
+---------------------+--------------------------+-----------------------------------+
| tiva_tm4c_launchpad | tiva_tm4c_launchpad.json | TM4C123G LaunchPad Evaluation Kit |
+---------------------+--------------------------+-----------------------------------+

Quick start
-----------

#. Install theCore (this may take a while)::

        pip3 install tcore
        tcore bootstrap

#. Download this example::

        tcore init --remote https://github.com/theCore-embedded/example_blinky

#. Step into the project directory::

        cd example_blinky

#. Compile:

   * For STM32 Discovery board::

        cd example_blinky
        tcore compile --target stm32f4_disc
    
   * For Tiva TM4C LaunchPad::

        tcore compile --target tiva_tm4c_launchpad 

#. Connect your board.

#. Run:

   * For TivaC launchpad::

        tcore --sudo flash

   * For old STM32F407G-DISC boards, with STLINK/V2::

        tcore --sudo flash

   * For new STM32F407G-DISC1 boards, with STLINK/V2.1::

        tcore --sudo flash --debugger-config stlink-v2.1

#. Observe LEDs blinking on your board.

Found a bug?
------------
Let it out! File an issue or create a pull-request, if you already have an idea how to fix it.

.. _`theCore documentation for blinky example`: https://forgge.github.io/theCore/examples/blinky.html
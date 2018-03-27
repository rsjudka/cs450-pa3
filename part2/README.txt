================================================ PROJECT ================================================

DIRECTORY STRUCTURE:
    09_PA3/
        part1/
            ...
        part2/
            xv6/
            deliverables/
            README.txt

DELIVERABLE 1:
    sources & executables - 09_PA3/part2/xv6/*
    README (this) - PA2/part2/README.txt

DELIVERABLE 2:
    myMemory() design w/ man page  - 09_PA3/part2/deliverables/myMemory_sys_call.pdf

DELIVERABLE 3:
    test program source - 09_PA3/part2/xv6/test.c
    test program executable - 09_PA3/part2/xv6/_test (can only be run within xv6)
    test data w/ reasons - 09_PA3/part2/deliverables/tests.pdf

================================================= SETUP =================================================

REQUIRED PACKAGES:
    Vagrant [https://www.vagrantup.com/downloads.html]
    Virtualbox [https://www.virtualbox.org/wiki/Downloads] (or other supported virtualization software)

BUILD ENVIORNMENT:
    1) In 09_PA3/part2/xv6/, run command
           $ vagrant up
       to build virtual enviornemnt (NOTE this step may take a few minutes)
    2) Once build finishes, run command
           $ vagrant ssh
    3) You should now be in the virtual OS (Ubuntu 14.04)
    4) To exit virtual OS, run command
           $ exit
    5) To shutdown the virtual machine, run command
           $ vagrant halt

BUILD XV6:
    1) In the virtual OS, change directory to /vagrant/ where xv6 will be run from
    5) run commands
           $ make clean ; make
           $ make qemu-nox
       to compile and execute xv6
    6) You should now be in xv6
    7) To exit xv6, press CTRL-a, then x

RUN TEST PROGRAM:
    1) In xv6, run command
           $ test [1-6]
       to run the test program for this programming assignment


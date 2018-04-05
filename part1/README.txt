James Guerrera-Sapone - A20365203 
Robert Judka - A20348051


================================================ PROJECT ================================================

DIRECTORY STRUCTURE:
    09_PA3/
        part1/
            malloc_no_free.c
            malloc_no_free
            malloc_free_print.c
            malloc_free_print
            deliverables/
            README.txt
        part2/
            ...

DELIVERABLE 1:
    1.1
        source - 09_PA3/part1/malloc_no_free.c
        executable - 09_PA3/part1/malloc_no_free
    1.2
        source - 09_PA3/part1/malloc_free_print.c
        executable - 09_PA3/part1/malloc_free_print
    README (this) - 09_PA3/part1/README.txt

DELIVERABLE 2:
    test results & answers - 09_PA3/part1/deliverables/tests_answers.pdf

================================================= SETUP =================================================

REQUIRED PACKAGES:
    GCC >=5.4.0 [https://gcc.gnu.org/install/download.html]
    GDB [https://www.gnu.org/software/gdb/download/]
    Valgrind [http://valgrind.org/downloads/current.html]

BUILD & EXECUTE DELIVERABLE 1.1:
    1) In 09_PA3/part1/, run commands
           $ gcc -g malloc_no_free.c -o malloc_no_free
           $ ./malloc_no_free
       to build and execute deliverable 1.1

DEBUG DELIVERABLE 1.1 USING GDB:
    1) In 09_PA3/part1/, run command
           $ gdb malloc_no_free
       to run program in gdb
    2) In gdb's console, run commands
           (gdb) break 7
           ...
           (gdb) break 11
           ...
           (gdb) run
           ...
           (gdb) bt
           ...
           (gdb) info locals
           ...
           (gdb) continue
           ...
           (gdb) info locals
           ...
           (gdb) bt
       to debug and discover the memory leak

DEBUG DELIVERABLE 1.1 USING VALGRIND:
    1) In 09_PA3/part1/, run command
           $ valgrind --leak-check=yes ./malloc_no_free
       to run program in valgrind and detect memory leaks

BUILD & EXECUTE DELIVERABLE 1.2:
    1) In 09_PA3/part1/, run commands
           $ gcc malloc_free_print.c -o malloc_free_print
           $ ./malloc_free_print
       to build and execute deliverable 1.2

DEBUG DELIVERABLE 1.2 USING VALGRIND:
    1) In 09_PA3/part1/, run command
           $ valgrind --leak-check=yes ./malloc_free_print
       to run program in valgrind and detect invalid read

# Linux device driver
my first repository.
Hi guys ,
my name is fariz.
This repo consist of a hello world linux kernel module.

steps to load the lkm to linux kernel:
1. make
2. sudo insmod ldd.ko                //For loading the module to linux kernel
3. sudo dmesg                        //For checking module is successfully loaded into kernel - Ensure "Hello world (from myModule driver!!)" message
4. sudo rmmod ldd                    //For removing module from kernel
5. sudo dmesg                        //For checking module is successfully removed from kernel - Ensure "Good Bye (from myModule driver!!)" message

For checking module info 
1. modinfo ldd.ko
   
For cleaning dmesg
1. dmesg -c

For checking module is loaded successfully
1. sudo lsmod
   
For checking file types in a directory
1. file - //eg: file file.c

For printing dmesg continuosly
1. sudo dmesg -W


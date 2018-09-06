# TrdosBoot
Find and rename first Basic program in image ZX Spectrum TR-DOS file (SCL or TRD) to boot.B  
Need for emulator lr-fuse in which is not possible run PENTAGON 512 or PENTAGON 1024 in gluck.rom service.  
Most image files (scl, trd) contain one basic file, that not called "boot.B", which does not allow simply autostart program.  

## Compile
Go to in make folder, and  
`make`  

The programm is compiled in Debian and Cygwin.  

## Example use:  
process one TRD file:  
`./TrDosBoot DISK.trd`  

process all SCL files in /media/usb0/ directory:  
`./TrDosBoot /media/usb0/*.scl`

The file extension is case insensitive and mandatory.

# Simple Web Server and Web Client

A server that return the file content requested by the client

## To Build the project

make clean
make

## To run the server
$sudo ./server

## To run the client
$./client uno.txt

##To Monitor the processes

$ps aux | grep server
get the <PID>

see their file descriptors
$sudo lsof -p <PID>
lsof: WARNING: can't stat() fuse.portal file system /run/user/1000/doc
      Output information may be incomplete.
lsof: WARNING: can't stat() fuse.gvfsd-fuse file system /run/user/1000/gvfs
      Output information may be incomplete.
COMMAND   PID USER  FD   TYPE DEVICE SIZE/OFF    NODE NAME
server  21783 root cwd    DIR    8,3     4096 1189204 /home/bext/workspaceC/labC/NetworkProgramming/multi-threadServer
server  21783 root rtd    DIR    8,3     4096       2 /
server  21783 root txt    REG    8,3    22176 1181891 /home/bext/workspaceC/labC/NetworkProgramming/multi-threadServer/server
server  21783 root mem    REG    8,3  2190608  394812 /usr/lib/x86_64-linux-gnu/libc.so.6
server  21783 root mem    REG    8,3   254864  394809 /usr/lib/x86_64-linux-gnu/ld-linux-x86-64.so.2
server  21783 root   0u   CHR  136,3      0t0       6 /dev/pts/3
server  21783 root   1u   CHR  136,3      0t0       6 /dev/pts/3
server  21783 root   2u   CHR  136,3      0t0       6 /dev/pts/3
server  21783 root   3u  IPv4  97236      0t0     TCP *:http (LISTEN)

# To monitor the traffic just localhost 

 sudo iftop -i lo

# Checking active sockets
 ss -tupn

bext@bext-G3-3779:~$ ss -tupn
Netid   State    Recv-Q    Send-Q                                  Local Address:Port                 Peer Address:Port   Process                                
udp     ESTAB    0         0                                  192.168.100.9%wlo1:68                  192.168.100.1:67                                            
tcp     ESTAB    0         0                                       192.168.100.9:58082               20.184.175.10:443     users:(("code",pid=30604,fd=26))      
tcp     ESTAB    0         0                                       192.168.100.9:52560              138.91.182.224:443     users:(("code",pid=30604,fd=28))      
tcp     ESTAB    0         0                                       192.168.100.9:50214               34.107.243.93:443     users:(("firefox",pid=36738,fd=50))   
tcp     ESTAB    0         0            [2806:2f0:5160:fa94:7e30:6369:b405:21fb]:57892       [2603:1061:14:105::1]:443     users:(("code",pid=30604,fd=27)) 

# To Monitor the Threads of a process

ps -o nlwp= -p <PID>   
or
ps -T -p <PID>   
or
grep '^Threads:' /proc/<PID>/status   
or
top -H -p <PID>   
or
watch -n 1 ps -o thcount= -p <PID>   

## View Current limits

ulimit -n         //show the current soft limit
ulimit -Hn        //show the hard limit, maximim ceiling you can reach without root access
ulimit -Sn        //show the soft limit, what the kernel enforces by default

# Configuring Limits in Limits.conf
/etc/security/limits.conf
hard nofile 65535
soft nofile 65536

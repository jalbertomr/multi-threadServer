# Simple Web Server and Web Client

A server that return the file content requested by the client

## To Build the project
```
make clean
make
```
## To run the server
```
$./server
```
## To run the client
```
$./client uno.txt
```
## To Monitor the processes
```
$ps aux | grep "\./server"
```
Then get the \<PID\>

see their file descriptors
```
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
```
# To monitor proces smap

```
cat /proc/<pid>/smap
```
# To Continuous monitoring connections

```
watch -n 2 'ss -tunap' 
OR 
watch -n 2 'ss -tn dport = :8989'

Netid    State        Recv-Q    Send-Q         Local Address:Port        Peer Address:Port     Process
udp      UNCONN       0         0                 127.0.0.54:53               0.0.0.0:*
udp      UNCONN       0         0              127.0.0.53%lo:53               0.0.0.0:*
udp      UNCONN       0         0                  127.0.0.1:323              0.0.0.0:*
udp      UNCONN       0         0                 172.17.0.1:3702             0.0.0.0:*         users:(("python3",pid=12078,fd=13))
udp      UNCONN       0         0            239.255.255.250:3702             0.0.0.0:*         users:(("python3",pid=12078,fd=11))
udp      UNCONN       0         0                    0.0.0.0:53338            0.0.0.0:*         users:(("python3",pid=12078,fd=12))
udp      UNCONN       0         0                224.0.0.251:5353             0.0.0.0:*         users:(("brave",pid=8857,fd=44))
udp      UNCONN       0         0                    0.0.0.0:5353             0.0.0.0:*
udp      UNCONN       0         0                      [::1]:323                 [::]:*
udp      UNCONN       0         0                       [::]:5353                [::]:*
tcp      LISTEN       0         1                    0.0.0.0:8989             0.0.0.0:*         users:(("server",pid=751969,fd=3))
tcp      LISTEN       0         4096               127.0.0.1:631              0.0.0.0:*
tcp      LISTEN       0         4096              127.0.0.54:53               0.0.0.0:*
tcp      LISTEN       0         511                127.0.0.1:45767            0.0.0.0:*         users:(("code",pid=30789,fd=38))
tcp      LISTEN       0         4096           127.0.0.53%lo:53               0.0.0.0:*
tcp      TIME-WAIT    0         0                  127.0.0.1:8989           127.0.0.1:39504
tcp      TIME-WAIT    0         0                  127.0.0.1:8989           127.0.0.1:39500
tcp      TIME-WAIT    0         0                  127.0.0.1:8989           127.0.0.1:39532
tcp      TIME-WAIT    0         0                  127.0.0.1:8989           127.0.0.1:39548
tcp      TIME-WAIT    0         0                  127.0.0.1:8989           127.0.0.1:39550
tcp      TIME-WAIT    0         0                  127.0.0.1:8989           127.0.0.1:39518
tcp      TIME-WAIT    0         0                  127.0.0.1:8989           127.0.0.1:39486
tcp      LISTEN       0         4096                   [::1]:631                 [::]:*

```

```
cat /proc/<PID>/net/tcp

sl  local_address rem_address   st tx_queue rx_queue tr tm->when retrnsmt   uid  timeout inode                                                     
0: 0100007F:A955 00000000:0000 0A 00000000:00000000 00:00000000 00000000  1000        0 61495 1 0000000000000000 100 0 0 10                    
1: 00000000:231D 00000000:0000 0A 00000000:00000000 00:00000000 00000000  1000        0 1589886 1 0000000000000000 100 0 0 10 0                   
2: 3600007F:0035 00000000:0000 0A 00000000:00000000 00:00000000 00000000   989        0 16720 1 0000000000000000 100 0 0 10 5                     
3: 0100007F:0277 00000000:0000 0A 00000000:00000000 00:00000000 00000000     0        0 1375162 1 0000000000000000 100 0 0 10 0                   
4: 0100007F:84EB 00000000:0000 0A 00000000:00000000 00:00000000 00000000  1000        0 59647 1 0000000000000000 100 0 0 10 0                     
5: 3500007F:0035 00000000:0000 0A 00000000:00000000 00:00000000 00000000   989        0 16718 1 0000000000000000 100 0 0 10 5                     
6: 0964A8C0:DA0E 1A72528C:01BB 01 00000000:00000000 02:00000046 00000000  1000        0 1645210 2 0000000000000000 26 4 31 2 2                    
```

```
cat /proc/792765/net/protocols
protocol  size sockets  memory press maxhdr  slab module     cl co di ac io in de sh ss gs se re bi br ha uh gp em
RFCOMM     896      0      -1   NI       0   no   rfcomm      n  n  n  n  n  n  n  n  n  n  n  n  n  n  n  n  n  n
QIPCRTR    832      0      -1   NI       0   yes  qrtr        n  n  n  n  n  n  n  n  n  n  n  n  n  n  n  n  n  n
ALG        840      0      -1   NI       0   no   af_alg      n  n  n  n  n  n  n  n  n  n  n  n  n  n  n  n  n  n
BNEP       864      0      -1   NI       0   no   bnep        n  n  n  n  n  n  n  n  n  n  n  n  n  n  n  n  n  n
SCO        904      0      -1   NI       0   no   bluetooth   n  n  n  n  n  n  n  n  n  n  n  n  n  n  n  n  n  n
L2CAP      888      0      -1   NI       0   no   bluetooth   n  n  n  n  n  n  n  n  n  n  n  n  n  n  n  n  n  n
HCI        944      0      -1   NI       0   no   bluetooth   n  n  n  n  n  n  n  n  n  n  n  n  n  n  n  n  n  n
PACKET    1664      3      -1   NI       0   no   kernel      n  n  n  n  n  n  n  n  n  n  n  n  n  n  n  n  n  n
MPTCPv6   2144      0     126   no       0   yes  kernel      y  y  y  n  y  y  y  y  y  y  y  y  n  n  y  y  y  n
PINGv6    1408      0      -1   NI       0   yes  kernel      y  y  y  n  n  y  n  n  y  y  y  y  y  y  n  y  y  n
RAWv6     1408      1      -1   NI       0   yes  kernel      y  y  y  n  y  y  y  n  y  y  y  y  y  y  y  y  n  n
UDPLITEv6 1472      0    1310   NI       0   yes  kernel      y  y  y  n  y  y  y  n  y  y  y  y  n  n  y  y  y  n
UDPv6     1472      7    1310   NI       0   yes  kernel      y  y  y  n  y  y  y  n  y  y  y  y  n  n  y  y  y  n
TCPv6     2560      1     126   no     320   yes  kernel      y  y  y  y  y  y  y  y  y  y  y  y  n  y  y  y  y  y
XDP       1088      0      -1   NI       0   no   kernel      n  n  n  n  n  n  n  n  n  n  n  n  n  n  n  n  n  n
UNIX-STREAM 1152   1045      -1   NI       0   yes  kernel      y  n  n  n  n  n  n  n  n  n  n  n  n  n  n  n  n  n
UNIX      1152     90      -1   NI       0   yes  kernel      y  n  n  n  n  n  n  n  n  n  n  n  n  n  n  n  n  n
UDP-Lite  1344      0    1310   NI       0   yes  kernel      y  y  y  n  y  y  y  n  y  y  y  y  n  n  y  y  y  n
MPTCP     2016      0     126   no       0   yes  kernel      y  y  y  n  y  y  y  y  y  y  y  y  n  n  y  y  y  n
PING      1056      0      -1   NI       0   yes  kernel      y  y  y  n  n  y  n  n  y  y  y  y  y  y  n  y  y  n
RAW       1216      0      -1   NI       0   yes  kernel      y  y  y  n  y  y  y  n  y  y  y  y  y  y  y  y  n  n
UDP       1344     13    1310   NI       0   yes  kernel      y  y  y  n  y  y  y  n  y  y  y  y  n  n  y  y  y  n
TCP       2432      8     126   no     320   yes  kernel      y  y  y  y  y  y  y  y  y  y  y  y  n  y  y  y  y  y
MCTP       872      0      -1   NI       0   no   kernel      y  n  n  n  n  y  n  n  n  n  n  n  n  n  y  y  n  n
NETLINK   1120     73      -1   NI       0   no   kernel      n  n  n  n  n  n  n  n  n  n  n  n  n  n  n  n  n  n
```

```
cat /proc/792765/net/sockstat

sockets: used 1275
TCP: inuse 9 orphan 0 tw 0 alloc 10 mem 127
UDP: inuse 13 mem 1310
UDPLITE: inuse 0
RAW: inuse 0
FRAG: inuse 0 memory 0
```

# To monitor the traffic just localhost 
```
 sudo iftop -i lo
```
# Checking active sockets
```
 ss -tupn

bext@bext-G3-3779:~$ ss -tupn
Netid   State    Recv-Q    Send-Q                                  Local Address:Port                 Peer Address:Port   Process                                
udp     ESTAB    0         0                                  192.168.100.9%wlo1:68                  192.168.100.1:67                                            
tcp     ESTAB    0         0                                       192.168.100.9:58082               20.184.175.10:443     users:(("code",pid=30604,fd=26))      
tcp     ESTAB    0         0                                       192.168.100.9:52560              138.91.182.224:443     users:(("code",pid=30604,fd=28))      
tcp     ESTAB    0         0                                       192.168.100.9:50214               34.107.243.93:443     users:(("firefox",pid=36738,fd=50))   
u
tcp     ESTAB    0         0            [2806:2f0:5160:fa94:7e30:6369:b405:21fb]:57892       [2603:1061:14:105::1]:443     users:(("code",pid=30604,fd=27)) 
```
# To Monitor the Threads of a process

```
ps -o nlwp= -p <PID>
```   
or
```
ps -T -p <PID>
```   
or
```
grep '^Threads:' /proc/<PID>/status
```
or
```
top -H -p <PID>
```
or
```
watch -n 1 ps -o thcount= -p <PID>
```

## View Current limits
```
ulimit -n         //show the current soft limit
ulimit -Hn        //show the hard limit, maximim ceiling you can reach without root access
ulimit -Sn        //show the soft limit, what the kernel enforces by default
```
# Configuring Limits in Limits.conf
```
/etc/security/limits.conf
hard nofile 65535
soft nofile 65536
```

# configuring server for max connctions

int listen(int sockfd, int backlog) which is in lib.c, uses backlog to configure the max connections
but if is less than /proc/sys/net/core/somaxconn, the kernel takes the greater, by default is 4096.
To change the /proc/sys/net/core/somaxconn then


```
cat /proc/sys/net/core/somaxconn
4096  
```

```
sudo sysctl -w net.core.somaxconn=1024   
```

```
echo "net.core.somaxconn = 1024" | sudo tee -a /etc/sysctl.conf
sudo sysctl -p   
```
# Ubuntu 启动耗时分析

## Ubuntu 16.04 desktop 正常启动

启动总耗时35.72s， 其中**Network-wait-online.service**耗时31.48s，是系统启动过程中的主要耗时。下一步采用禁用Ubuntu的NetworkManager，采用networking.service进行优化

## 禁用NetworkManager

启动总耗时14.72s，优化效果明显，不过，在启动过程中，网络的耗时任然达到7s左右，在实际的生产环境中是不需要链接网络的，下一步将网络服务关掉进行测试.

### 具体操作

执行如下命令，编辑网络配置文件
```
$ sudo vi /etc/network/interface
```
加入以下配置信息
```
auto lo
iface lo inet loopback

auto wlan0
# 静态IP
iface wlan0 inet static
# 掩码
netmask 255.255.255.0
# 网段
network 192.168.10.0
# 广播地址
broadcask 192.168.10.255
# 网关
gateway 192.168.10.1
# IP
address 192.168.10.33
# DNS server
dns-nameservers 192.168.10.5
# WiFi name
wpa-ssid Zodiac
# WIFI password
wpa-psk Tx261010
```
配置DNS，配置 /etc/resolv.conf 文件
```
$ sudo rm /etc/resolv.conf
$ sudo vi /etc/resolv.conf
```
写入DNS的配置信息
```
nameserver 192.168.10.5
```
禁用NetworkManager开机自启
```
systemctl disable NetworkManager.service
```
重启系统，Ubuntu就会禁用NetworkManager，
## 禁用网络

启动总耗时8.72s，其中图形界面是server不需要的，下一步将Ubuntu的default-target设为multi-user.target,进行进一步优化。
```
systemctl disable networking.service
```

## 禁用图形界面

内核启动时间下降为3秒左右，总启动时间达到5秒，基本达到要求。
```
systemctl set-default multi-user.target
```

## 使用单用户模式

使用root用户登录，内核只启动必要服务（具体哪些没注意），启动时间大概在2秒左右。
```
systemctl set-default rescue.target
```

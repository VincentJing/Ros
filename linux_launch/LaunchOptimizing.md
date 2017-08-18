# Ubuntu 启动耗时分析

## Ubuntu 16.04 desktop 正常启动

启动总耗时35.72s， 其中**Network-wait-online.service**耗时31.48s，是系统启动过程中的主要耗时。下一步采用禁用Ubuntu的NetworkManager，采用networking.service进行优化

## 禁用NetworkManager

启动总耗时14.72s，优化效果明显，不过，在启动过程中，网络的耗时任然达到7s左右，在实际的生产环境中是不需要链接网络的，下一步将网络服务关掉进行测试，

## 禁用网络

启动总耗时8.72s，其中图形界面是server不需要的，下一步将Ubuntu的default-target设为multi-user.target,进行进一步优化。

## 禁用图形界面

内核启动时间下降为3秒左右，总启动时间达到5秒，基本达到要求。

## 使用单用户模式

使用root用户登录，内核只启动必要服务（具体哪些没注意），启动时间大概在2秒左右。

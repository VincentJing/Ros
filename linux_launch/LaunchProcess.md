让我们看一下Linux系统在使用systemd作为引导程序时的开机启动过程的结构性细节。为了简单，我们将在下面按步骤列出来这个过程：

1. 当你打开电源后电脑所做的第一件事情就是BIOS初始化。BIOS会读取引导设备设定，定位并传递系统控制权给MBR（假设硬盘是第一引导设备）。

2. MBR从Grub或LILO引导程序读取相关信息并初始化内核。接下来将由Grub或LILO继续引导系统。如果你在grub配置文件里指定了systemd作为引导管理程序，之后的引导过程将由systemd完成。Systemd使用“target”来处理引导和服务管理过程。这些systemd里的“target”文件被用于分组不同的引导单元以及启动同步进程。

3. systemd执行的第一个目标是default.target。但实际上default.target是指向graphical.target的软链接。Linux里的软链接用起来和Windows下的快捷方式一样。文件Graphical.target的实际位置是/usr/lib/systemd/system/graphical.target。在下面的截图里显示了graphical.target文件的内容。

4. 在这个阶段，会启动multi-user.target而这个target将自己的子单元放在目录“/etc/systemd/system/multi-user.target.wants”里。这个target为多用户支持设定系统环境。非root用户会在这个阶段的引导过程中启用。防火墙相关的服务也会在这个阶段启动。
"multi-user.target"会将控制权交给另一层“basic.target”。

5. "basic.target"单元用于启动普通服务特别是图形管理服务。它通过/etc/systemd/system/basic.target.wants目录来决定哪些服务会被启动，basic.target之后将控制权交给sysinit.target.

6. "sysinit.target"会启动重要的系统服务例如系统挂载，内存交换空间和设备，内核补充选项等等。sysinit.target在启动过程中会传递给local-fs.target。这个target单元的内容如下面截图里所展示。

7. local-fs.target，这个target单元不会启动用户相关的服务，它只处理底层核心服务。这个target会根据/etc/fstab和/etc/inittab来执行相关操作。

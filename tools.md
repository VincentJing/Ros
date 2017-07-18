# catkin_cmake常用工具
>* 3D可视化工具：RVIZ
>>

>* 记录和可视化数据
>>* rosbag<br>
  rosbag&nbsp;recor&nbsp;-a<br>
  录入所有的话题上传的消息到本文件夹<br>
  rosbag&nbsp;record&nbsp;-O&nbsp;subset&nbsp;/turtle1/cmd_vel&nbsp;/turtle1/pose<br>
  录入上述两个话题上传的信息到本文件中<br>
  rosbag&nbsp;info&nbsp;<your&nbsp;bagfile><br>
  查看某个文件夹的信息<br>
  rosbag&nbsp;play&nbsp;[-r]&nbsp;n&nbsp;&nbsp;<your&nbsp;bagfile><br>
  [以一定的速率]回放录入的信息<br>
>>* rqt_bag<br>
    完成上面功能的图形化工具。
>* 生命线
>>rqt_plot<br>
    $&nbsp;rosrun&nbsp;rqt_plot&nbsp;rqt_plot<br>
    显示实时的数据。

>* 系统可视化
>>rqt_graph<br>
  $&nbsp;rosrun&nbsp;rqt_grap&nbsp;hrqt_graph<br>
  查看目前的消息和主题

>* 命令行工具
>>* 运行ROS系统<br>
  $&nbsp;roslaunch<br>
  运行.launch文件，可同时启动多个节点<br>
  $&nbsp;rosrun<br>
  运行单个节点<br>
  $&nbsp;roscore<br>
  启动节点管理器，ros系统的核心,每次运行前需要启动<br>
>>* 交互和调试运行ROS系统<br>
>>>* 使用rostopic:<br>
     	rostopic&nbsp;bw&nbsp;主题&nbsp;&nbsp;//显示该主题的带宽<br>
     	rostopic&nbsp;echo&nbsp;主题&nbsp;//在dos中打印在该主题上的数据<br>
     	rostopic&nbsp;hz&nbsp;主题&nbsp;//显示该主题发布者发布的频率<br>
     	rostopic&nbsp;list&nbsp;//显示此时活跃的主题<br>
     	rostopic&nbsp;list&nbsp;-v&nbsp;//显示所有的主题<br>
     	rostopic&nbsp;list&nbsp;-p&nbsp;//显示有发布者的主题<br>
     	rostopic&nbsp;list&nbsp;-s&nbsp;//显示有订阅者的主题<br>
     	rostopic&nbsp;pub&nbsp;-n&nbsp;主题&nbsp;&nbsp;消息类型&nbsp;&nbsp;--消息&nbsp;//发送数据到该主题上
     	eg.&nbsp;$&nbsp;rostopic&nbsp;pub&nbsp;-n(次数)&nbsp;/turtle1/cmd_vel&nbsp;geometry_msgs/Twist&nbsp;--&nbsp;'[2.0,0.0,0.0]'&nbsp;'[0.0,0.0,1.8]'<br>
     	rostopic&nbsp;type&nbsp;主题&nbsp;//显示主题上消息的类型<br>
     	eg.&nbsp;$&nbsp;rosmsg&nbsp;show&nbsp;消息类型&nbsp;//显示该消息的详细数据<br>
>>>* rosservice<br>
    rosservice&nbsp;list&nbsp;&nbsp;输出可用服务的信息<br>
    rosservice&nbsp;call&nbsp;&nbsp;调用带参数的服务<br>
    rosservice&nbsp;type&nbsp;&nbsp;输出服务类型<br>
    rosservice&nbsp;find&nbsp;&nbsp;依据类型寻找服务find&nbsp;services&nbsp;by&nbsp;service&nbsp;type<br>
    rosservice&nbsp;uri&nbsp;&nbsp;输出服务的ROSRPC&nbsp;uri<br>
    @1&nbsp;先用rosservice&nbsp;list-->列出所有的服务<br>
    @2&nbsp;使用rosservice&nbsp;type服务名-->得到服务类型<br>
    @3&nbsp;使用rossrv&nbsp;show服务类型-->服务的参数形式<br>
    @4&nbsp;使用rosservice&nbsp;call服务名&nbsp;参数&nbsp;调用服务<br>
>>>* 使用rosnode
     	rosnode&nbsp;info&nbsp;//显示一个节点的消息<br>
     	rosnode&nbsp;kill&nbsp;//杀死正在运行的节点<br>
     	rosnode&nbsp;list&nbsp;//列出所有活动的节点<br>
     	rosnode&nbsp;machine&nbsp;//列出运行节点的机器<br>
     	rosnode&nbsp;ping&nbsp;//测试与节点连接性<br>
     	rosnode&nbsp;cleanup&nbsp;//清楚无法到达的节点<br>
>>>* rosmsg<br>
    rosmsg&nbsp;show&nbsp;//显示消息的描述
    rosmsg&nbsp;users&nbsp;//找到用到该消息的文件（kinetic好像没有）
    rosmsg&nbsp;md5&nbsp;//显示该消息的MD5消息和
    rosmsg&nbsp;package&nbsp;//列出某一个包中的所有消息
    rosmsg&nbsp;packages&nbsp;//列出包含该消息的所有的包
>>>* rossrv<br>
    rossrv&nbsp;show&nbsp;//显示服务的描述<br>
>>>* 使用rosparam<br>	
     	rosparam&nbsp;set&nbsp;//设置参数<br>
     	rosparam&nbsp;get&nbsp;//获取参数<br>
     	rosparam&nbsp;load&nbsp;//从文件读取参数<br>
     	rosparam&nbsp;dump&nbsp;//向文件中写入参数<br>
     	rosparam&nbsp;delete&nbsp;//删除参数<br>
     	rosparam&nbsp;list&nbsp;//列出参数名<br>
     @1&nbsp;使用rosparam&nbsp;list获取参数名称列表<br>
     @2&nbsp;使用rosparam&nbsp;set/get进行设置和获取参数值<br>
     @3&nbsp;编写.yaml文件进行设置、或者直接将参数值加载到.yaml文件中。<br>
>>>* roswtf<br>
    对系统进行检查。
>>>* 使用rqt_console和rqt_logger_level<br>
    rqt_console属于ROS日志框架(logging&nbsp;framework)的一部分，用来显示节点的输出信息。<br>
    rqt_logger_level允许我们修改节点运行时输出信息的日志等级(logger&nbsp;levels)&nbsp;(包括DEBUG、WARN、INFO和ERROR）。<br>
>>* 安装、编译、文件系统工具<br>
>>>* rosmake编译
    类似catkin_make,rosmake需要加待编译的包<br>
>>>* rosinstall<br>
    从源文件安装
>>>* roslocate<br>
            info&nbsp;//Get&nbsp;rosinstall&nbsp;info&nbsp;of&nbsp;resource<br>
            vcs&nbsp;//Get&nbsp;name&nbsp;of&nbsp;source&nbsp;control&nbsp;system<br>
            type&nbsp;//Package&nbsp;or&nbsp;stack<br>
            uri&nbsp;//Get&nbsp;source&nbsp;control&nbsp;URI&nbsp;of&nbsp;resource<br>
            www&nbsp;//Get&nbsp;web&nbsp;page&nbsp;of&nbsp;resource<br>
            repo&nbsp;//Get&nbsp;repository&nbsp;name&nbsp;of&nbsp;resource<br>
            describe&nbsp;//Get&nbsp;description&nbsp;of&nbsp;resource<br>
>>>* rosdep<br>
    安装系统依赖
>>>* rosstack(包的集合)<br>
    是一个用于检索文件系统上可用的ROS堆栈信息的命令行工具。它实现了各种命令，从定位文件系统中的ROS堆栈到列出可用的堆栈，以计算堆栈的依赖关系树。它也用于ROS构建系统中用于计算堆栈的构建信息。
>>>* rospack<br>
    是一个用于检索文件系统上可用的ROS包的信息的命令行工具。它实现了各种各样的命令，从定位文件系统中的ROS包，列出可用的包，以计算包的依赖关系树。它也用于ROS构建系统中用于计算软件包的构建信息	


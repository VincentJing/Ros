ros一些常用命令
---
>ros中主要的通信手段:话题、服务<br>
>>话题：发布者（pub）、订阅者（sub）<br>
>>>发布者(pub)<br>
>>>>完整的发布节点<br>
    1、初始化与节点申明：<br>
    int&main(int&argc,char**&argv){<br>
    ...<br>
    ros::init(argc,argv,"test1");<br>
    ros::NodeHandle&n;<br>
    ...<br>
    }<br>
    2、申明发布者并向特定话题发布消息：<br>
    @param&message_type:消息类型
    @param&topic:发布话题的名称<br>
    @param&queue_size:该话题消息队列的大小（当订阅者的频率小于发布者的频率时，能存储的量）<br>
    @param&latch:该值为true时，该话题上一个发布的消息将会被新连接的订阅者收听到<br>
    ros::Publisher&pub=n.advertise<message_type>(const&std::string&&topic,uint32_t&queue_size,bool&latch=false)<br>
    相同参数和上面一样<br>
    @param&connect_cb:该话题上有订阅者连接时，回调该函数<br>
    @param&disconnect_cb:该话题有订阅者断开连接时，回调该函数<br>
    @param&tracked_object:指向要追踪这些回调函数的共享指针记录记录次数<br>
    ros::Publisher&pub=n.advertise<message_type>advertise(const&std::string\&&topic,uint32_t&queue_size,const&SubscriberStatusCallback\&&connect_cb,const&SubscriberStatusCallback\&&disconnect_cb=SubscriberStatusCallback(),const&VoidConstPtr\&&tracked_object=VoidConstPtr(),bool&latch=false)<br>
    3、发布相应的消息<br>
    申明相应的消息类型msg<br>
    ...<br>
    pub.publish(msg);<br>
    ...<br>
    
>>>订阅者(sub)<br>
>>>>完整的订阅节点<br>
>>>>1、初始化与节点申明(同上)<br>
    2、申明订阅者并订阅特定话题<br>
       相同的同上<br>
       @param&void(T::*fp)(M):回调函数（当订阅的话题上有消息时就会调用该函数，一般该函数的参数为消息类型的常量）<br>
       @param&T\*&obj:
       @param&transport_hints:
       ros::Subscriber&sub=n.subscribe(const&std::string\&&topic,uint32_t&queue_size,void(T::*fp)(M),T\*&obj,const&TransportHints\&&transport_hints=TransportHints())<br>
       使用ros::spin（）或者ros::spinOnce（）进入循环监听<br>
    3、编写回调函数<br>
    
>>服务：客户端（client）和服务端(server)<br>
>>>服务端（server）：<br>
    1、初始化和节点申明（同上）<br>
    2、申明服务服务端订阅并申明特定服务<br>
       @param&service:申明服务的名字<br>
       @param&srv_func:实现该服务的函数,当有消息到时，调用<br>
       ros::ServiceServer&service=n.advertiseService(const&std::string\&&service,bool(*srv_func)(ServiceEvent<MReq,MRes>&))<br>
       @param&tracked_object:指向要追踪这些回调函数的共享指针,如果引用次数为了0则不调用回调函数<br>
       ros::ServiceServer&service=n.advertiseService(const&std::string\&&service,const&boost::function<bool(MReq&,MRes&)>\&&callback,const&VoidConstPtr\&&tracked_object=VoidConstPtr())<br>
    3、编写回调函数<br>
>>>客户端(client):<br>
    1、初始化和节点申明（同上）<br>
    2、申明服务客户端并申明调用特定的服务<br>
       @param&message_type:作为服务的消息类型，请求值和返回值.<br>
       @param&service_name:申明调用特定服务的名字<br>
       @param&persistent:是否持续,持续的话，在之后的调用会比较快，但是没有非持续性的鲁棒性好<br>
       @param&header_values:在连接时握手时是否需要发送键值对<br>
       ros::ServiceClient&client=n.serviceClient<message_type>(const&std::string\&&service_name,bool&persistent=false,const&M_string\&&header_values=M_string())<br>
    3、设置服务消息类型的请求值，并进行服务调用.<br>
       client.call(const&std::string\&&service_name,Service\&&service)<br>
       client.call(const&std::string\&&service_name,MReq\&&req,MRes\&&res)<br>
        

>>常用的指令<br>
关于消息接收回调机制的原理是这样的：除了用户的主程序以外，ROS的socket连接控制进程会在后台接收订阅的消息，所有接收到的消息并不是立即处理，而是等到spin()或者spinOnce()执行时才集中处理。<br>
>>>ROS消息回调处理函數,因此对于二者而言，只有在有回调函数的情况下才有用<br>
>>>>ros::spin()<br>
    程序进入无限循环，每当有消息到达时调用关于消息接收回调机制的原理是这样的：除了用户的主程序以外，ROS的socket连接控制进程会在后台接收订阅的消息，所有接收到的消息并不是立即处理，而是等到spin()或者spinOnce()执行时才集中处理。回调函数<br>
>>>>ros::spinOnce()<br>
    每次进行一次，常与ros::Rate配合使用，并且如果想循环监听，需要将其放入一个循环中调用<br>
>>>ros::Rate&loop_rate(n)<br>
    设置循环的频率，与Rate.sleep()配合使用.<br>
>>>ros::Rate.sleep()<br>
    按照Rate设置的频率，进行调控,使循环过程中执行的次数满足设定频率的要求<br>
>>>ros::Time（）计算时间<br>
>>>
    
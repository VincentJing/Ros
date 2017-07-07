Build Process Guideline
---
CMake
---
>CMake介绍：
>> CMake是一个跨平台的安装（编译）工具，可以用简单的语句来描述所有平台的安装(编译过程)。他能够输出各种各样的makefile或者project文件，能测
>> 试编译器所支持的C++特性,类似UNIX下的automake。只是CMake的组态档取名为CMakeLists.txt。Cmake并不直接建构出最终的软件，而是产生标准的
>> 建构档（如Unix的Makefile或Windows Visual C++的projects/workspaces），然后再依一般的建构方式使用。

>CMake工作大致流程
>> * 运行cmake根检测编译环境，并生成相应的makefile。（根据CMakeLists.txt）。
>> * 运行make进行编译（根据makefile）。
>> * 运行make install安装到相应的目录下。

>CMakeLists.txt
>> * 有工作流程可知其核心为如何编写CMakeLists.txt。
>> * CMakeLists.txt的编写是根据目录结构和源程序的各种依赖或其他情况。
>> * CMakeLists.txt中常用的命名。

>>>> * project<br>
         project(PROJECTNAME [CXX] [C] [JAVA])<BR>
         指定工程名称,并可指定工程支持的语言。支持语言列表可忽略,默认支持所有语言<br>
>>>> * set<br>
         set(VAR [VALUE] [CACHE TYPE DOCSTRING [FORCE]])<BR>
       定义变量(可以定义多个VALUE,如SET(SRC_LIST MAIN.C UTIL.C REACTOR.C))<BR>
>>>> * message<br>
         message([SEND_ERROR | STATUS | FATAL_ERROR] “message to display” …)<br>
       向终端输出用户定义的信息或变量的值<br>
       SEND_ERROR, 产生错误,生成过程被跳过<br>
       STATUS, 输出前缀为—的信息<br>
       FATAL_ERROR, 立即终止所有cmake过程<br>
>>>> * add_executable<br>
         add_executable(bin_file_name ${SRC_LIST})<br>
       生成可执行文件<br>
>>>> * add_library<br>
       add_library(libname [SHARED | STATIC | MODULE] [EXCLUDE_FROM_ALL] SRC_LIST)<br>
       生成动态库或静态库<br>
       SHARED 动态库<br>
       STATIC 静态库<br>
       MODULE 在使用dyld的系统有效,若不支持dyld,等同于SHARED<br>
       EXCLUDE_FROM_ALL 表示该库不会被默认构建<br>
>>>> * set_target_properties<br>
       设置输出的名称,设置动态库的版本和API版本<br>
>>>> * cmake_minimum_required<br>
       cmake_minimum_required(VERSION version_number [FATAL_ERROR])<br>
       声明CMake的版本要求<br>
>>>> * add_subdirectory<br>
       add_subdirectory(src_dir [binary_dir] [EXCLUDE_FROM_ALL])<br>
       向当前工程添加存放源文件的子目录,并可以指定中间二进制和目标二进制的存放位置<br>
       EXCLUDE_FROM_ALL含义：将这个目录从编译过程中排除<br>
       (hello sample)相当于分别写add_subdirectory(hello),add_subdirectory(sample)<br>
>>>> * include_directories<br>
       include_directories([AFTER | BEFORE] [SYSTEM] dir1 dir2 …)<br>
       向工程添加多个特定的头文件搜索路径,路径之间用空格分隔,如果路径包含空格,可以使用双引号将它括起来,默认的行为为追加到当前头文<br>
       件搜索路径的后面。有如下两种方式可以控制搜索路径添加的位置：<br>
       CMAKE_INCLUDE_DIRECTORIES_BEFORE,通过SET这个cmake变量为on,可以将添加的头文件搜索路径放在已有路径的前面<br>
       通过AFTER或BEFORE参数,也可以控制是追加还是置前<br>
>>>> * link_directories<br>
       link_directories(dir1 dir2 …)<br>
       添加非标准的共享库搜索路径<br>
>>>> * target_link_libraries<br>
       target_link_libraries(target lib1 lib2 …)<br>
       为target添加需要链接的共享库<br>
>>>> * add_definitions<br>
       向C/C++编译器添加-D定义<br>
       add_definitions(-DENABLE_DEBUG -DABC),参数之间用空格分隔<br>
>>>> * add_dependencies<br>
       add_dependencies(target-name depend-target1 depend-target2 …)<br>
       定义target依赖的其他target,确保target在构建之前,其依赖的target已经构建完毕<br>
       catkin_make中有两种情况：<br>
       (1)你所构建的包依赖需要使用message等的包<br>
       add_dependencies(some_target  ${catkin_EXPORTED_TARGETS})<br>
       (2)你所构建的包需要使用message等<br>
       add_dependencies(some_target  ${${PROJECT_NAME}_EXPORTED_TARGETS})<br>
>>>> * aux_source_directory<br>
       aux_source_directory(dir VAR)<br>
       发现一个目录下所有的源代码文件并将列表存储在一个变量中把当前目录下的所有源码文件名赋给变量DIR_HELLO_SRCS<br>
>>>> * exec_program<br>
        exec_program(Executable [dir where to run] [ARGS <args>] [OUTPUT_VARIABLE <var>] [RETURN_VALUE <value>])<br>
        用于在指定目录运行某个程序 默认为当前CMakeLists.txt所在目录）,通过ARGS添加参数,通过OUTPUT_VARIABLE和RETURN_VALUE获取输出和返回值,如下示例
>>>> * include<br>
        include(file [OPTIONAL]) 用来载入CMakeLists.txt文件<br>
        include(module [OPTIONAL])用来载入预定义的cmake模块<br>
        OPTIONAL参数的左右是文件不存在也不会产生错误<br>
        可以载入一个文件,也可以载入预定义模块（模块会在CMAKE_MODULE_PATH指定的路径进行搜索)<br>
        载入的内容将在处理到INCLUDE语句时直接执行<br>
>>>> * find_<br>
        find_file(<VAR> name path1 path2…)<br>
        VAR变量代表找到的文件全路径,包含文件名<br>
        find_library(<VAR> name path1 path2…)<br>
        VAR变量代表找到的库全路径,包含库文件名<br>
        find_program(<VAR> name path1 path2…)<br>
        VAR变量代表包含这个程序的全路径<br>
        find_package(<name> [major.minor] [QUIET] [NO_MODULE] [[REQUIRED | COMPONENTS] [componets…]])<br>
        用来调用预定义在CMAKE_MODULE_PATH下的Find<name>.cmake模块,你也可以自己定义Find<name><br>
        模块,通过SET(CMAKE_MODULE_PATH dir)将其放入工程的某个目录供工程使用<br>
        ros下find_package()需要包含（catkin()宏）如：find_package(catkin ...)<br>
>>>> * install(TARGETS targets...<br>
>>>>  [ [ ARCHIVE | LIBRARY | RUNTIME ]<br>
>>>>  [ DESTINATION < dir >]<br>
>>>>  [ PERMISSIONS permissions...]<br>
>>>>  [ CONFIGURATIONS [ Debug | Release |...] ]<br>
>>>>  [ COMPONENT < component >]<br>
>>>>  [ OPTIONAL ]
>>>>  [...])<br>
      参数中的TARGETS后面跟的就是我们通过ADD_EXECUTABLE或者ADD_LIBRARY定义的目标文件,可能是可执行二进制、动态库、静态库。
      <br>DESTINATION定义了安装的路径,如果路径以/开头,那么指的是绝对路径,这时候CMAKE_INSTALL_PREFIX其实就无效了。
      <br>如果你希望使用CMAKE_INSTALL_PREFIX来定义安装路径,就要写成相对路径,即不要以/开头,那么安装后的路径就是${CMAKE_INSTALL_PREFIX}/< destination定义的路径>
      <br>PERMISSIONS定义安装文件的权限，若本机上没有相应权限则作废
      <br>CONFIGURATIONS安装规则的配置列表


>CMake事例
>>事例一：将多个源程序整合在一起编译
>>文件目录结构如下：
    
     +--HELLO/
      |
      |--function.h
      |--function.cxx
      |--main.cxx
      |--CMakeLists.txt
>>>对应的比较简单的CMakeLists.txt如下：
           
           
           cmake_minimum_required(VERSION 3.5)
           project(test1)
           set(CMAKE_CXX_STANDARD 11)
           set(SOURCE_FILES main.cxx function.cxx)
           add_executable(test1 ${SOURCE_FILES})
           
>>>接着去当前目录执行cmake,make为了使生成中间产物与源代码分离

            cd HELLO
            mkdir build
            cd build 
            cmake ..
            make
            (make install)
>>>则其产生的目录结构如下
        
           + HELLO/
           	|
           	|--- function.h
           	|--- function.cxx
           	|--- main.cxx
           	|--- CMakeList.txt
           	|
           	/--+ build/
           	    |
           	    |--- hello.exe
        
>>事例二：将其他源文件作为库，进行编译
>>>结构目录如下

            + HELLO/
            			|
            			+--- CMakeList.txt（c1）
            			+--+ src/
            			|  |
            			|  +--- main.cxx
            			|  /--- CMakeList.txt(c2)
            			|
            			+--+ lib/
            			|  |
            			|  +--- function.h
            			|  +--- function.cxx
            			|  /--- CMakeList.txt(c3)
            			|
            			/--+ build/
    
>>>对应的比较简单的MakeLists.txt如下：
           
           (c1)
           cmake_minimum_required(VERSION 3.5)
           project(test2)
           add_subdirectory(src lib)
           
           (c2)
           cmake_minimum_required(VERSION 3.5)
           include_directories(${PROJECT_SOURCE_DIR}/lib)	  
           add_executable(hello main.cxx)
           target_link_libraries(hello libfunc)
           
           (c3)
           cmake_minimum_required(VERSION 3.5)
           add_library(libfunc [STATIC | SHARED | MODULE] function.cxx)
>>>运行和第一个事例一样。

Catkin_make
---
>根据ros官网给出的介绍以下两种表达是等价的。
>> catkin_make
>>>$ cd ~/catkin_make<br>	
>>>$ catkin_make<br>

>>cmake
>>>$ cd ~/catkin_ws<br>	
>>>$ cd src<br>
>>>$ catkin_init_workspace<br>
>>>$ cd ..<br>
>>>$ mkdir build<br>
>>>$ cd build<br>
>>>$ cmake ../src -DCMAKE_INSTALL_PREFIX=../install -DCATKIN_DEVEL_PREFIX=../devel<br>
>>>$ make<br>

>catkin_make中每个包需要CMakeLists.txt和package.xml
>>CMakeLists.txt需要按照下列流程（4、5、6、7、9与一般的不同）
>>>* 1.Required CMake Version (cmake_minimum_required)
>>>* 2.Package Name (project())
>>>* 3.Find other CMake/Catkin packages needed for build (find_package())
>>>//如果您的ROS包提供了一些Python模块，您应该创建一个setup.py文件并调用
>>>* <font color=red>4.Enable Python module support (catkin_python_setup())</font>
>>>* <font color=red>5.Message/Service/Action Generators (add_message_files(),add_service_files(),add_action_files())</font>
>>>* <font color=red>6.Invoke message/service/action generation (generate_messages())</font>
>>>//负责ros特定的配置,这也是ros包和一般包的区别
>>>* <font color=red>7.Specify package build info export (catkin_package())</font>
>>>* 8.Libraries/Executables to build (add_library()/add_executable()/target_link_libraries())
>>>* <font color=red>9.Tests to build (catkin_add_gtest())</font>
>>>* 10.Install rules (install()) 

>>package.xml
>>>最基本的标签package name,version numbers,authors,maintainers,and dependencies on other catkin packages
    
    <package>
    <name>xx</name>
    <version>xx</version>
    <description>xx</description>
    <maintainer email="fate@todo.todo">xx</maintainer>
    <license>TODO</license>
    <buildtool_depend>catkin</buildtool_depend>
    <build_depend>xx</build_depend>
    <run_depend>xx</run_depend>>
    </package>
    
>>因此对ros包进行编译安装的核心在于写好CMakeLists.txt和package.xml

ROS下的编译工作
---
#### CMakeLists.txt依赖于被编译的文件的存储路径和各种调用关系

>ros工作空间


    workspace_folder/         -- WORKSPACE
        src/                    -- SOURCE SPACE
            CMakeLists.txt        -- The 'toplevel' CMake file
            package_1/
                CMakeLists.txt
                package.xml
                include/
                    xx.h        --头文件
                src/            --放置源文件的
                    xx.cpp
                srv/            --定义服务的源文件
                    AddTwoInts.srv<br>  
                msg/            --定义消息的源文件
                    Num.msg
                action/         --定义行为的源文件
                    Action1.action<br>
                cfg/            --配置文件
                    ALMC.cfg
                ...
            package_n/
                CMakeLists.txt
                package.xml
                ...
        build/                  -- BUILD SPACE
            CATKIN_IGNORE         -- Keeps catkin from walking this directory
        devel/                  -- DEVELOPMENT SPACE (set by CATKIN_DEVEL_PREFIX)
            bin/
            etc/
            include/
            lib/
            share/
            .catkin
            env.bash
            setup.bash
            setup.sh
            ...
        install/                -- INSTALL SPACE (set by CMAKE_INSTALL_PREFIX)
            bin/
            etc/
            include/
            lib/
            share/
            .catkin             
            env.bash
            setup.bash
            setup.sh
            ... 

>CMakeLists.txt编写
>> * CMakeLists.txt编写

>>> * 申明使用CMake的最低版本号(根据你所使用的ros的版本不同而不同)<br>
    cmake_minimum_required(VERSION x.x.x)<br>
>>> * 项目的名称<br>
    project(xxx)<br>
>>> * 指明构建该包需要的package，catkin包必须包含，后面的依情况而定<br>
    find_package(catkin REQUIRED COMPONENTS roscpp rospy std_msgs message_generation)<br>
>>> * 申明对python模块的支持（可选)<br>
    
>>> * 添加过程中需要使用的messages,services,actions(没有用的可以不用添加)<br>
    #需要在package.xml中加入<build_depend>message_generation</build_depend>.<run_depend>message_runtime</run_depend><br>
    #需要在CMakeLists.xml的find_package（）中加入message_generation，在catkin_package()中添加message_runtime<br>
    #在包下的msg文件夹下生成消息Num.msg<br>
    add_message_files(<br>
        FILES<br>
        Num.msg<br>
    )<br>
    #在包下的srv文件夹下生成服务AddTwoInts.srv<br>
    add_service_files(<br>
        FILES<br>
        AddTwoInts.srv<br>
    )<br>
     #在包下的action文件夹下生成操作Action1.action<br>
     add_action_files(<br>
          FILES<br>
          Action1.action<br>
     )<br>
>>> * 调用、生成消息,服务时的所需要的依赖<br>
     generate_messages(<br>
          DEPENDENCIES<br>
          std_msgs<br>
     )<br>
>>> * 动态配置（可选）
     #在包下的cfg文件夹中生成动态配置参数（需要在catkin_package()中添加dynamic_reconfigure，package.xml run_depent,build_depent增加dynamic_reconfigure）<br>
     generate_dynamic_reconfigure_options(<br>
        cfg/DynReconf1.cfg<br>
     )<br>
>>> * catkin_package()<br>
    #catkin的特殊配置，必须在生成库文件或则可执行文件之前执行<br> 
    catkin_package(<br>
       #INCLUDE_DIRS  include           包含路径<br>
       #LIBRARIES  beginner_tutorials               项目输出的库文件<br>
       CATKIN_DEPENDS  message_runtime              这个项目调用的其他的catkin项目<br>
       #CATKIN_DEPENDS  roscpp rospy std_msgs             这个项目调用其他的cmake项目<br>
       #DEPENDS  system_lib                添加配置选项<br>
    )<br>
>>> * 编译<br>
    #添加需要引用文件的头文件<br>
    include_directories(<br>
       include   ${catkin_INCLUDE_DIRS}<br>
    )<br>
    <br>
    生成库文件<br>
    add_library(${PROJECT_NAME}   src/${PROJECT_NAME}/beginner_tutorials.cpp)<br>
    生成可执行文件<br>
    add_executable(${PROJECT_NAME}_node  src/beginner_tutorials_node.cpp)<br>
    <br>
    添加依赖依赖<br>
    #添加对其它package消息的依赖，前提是已经通过find_package()引入了这个package<br>
    add_dependencies(${PROJECT_NAME}  ${catkin_EXPORTED_TARGETS}}<br>
    #添加对本package消息的依赖<br>
    dd_dependencies(${PROJECT_NAME}  ${PROJECT_NAME}_EXPORTED_TARGETS}}<br>
    #如果满足上述两个条件则添加两个<br>
    add_dependencies(${PROJECT_NAME}  ${PROJECT_NAME}_EXPORTED_TARGETS}  ${catkin_EXPORTED_TARGETS})<br>
    <br>
    为目标申明链接库<br>
    target_link_libraries(${PROJECT_NAME}_node  ${catkin_LIBRARIES})<br>
    <br> 
    修改可执行文件的相关信息<br>
    set_target_properties(${PROJECT_NAME}_node PROPERTIES OUTPUT_NAME node PREFIX "")<br>
>>> * 测试(可选)<br>
    添加基于gtt的cpp测试目标和链接库<br>
    catkin_add_gtest(${PROJECT_NAME}-test  test/test_beginner_tutorials.cpp)<br>
    if(TARGET ${PROJECT_NAME}-test)<br>
         target_link_libraries(${PROJECT_NAME}-test ${PROJECT_NAME})<br>
    endif()<br>
    添加要由python nosetests运行的文件夹<br>
    catkin_add_nosetests(test)<br>
>>> * 安装<br>
    安装脚本<br>
    install(<br>
         PROGRAMS  scripts/my_python_script<br>
         DESTINATION   {CATKIN_PACKAGE_BIN_DESTINATION}<br>
    )<br>
    安装可执行文件或库文件<br>
    install(<br>
         TARGETS  ${PROJECT_NAME}  ${PROJECT_NAME}_node<br>
         ARCHIVE  DESTINATION  ${CATKIN_PACKAGE_LIB_DESTINATION}<br>
         LIBRARY  DESTINATION  ${CATKIN_PACKAGE_LIB_DESTINATION}<br>
         RUNTIME  DESTINATION  ${CATKIN_PACKAGE_BIN_DESTINATION}<br>
    )<br>
    安装其他文件<br>
    install(DIRECTORY  include/${PROJECT_NAME}/<br>
         DESTINATION  ${CATKIN_PACKAGE_INCLUDE_DESTINATION}<br>
         FILES_MATCHING  PATTERN "*.h"<br>
         PATTERN  ".svn" EXCLUDE<br>
    )<br>
    #Mark other files for installation (e.g. launch and bag files,etc.)<br>
    install(FILES<br>
         myfile1<br>
         myfile2<br>
         DESTINATION  ${CATKIN_PACKAGE_SHARE_DESTINATION}<br>
    )<br>

    
>> * CMakeLists.txt解析


        
        cmake_minimum_required(VERSION 2.8.3)                  --cmake最低版本2.8.3
        project(amcl)                                          --项目名称为amcl
        
        find_package(catkin REQUIRED                           --寻找一般依赖库
                COMPONENTS
                    rosbag
                    roscpp
                    tf
                    dynamic_reconfigure
                    nav_msgs
                    std_srvs
                )
        
        find_package(Boost REQUIRED)                           --查找系统依赖库   
        
        # dynamic reconfigure
        generate_dynamic_reconfigure_options(                  --动态重新配置参数
            cfg/AMCL.cfg
        )
        
        catkin_package(                                        --特殊的依赖
            CATKIN_DEPENDS
                rosbag
                roscpp
                dynamic_reconfigure
                tf
            INCLUDE_DIRS include                                
            LIBRARIES amcl_sensors amcl_map amcl_pf
        )
        
        --添加文件头文件的路径，在include下创建多个文件应该是为了防止产生冲突
        include_directories(include/amcl include/amcl/map include/amcl/sensors include/amcl/pf) 
        --添加文件头文件的路径
        include_directories(${catkin_INCLUDE_DIRS} ${Boost_INCLUDE_DIRS})
        
        --.c/.cpp生成amcl_pf库文件
        add_library(amcl_pf
                            src/amcl/pf/pf.c
                            src/amcl/pf/pf_kdtree.c
                            src/amcl/pf/pf_pdf.c
                            src/amcl/pf/pf_vector.c
                            src/amcl/pf/eig3.c
                            src/amcl/pf/pf_draw.c)
                            
        --.c/.cpp文件生成amcl_map库文件
        add_library(amcl_map
                            src/amcl/map/map.c
                            src/amcl/map/map_cspace.cpp
                            src/amcl/map/map_range.c
                            src/amcl/map/map_store.c
                            src/amcl/map/map_draw.c)
                            
        --用.cpp/.c文件生成amcl_sensors库文件
        add_library(amcl_sensors
                            src/amcl/sensors/amcl_sensor.cpp
                            src/amcl/sensors/amcl_odom.cpp
                            src/amcl/sensors/amcl_laser.cpp)
                            
        --指明amcl_sensors生成库文件的链接库为amcl_map,amcl_pf，因此amcl_map amcl_pf库文件生成在其前面说明
        target_link_libraries(amcl_sensors amcl_map amcl_pf)
        
        --用src/amcl_node.cpp生成可执行文件amcl
        add_executable(amcl  src/amcl_node.cpp)
        add_dependencies添加依赖
        
        add_dependencies(amcl amcl_gencfg)
        
        //#添加对其它package消息的依赖，前提是已经通过find_package()引入了这个package
        //add_dependencies(my_target ${catkin_EXPORTED_TARGETS})
        // # 添加对本package消息的依赖
        //add_dependencies(my_target ${${PROJECT_NAME}_EXPORTED_TARGETS})
        // 项目名字_gencfg/gencpp
        // 项目名字_generate_messages_cpp
        // 对本包消息的依赖
        // add_dependencies(amcl amcl_gencfg)
        // add_dependencies(talker beginner_tutorials_generate_messages_cpp)
        // add_dependencies(add_two_ints_server beginner_tutorials_gencpp)
        //对其他包消息的依赖
        //add_dependencies(navfn ${PROJECT_NAME}_generate_messages_cpp ${catkin_EXPORTED_TARGETS})
        
        
        --指明amcl生成库文件的链接库为amcl_map,amcl_pf
        target_link_libraries(amcl
            amcl_sensors amcl_map amcl_pf
            ${Boost_LIBRARIES}
            ${catkin_LIBRARIES}
        )
        
        --安装amcl amcl_sensors amcl_map amcl_pf，并指明二进制、库、可执行的安装路径
        install( TARGETS
            amcl amcl_sensors amcl_map amcl_pf
            ARCHIVE DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
            LIBRARY DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
            RUNTIME DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION}
        )
        
        --安装文件夹 nclude/amcl下的所有文件到指定文件下
        install(DIRECTORY include/amcl/
          DESTINATION ${CATKIN_PACKAGE_INCLUDE_DESTINATION}
        )
        
        --安装文件夹 examples/下的所有文件到指定文件下
        install(DIRECTORY examples/
            DESTINATION ${CATKIN_PACKAGE_SHARE_DESTINATION}/examples
        )
        
        --将一个软件包分解成多个逻辑单一的软件包。catkin_make特有的。
        catkin_metapackage()
       

   

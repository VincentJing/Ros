#rostest简介
rostest是roslaunch的扩展,rostest文件和roslaunch文件100%兼容
>* rostest文件的编写
>>* 编写测试节点(一般放在test/下)
>>>* 使用c++<br>
>>>>* 编写test.cpp<br>
    1、申明测试<br>
    Test(TestSuite,testCase1)<br>
    {<br>
    &nbsp;&nbsp;<test&nbsp;things&nbsp;here,calling&nbsp;EXPECT_*&nbsp;and/or&nbsp;ASSERT_*&nbsp;macros&nbsp;as&nbsp;needed>
    <br>}<br>
    2、运行申明的所有的测试<br>
     int&nbsp;main(int&nbsp;argc,char&nbsp;**argv){<br>
     &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;testing::InitGoogleTest(&argc,argv);<br>
     &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;return&nbsp;RUN_ALL_TESTS();<br>
     }<br>
>>>>* 编译运行test.cpp<br>
    需要在CMakeLists.txt中加入catkin_add_gtest(utest&nbsp;test/utest.cpp)<br>
    make test <br>
    or&nbsp;运行./bin/test/utest
>>>* 使用python<br>
>>* 节点启动文件格式<br>
    以.test或者.launch后缀结束，主要差别在于<&nbsp;test&nbsp;>&nbsp;<&nbsp;/test&nbsp;>
>>* <&nbsp;test&nbsp;>标记<br>
<&nbsp;test&nbsp;test-name="test_1_2"&nbsp;pkg="mypkg"&nbsp;type="test_1_2.cpp"&nbsp;time-limit="10.0"&nbsp;args="--test1&nbsp;--test2" />
标记最上的属性pkg、test-name、type<br>
pkg->节点所在的包<br>
test-name->测试的名字<br>
type->节点的类型，必须和可执行文件一直<br>
>>* 在CMakeLists.txt中申明rostest<br>
>>>* with&nbsp;getest<br>
    add_rostest_gtest(tests_mynode&nbsp;test/mynode.test&nbsp;src/test/test_mynode.cpp&nbsp;[&nbsp;more&nbsp;cpp&nbsp;files]&nbsp;)<br>
    target_link_libraries(tests_mynode&nbsp;[libraries&nbsp;to&nbsp;depend&nbsp;on,&nbsp;e.g.&nbsp;${catkin_LIBRARIES}])<br>
>>>* with&nbsp;unittest<br>
    if(CATKIN_ENABLE_TESTING)<br>
    &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;find_package(rostest&nbsp;REQUIRED)<br>
    &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;add_rostest(test/mytest.test)<br>
    endif()<br>
>>* 用make&nbsp;run_tests运行测试
>* 运行rostest<br>
   1、$&nbsp;make&nbsp;run_tests(运行全部测试)<br>
   2、$&nbsp;catkin_make&nbsp;run_tests<&nbsp;TAB&nbsp;><&nbsp;TAB&nbsp;>(运行单个测试)<br>
   3、$&nbsp;rostest&nbsp;test_rospy&nbsp;rospy.test&nbsp;or&nbsp;$&nbsp;rostest&nbsptest_rospy/test/rospy.test<br>
   4、rostest参数命令<br>
   --text<br>
   将默认情况下运行测试节点参数的xml文件显示在命令行，与之同时将不会再产生xml文件。<br>
   --bare(DEPRECATED)<br>
    Run rostest on a bare, gtest-compatible executable. Executable is not run within a ROS graph. 
   --bare-name(DEPRECATED)<br>
    Set test name of --bare test. Test name defaults to name of executable. This option should be set when running wrapped tests, e.g. with python. 
   --bare-limit(DEPRECATED)<br>
    Time limit for --bare executable. 
>* 可重用的测试节点(对于kinetic而言)
>>* hztest<br>
>>* paramtest<br>
>>* publishtest<br>
>* 连接到测试的节点管理器(只讨论Indigo以及其之后的版本)<br>
    1、roscore(运行节点管理器)<br>
    2、rostest&nbsp;--reuse-master&nbsp;foo_package&nbsp;foo.test<br>
    3、grep&nbsp;-r&nbsp;"Registering&nbsp;with&nbsp;master&nbsp;node"~/.ros/log/latest<br>
#rostest简介
rostest是roslaunch的扩展,rostest文件和roslaunch文件100%兼容,将一个测试给一个测试节点去跑的感觉。<br>
需要一个测试(一般放在scr/test/testnode.cpp)、一个launch文件(test/testnode.test)
>* 一般流程：<br>
    1、编写测试。<br>
    2、编写launch文件。<br>
    3、添加相关依赖。<br>
    4、在CMakeLists.txt中添rostest<br>
    5、编译、运行。
    <br>
    <br>
    文件一般的结构如下：<br>
    
    my_ros_pkg/
                CMakeLists.txt
                bin/
                build/
                msg/
                srv/
                src/
                    test/   <---gtests go there
                test/       <---rostests  go there
    
>>* 编写测试(一般放在test/下，可以使用C++借用gtest框架或者python借用unittest框架)<br>
>>>* 使用c++(rostest和gtest100%兼容)<br>
>>>>* 编写test.cpp<br>
    1、包含需要测试的对象、以及<gtest/gtest.h><br>
    2、申明所要做的测试<br>
    Test(TestSuite,testCase1)()<br>
    {<br>
    &nbsp;&nbsp;测试的消息，在需要的时候通过调用EXPECT_宏和ASSERT_宏<br>
    (EXPECT:<br>
     ASSERT:)<br>
    }<br>
    3、运行申明的所有的测试<br>
     int&nbsp;main(int&nbsp;argc,char&nbsp;**argv){<br>
     &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;testing::InitGoogleTest(&argc,argv);<br>
     &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;return&nbsp;RUN_ALL_TESTS();<br>
     }<br>
     eg.<br>
     测试math_utils/math_utils.h中的函数(该测试命名为utest.cpp)<br>
     #inlcude&nbsp;"math_utils/math_utils.h"<br>
     #inlcude&nbsp;<gtest/gtest.h><br>
     TEST(MathUtil,testcase1)<br>
     {<br>
     &nbsp;&nbsp;EXPECE_EQ/ASSERT_EQ(math_utils.function(agrc),Expected);//该函数的结果和Expected是否相等<br>
     }<br>
     int&nbsp;main(int&nbsp;argc,char&nbsp;**argv){  
     &nbsp;&nbsp;testing::InitGoogleTest(&argc,argv);<br> 
     &nbsp;&nbsp;return&nbsp;RUN_ALL_TESTS();<br>
     }<br>
     运行你的测试<br>
     在CMakeLists.txt中添加<br>
     catkin_add_gtest(utest_node&nbsp;src/test/utest.cpp)<br>
     target_link_libraries(utest_node&nbsp;${catkin_LIBRARIES})<br>
     like&nbsp;this:<br>
     cd ~/catkin_ws<br>
     catkin_make run_tests_mypackage<br>
     
>>* rostest的launch文件格式<br>
    以.test或者.launch后缀结束，与一般的launch文件基本一样，主要差别在于<&nbsp;test&nbsp;>&nbsp;<&nbsp;/test&nbsp;><br>
    eg.<br>
    <&nbsp;launch&nbsp;><br>
    &nbsp;&nbsp;&nbsp;<&nbsp;test&nbsp;&nbsp;/><br>
    <&nbsp;/launch&nbsp;><br>
>>* <&nbsp;test&nbsp;>标记<br>
<&nbsp;test&nbsp;test-name="test_1_2"&nbsp;pkg="mypkg"&nbsp;type="test_1_2.cpp"&nbsp;time-limit="10.0"&nbsp;args="--test1&nbsp;--test2" />
标记至少需要的属性pkg、test-name、type<br>
pkg->节点所在的包<br>
test-name->测试的名字<br>
type->节点的类型，必须和可执行文件一直<br>
>>* 在CMakeLists.txt中申明rostest<br>
>>>* with&nbsp;getest<br>
    add_rostest_gtest(tests_mynode&nbsp;test/mynode.test&nbsp;src/test/test_mynode.cpp&nbsp;[&nbsp;more&nbsp;cpp&nbsp;files]&nbsp;)<br>
    target_link_libraries(tests_mynode&nbsp;[libraries&nbsp;to&nbsp;depend&nbsp;on,&nbsp;e.g.&nbsp;${catkin_LIBRARIES}])<br>
    或者添加<br>
    if(CATKIN_ENABLE_TESTING)<br>
    &nbsp;&nbsp;find_package(rostest&nbsp;REQUIRED)<br>
    &nbsp;&nbsp;add_rostest_gtest(utest_node&nbsp;test/utest_launch.test&nbsp;src/test/utest.cpp)<br>
    &nbsp;&nbsp;target_link_libraries(utest_node&nbsp;${catkin_LIBRARIES})<br>
    endif()<br>
>>>* with&nbsp;unittest<br>
    if(CATKIN_ENABLE_TESTING)<br>
    &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;find_package(rostest&nbsp;REQUIRED)<br>
    &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;add_rostest(test/mytest.test)<br>
    endif()<br>
>>* 编译、运行测试
>* 运行rostest<br>
   cd ~/catkin_ws<br>
   catkin_make<br>
   catkin_make&nbsp;run_tests_mypackage<br>
   or<br>
   rostest&nbsp;mypackage&nbsp;xxx.test<br>
>* 可重用的测试节点(对于kinetic而言)
>>* hztest<br>
    测试节点在某一主题上发布的频率<br>
>>* paramtest<br>
    测试参数的值<br>
>>* publishtest<br>
    测试主题至少发布一次<br>
>* 连接到测试的节点管理器(只讨论Indigo以及其之后的版本)<br>
    1、roscore(运行节点管理器)<br>
    2、rostest&nbsp;--reuse-master&nbsp;foo_package&nbsp;foo.test<br>
    3、grep&nbsp;-r&nbsp;"Registering&nbsp;with&nbsp;master&nbsp;node"~/.ros/log/latest<br>
    将返回主节点的URL和端口号
#gtest
>* 下载安装(如有需要):<br>
  1.下载gtest<br>
>* gtest断言：<br>
    &nbsp;&nbsp;&nbsp;&nbsp;断言介绍(对于指针而言是判断是否指向同一块内存空间)<br>
    &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;ASSERT:的断言函数如果判定最终结果不满足判定输出值，将会发出&nbsp;断言失败+终止程序的结果<br>
    &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;EXPECT:的断言函数如果判断最终结果不满足判定输出值，将仅会发出&nbsp;断言失败的提示信息<br>
    &nbsp;&nbsp;&nbsp;&nbsp;基本断言：<br>
    &nbsp;&nbsp;&nbsp;&nbsp;布尔型检测:<br>
    &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;ASSERT:ASSERT_TRUE(condition);condition为布尔值，且判断其是否为真<br> 
    &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;ASSERT:ASSERT_FALSE(condition);condition为布尔值，且判断其是否为假<br>
    &nbsp;&nbsp;&nbsp;&nbsp;数值型数据检查:<br>
    &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;ASSERT_EQ(expected,actual);&nbsp;&nbsp;&nbsp;expected==actual<br>
    &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;ASSERT_NE(expected,actual);&nbsp;&nbsp;&nbsp;expected!=actual<br>
    &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;ASSERT_LT(expected,actual);&nbsp;&nbsp;&nbsp;expected小于actual<br>
    &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;ASSERT_LE(expected,actual);&nbsp;&nbsp;&nbsp;expected小于等于actual<br>
    &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;ASSERT_GT(expected,actual);&nbsp;&nbsp;&nbsp;expected大于actual<br>
    &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;ASSERT_GE(expected,actual);&nbsp;&nbsp;&nbsp;expected大于等于actual<br>
    &nbsp;&nbsp;&nbsp;&nbsp;基于字符串:<br>
    &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;ASSERT_STREQ(str1,str2);str1's&nbsp;&nbsp;content&nbsp;=&nbsp;str2's&nbsp;&nbsp;content<br>
    &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;ASSERT_STRNE(str1,str2);str1's&nbsp;&nbsp;content!&nbsp;=&nbsp;str2's&nbsp;&nbsp;content<br>
    &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;ASSERT_STRCASEEQ(str1,str2);str1's&nbsp;&nbsp;content&nbsp;=&nbsp;str2's&nbsp;&nbsp;content,ignoring&nbsp;&nbsp;characters&nbsp;&nbsp;case<br>
    &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;ASSERT_STRCASENE(str1,str2);ignoring&nbsp;&nbsp;string&nbsp;&nbsp;characters'case,str1's&nbsp;&nbsp;content&nbsp;!=&nbsp;str2's&nbsp;&nbsp;content<br>
    &nbsp;&nbsp;&nbsp;&nbsp;浮点型检查:<br>
    &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;ASSERT_FLOAT_EQ(expected,actual);<br>
    &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;ASSERT_DOUBLE_EQ(expected,actual);<br>
    &nbsp;&nbsp;&nbsp;&nbsp;异常检查:<br>
    &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;ASSERT_THROW(statement,exception_type);<br>
    &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;ASSERT_ANY_THROW(statement);<br>
    &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;ASSERT_NO_THROW(statement);<br>
    &nbsp;&nbsp;&nbsp;&nbsp;谓词断言:<br>
    &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;ASSERT_PRED1(pred1,val1);<br>
    &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;ASSERT_PRED2(pred2,val1,val2);<br>
    &nbsp;&nbsp;&nbsp;&nbsp;类型检查:<br>
>* gtest事件机制:<br>
    1.全局的,即在测试工程开始前和结束后进行.<br>
    &nbsp;&nbsp;&nbsp;第一步编写类继承testing::Environment<br>
    &nbsp;&nbsp;&nbsp;class&nbsp;FooEnvironment:public&nbsp;testing::Environment<br>
    &nbsp;&nbsp;&nbsp;{<br>
    &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;public:<br>
    &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;virtual&nbsp;void&nbsp;SetUp()<br>
    &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;{<br>
    &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;std::cout<<"Foo&nbsp;FooEnvironment&nbsp;SetUP"<<std::endl;<br>
    &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;}<br>
    &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;virtual&nbsp;void&nbsp;TearDown()<br>
    &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;{<br>
    &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;std::cout<<"Foo&nbsp;FooEnvironment&nbsp;TearDown"<<std::endl;<br>
    &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;}<br>
    &nbsp;&nbsp;&nbsp;}<br>
    &nbsp;&nbsp;&nbsp;第二步在在main函数中通过testing::AddGlobalTestEnvironment方法将事件挂进来(在初始化之前)<br>
    2.TestSuite级别的,即在某个测试套件开始前和结束后进行.<br>
    &nbsp;&nbsp;&nbsp;我们需要写一个类，继承testing::Test，然后实现两个静态方法<br>
    &nbsp;&nbsp;&nbsp;1.SetUpTestCase()方法在第一个TestCase之前执行<br>
    &nbsp;&nbsp;&nbsp;2.TearDownTestCase()方法在最后一个TestCase之后执行<br>
    3.TestCase级别的,即在某个测试用例开始前和结束后进行.
    &nbsp;&nbsp;&nbsp;我们需要写一个类，继承testing::Test，然后实现两个静态方法<br>
    &nbsp;&nbsp;&nbsp;1.SetUp()方法在每个TestCase之前执行<br>
    &nbsp;&nbsp;&nbsp;2.TearDown()方法在每个TestCase之后执行<br>
>* 参数化<br>
   1、写一个继承testing::TestWithParam<T>的类，其中T为你所测试的类型eg.&nbsp;int<br>
   2、使用TEST_P宏而不是TEST宏<br>
   3、告诉参数的范围使用INSTANTIATE_TEST_CASE_P宏;<br>
   eg.假如要测试一个判断是否为偶数的函数bool&nbsp;isEven(int&nbsp;n);<br>
   &nbsp;&nbsp;1:<br>
   &nbsp;&nbsp;class&nbsp;IsEvenTest:public::testing::TestWithParam<&nbsp;int&nbsp;><br>
   &nbsp;&nbsp;{<br>
   &nbsp;&nbsp;          
   &nbsp;&nbsp;}<br>
   &nbsp;&nbsp;2:<br>
   &nbsp;&nbsp;TEST_P(IsEvenTest,TrueReturn)<br>
   &nbsp;&nbsp;{<br>
   &nbsp;&nbsp;&nbsp;&nbsp;int&nbsp;n=GetParam();<br>
   &nbsp;&nbsp;&nbsp;&nbsp;EXPECT_TRUE(IsEvenTest(n));<br>
   &nbsp;&nbsp;}
   &nbsp;&nbsp;3:<br>
   &nbsp;&nbsp;INSTANTIATE_TEST_CASE_P(TrueReturn,IsEvenTest,testing::Values(3,5,11,23,17));<br>
   &nbsp;&nbsp;第一个参数是测试案例的前缀，可以任意取。<br>
   &nbsp;&nbsp;第二个参数是测试案例的名称，需要和之前定义的参数化的类的名称相同，如：IsEvenTest<br>
   &nbsp;&nbsp;第三个参数是可以理解为参数生成器，上面的例子使用test::Values表示使用括号内的参数。Google提供了一系列的参数生成的函数：<br>
   &nbsp;&nbsp;&nbsp;&nbsp;Range(begin,end[,step])//范围在begin~end之间，步长为step，不包括end<br>
   &nbsp;&nbsp;&nbsp;&nbsp;Values(v1,v2,...,vN)//取v1到vN<br>
   &nbsp;&nbsp;&nbsp;&nbsp;ValuesIn(container)&nbsp;and&nbsp;ValuesIn(begin,end)//从一个C类型的数组或是STL容器，或是迭代器中取值<br>
   &nbsp;&nbsp;&nbsp;&nbsp;Bool()//true和false中取值<br>
   &nbsp;&nbsp;&nbsp;&nbsp;Combine(g1,g2,...,gN)//它将g1,g2,...gN进行排列组合，g1,g2,...gN本身是一个参数生成器，每次分别从g1,g2,..gN中各取出一个值，组合成一个元组(Tuple)作为一个参数。<br>
#rostest简介
rostest是roslaunch的扩展,rostest文件和roslaunch文件100%兼容,将一个测试给一个测试节点去跑的感觉。<br>
需要一个测试(一般放在scr/test/testnode.cpp)、一个launch文件(test/testnode.test)
>* 一般流程：<br>
    1、编写测试。<br>
    2、编写launch文件。<br>
    3、在CMakeLists.txt中添rostest<br>
    4、编译、运行。
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
    Test(TestSuite,testCase1)(个人感觉这两个名字无所谓，只是便于你在查看的时候知道，一般前者为测试对象-像一个类，后者为测试对象里的测试原子-类里面具体的方法)<br>
    {<br>
    &nbsp;&nbsp;测试的消息，在需要的时候通过断言EXPECT_宏和ASSERT_宏进行测试<br>
     }<br> 
    3、运行申明的所有的测试<br>
     int&nbsp;main(int&nbsp;argc,char&nbsp;**argv){<br>
     &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;testing::InitGoogleTest(&argc,argv)//初始化;<br>
     &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;return&nbsp;RUN_ALL_TESTS()//运行你所申明的所有测试;<br>
     }<br>
     eg.<br>
     测试math_utils/math_utils.h中的函数(该测试命名为utest.cpp)<br>
     #inlcude&nbsp;"math_utils/math_utils.h"<br>
     #inlcude&nbsp;<gtest/gtest.h><br>
     TEST(MathUtil,testcase1)<br>
     {<br>
     &nbsp;&nbsp;EXPECE_EQ/ASSERT_EQ(math_utils.function(agrc),Expected);//该函数的结果和期望值Expected是否相等<br>
     }<br>
     int&nbsp;main(int&nbsp;argc,char&nbsp;**argv){  
     &nbsp;&nbsp;testing::InitGoogleTest(&argc,argv);<br> 
     &nbsp;&nbsp;return&nbsp;RUN_ALL_TESTS();<br>
     }<br>
     运行你的测试<br>
     在运行测试之前你需要在CMakeLists.txt中添加<br>
     在catkin_make(推荐)的情况下(在rosbuild的情况下rosbuild_add_gtest(utest_node&nbsp;src/test/utest.cpp))<br>
     catkin_add_gtest(utest_node&nbsp;src/test/utest.cpp)<br>
     target_link_libraries(utest_node&nbsp;${catkin_LIBRARIES})<br>
     like&nbsp;this:<br>
     cd ~/catkin_ws<br>
     catkin_make run_tests_mypackage_<TAB><br>
     
>>* rostest的launch文件格式<br>
    以.test或者.launch后缀结束，与一般的launch文件基本一样，主要差别在于<&nbsp;test&nbsp;>&nbsp;<&nbsp;/test&nbsp;><br>
    eg.<br>
    <&nbsp;launch&nbsp;><br>
    &nbsp;&nbsp;&nbsp;<&nbsp;test&nbsp;&nbsp;/><br>
    <&nbsp;/launch&nbsp;><br>
>>* <&nbsp;test&nbsp;>标记<br>
<&nbsp;test&nbsp;test-name="test_1_2"&nbsp;pkg="mypkg"&nbsp;type="test_1_2"&nbsp;time-limit="10.0"&nbsp;args="--test1&nbsp;--test2" />
标记至少需要的属性pkg、test-name、type<br>
pkg->节点所在的包<br>
test-name->测试的名字<br>
type->节点的类型，必须和add_rostest_gtest(tests_mynode_test,test/mynode.test,src/test/test_mynode.cpp)中的tests_mynode_test一致<br>
为了区别add_rostest_gtest，catkin_add_gtest生成的可执行文件最好取不同的名字比如前者加_test,后者加_node。
>>* 在CMakeLists.txt中申明rostest<br>
>>>* with&nbsp;getest<br>
    add_rostest_gtest(tests_mynode_test&nbsp;test/mynode.test&nbsp;src/test/test_mynode.cpp&nbsp;[&nbsp;more&nbsp;cpp&nbsp;files]&nbsp;)<br>
    target_link_libraries(tests_mynode&nbsp;[libraries&nbsp;to&nbsp;depend&nbsp;on,&nbsp;e.g.&nbsp;${catkin_LIBRARIES}])<br>
    或者添加<br>
    if(CATKIN_ENABLE_TESTING)<br>
    &nbsp;&nbsp;find_package(rostest&nbsp;REQUIRED)<br>
    &nbsp;&nbsp;add_rostest_gtest(utest_node_test&nbsp;test/utest_launch.test&nbsp;src/test/utest.cpp)<br>
    &nbsp;&nbsp;target_link_libraries(utest_node&nbsp;${catkin_LIBRARIES})<br>
    endif()<br>
>>>* with&nbsp;unittest<br>
    if(CATKIN_ENABLE_TESTING)<br>
    &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;find_package(rostest&nbsp;REQUIRED)<br>
    &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;add_rostest(test/mytest.test)<br>
    endif()<br>
>>* 编译、运行测试
>>>* 编译<br>
    catkin_make&nbsp;and&nbsp;catkin_make&nbsp;tests<br>
    or<br>
    catkin_make&nbsp;mypackage_test<br>
>>>* 运行<br>
    cd ~/catkin_ws<br>
    catkin_make&nbsp;run_tests<TAB><br>
    or<br>
    rostest&nbsp;mypackage&nbsp;xxx.test<br><br>
    注释:每次修改后需要重新编译一下测试节点,使用rostest才能更新.<br>
>>>* rostest介绍<br>
     rostest&nbsp;[options]&nbsp;[package]&nbsp;<filename><br>
     rostest默认情况下时：将.test文件中的节点注册到一个新的master中，而不是已运行的条件下<br>
     在此，我想说明一下的是，多用命令的help,rostest --help如下:<br>
     Options:<br>
      &nbsp;-h,&nbsp;--help//获取帮助<br>
      &nbsp;-t,&nbsp;--text//以标准输出在控制台，而不是默认的XML文件<nr>
      &nbsp;--pkgdir=PKG_DIR//包目录<br>
      &nbsp;--package=PACKAGE//包文件<br>
      &nbsp;--results-filename=RESULTS_FILENAME//测试结果文件的名字<br>
      &nbsp;--results-base-dir=RESULTS_BASE_DIR//测试结果的基本路径，具体测试的结果以PKG_DIR名为子目录<br>
      &nbsp;-r,&nbsp;--reuse-master//连接到已经存在的master上而不是新生成一个master<br>
      &nbsp;-c,&nbsp;--clear//当连接到已经存在的master上，清楚所有的参数<br>
                             


   
>>* 可重用的测试节点(对于kinetic而言)
>>>* hztest<br>
    测试节点在某一主题上发布的频率<br>
    eg.(测试主题chatter上发布的频率的是否和给定的相等)
    
    <launch>
      <node name="talker" pkg="beginner_tutorials" type="talker"/>
     
      <param name="hztest1/topic" value="chatter" />
      <param name="hztest1/hz" value="10.0" />
      <param name="hztest1/hzerror" value="0.5" />
      <param name="hztest1/test_duration" value="5.0" />
      <test test-name="hztest_test" pkg="rostest" type="hztest" name="hztest1" />
    </launch>
>>>* paramtest<br>
    测试参数的值<br>
>>>* publishtest<br>
    测试主题至少发布一次<br>
    eg.(测试主题chatter是否至少发布一次)
    
    <launch>
      <node name="talker" pkg="beginner_tutorials" type="talker"/> 
      
      <test test-name="publishtest" pkg="rostest" type="publishtest">
        <rosparam>
          topics:
            - name: chatter
              timeout: 10
              negative: False
        </rosparam>
      </test>
    </launch>
    
>>* 连接到测试的节点管理器(只讨论Indigo以及其之后的版本)<br>
    1、roscore(运行节点管理器)<br>
    2、rostest&nbsp;--reuse-master&nbsp;foo_package&nbsp;foo.test<br>
    3、grep&nbsp;-r&nbsp;"Registering&nbsp;with&nbsp;master&nbsp;node"~/.ros/log/latest<br>
    将返回主节点的URL和端口号
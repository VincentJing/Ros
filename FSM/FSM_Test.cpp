//
// Created by fate on 17-8-9.
//
#include <iostream>
#include <FSM.h>
#include <gtest/gtest.h>
#include <ros/ros.h>
#include <mobile_base_msgs/BumperEvent.h>
    int target,plan;
    FSM *fsm = new FSM();
    FSM::MobileState target_state;
    void physical_cb(const mobile_base_msgs::BumperEvent::ConstPtr& msg){
        target = msg->bumper;
    };
    void planning_cb(const mobile_base_msgs::BumperEvent::ConstPtr& msg){
        plan = msg->bumper;
        RUN_ALL_TESTS();
    }
TEST(StatusTest,CaseTest){

    //根据物理层的消息设置目标状态
    target_state = fsm->IntToStatus(target);

    ROS_INFO("previous:%s",fsm->getCurrent_State());
    ROS_INFO("target:%s",fsm->StateStr[target]);

    //判断change结果
    int ok = 1;
    //状态机更改当前状态
    ok = fsm->ChangeState(target_state);
    //获取当前状态

    if(!ok) {
        ROS_INFO("current:%s", fsm->getCurrent_State());
        char* expected = fsm->getCurrent_State();
        //比较当前状态和上层跳转的状态
        EXPECT_STREQ(expected,fsm->StateStr[plan]);
    }else{
        ROS_INFO("msg:%s", "unreachable");
        char* expected = fsm->getCurrent_State();
        //比较当前状态和上层跳转的状态
        EXPECT_EQ(1,1);
    }

}
int main(int argc,char **argv){
    testing::InitGoogleTest(&argc,argv);
    ros::init(argc,argv,"Status");
    ros::NodeHandle nh;
        //订阅物理层
    ros::Subscriber physical = nh.subscribe("/physical", 1000, physical_cb);
        //订阅上层
    ros::Subscriber planning = nh.subscribe("/planning", 1000, planning_cb);
        //初始化当前状态以及当前状态的前一个状态。

    ros::spin();

    return 1;
}

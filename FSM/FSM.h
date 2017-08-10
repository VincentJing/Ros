//
// Created by fate on 17-8-9.
//

#ifndef PROJECT_FSM_H
#define PROJECT_FSM_H

#include <string>


class FSM {

public:
    typedef enum MobileState {
        Standby = 0,
        StandbySleep = 1,
        Charge = 2,
        ChargeSleep = 3,
        AutomaticCleaning = 4,
        SweepAlongTheEdge = 5,
        FixedPointCleaning = 6,
        ReturnToCharge = 7,
        FollowMode = 8
    };
    char* StateStr[9]= {
            "Standby",
            "StandbySleep",
            "Charge",
            "ChargeSleep",
            "AutomaticCleaning",
            "SweepAlongTheEdge",
            "FixedPointCleaning",
            "ReturnToCharge",
            "FollowMode"
    };
private:
    int changed = 1;
    MobileState current_State,previous_State;
    int ChangeStateFor_Standby(MobileState target_state);
    int ChangeStateForStandbySleep(MobileState target_state);
    int ChangeStateForCharge(MobileState target_state);
    int ChangeStateForChargeSleep(MobileState target_state);
    int ChangeStateForAutomaticCleaning(MobileState target_state);
    int ChangeStateForSweepAlongTheEdge(MobileState target_state);
    int ChangeStateForFixedPointCleaning(MobileState target_state);
    int ChangeStateForReturnToCharge(MobileState target_state);
    int ChangeStateForFollowMode(MobileState target_state);
public:

    FSM();
    FSM(int m,int n);
    FSM(MobileState current_State,MobileState previous_State);
    ~FSM();
    int ChangeState(MobileState t_state);
    int ChangeState(int i);
    MobileState IntToStatus(int i);
    char* getCurrent_State();
    char* getPrevious_State();
    void  printState();
};



#endif //PROJECT_FSM_H

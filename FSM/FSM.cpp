//
// Created by fate on 17-8-9.
//

#include <FSM.h>
#include <iostream>

using namespace std;

    //初始化当前状态和前一个状态
    FSM::FSM() {
        this->current_State=Standby;
        this->previous_State=Standby;
    }
    //初始化当前状态和前一个状态
    FSM::FSM(int m, int n) {
        if(m>9||m<0||n>9||n<0){
            std::cout<<"Initialization error";
        }else {
            this->current_State = IntToStatus(m) ;
            this->current_State = IntToStatus(n);
        }
    }
    FSM::~FSM() {

    }

    /*
     * @param StateMachine 状态机的当前状态
     * @param Target_state 接受命令将要装换的状态
     *
     * @return 0代表成功，1代表失败
     * */

    //Standby状态的转换函数
    int FSM::ChangeStateFor_Standby(MobileState target_state) {
        switch (target_state) {
            case Standby:
                this->current_State = Standby;
                this->previous_State = Standby;
                break;
            case StandbySleep:
                this->previous_State = Standby;
                this->current_State = StandbySleep;
                break;
            case Charge:
                this->previous_State = Standby;
                this->current_State = Charge;
                break;
            case ChargeSleep:
                changed = 0;
                break;
            case AutomaticCleaning:
                this->previous_State = Standby;
                this->current_State = AutomaticCleaning;
                break;
            case SweepAlongTheEdge:
                this->previous_State = Standby;
                this->current_State = SweepAlongTheEdge;
                break;
            case FixedPointCleaning:
                this->previous_State = Standby;
                this->current_State = FixedPointCleaning;
                break;
            case ReturnToCharge:
                this->previous_State = Standby;
                this->current_State = ReturnToCharge;
                break;
            case FollowMode:
                this->previous_State = Standby;
                this->current_State = FollowMode;
                break;
            default:
                changed = 0;
                break;
        }
        if(changed ==0)
        {
            changed = 1;
            return 1;
        }
        return 0;
    }

    //StandbySleep状态的转换函数
    int  FSM::ChangeStateForStandbySleep(MobileState target_state) {
        switch (target_state) {
            case Standby:
                this->previous_State = StandbySleep;
                this->current_State = Standby;
                break;
            case StandbySleep:
                break;
            case Charge:
                changed = 0;
                break;
            case ChargeSleep:
                changed = 0;
                break;
            case AutomaticCleaning:
                changed = 0;
                break;
            case SweepAlongTheEdge:
                changed = 0;
                break;
            case FixedPointCleaning:
                changed = 0;
                break;
            case ReturnToCharge:
                this->previous_State = StandbySleep;
                this->current_State = ReturnToCharge;
                break;
            case FollowMode:
                changed = 0;
                break;
            default:
                changed = 0;
                break;
        }
        if(changed == 0){
            changed = 1;
            return 1;
        }
        return 0;
    }

    //Charge状态的转换函数
    int FSM::ChangeStateForCharge(MobileState target_state) {
        switch (target_state) {
            case Standby:
                this->previous_State = Charge;
                this->current_State = Standby;
                break;
            case StandbySleep:
                changed = 0;
                break;
            case Charge:
                break;
            case ChargeSleep:
                this->previous_State = Charge;
                this->current_State = ChargeSleep;
                break;
            case AutomaticCleaning:
                changed = 0;
                break;
            case SweepAlongTheEdge:
                changed = 0;
                break;
            case FixedPointCleaning:
                changed = 0;
                break;
            case ReturnToCharge:
                this->previous_State = Charge;
                this->current_State = ReturnToCharge;
                break;
            case FollowMode:
                changed = 0;
                break;
            default:
                changed = 0;
                break;
        }
        if(changed ==0)
        {
            changed = 1;
            return 1;
        }
        return 0;
    }

    //ChargeSleep状态的转换函数
    int FSM::ChangeStateForChargeSleep(MobileState target_state) {
        switch (target_state) {
            case Standby:
                this->previous_State = ChargeSleep;
                this->current_State = Standby;
                break;
            case StandbySleep:
                changed = 0;
                break;
            case Charge:
                this->previous_State = ChargeSleep;
                this->current_State = Charge;
                break;
            case ChargeSleep:
                break;
            case AutomaticCleaning:
                changed = 0;
                break;
            case SweepAlongTheEdge:
                changed = 0;
                break;
            case FixedPointCleaning:
                changed = 0;
                break;
            case ReturnToCharge:
                break;
            case FollowMode:
                changed = 0;
                break;
            default:
                changed = 0;
                break;
        }
        if(changed ==0)
        {
            changed = 1;
            return 1;
        }
        return 0;
    }

    //AutomaticCleaning状态的转换函数
    int FSM::ChangeStateForAutomaticCleaning(MobileState target_state) {
        switch (target_state) {
            case Standby:
                this->previous_State = AutomaticCleaning;
                this->current_State = Standby;
                break;
            case StandbySleep:
                changed = 0;
                break;
            case Charge:
                changed = 0;
                break;
            case ChargeSleep:
                changed = 0;
                break;
            case AutomaticCleaning:
                changed = 0;
                break;
            case SweepAlongTheEdge:
                changed = 0;
                break;
            case FixedPointCleaning:
                changed = 0;
                break;
            case ReturnToCharge:
                this->previous_State = AutomaticCleaning;
                this->current_State = ReturnToCharge;
                break;
            case FollowMode:
                changed = 0;
                break;
            default:
                changed = 0;
                break;
        }
        if(changed ==0)
        {
            changed = 1;
            return 1;
        }
        return 0;
    }

    //SweepAlongTheEdge状态的转换函数
    int FSM::ChangeStateForSweepAlongTheEdge(MobileState target_state) {
        switch (target_state) {
            case Standby:
                this->previous_State = SweepAlongTheEdge;
                this->current_State = Standby;
                break;
            case StandbySleep:
                changed = 0;
                break;
            case Charge:
                changed = 0;
                break;
            case ChargeSleep:
                changed = 0;
                break;
            case AutomaticCleaning:
                changed = 0;
                break;
            case SweepAlongTheEdge:
                break;
            case FixedPointCleaning:
                changed = 0;
                break;
            case ReturnToCharge:
                this->previous_State = SweepAlongTheEdge;
                this->current_State = ReturnToCharge;
                break;
            case FollowMode:
                changed = 0;
                break;
            default:
                changed = 0;
                break;
        }
        if(changed ==0)
        {
            changed = 1;
            return 1;
        }
        return 0;
    }

    //FixedPointCleaning状态的转换函数
    int FSM::ChangeStateForFixedPointCleaning(MobileState target_state) {
        switch (target_state) {
            case Standby:
                this->previous_State = FixedPointCleaning;
                this->current_State = Standby;
                break;
            case StandbySleep:
                changed = 0;
                break;
            case Charge:
                changed = 0;
                break;
            case ChargeSleep:
                changed = 0;
                break;
            case AutomaticCleaning:
                changed = 0;
                break;
            case SweepAlongTheEdge:
                changed = 0;
                break;
            case FixedPointCleaning:
                break;
            case ReturnToCharge:
                this->previous_State = FixedPointCleaning;
                this->current_State = ReturnToCharge;
                break;
            case FollowMode:
                changed = 0;
                break;
            default:
                changed = 0;
                break;
        }
        if(changed ==0)
        {
            changed = 1;
            return 1;
        }
        return 0;
    }

    //ReturnToCharge状态的转换函数
    int FSM::ChangeStateForReturnToCharge(MobileState target_state) {
        switch (target_state) {
            case Standby:
                this->previous_State = ReturnToCharge;
                this->current_State = Standby;
                break;
            case StandbySleep:
                changed = 0;
                break;
            case Charge:
                changed = 0;
                break;
            case ChargeSleep:
                changed = 0;
                break;
            case AutomaticCleaning:
                changed = 0;
                break;
            case SweepAlongTheEdge:
                changed = 0;
                break;
            case FixedPointCleaning:
                changed = 0;
                break;
            case ReturnToCharge:
                break;
            case FollowMode:
                changed = 0;
                break;
            default:
                changed = 0;
                break;
        }
        if(changed ==0)
        {
            changed = 1;
            return 1;
        }
        return 0;
    }

    //FollowMode状态的转换函数
    int FSM::ChangeStateForFollowMode(MobileState target_state) {
        switch (target_state) {
            case Standby:
                this->previous_State = FollowMode;
                this->current_State = Standby;
                break;
            case StandbySleep:
                changed = 0;
                break;
            case Charge:
                changed = 0;
                break;
            case ChargeSleep:
                changed = 0;
                break;
            case AutomaticCleaning:
                changed = 0;
                break;
            case SweepAlongTheEdge:
                changed = 0;
                break;
            case FixedPointCleaning:
                changed = 0;
                break;
            case ReturnToCharge:
                this->previous_State = FollowMode;
                this->current_State = ReturnToCharge;
                break;
            case FollowMode:
                break;
            default:
                changed = 0;
                break;
        }
        if(changed ==0)
        {
            changed = 1;
            return 1;
        }
        return 0;
    }

    //状态转换
    int  FSM::ChangeState(MobileState target_state) {
        int ok;
        switch (this->current_State) {
            case Standby:
                ok = ChangeStateFor_Standby(target_state);
                break;
            case StandbySleep:
                ok = ChangeStateForStandbySleep(target_state);
                break;
            case Charge:
                ok = ChangeStateForCharge(target_state);
                break;
            case ChargeSleep:
                ok = ChangeStateForChargeSleep(target_state);
                break;
            case AutomaticCleaning:
                ok = ChangeStateForAutomaticCleaning(target_state);
                break;
            case SweepAlongTheEdge:
                ok = ChangeStateForSweepAlongTheEdge(target_state);
                break;
            case FixedPointCleaning:
                ok = ChangeStateForFixedPointCleaning(target_state);
                break;
            case ReturnToCharge:
                ok = ChangeStateForReturnToCharge(target_state);
                break;
            case FollowMode:
                ok = ChangeStateForFollowMode(target_state);
                break;
            default:
                ok = 1;
                break;
        }
        return  ok ;
    }

    int  FSM::ChangeState(int i) {
        int ok;
        MobileState target_state;
        target_state = IntToStatus(i);
        switch (this->current_State) {
            case Standby:
                ok = ChangeStateFor_Standby(target_state);
                break;
            case StandbySleep:
                ok = ChangeStateForStandbySleep(target_state);
                break;
            case Charge:
                ok = ChangeStateForCharge(target_state);
                break;
            case ChargeSleep:
                ok = ChangeStateForChargeSleep(target_state);
                break;
            case AutomaticCleaning:
                ok = ChangeStateForAutomaticCleaning(target_state);
                break;
            case SweepAlongTheEdge:
                ok = ChangeStateForSweepAlongTheEdge(target_state);
                break;
            case FixedPointCleaning:
                ok = ChangeStateForFixedPointCleaning(target_state);
                break;
            case ReturnToCharge:
                ok = ChangeStateForReturnToCharge(target_state);
                break;
            case FollowMode:
                ok = ChangeStateForFollowMode(target_state);
                break;
            default:
                ok = 1;
                break;
        }
        return  ok ;
    }

    FSM::MobileState FSM::IntToStatus(int i) {
        MobileState target_state;
        switch (i) {
            case 0:
                target_state = FSM::Standby;
                break;
            case 1:
                target_state = FSM::StandbySleep;
                break;
            case 2:
                target_state = FSM::Charge;
                break;
            case 3:
                target_state = FSM::ChargeSleep;
                break;
            case 4:
                target_state = FSM::AutomaticCleaning;
                break;
            case 5:
                target_state = FSM::SweepAlongTheEdge;
                break;
            case 6:
                target_state = FSM::FixedPointCleaning;
                break;
            case 7:
                target_state = FSM::ReturnToCharge;
                break;
            case 8:
                target_state = FSM::FollowMode;
                break;
            default:
                target_state = FSM::Standby;
                break;
        }
        return target_state;
    }

    char* FSM::getCurrent_State(){
        return StateStr[(int)this->current_State];
    }

    char* FSM::getPrevious_State() {
        return StateStr[(int)this->previous_State];
    }
    void FSM::printState() {
        cout<<"previous_State:"<<getPrevious_State()<<"   "<<"current_State:"<<this->getCurrent_State()<<endl;
    }





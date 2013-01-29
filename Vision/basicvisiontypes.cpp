#include "basicvisiontypes.h"

namespace Vision {

    std::string getVFOName(VFO_ID id)
    {
        switch(id) {
        case BALL:          return "BALL";
        case GOAL_L:        return "GOAL_L";
        case GOAL_R:        return "GOAL_R";
        case GOAL_U:        return "GOAL_U";
    //    case GOAL_Y_L:      return "GOAL_Y_L";
    //    case GOAL_Y_R:      return "GOAL_Y_R";
    //    case GOAL_Y_U:      return "GOAL_Y_U";
        //case GOAL_B_L:      return "GOAL_B_L";
        //case GOAL_B_R:      return "GOAL_B_R";
        //case GOAL_B_U:      return "GOAL_B_U";
        //case BEACON_Y:      return "BEACON_Y";
        //case BEACON_B:      return "BEACON_B";
        //case BEACON_U:      return "BEACON_U";
        case FIELDLINE:     return "FIELDLINE";
        case OBSTACLE:      return "OBSTACLE";
        default:            return "INVALID";
        }
    }

    VFO_ID getVFOFromName(const std::string &name)
    {
        if(name.compare("BALL") == 0)
            return BALL;
        else if(name.compare("GOAL_L") == 0)
            return GOAL_L;
        else if(name.compare("GOAL_R") == 0)
            return GOAL_R;
        else if(name.compare("GOAL_U") == 0)
            return GOAL_U;
    //    else if(name.compare("GOAL_Y_L") == 0)
    //        return GOAL_Y_L;
    //    else if(name.compare("GOAL_Y_R") == 0)
    //        return GOAL_Y_R;
    //    else if(name.compare("GOAL_Y_U") == 0)
    //        return GOAL_Y_U;
    //    else if(name.compare("GOAL_B_L") == 0)
    //        return GOAL_B_L;
    //    else if(name.compare("GOAL_B_R") == 0)
    //        return GOAL_B_R;
    //    else if(name.compare("GOAL_B_U") == 0)
    //        return GOAL_B_U;
    //    else if(name.compare("BEACON_Y") == 0)
    //        return BEACON_Y;
    //    else if(name.compare("BEACON_B") == 0)
    //        return BEACON_B;
    //    else if(name.compare("BEACON_U") == 0)
    //        return BEACON_U;
        else if(name.compare("FIELDLINE") == 0)
            return FIELDLINE;
        else if(name.compare("OBSTACLE") == 0)
            return OBSTACLE;
        else
            return INVALID;
    }

    VFO_ID getVFOFromNum(int n) {
        switch(n) {
        case 0: return BALL;
        case 1: return GOAL_L;
        case 2: return GOAL_R;
        case 3: return GOAL_U;
        case 4: return FIELDLINE;
        case 5: return OBSTACLE;
    //    case 1: return GOAL_Y_L;
    //    case 2: return GOAL_Y_R;
    //    case 3: return GOAL_Y_U;
    //    case 4: return GOAL_B_L;
    //    case 5: return GOAL_B_R;
    //    case 6: return GOAL_B_U;
    //    case 7: return BEACON_Y;
    //    case 8: return BEACON_B;
    //    case 9: return BEACON_U;
    //    case 10: return FIELDLINE;
    //    case 11: return OBSTACLE;
        default: return INVALID;
        }
    }

    int getVFONum(VFO_ID id) {
        switch(id) {
        case BALL:          return 0;
        case GOAL_L:        return 1;
        case GOAL_R:        return 2;
        case GOAL_U:        return 3;
        case FIELDLINE:     return 4;
        case OBSTACLE:      return 5;
    //    case GOAL_Y_L:      return 1;
    //    case GOAL_Y_R:      return 2;
    //    case GOAL_Y_U:      return 3;
    //    case GOAL_B_L:      return 4;
    //    case GOAL_B_R:      return 5;
    //    case GOAL_B_U:      return 6;
    //    case BEACON_Y:      return 7;
    //    case BEACON_B:      return 8;
    //    case BEACON_U:      return 9;
    //    case FIELDLINE:     return 10;
    //    case OBSTACLE:      return 11;
        default:            return -1;
        }
    }

    std::string getColourClassName(COLOUR_CLASS id)
    {
        switch(id) {
        case BALL_COLOUR:          return "BALL_COLOUR";
        case GOAL_COLOUR:          return "GOAL_COLOUR";
    //    case GOAL_Y_COLOUR:        return "GOAL_Y_COLOUR";
    //    case GOAL_B_COLOUR:        return "GOAL_B_COLOUR";
        case LINE_COLOUR:          return "LINE_COLOUR";
        default:                   return "UNKNOWN_COLOUR";
        }
    }

    COLOUR_CLASS getColourClassFromName(const std::string& name)
    {
        if(name.compare("BALL_COLOUR") == 0)
            return BALL_COLOUR;
        else if(name.compare("GOAL_COLOUR") == 0)
            return GOAL_COLOUR;
    //    else if(name.compare("GOAL_Y_COLOUR") == 0)
    //        return GOAL_Y_COLOUR;
    //    else if(name.compare("GOAL_B_COLOUR") == 0)
    //        return GOAL_B_COLOUR;
        else if(name.compare("LINE_COLOUR") == 0)
            return LINE_COLOUR;
        else
            return UNKNOWN_COLOUR;
    }
}
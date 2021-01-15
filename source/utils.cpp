#include "utils.h"

float min(float a, float b){
    if(a > b){
        return b;
    }
    return a;
}

float max(float a, float b){
    if(a > b){
        return a;
    }
    return b;
}
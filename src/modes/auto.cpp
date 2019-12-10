#include "robot/modes/auto.hpp"

namespace Auto{

void run(){
  runAuto(routine);
}

void runAuto(const std::string& id){
  initAuto();
  for( auto&&[first, second]: routines ){
    if( first == id ){
      //running routine
      second();
    }
  }
  //error
}

std::string routine = "simpleBackward";

void initAuto(){
  if( isInitAuto == false ){//*
    routines.emplace_back(std::string("simpleBackward"), [&](){
      ;
    });

    isInitAuto = true;
  }
}

bool isInitAuto = false;

}//Auto

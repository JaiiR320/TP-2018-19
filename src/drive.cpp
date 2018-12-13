#include "main.h"

class Drive {
  void speed(double left, double right, int side){
  	if(side == 1){
  		left_front.move(left);
  		left_back.move(left);
  		right_front.move(right);
  		right_back.move(right);
  	}
    else if(side == -1){
      left_front.move(right * -1);
      left_back.move(right * -1);
      right_front.move(left * -1);
      right_back.move(left * -1);
    }
  }

  void dist(float dist, int speed){//in inches
    int encdist;
  	encdist = ((dist / 12.566) * 360);
    dist = ((encdist / 360) * 12.566);
    //encoder degrees = pathlength / circumferemce times 1 rotation
    //pathlength = encoder deg / 1 rotation times circumference

  	left_front.move_relative(dist, speed);
  	left_back.move_relative(dist, speed);
  	right_front.move_relative(dist, speed);
  	right_back.move_relative(dist, speed);
  }

  void turn(double degrees, int speed){ //Pos degrees turns right
  	double arclength = 2 * 3.1415926 * 7 * (degrees / 360);

  	double dist = (arclength / 12.566) * 360;

  	left_front.move_relative(dist, speed);
  	left_back.move_relative(dist, speed);
  	right_front.move_relative(-dist, speed);
  	right_back.move_relative(-dist, speed);
  }
} drive;

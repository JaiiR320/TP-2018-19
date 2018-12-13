#ifndef DRIVE_H
#define DRIVE_H

class Drive{
  void speed(int left, int right, int side);

  void dist(float dist, int speed);

  void turn(double degrees, int speed);
} extern drive;


#endif

#include <simple_hardware_interface.h>

int main(int argc, char **argv)
{
  // initialize ros
  ros::init(argc, argv, "simple_ros_control");
  ros::NodeHandle nh;

  SpHwInterface robot;
  controller_manager::ControllerManager cm(&robot, nh);

  // start loop
  ros::Rate rate(1.0 / robot.getPeriod().toSec());
  ros::AsyncSpinner spinner(1);
  spinner.start();

  while (ros::ok())
  {
     //robot.read();
	 robot.update();
     cm.update(robot.getTime(), robot.getPeriod());
     //robot.write();
	 
	 rate.sleep();
  }
  spinner.stop();

  return 0;
}

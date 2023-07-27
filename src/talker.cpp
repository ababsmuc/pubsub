#include "ros/ros.h"
#include "std_msgs/String.h"

#include <sstream>

int main(int argc, char **argv)
{
  /**
   * The ros::init() function needs to see argc and argv so that it can perform
   * any ROS arguments and name remapping that were provided at the command line.
   */
  ros::init(argc, argv, "talker");

  /**
   * NodeHandle is the main access point to communications with the ROS system.
   * The first NodeHandle constructed will fully initialize this node, and the last
   * NodeHandle destructed will close down the node.
   */
  ros::NodeHandle n;

  /**
   * The advertise() function is how you tell ROS that you want to
   * publish on a given topic name. 
   * The second parameter to advertise() is the size of the message queue*/
  ros::Publisher chatter_pub = n.advertise<std_msgs::String>("talker", 1000);

  ros::Rate loop_rate(10);

  int count = 0;
  while (ros::ok())
  {
    
    std_msgs::String msg;

    std::stringstream ss;
    ss << "hello ros " << count;
    msg.data = ss.str();

    ROS_INFO("%s", msg.data.c_str());

    /*The publish() function is how you send messages. The parameter*/
    chatter_pub.publish(msg);
count ++;
    ros::spinOnce();

    loop_rate.sleep();
    
  }


  return 0;
}

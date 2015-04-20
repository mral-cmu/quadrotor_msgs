#include <ros/ros.h>
#include <ipc_bridge/ipc_bridge.h>

#include <quadrotor_msgs/CascadedCommand.h>
#include <ipc_bridge/msgs/quadrotor_msgs_CascadedCommand.h>

#define NAMESPACE quadrotor_msgs
#define NAME CascadedCommand

ros::Publisher pub;
NAMESPACE::NAME out_msg;

void callback(const ipc_bridge::NAMESPACE::NAME &msg)
{
  out_msg.thrust = msg.thrust;

  out_msg.orientation.x = msg.orientation.x;
  out_msg.orientation.y = msg.orientation.y;
  out_msg.orientation.z = msg.orientation.z;
  out_msg.orientation.w = msg.orientation.w;

  out_msg.angular_velocity.x = msg.angular_velocity.x;
  out_msg.angular_velocity.y = msg.angular_velocity.y;
  out_msg.angular_velocity.z = msg.angular_velocity.z;

  out_msg.kR.x = msg.kR.x;
  out_msg.kR.y = msg.kR.y;
  out_msg.kR.z = msg.kR.z;

  out_msg.kOm.x = msg.kOm.x;
  out_msg.kOm.y = msg.kOm.y;
  out_msg.kOm.z = msg.kOm.z;

  pub.publish(out_msg);
}

#include <ipc_bridge/subscriber.h>

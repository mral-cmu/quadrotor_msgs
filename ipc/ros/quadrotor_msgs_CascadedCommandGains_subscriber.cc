#include <ros/ros.h>
#include <ipc_bridge/ipc_bridge.h>

#include <quadrotor_msgs/CascadedCommandGains.h>
#include <ipc_bridge/msgs/quadrotor_msgs_CascadedCommandGains.h>

#define NAMESPACE quadrotor_msgs
#define NAME CascadedCommandGains

ros::Publisher pub;
NAMESPACE::NAME out_msg;

void callback(const ipc_bridge::NAMESPACE::NAME &msg)
{
  out_msg.header.seq = msg.header.seq;
  out_msg.header.stamp = ros::Time(msg.header.stamp);
  if (msg.header.frame_id != 0)
    out_msg.header.frame_id = std::string(msg.header.frame_id);
  else
    out_msg.header.frame_id = std::string("");

  out_msg.kR.x = msg.kR.x;
  out_msg.kR.y = msg.kR.y;
  out_msg.kR.z = msg.kR.z;

  out_msg.kOm.x = msg.kOm.x;
  out_msg.kOm.y = msg.kOm.y;
  out_msg.kOm.z = msg.kOm.z;

  pub.publish(out_msg);
}

#include <ipc_bridge/subscriber.h>

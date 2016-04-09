#include <ros/ros.h>
#include <ipc_bridge/ipc_bridge.h>

#include <quadrotor_msgs/PositionCommandGains.h>
#include <ipc_bridge/msgs/quadrotor_msgs_PositionCommandGains.h>

#define NAMESPACE quadrotor_msgs
#define NAME PositionCommandGains

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

  out_msg.kp.x = msg.kp.x;
  out_msg.kp.y = msg.kp.y;
  out_msg.kp.z = msg.kp.z;

  out_msg.kd.x = msg.kd.x;
  out_msg.kd.y = msg.kd.y;
  out_msg.kd.z = msg.kd.z;

  pub.publish(out_msg);
}

#include <ipc_bridge/subscriber.h>

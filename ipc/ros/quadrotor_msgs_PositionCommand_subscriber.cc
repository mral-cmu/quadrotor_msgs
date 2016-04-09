#include <ros/ros.h>
#include <ipc_bridge/ipc_bridge.h>

#include <quadrotor_msgs/PositionCommand.h>
#include <ipc_bridge/msgs/quadrotor_msgs_PositionCommand.h>

#define NAMESPACE quadrotor_msgs
#define NAME PositionCommand

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

  out_msg.pos.x = msg.pos.x;
  out_msg.pos.y = msg.pos.y;
  out_msg.pos.z = msg.pos.z;

  out_msg.vel.x = msg.vel.x;
  out_msg.vel.y = msg.vel.y;
  out_msg.vel.z = msg.vel.z;

  out_msg.acc.x = msg.acc.x;
  out_msg.acc.y = msg.acc.y;
  out_msg.acc.z = msg.acc.z;

  out_msg.jerk.x = msg.jerk.x;
  out_msg.jerk.y = msg.jerk.y;
  out_msg.jerk.z = msg.jerk.z;

  out_msg.heading = msg.heading;

  pub.publish(out_msg);
}

#include <ipc_bridge/subscriber.h>

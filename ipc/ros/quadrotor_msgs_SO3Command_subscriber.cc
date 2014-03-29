#include <ros/ros.h>
#include <ipc_bridge/ipc_bridge.h>

#include <quadrotor_msgs/SO3Command.h>
#include <ipc_bridge/msgs/quadrotor_msgs_SO3Command.h>

#define NAMESPACE quadrotor_msgs
#define NAME SO3Command

ros::Publisher pub;
NAMESPACE::NAME out_msg;

void callback(const ipc_bridge::NAMESPACE::NAME &msg)
{
  out_msg.force.x = msg.force.x;
  out_msg.force.y = msg.force.y;
  out_msg.force.z = msg.force.z;

  out_msg.rotation.x = msg.rotation.x;
  out_msg.rotation.y = msg.rotation.y;
  out_msg.rotation.z = msg.rotation.z;
  out_msg.rotation.w = msg.rotation.w;

  out_msg.kR.x = msg.kR.x;
  out_msg.kR.y = msg.kR.y;
  out_msg.kR.z = msg.kR.z;

  out_msg.kOm.x = msg.kOm.x;
  out_msg.kOm.y = msg.kOm.y;
  out_msg.kOm.z = msg.kOm.z;

  pub.publish(out_msg);
}

#include <ipc_bridge/subscriber.h>

#include <ros/ros.h>
#include <ipc_bridge/ipc_bridge.h>

#include <quadrotor_msgs/BatteryStatus.h>
#include <ipc_bridge/msgs/quadrotor_msgs_BatteryStatus.h>

#define NAMESPACE quadrotor_msgs
#define NAME BatteryStatus

ros::Publisher pub;
NAMESPACE::NAME out_msg;

void callback(const ipc_bridge::NAMESPACE::NAME &msg)
{
  out_msg.voltage = msg.voltage;

  pub.publish(out_msg);
}

#include <ipc_bridge/subscriber.h>

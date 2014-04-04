#include <ros/ros.h>
#include <ipc_bridge/ipc_bridge.h>

#include <quadrotor_msgs/BatteryVoltage.h>
#include <ipc_bridge/msgs/quadrotor_msgs_BatteryVoltage.h>

#define NAMESPACE quadrotor_msgs
#define NAME BatteryVoltage

ros::Publisher pub;
NAMESPACE::NAME out_msg;

void callback(const ipc_bridge::NAMESPACE::NAME &msg)
{
  out_msg.voltage = msg.voltage;

  pub.publish(out_msg);
}

#include <ipc_bridge/subscriber.h>

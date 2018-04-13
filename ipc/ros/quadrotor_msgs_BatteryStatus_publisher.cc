#include <ros/ros.h>
#include <ipc_bridge/ipc_bridge.h>

#include <quadrotor_msgs/BatteryStatus.h>
#include <ipc_bridge/msgs/quadrotor_msgs_BatteryStatus.h>

#define NAMESPACE quadrotor_msgs
#define NAME BatteryStatus

ipc_bridge::Publisher<ipc_bridge::NAMESPACE::NAME> *p;
ipc_bridge::NAMESPACE::NAME out_msg;

void callback(const NAMESPACE::NAME::ConstPtr &msg)
{
  out_msg.voltage = msg->voltage;

  p->Publish(out_msg);
}

#include <ipc_bridge/publisher.h>

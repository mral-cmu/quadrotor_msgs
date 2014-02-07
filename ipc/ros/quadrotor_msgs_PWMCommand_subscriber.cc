#include <ros/ros.h>
#include <ipc_bridge/ipc_bridge.h>

#include <quadrotor_msgs/PWMCommand.h>
#include <ipc_bridge/msgs/quadrotor_msgs_PWMCommand.h>

#define NAMESPACE quadrotor_msgs
#define NAME PWMCommand

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

  std::copy(msg.motor_pwm, msg.motor_pwm + 4,
            out_msg.motor_pwm.begin());

  pub.publish(out_msg);
}

#include "subscriber.h"

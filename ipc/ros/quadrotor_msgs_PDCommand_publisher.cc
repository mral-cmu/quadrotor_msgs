#include <ros/ros.h>
#include <ipc_bridge/ipc_bridge.h>

#include <quadrotor_msgs/PDCommand.h>
#include <ipc_bridge/msgs/quadrotor_msgs_PDCommand.h>

#define NAMESPACE quadrotor_msgs
#define NAME PDCommand

ipc_bridge::Publisher<ipc_bridge::NAMESPACE::NAME> *p;
ipc_bridge::NAMESPACE::NAME out_msg;

unsigned int frame_id_prior_size = 0;

void callback(const NAMESPACE::NAME::ConstPtr &msg)
{
  out_msg.header.seq = msg->header.seq;
  out_msg.header.stamp = msg->header.stamp.toSec();

  if (strlen(msg->header.frame_id.c_str()) != frame_id_prior_size)
    {
      if (out_msg.header.frame_id != 0)
        delete[] out_msg.header.frame_id;

      out_msg.header.frame_id =
        new char[strlen(msg->header.frame_id.c_str()) + 1];
      strcpy(out_msg.header.frame_id, msg->header.frame_id.c_str());
      frame_id_prior_size = strlen(msg->header.frame_id.c_str());
    }

  out_msg.roll = msg->roll;
  out_msg.pitch = msg->pitch;
  out_msg.yaw = msg->yaw;
  out_msg.thrust = msg->thrust;

  out_msg.kp_roll = msg->kp_roll;
  out_msg.kp_pitch = msg->kp_pitch;
  out_msg.kp_yaw = msg->kp_yaw;

  out_msg.kd_roll = msg->kd_roll;
  out_msg.kd_pitch = msg->kd_pitch;
  out_msg.kd_yaw = msg->kd_yaw;

  p->Publish(out_msg);
}

#include <ipc_bridge/publisher.h>

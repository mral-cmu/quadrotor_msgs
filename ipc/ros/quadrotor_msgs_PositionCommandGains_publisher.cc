#include <ros/ros.h>
#include <ipc_bridge/ipc_bridge.h>

#include <quadrotor_msgs/PositionCommandGains.h>
#include <ipc_bridge/msgs/quadrotor_msgs_PositionCommandGains.h>

#define NAMESPACE quadrotor_msgs
#define NAME PositionCommandGains

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

  out_msg.kp.x = msg->kp.x;
  out_msg.kp.y = msg->kp.y;
  out_msg.kp.z = msg->kp.z;
  out_msg.kd.x = msg->kd.x;
  out_msg.kd.y = msg->kd.y;
  out_msg.kd.z = msg->kd.z;

  p->Publish(out_msg);
}

#include <ipc_bridge/publisher.h>

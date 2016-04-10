#include <ros/ros.h>
#include <ipc_bridge/ipc_bridge.h>

#include <quadrotor_msgs/PositionCommand.h>
#include <ipc_bridge/msgs/quadrotor_msgs_PositionCommand.h>

#define NAMESPACE quadrotor_msgs
#define NAME PositionCommand

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

  out_msg.pos.x = msg->pos.x;
  out_msg.pos.y = msg->pos.y;
  out_msg.pos.z = msg->pos.z;
  out_msg.vel.x = msg->vel.x;
  out_msg.vel.y = msg->vel.y;
  out_msg.vel.z = msg->vel.z;
  out_msg.acc.x = msg->acc.x;
  out_msg.acc.y = msg->acc.y;
  out_msg.acc.z = msg->acc.z;
  out_msg.jerk.x = msg->jerk.x;
  out_msg.jerk.y = msg->jerk.y;
  out_msg.jerk.z = msg->jerk.z;
  for (unsigned int i = 0; i < 3; i++)
    out_msg.heading[i] = msg->heading[i];

  p->Publish(out_msg);
}

#include <ipc_bridge/publisher.h>

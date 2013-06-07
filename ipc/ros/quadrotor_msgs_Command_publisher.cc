#include <ros/ros.h>
#include <ipc_bridge/ipc_bridge.h>

#include <quadrotor_msgs/Command.h>
#include <ipc_bridge/msgs/quadrotor_msgs_Command.h>

#define NAMESPACE quadrotor_msgs
#define NAME Command

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

  out_msg.force.x = msg->force.x;
  out_msg.force.y = msg->force.y;
  out_msg.force.z = msg->force.z;
  out_msg.rotation.x = msg->rotation.x;
  out_msg.rotation.y = msg->rotation.y;
  out_msg.rotation.z = msg->rotation.z;
  out_msg.rotation.w = msg->rotation.w;
  memcpy(out_msg.kR, (void*)&(msg->kR[0]), sizeof(out_msg.kR));
  memcpy(out_msg.kOm, (void*)&(msg->kOm[0]), sizeof(out_msg.kOm));
  memcpy(out_msg.corrections, (void*)&(msg->corrections[0]),
         sizeof(out_msg.corrections));

  p->Publish(out_msg);
}

#include "publisher.h"

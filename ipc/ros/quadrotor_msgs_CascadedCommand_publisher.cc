#include <ros/ros.h>
#include <ipc_bridge/ipc_bridge.h>

#include <quadrotor_msgs/CascadedCommand.h>
#include <ipc_bridge/msgs/quadrotor_msgs_CascadedCommand.h>

#define NAMESPACE quadrotor_msgs
#define NAME CascadedCommand

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

  out_msg.current_heading = msg->current_heading;
  out_msg.thrust = msg->thrust;
  out_msg.orientation.x = msg->orientation.x;
  out_msg.orientation.y = msg->orientation.y;
  out_msg.orientation.z = msg->orientation.z;
  out_msg.orientation.w = msg->orientation.w;
  out_msg.angular_velocity.x = msg->angular_velocity.x;
  out_msg.angular_velocity.y = msg->angular_velocity.y;
  out_msg.angular_velocity.z = msg->angular_velocity.z;
  out_msg.kR.x = msg->kR.x;
  out_msg.kR.y = msg->kR.y;
  out_msg.kR.z = msg->kR.z;
  out_msg.kOm.x = msg->kOm.x;
  out_msg.kOm.y = msg->kOm.y;
  out_msg.kOm.z = msg->kOm.z;

  p->Publish(out_msg);
}

#include <ipc_bridge/publisher.h>

/*
ipc_bridge: ROS-MATLAB interface via CMU's IPC
Copyright (C) 2014  Nathan Michael

This program is free software; you can redistribute it and/or
modify it under the terms of the GNU General Public License
as published by the Free Software Foundation; either version 2
of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
*/
#include <ros/ros.h>
#include <ipc_bridge/ipc_bridge.h>

#include <quadrotor_msgs/OdometryArray.h>
#include <ipc_bridge/msgs/quadrotor_msgs_OdometryArray.h>

#define NAMESPACE quadrotor_msgs
#define NAME OdometryArray

ipc_bridge::Publisher<ipc_bridge::NAMESPACE::NAME> *p;
ipc_bridge::NAMESPACE::NAME out_msg;

void copyHeader(const std_msgs::Header& in, std_msgs_Header& out)
{
  out.seq = in.seq;
  out.stamp = in.stamp.toSec();

  if (out.frame_id != 0)
    delete[] out.frame_id;

  out.frame_id = new char[in.frame_id.size() + 1];
  std::copy(in.frame_id.begin(), in.frame_id.end(), out.frame_id);
  out.frame_id[in.frame_id.size()] = '\0';
}

void callback(const NAMESPACE::NAME::ConstPtr &msg)
{
  copyHeader(msg->header, out_msg.header);

  out_msg.odoms_length = msg->odoms.size();

  out_msg.odoms = new nav_msgs_Odometry[out_msg.odoms_length];

  for (unsigned int i = 0; i < out_msg.odoms_length; i++)
  {
    copyHeader(msg->odoms[i].header, out_msg.odoms[i].header);

    out_msg.odoms[i].child_frame_id =
      new char[msg->odoms[i].child_frame_id.size() + 1];
    std::copy(msg->odoms[i].child_frame_id.begin(),
              msg->odoms[i].child_frame_id.end(),
              out_msg.odoms[i].child_frame_id);
    out_msg.odoms[i].child_frame_id[msg->odoms[i].child_frame_id.size()] = '\0';

    out_msg.odoms[i].pose.pose.position.x = msg->odoms[i].pose.pose.position.x;
    out_msg.odoms[i].pose.pose.position.y = msg->odoms[i].pose.pose.position.y;
    out_msg.odoms[i].pose.pose.position.z = msg->odoms[i].pose.pose.position.z;

    out_msg.odoms[i].pose.pose.orientation.x = msg->odoms[i].pose.pose.orientation.x;
    out_msg.odoms[i].pose.pose.orientation.y = msg->odoms[i].pose.pose.orientation.y;
    out_msg.odoms[i].pose.pose.orientation.z = msg->odoms[i].pose.pose.orientation.z;
    out_msg.odoms[i].pose.pose.orientation.w = msg->odoms[i].pose.pose.orientation.w;

    std::copy(msg->odoms[i].pose.covariance.begin(),
              msg->odoms[i].pose.covariance.end(),
              out_msg.odoms[i].pose.covariance);

    out_msg.odoms[i].twist.twist.linear.x = msg->odoms[i].twist.twist.linear.x;
    out_msg.odoms[i].twist.twist.linear.y = msg->odoms[i].twist.twist.linear.y;
    out_msg.odoms[i].twist.twist.linear.z = msg->odoms[i].twist.twist.linear.z;

    out_msg.odoms[i].twist.twist.angular.x = msg->odoms[i].twist.twist.angular.x;
    out_msg.odoms[i].twist.twist.angular.y = msg->odoms[i].twist.twist.angular.y;
    out_msg.odoms[i].twist.twist.angular.z = msg->odoms[i].twist.twist.angular.z;

    std::copy(msg->odoms[i].twist.covariance.begin(),
              msg->odoms[i].twist.covariance.end(),
              out_msg.odoms[i].twist.covariance);
  }

  p->Publish(out_msg);

  if (out_msg.odoms != 0)
    delete[] out_msg.odoms;

  out_msg.odoms = 0;
}

#include <ipc_bridge/publisher.h>

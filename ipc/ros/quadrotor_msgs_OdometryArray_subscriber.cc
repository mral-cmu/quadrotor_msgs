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

ros::Publisher pub;
NAMESPACE::NAME out_msg;

void copyHeader(const std_msgs_Header& in, std_msgs::Header& out)
{
  out.seq = in.seq;
  out.stamp = ros::Time(in.stamp);
  if (in.frame_id != 0)
    out.frame_id = std::string(in.frame_id);
  else
    out.frame_id = std::string("");
}

void callback(const ipc_bridge::NAMESPACE::NAME &msg)
{
  copyHeader(msg.header, out_msg.header);

  out_msg.odoms.resize(msg.odoms_length);
  for (unsigned int i = 0; i < msg.odoms_length; i++)
  {
    copyHeader(msg.odoms[i].header, out_msg.odoms[i].header);
    out_msg.odoms[i].child_frame_id = std::string(msg.odoms[i].child_frame_id);

    out_msg.odoms[i].pose.pose.position.x = msg.odoms[i].pose.pose.position.x;
    out_msg.odoms[i].pose.pose.position.y = msg.odoms[i].pose.pose.position.y;
    out_msg.odoms[i].pose.pose.position.z = msg.odoms[i].pose.pose.position.z;

    out_msg.odoms[i].pose.pose.orientation.x = msg.odoms[i].pose.pose.orientation.x;
    out_msg.odoms[i].pose.pose.orientation.y = msg.odoms[i].pose.pose.orientation.y;
    out_msg.odoms[i].pose.pose.orientation.z = msg.odoms[i].pose.pose.orientation.z;
    out_msg.odoms[i].pose.pose.orientation.w = msg.odoms[i].pose.pose.orientation.w;

    std::copy(msg.odoms[i].pose.covariance, msg.odoms[i].pose.covariance + 36,
              out_msg.odoms[i].pose.covariance.begin());

    out_msg.odoms[i].twist.twist.linear.x = msg.odoms[i].twist.twist.linear.x;
    out_msg.odoms[i].twist.twist.linear.y = msg.odoms[i].twist.twist.linear.y;
    out_msg.odoms[i].twist.twist.linear.z = msg.odoms[i].twist.twist.linear.z;

    out_msg.odoms[i].twist.twist.angular.x = msg.odoms[i].twist.twist.angular.x;
    out_msg.odoms[i].twist.twist.angular.y = msg.odoms[i].twist.twist.angular.y;
    out_msg.odoms[i].twist.twist.angular.z = msg.odoms[i].twist.twist.angular.z;

    std::copy(msg.odoms[i].twist.covariance, msg.odoms[i].twist.covariance + 36,
              out_msg.odoms[i].twist.covariance.begin());
  }

  pub.publish(out_msg);
}

#include <ipc_bridge/subscriber.h>

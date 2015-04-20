#ifndef IPC_BRIDGE_MATLAB_QUADROTOR_MSGS_CASCADED_COMMAND
#define IPC_BRIDGE_MATLAB_QUADROTOR_MSGS_CASCADED_COMMAND
#include <ipc_bridge/ipc_bridge_matlab.h>
#include <ipc_bridge/msgs/quadrotor_msgs_CascadedCommand.h>

#include <ipc_bridge/matlab/rosgraph_msgs/rosgraph_msgs_Header.h>
#include <ipc_bridge/matlab/geometry_msgs/geometry_msgs_Vector3.h>
#include <ipc_bridge/matlab/geometry_msgs/geometry_msgs_Quaternion.h>

namespace ipc_bridge_matlab
{
  namespace quadrotor_msgs
  {
    namespace CascadedCommand
    {
      static mxArray* ProcessMessage(const ipc_bridge::quadrotor_msgs::CascadedCommand &msg)
      {
        const char *fields[] = {"header",
                                "thrust",
                                "orientation",
                                "angular_velocity",
                                "kR", "kOm"};
        const int nfields = sizeof(fields)/sizeof(*fields);
        mxArray *out = mxCreateStructMatrix(1, 1, nfields, fields);

        mxSetField(out, 0, "header",
                   ipc_bridge_matlab::Header::ProcessMessage(msg.header));
        mxSetField(out, 0, "thrust", mxCreateDoubleScalar(msg.thrust));
        mxSetField(out, 0, "orientation",
                   ipc_bridge_matlab::geometry_msgs::Quaternion::ProcessMessage(msg.orientation));
        mxSetField(out, 0, "angular_velocity",
                   ipc_bridge_matlab::geometry_msgs::Vector3::ProcessMessage(msg.angular_velocity));
        mxSetField(out, 0, "kR",
                   ipc_bridge_matlab::geometry_msgs::Vector3::ProcessMessage(msg.kR));
        mxSetField(out, 0, "kOm",
                   ipc_bridge_matlab::geometry_msgs::Vector3::ProcessMessage(msg.kOm));

        return out;
      }

      static int ProcessArray(const mxArray *a,
                              ipc_bridge::quadrotor_msgs::CascadedCommand &msg)
      {
        mxArray *field;

        field = mxGetField(a, 0, "header");
        ipc_bridge_matlab::Header::ProcessArray(field, msg.header);

        field = mxGetField(a, 0, "thrust");
        msg.thrust = mxGetScalar(field);

        field = mxGetField(a, 0, "orientation");
        ipc_bridge_matlab::geometry_msgs::Quaternion::ProcessArray(field,
                                                                   msg.orientation);

        field = mxGetField(a, 0, "angular_velocity");
        ipc_bridge_matlab::geometry_msgs::Vector3::ProcessArray(field,
                                                                msg.angular_velocity);

        field = mxGetField(a, 0, "kR");
        ipc_bridge_matlab::geometry_msgs::Vector3::ProcessArray(field, msg.kR);

        field = mxGetField(a, 0, "kOm");
        ipc_bridge_matlab::geometry_msgs::Vector3::ProcessArray(field, msg.kOm);

        return SUCCESS;
      }

      static void Cleanup(ipc_bridge::quadrotor_msgs::CascadedCommand &msg)
      {
        ipc_bridge_matlab::Header::Cleanup(msg.header);
        ipc_bridge_matlab::geometry_msgs::Quaternion::Cleanup(msg.orientation);
        ipc_bridge_matlab::geometry_msgs::Vector3::Cleanup(msg.angular_velocity);
        ipc_bridge_matlab::geometry_msgs::Vector3::Cleanup(msg.kR);
        ipc_bridge_matlab::geometry_msgs::Vector3::Cleanup(msg.kOm);

        return;
      }
    }
  }
}
#endif

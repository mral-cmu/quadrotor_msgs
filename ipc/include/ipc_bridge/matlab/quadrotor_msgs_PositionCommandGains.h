#ifndef IPC_BRIDGE_MATLAB_QUADROTOR_MSGS_POSITION_COMMAND_GAINS
#define IPC_BRIDGE_MATLAB_QUADROTOR_MSGS_POSITION_COMMAND_GAINS
#include <ipc_bridge/ipc_bridge_matlab.h>
#include <ipc_bridge/msgs/quadrotor_msgs_PositionCommandGains.h>

#include <ipc_bridge/matlab/std_msgs/std_msgs_Header.h>
#include <ipc_bridge/matlab/geometry_msgs/geometry_msgs_Vector3.h>

namespace ipc_bridge_matlab
{
  namespace quadrotor_msgs
  {
    namespace PositionCommandGains
    {
      static mxArray* ProcessMessage(const ipc_bridge::quadrotor_msgs::PositionCommandGains &msg)
      {
        const char *fields[] = {"header", "kp", "kd"};
        const int nfields = sizeof(fields)/sizeof(*fields);
        mxArray *out = mxCreateStructMatrix(1, 1, nfields, fields);

        mxSetField(out, 0, "header",
                   ipc_bridge_matlab::std_msgs::Header::ProcessMessage(msg.header));
        mxSetField(out, 0, "kp",
                   ipc_bridge_matlab::geometry_msgs::Vector3::ProcessMessage(msg.kp));
        mxSetField(out, 0, "kd",
                   ipc_bridge_matlab::geometry_msgs::Vector3::ProcessMessage(msg.kd));

        return out;
      }

      static int ProcessArray(const mxArray *a,
                              ipc_bridge::quadrotor_msgs::PositionCommandGains &msg)
      {
        mxArray *field;

        field = mxGetField(a, 0, "header");
        ipc_bridge_matlab::std_msgs::Header::ProcessArray(field, msg.header);

        field = mxGetField(a, 0, "kp");
        ipc_bridge_matlab::geometry_msgs::Vector3::ProcessArray(field, msg.kp);

        field = mxGetField(a, 0, "kd");
        ipc_bridge_matlab::geometry_msgs::Vector3::ProcessArray(field, msg.kd);

        return SUCCESS;
      }

      static void Cleanup(ipc_bridge::quadrotor_msgs::PositionCommandGains &msg)
      {
        ipc_bridge_matlab::std_msgs::Header::Cleanup(msg.header);
        ipc_bridge_matlab::geometry_msgs::Vector3::Cleanup(msg.kp);
        ipc_bridge_matlab::geometry_msgs::Vector3::Cleanup(msg.kd);
        return;
      }
    }
  }
}
#endif

#ifndef IPC_BRIDGE_MATLAB_QUADROTOR_MSGS_CASCADED_COMMAND_GAINS
#define IPC_BRIDGE_MATLAB_QUADROTOR_MSGS_CASCADED_COMMAND_GAINS
#include <ipc_bridge/ipc_bridge_matlab.h>
#include <ipc_bridge/msgs/quadrotor_msgs_CascadedCommandGains.h>

#include <ipc_bridge/matlab/rosgraph_msgs/rosgraph_msgs_Header.h>
#include <ipc_bridge/matlab/geometry_msgs/geometry_msgs_Vector3.h>

namespace ipc_bridge_matlab
{
  namespace quadrotor_msgs
  {
    namespace CascadedCommandGains
    {
      static mxArray* ProcessMessage(const ipc_bridge::quadrotor_msgs::CascadedCommandGains &msg)
      {
        const char *fields[] = {"header",
                                "kR", "kOm"};
        const int nfields = sizeof(fields)/sizeof(*fields);
        mxArray *out = mxCreateStructMatrix(1, 1, nfields, fields);

        mxSetField(out, 0, "header",
                   ipc_bridge_matlab::Header::ProcessMessage(msg.header));
        mxSetField(out, 0, "kR",
                   ipc_bridge_matlab::geometry_msgs::Vector3::ProcessMessage(msg.kR));
        mxSetField(out, 0, "kOm",
                   ipc_bridge_matlab::geometry_msgs::Vector3::ProcessMessage(msg.kOm));

        return out;
      }

      static int ProcessArray(const mxArray *a,
                              ipc_bridge::quadrotor_msgs::CascadedCommandGains &msg)
      {
        mxArray *field;

        field = mxGetField(a, 0, "header");
        ipc_bridge_matlab::Header::ProcessArray(field, msg.header);

        field = mxGetField(a, 0, "kR");
        ipc_bridge_matlab::geometry_msgs::Vector3::ProcessArray(field, msg.kR);

        field = mxGetField(a, 0, "kOm");
        ipc_bridge_matlab::geometry_msgs::Vector3::ProcessArray(field, msg.kOm);

        return SUCCESS;
      }

      static void Cleanup(ipc_bridge::quadrotor_msgs::CascadedCommandGains &msg)
      {
        ipc_bridge_matlab::Header::Cleanup(msg.header);
        ipc_bridge_matlab::geometry_msgs::Vector3::Cleanup(msg.kR);
        ipc_bridge_matlab::geometry_msgs::Vector3::Cleanup(msg.kOm);

        return;
      }
    }
  }
}
#endif

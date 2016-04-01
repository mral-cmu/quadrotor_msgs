#ifndef IPC_BRIDGE_MATLAB_QUADROTOR_MSGS_SO3_COMMAND
#define IPC_BRIDGE_MATLAB_QUADROTOR_MSGS_SO3_COMMAND
#include <ipc_bridge/ipc_bridge_matlab.h>
#include <ipc_bridge/msgs/quadrotor_msgs_SO3Command.h>

#include <ipc_bridge/matlab/std_msgs/std_msgs_Header.h>
#include <ipc_bridge/matlab/geometry_msgs/geometry_msgs_Vector3.h>
#include <ipc_bridge/matlab/geometry_msgs/geometry_msgs_Quaternion.h>

namespace ipc_bridge_matlab
{
  namespace quadrotor_msgs
  {
    namespace SO3Command
    {
      static mxArray* ProcessMessage(const ipc_bridge::quadrotor_msgs::SO3Command &msg)
      {
        const char *fields[] = {"header", "force", "rotation",
                                "kR", "kOm"};
        const int nfields = sizeof(fields)/sizeof(*fields);
        mxArray *out = mxCreateStructMatrix(1, 1, nfields, fields);

        mxSetField(out, 0, "header",
                   ipc_bridge_matlab::std_msgs::Header::ProcessMessage(msg.header));
        mxSetField(out, 0, "force",
                   ipc_bridge_matlab::geometry_msgs::Vector3::ProcessMessage(msg.force));
        mxSetField(out, 0, "rotation",
                   ipc_bridge_matlab::geometry_msgs::Quaternion::ProcessMessage(msg.rotation));
        mxSetField(out, 0, "kR",
                   ipc_bridge_matlab::geometry_msgs::Vector3::ProcessMessage(msg.kR));
        mxSetField(out, 0, "kOm",
                   ipc_bridge_matlab::geometry_msgs::Vector3::ProcessMessage(msg.kOm));

        return out;
      }

      static int ProcessArray(const mxArray *a,
                              ipc_bridge::quadrotor_msgs::SO3Command &msg)
      {
        mxArray *field;

        field = mxGetField(a, 0, "header");
        ipc_bridge_matlab::std_msgs::Header::ProcessArray(field, msg.header);

        field = mxGetField(a, 0, "force");
        ipc_bridge_matlab::geometry_msgs::Vector3::ProcessArray(field,
                                                                msg.force);

        field = mxGetField(a, 0, "rotation");
        ipc_bridge_matlab::geometry_msgs::Quaternion::ProcessArray(field,
                                                                   msg.rotation);

        field = mxGetField(a, 0, "kR");
        ipc_bridge_matlab::geometry_msgs::Vector3::ProcessArray(field,
                                                                msg.kR);

        field = mxGetField(a, 0, "kOm");
        ipc_bridge_matlab::geometry_msgs::Vector3::ProcessArray(field,
                                                                msg.kOm);

        return SUCCESS;
      }

      static void Cleanup(ipc_bridge::quadrotor_msgs::SO3Command &msg)
      {
        ipc_bridge_matlab::std_msgs::Header::Cleanup(msg.header);
        ipc_bridge_matlab::geometry_msgs::Vector3::Cleanup(msg.force);
        ipc_bridge_matlab::geometry_msgs::Quaternion::Cleanup(msg.rotation);
        ipc_bridge_matlab::geometry_msgs::Vector3::Cleanup(msg.kR);
        ipc_bridge_matlab::geometry_msgs::Vector3::Cleanup(msg.kOm);

        return;
      }
    }
  }
}
#endif

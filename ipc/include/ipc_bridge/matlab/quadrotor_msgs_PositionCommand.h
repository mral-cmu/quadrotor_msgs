#ifndef IPC_BRIDGE_MATLAB_QUADROTOR_MSGS_POSITION_COMMAND
#define IPC_BRIDGE_MATLAB_QUADROTOR_MSGS_POSITION_COMMAND
#include <ipc_bridge/ipc_bridge_matlab.h>
#include <ipc_bridge/msgs/quadrotor_msgs_PositionCommand.h>

#include <ipc_bridge/matlab/std_msgs/std_msgs_Header.h>
#include <ipc_bridge/matlab/geometry_msgs/geometry_msgs_Vector3.h>

namespace ipc_bridge_matlab
{
  namespace quadrotor_msgs
  {
    namespace PositionCommand
    {
      static mxArray* ProcessMessage(const ipc_bridge::quadrotor_msgs::PositionCommand &msg)
      {
        const char *fields[] = {"header", "pos", "vel", "acc", "jerk", "heading"};
        const int nfields = sizeof(fields)/sizeof(*fields);
        mxArray *out = mxCreateStructMatrix(1, 1, nfields, fields);

        mxSetField(out, 0, "header",
                   ipc_bridge_matlab::std_msgs::Header::ProcessMessage(msg.header));
        mxSetField(out, 0, "pos",
                   ipc_bridge_matlab::geometry_msgs::Vector3::ProcessMessage(msg.pos));
        mxSetField(out, 0, "vel",
                   ipc_bridge_matlab::geometry_msgs::Vector3::ProcessMessage(msg.vel));
        mxSetField(out, 0, "acc",
                   ipc_bridge_matlab::geometry_msgs::Vector3::ProcessMessage(msg.acc));
        mxSetField(out, 0, "jerk",
                   ipc_bridge_matlab::geometry_msgs::Vector3::ProcessMessage(msg.jerk));

        mxArray *heading = mxCreateDoubleMatrix(1, 3, mxREAL);
        std::copy(msg.heading, msg.heading + 3, mxGetPr(heading));
        mxSetField(out, 0, "heading", heading);

        return out;
      }

      static int ProcessArray(const mxArray *a,
                              ipc_bridge::quadrotor_msgs::PositionCommand &msg)
      {
        mxArray *field;

        field = mxGetField(a, 0, "header");
        ipc_bridge_matlab::std_msgs::Header::ProcessArray(field, msg.header);

        field = mxGetField(a, 0, "pos");
        ipc_bridge_matlab::geometry_msgs::Vector3::ProcessArray(field, msg.pos);

        field = mxGetField(a, 0, "vel");
        ipc_bridge_matlab::geometry_msgs::Vector3::ProcessArray(field, msg.vel);

        field = mxGetField(a, 0, "acc");
        ipc_bridge_matlab::geometry_msgs::Vector3::ProcessArray(field, msg.acc);

        field = mxGetField(a, 0, "jerk");
        ipc_bridge_matlab::geometry_msgs::Vector3::ProcessArray(field, msg.jerk);

        field = mxGetField(a, 0, "heading");
        double* p = mxGetPr(field);
        std::copy(p, p + 3, msg.heading);

        return SUCCESS;
      }

      static void Cleanup(ipc_bridge::quadrotor_msgs::PositionCommand &msg)
      {
        ipc_bridge_matlab::std_msgs::Header::Cleanup(msg.header);
        ipc_bridge_matlab::geometry_msgs::Vector3::Cleanup(msg.pos);
        ipc_bridge_matlab::geometry_msgs::Vector3::Cleanup(msg.vel);
        ipc_bridge_matlab::geometry_msgs::Vector3::Cleanup(msg.acc);
        ipc_bridge_matlab::geometry_msgs::Vector3::Cleanup(msg.jerk);
        return;
      }
    }
  }
}
#endif

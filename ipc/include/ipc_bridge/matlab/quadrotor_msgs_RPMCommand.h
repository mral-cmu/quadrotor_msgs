#ifndef IPC_BRIDGE_MATLAB_QUADROTOR_MSGS_RPM_COMMAND
#define IPC_BRIDGE_MATLAB_QUADROTOR_MSGS_RPM_COMMAND
#include <ipc_bridge/ipc_bridge_matlab.h>
#include <ipc_bridge/msgs/quadrotor_msgs_RPMCommand.h>

#include <ipc_bridge/matlab/rosgraph_msgs/rosgraph_msgs_Header.h>

namespace ipc_bridge_matlab
{
  namespace quadrotor_msgs
  {
    namespace RPMCommand
    {
      static mxArray* ProcessMessage(const ipc_bridge::quadrotor_msgs::RPMCommand &msg)
      {
        const char *fields[] = {"header", "motor_rpm"};
        const int nfields = sizeof(fields)/sizeof(*fields);
        mxArray *out = mxCreateStructMatrix(1, 1, nfields, fields);

        mxSetField(out, 0, "header",
                   ipc_bridge_matlab::Header::ProcessMessage(msg.header));

        mxArray *motor_rpm = mxCreateDoubleMatrix(1, 4, mxREAL);
        std::copy(msg.motor_rpm, msg.motor_rpm + 4, mxGetPr(motor_rpm));
        mxSetField(out, 0, "motor_rpm", motor_rpm);

        return out;
      }

      static int ProcessArray(const mxArray *a,
                              ipc_bridge::quadrotor_msgs::RPMCommand &msg)
      {
        mxArray *field;

        field = mxGetField(a, 0, "header");
        ipc_bridge_matlab::Header::ProcessArray(field, msg.header);

        field = mxGetField(a, 0, "motor_rpm");
        double* p = mxGetPr(field);
        std::copy(p, p + 4, msg.motor_rpm);

        return SUCCESS;
      }

      static void Cleanup(ipc_bridge::quadrotor_msgs::RPMCommand &msg)
      {
        ipc_bridge_matlab::Header::Cleanup(msg.header);

        return;
      }
    }
  }
}
#endif

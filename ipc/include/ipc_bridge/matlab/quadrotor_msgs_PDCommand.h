#ifndef IPC_BRIDGE_MATLAB_QUADROTOR_MSGS_PD_COMMAND
#define IPC_BRIDGE_MATLAB_QUADROTOR_MSGS_PD_COMMAND
#include <ipc_bridge/ipc_bridge_matlab.h>
#include <ipc_bridge/msgs/quadrotor_msgs_PDCommand.h>

#include <ipc_bridge/matlab/rosgraph_msgs/rosgraph_msgs_Header.h>

namespace ipc_bridge_matlab
{
  namespace quadrotor_msgs
  {
    namespace PDCommand
    {
      static mxArray* ProcessMessage(const ipc_bridge::quadrotor_msgs::PDCommand &msg)
      {
        const char *fields[] = {"header", "roll", "pitch", "yaw", "thrust",
                                "kp_roll", "kp_pitch", "kp_yaw",
                                "kd_roll", "kd_pitch", "kd_yaw"};
        const int nfields = sizeof(fields)/sizeof(*fields);
        mxArray *out = mxCreateStructMatrix(1, 1, nfields, fields);

        mxSetField(out, 0, "header",
                   ipc_bridge_matlab::Header::ProcessMessage(msg.header));

        mxSetField(out, 0, "roll", mxCreateDoubleScalar(msg.roll));
        mxSetField(out, 0, "pitch", mxCreateDoubleScalar(msg.pitch));
        mxSetField(out, 0, "yaw", mxCreateDoubleScalar(msg.yaw));
        mxSetField(out, 0, "thrust", mxCreateDoubleScalar(msg.thrust));
        mxSetField(out, 0, "kp_roll", mxCreateDoubleScalar(msg.kp_roll));
        mxSetField(out, 0, "kp_pitch", mxCreateDoubleScalar(msg.kp_pitch));
        mxSetField(out, 0, "kp_yaw", mxCreateDoubleScalar(msg.kp_yaw));
        mxSetField(out, 0, "kd_roll", mxCreateDoubleScalar(msg.kd_roll));
        mxSetField(out, 0, "kd_pitch", mxCreateDoubleScalar(msg.kd_pitch));
        mxSetField(out, 0, "kd_yaw", mxCreateDoubleScalar(msg.kd_yaw));

        return out;
      }

      static int ProcessArray(const mxArray *a,
                              ipc_bridge::quadrotor_msgs::PDCommand &msg)
      {
        mxArray *field;

        field = mxGetField(a, 0, "header");
        ipc_bridge_matlab::Header::ProcessArray(field, msg.header);

        field = mxGetField(a, 0, "roll");
        msg.roll = mxGetScalar(field);

        field = mxGetField(a, 0, "pitch");
        msg.pitch = mxGetScalar(field);

        field = mxGetField(a, 0, "yaw");
        msg.yaw = mxGetScalar(field);

        field = mxGetField(a, 0, "thrust");
        msg.thrust = mxGetScalar(field);

        field = mxGetField(a, 0, "kp_roll");
        msg.kp_roll = mxGetScalar(field);

        field = mxGetField(a, 0, "kp_pitch");
        msg.kp_pitch = mxGetScalar(field);

        field = mxGetField(a, 0, "kp_yaw");
        msg.kp_yaw = mxGetScalar(field);

        field = mxGetField(a, 0, "kd_roll");
        msg.kd_roll = mxGetScalar(field);

        field = mxGetField(a, 0, "kd_pitch");
        msg.kd_pitch = mxGetScalar(field);

        field = mxGetField(a, 0, "kd_yaw");
        msg.kd_yaw = mxGetScalar(field);

        return SUCCESS;
      }

      static void Cleanup(ipc_bridge::quadrotor_msgs::PDCommand &msg)
      {
        ipc_bridge_matlab::Header::Cleanup(msg.header);

        return;
      }
    }
  }
}
#endif

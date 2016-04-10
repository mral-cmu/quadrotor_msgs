#ifndef IPC_BRIDGE_MATLAB_QUADROTOR_MSGS_PD_COMMAND
#define IPC_BRIDGE_MATLAB_QUADROTOR_MSGS_PD_COMMAND
#include <ipc_bridge/ipc_bridge_matlab.h>
#include <ipc_bridge/msgs/quadrotor_msgs_PDCommand.h>

#include <ipc_bridge/matlab/std_msgs/std_msgs_Header.h>

namespace ipc_bridge_matlab
{
  namespace quadrotor_msgs
  {
    namespace PDCommand
    {
      static mxArray* ProcessMessage(const ipc_bridge::quadrotor_msgs::PDCommand &msg)
      {
        const char *fields[] = {"header", "roll", "pitch", "yaw_delta", "thrust",
                                "roll_speed", "pitch_speed", "yaw_speed",
                                "kp_roll", "kp_pitch",
                                "kd_roll", "kd_pitch", "kd_yaw",
                                "gains_seq", "speeds_seq"};
        const int nfields = sizeof(fields)/sizeof(*fields);
        mxArray *out = mxCreateStructMatrix(1, 1, nfields, fields);

        mxSetField(out, 0, "header",
                   ipc_bridge_matlab::std_msgs::Header::ProcessMessage(msg.header));

        mxSetField(out, 0, "roll", mxCreateDoubleScalar(msg.roll));
        mxSetField(out, 0, "pitch", mxCreateDoubleScalar(msg.pitch));
        mxSetField(out, 0, "yaw_delta", mxCreateDoubleScalar(msg.yaw_delta));
        mxSetField(out, 0, "thrust", mxCreateDoubleScalar(msg.thrust));
        mxSetField(out, 0, "roll_speed", mxCreateDoubleScalar(msg.roll_speed));
        mxSetField(out, 0, "pitch_speed", mxCreateDoubleScalar(msg.pitch_speed));
        mxSetField(out, 0, "yaw_speed", mxCreateDoubleScalar(msg.yaw_speed));
        mxSetField(out, 0, "kp_roll", mxCreateDoubleScalar(msg.kp_roll));
        mxSetField(out, 0, "kp_pitch", mxCreateDoubleScalar(msg.kp_pitch));
        mxSetField(out, 0, "kd_roll", mxCreateDoubleScalar(msg.kd_roll));
        mxSetField(out, 0, "kd_pitch", mxCreateDoubleScalar(msg.kd_pitch));
        mxSetField(out, 0, "kd_yaw", mxCreateDoubleScalar(msg.kd_yaw));
        mxSetField(out, 0, "gains_seq", mxCreateDoubleScalar(msg.gains_seq));
        mxSetField(out, 0, "speeds_seq", mxCreateDoubleScalar(msg.speeds_seq));

        return out;
      }

      static int ProcessArray(const mxArray *a,
                              ipc_bridge::quadrotor_msgs::PDCommand &msg)
      {
        mxArray *field;

        field = mxGetField(a, 0, "header");
        ipc_bridge_matlab::std_msgs::Header::ProcessArray(field, msg.header);

        field = mxGetField(a, 0, "roll");
        msg.roll = mxGetScalar(field);

        field = mxGetField(a, 0, "pitch");
        msg.pitch = mxGetScalar(field);

        field = mxGetField(a, 0, "yaw_delta");
        msg.yaw_delta = mxGetScalar(field);

        field = mxGetField(a, 0, "thrust");
        msg.thrust = mxGetScalar(field);

        field = mxGetField(a, 0, "roll_speed");
        msg.roll_speed = mxGetScalar(field);

        field = mxGetField(a, 0, "pitch_speed");
        msg.pitch_speed = mxGetScalar(field);

        field = mxGetField(a, 0, "yaw_speed");
        msg.yaw_speed = mxGetScalar(field);

        field = mxGetField(a, 0, "kp_roll");
        msg.kp_roll = mxGetScalar(field);

        field = mxGetField(a, 0, "kp_pitch");
        msg.kp_pitch = mxGetScalar(field);

        field = mxGetField(a, 0, "kd_roll");
        msg.kd_roll = mxGetScalar(field);

        field = mxGetField(a, 0, "kd_pitch");
        msg.kd_pitch = mxGetScalar(field);

        field = mxGetField(a, 0, "kd_yaw");
        msg.kd_yaw = mxGetScalar(field);

        field = mxGetField(a, 0, "gains_seq");
        msg.gains_seq = mxGetScalar(field);

        field = mxGetField(a, 0, "speeds_seq");
        msg.speeds_seq = mxGetScalar(field);

        return SUCCESS;
      }

      static void Cleanup(ipc_bridge::quadrotor_msgs::PDCommand &msg)
      {
        ipc_bridge_matlab::std_msgs::Header::Cleanup(msg.header);

        return;
      }
    }
  }
}
#endif

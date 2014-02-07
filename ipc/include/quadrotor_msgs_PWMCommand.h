#ifndef __IPC_BRIDGE_MATLAB_QUADROTOR_MSGS_PWM_COMMAND__
#define __IPC_BRIDGE_MATLAB_QUADROTOR_MSGS_PWM_COMMAND__
#include <ipc_bridge_matlab/ipc_bridge_matlab.h>
#include <ipc_bridge/msgs/quadrotor_msgs_PWMCommand.h>

#include <rosgraph_msgs_Header.h>

namespace ipc_bridge_matlab
{
  namespace quadrotor_msgs
  {
    namespace PWMCommand
    {
      static mxArray* ProcessMessage(const ipc_bridge::quadrotor_msgs::PWMCommand &msg)
      {
        const char *fields[] = {"header", "motor_pwm"};
        const int nfields = sizeof(fields)/sizeof(*fields);
        mxArray *out = mxCreateStructMatrix(1, 1, nfields, fields);

        mxSetField(out, 0, "header",
                   ipc_bridge_matlab::Header::ProcessMessage(msg.header));

        mxArray *motor_pwm = mxCreateDoubleMatrix(1, 4, mxREAL);
        std::copy(msg.motor_pwm, msg.motor_pwm + 4, mxGetPr(motor_pwm));
        mxSetField(out, 0, "motor_pwm", motor_pwm);

        return out;
      }

      static int ProcessArray(const mxArray *a,
                              ipc_bridge::quadrotor_msgs::PWMCommand &msg)
      {
        mxArray *field;

        field = mxGetField(a, 0, "header");
        ipc_bridge_matlab::Header::ProcessArray(field, msg.header);

        field = mxGetField(a, 0, "motor_pwm");
        double* p = mxGetPr(field);
        std::copy(p, p + 4, msg.motor_pwm);

        return SUCCESS;
      }

      static void Cleanup(ipc_bridge::quadrotor_msgs::PWMCommand &msg)
      {
        ipc_bridge_matlab::Header::Cleanup(msg.header);

        return;
      }
    }
  }
}
#endif

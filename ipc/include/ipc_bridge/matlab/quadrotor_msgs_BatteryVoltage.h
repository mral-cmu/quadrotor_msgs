#ifndef IPC_BRIDGE_MATLAB_QUADROTOR_MSGS_BATTERY_VOLTAGE
#define IPC_BRIDGE_MATLAB_QUADROTOR_MSGS_BATTERY_VOLTAGE
#include <ipc_bridge/ipc_bridge_matlab.h>
#include <ipc_bridge/msgs/quadrotor_msgs_BatteryVoltage.h>

namespace ipc_bridge_matlab
{
  namespace quadrotor_msgs
  {
    namespace BatteryVoltage
    {
      static mxArray* ProcessMessage(const ipc_bridge::quadrotor_msgs::BatteryVoltage &msg)
      {
        const char *fields[] = {"voltage"};
        const int nfields = sizeof(fields)/sizeof(*fields);
        mxArray *out = mxCreateStructMatrix(1, 1, nfields, fields);

        mxSetField(out, 0, "voltage", mxCreateDoubleScalar(msg.voltage));

        return out;
      }

      static int ProcessArray(const mxArray *a,
                              ipc_bridge::quadrotor_msgs::BatteryVoltage &msg)
      {
        mxArray *field;

        field = mxGetField(a, 0, "voltage");
        msg.voltage = mxGetScalar(field);

        return SUCCESS;
      }

      static void Cleanup(ipc_bridge::quadrotor_msgs::BatteryVoltage &msg)
      {
        return;
      }
    }
  }
}
#endif

#ifndef IPC_BRIDGE_MATLAB_QUADROTOR_MSGS_ODOMETRY_ARRAY
#define IPC_BRIDGE_MATLAB_QUADROTOR_MSGS_ODOMETRY_ARRAY
#include <ipc_bridge/ipc_bridge_matlab.h>
#include <ipc_bridge/msgs/quadrotor_msgs_OdometryArray.h>

#include <ipc_bridge/matlab/std_msgs/std_msgs_Header.h>
#include <ipc_bridge/matlab/nav_msgs/nav_msgs_Odometry.h>

namespace ipc_bridge_matlab
{
  namespace quadrotor_msgs
  {
    namespace OdometryArray
    {
      static mxArray* ProcessMessage(const ipc_bridge::quadrotor_msgs::OdometryArray &msg)
      {
        const char *fields[] = {"header", "odoms"};
        const int nfields = sizeof(fields)/sizeof(*fields);
        mxArray *out = mxCreateStructMatrix(1, 1, nfields, fields);

        mxSetField(out, 0, "header",
                   ipc_bridge_matlab::std_msgs::Header::ProcessMessage(msg.header));

        const size_t length = msg.odoms_length;
        mxArray *odoms = mxCreateCellArray(1, &length);

        for (unsigned int i = 0; i < length; i++)
          mxSetCell(odoms, i,
                    ipc_bridge_matlab::nav_msgs::Odometry::ProcessMessage(msg.odoms[i]));
        mxSetField(out, 0, "odoms", odoms);

        return out;
      }

      static int ProcessArray(const mxArray *a,
                              ipc_bridge::quadrotor_msgs::OdometryArray &msg)
      {
        mxArray *field;

        field = mxGetField(a, 0, "header");
        ipc_bridge_matlab::std_msgs::Header::ProcessArray(field, msg.header);

        field = mxGetField(a, 0, "odoms");
        int nrows = mxGetM(field);
        int ncols = mxGetN(field);

        unsigned int length = nrows;
        if (nrows < ncols)
          length = ncols;
        msg.odoms_length = length;

        if ((ncols == 0) || (nrows == 0))
        {
          msg.odoms_length = 0;
          msg.odoms = 0;
        }

        if (msg.odoms_length > 0)
        {
          msg.odoms = new nav_msgs_Odometry[msg.odoms_length];
          for (unsigned int i = 0; i < msg.odoms_length; i++)
          {
            mxArray *p = mxGetCell(field, i);
            ipc_bridge_matlab::nav_msgs::Odometry::ProcessArray(p, msg.odoms[i]);
          }
        }

        return SUCCESS;
      }

      static void Cleanup(ipc_bridge::quadrotor_msgs::OdometryArray &msg)
      {
        ipc_bridge_matlab::std_msgs::Header::Cleanup(msg.header);

        for (unsigned int i = 0; i < msg.odoms_length; i++)
          ipc_bridge_matlab::nav_msgs::Odometry::Cleanup(msg.odoms[i]);
        if (msg.odoms != 0)
        {
          delete[] msg.odoms;
          msg.odoms_length = 0;
          msg.odoms = 0;
        }

        return;
      }
    }
  }
}
#endif

^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
Changelog for package quadrotor_msgs
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

Forthcoming
-----------
* Merge branch 'feature/spline_msg' into 'develop'
  Feature/spline msg
  See merge request !2
* Merge branch 'develop' into feature/spline_msg
  Conflicts:
  CMakeLists.txt
* Added new Spline message type to send trajectory coefficients
* Contributors: Nathan Michael, Vishnu Desaraju

0.0.9 (2014-10-24)
------------------
* Merge branch 'feature/local_odometry' into 'develop'
  Feature/local odometry
  See merge request !1
* added local odometry message type
* Contributors: John Yao, Nathan Michael

0.0.8 (2014-09-16)
------------------
* added message type for transient trim observer information
* add u_Mz and u_acc fields to StaticTrimInfo message
* Removing AltitudeInfo messsage and absorbing it into AltitudeObservation
* added message type for static trim estimator information
* added AltitudeInfo message
* add HeightDelta message
* Adding AltitudeObservation.msg (previously in altitude_pf)
* Contributors: Erik Nelson, John Yao, Nathan Michael

0.0.7 (2014-05-05)
------------------
* Changes to handling of PDCommands and yaw_delta
* Contributors: Nathan Michael

0.0.6 (2014-04-07)
------------------
* Adding support for custom BatteryVoltage msg
* Merge branch 'develop' of nmichael.frc.ri.cmu.edu:msgs/quadrotor_msgs into develop
* Updating PDCommand support and renaming Command to SO3Command
* Contributors: Nathan Michael

0.0.5 (2014-03-26)
------------------
* Fix thrust setting and incorrect header include
* Adding support for PDCommands
* Contributors: Nathan Michael

0.0.4 (2014-02-25)
------------------
* Quieting output if IPC is not found
* Added missing IPC header include variable
* Fixing incorrect call to find_package without specifying components
* Updates to support rework of IPC bridge
* New PWMCommand and IPC bridge interface
* Updating license tag to specify GPLv2
* Contributors: Nathan Michael

0.0.3 (2014-01-14)
------------------
* Adding GPLv2 license and documentation base
* Contributors: Nathan Michael

0.0.2 (2014-01-13)
------------------
* Moving status msg to quadrotor_msgs package
* Contributors: Nathan Michael

0.0.1 (2014-01-13)
------------------
* Updating to remove corrections term and vector3 instead of float64 arrays for gains
* Moving to hydro
* Template hydro files
* Removing in place turn as it is accomplished by hover
* Initial commit
* Contributors: Nathan Michael

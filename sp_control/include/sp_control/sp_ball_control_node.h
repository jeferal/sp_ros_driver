#include <ros/ros.h>

#include <sp_ros_driver/SpCommand.h>


namespace sp_control
{
    class SpBallControl
    {

        public:

            /// @brief 
            /// @param nh 
            SpBallControl(ros::NodeHandle& nh);

            bool init();

            /// @brief 
            /// @param msg 
            void ballPositionCallback(const sp_ros_driver::SpCommand::ConstPtr& msg);

            /// @brief 
            void run();

        private:

            void saturate_(double& value, double min, double max);

            ros::NodeHandle nh_;

            // Subscriber for the ball position
            ros::Subscriber ball_position_sub_;

            // Publisher for the servo platform command
            ros::Publisher sp_command_pub_;

            // PID parameters
            double kp_;
            double ki_;
            double kd_;

            // Internal variables of PID
            double error_x_, error_y_;
            double error_sum_x_, error_sum_y_;

            // Current set point
            double set_point_x;
            double set_point_y;

            // Current roll and pitch
            double start_roll_;
            double start_pitch_;
    };

}   // namespace sp_control
#include <chrono>
#include <functional>
#include <memory>
#include <string>
#include <cmath> 

#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/float32.hpp"

using namespace std::chronoliterals;

class GenTwoCos : public rclcpp::Node
{
public:
    GenTwoCos() : Node("generalas"), count(0)
        {
            RCLCPP_INFO(this->getlogger(), "Koszinusz jelek generálása");
            pub1 = this->create_publisher<stdmsgs::msg::Float32>("cos1", 10);
            pub2 = this->create_publisher<stdmsgs::msg::Float32>("cos2", 10);
            timer = this->create_wall_timer(50ms, std::bind(&GenTwoCos::timer_callback, this));
        }


private:
    void timer_callback()
    {
        auto msg1 = std_msgs::msg::Float32();
        auto msg2 = stdmsgs::msg::Float32();

        auto t = count * 0.01;
        msg1.data = cos(t * 2M_PI1) * 2;
        msg2.data = cos(t * 2M_PI2) * 0.5;

        pub1->publish(msg1);
        pub2->publish(msg2);

        count++;
    }

    rclcpp::TimerBase::SharedPtr timer;
    rclcpp::Publisher<stdmsgs::msg::Float32>::SharedPtr pub1, pub2_;
    sizet count;
};

int main(int argc, char *argv[])
{
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<GenTwoCos>());
    rclcpp::shutdown();
    return 0;
}
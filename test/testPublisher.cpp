#include <gtest/gtest.h>
#include <ros/ros.h>
#include <ros/service_client.h>
#include <beginner_tutorials/string_modifier.h>
#include <tf/transform_listener.h>


// Declare a test
TEST(TestSuite, test_ServiceOutput)
{
  ros::NodeHandle n;
  ros::ServiceClient client = n.serviceClient<beginner_tutorials::string_modifier>("string_modifier");
  beginner_tutorials::string_modifier srv;
  srv.request.input = "see if it works";
  client.call(srv);
  EXPECT_STREQ("see if it works", srv.response.output.c_str());
}


// Run all the tests that were declared with TEST()
int main(int argc, char **argv){
  testing::InitGoogleTest(&argc, argv);
  ros::init(argc, argv, "testPublisher");
  return RUN_ALL_TESTS();
}

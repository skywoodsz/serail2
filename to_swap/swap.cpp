void caculate_Points::draw_txt(int id,double x,double y,string s,double num,ros::Publisher pub)
{
  visualization_msgs::Marker visual_temp;

  visual_temp.header.frame_id = "/map";
  visual_temp.header.stamp = ros::Time::now();
  visual_temp.ns = "points_and_txt";
  visual_temp.id = id;
  visual_temp.type = visualization_msgs::Marker::TEXT_VIEW_FACING;
  visual_temp.scale.z = 0.3;
  visual_temp.color.b = 1.0;
  visual_temp.color.a = 1;

  geometry_msgs::Pose pose;
  pose.position.x = x;
  pose.position.y = y;
  pose.position.z = 1;
  ostringstream str;
  str<<s<<num;
  visual_temp.text=str.str();
  visual_temp.pose = pose;
  pub.publish(visual_temp);
}

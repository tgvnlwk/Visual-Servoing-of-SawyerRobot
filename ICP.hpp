/*    
 *     
 * Created by Soham 26/04/2020
 *   
 */

#ifndef ICPTIME_HPP_INCLUDED
#define ICPTIME_INCLUDED
#include <iostream>
#include <string>
#include <sstream>
#include <pcl/io/pcd_io.h>
#include <pcl/io/ply_io.h>
#include <pcl/point_cloud.h>
#include <pcl/console/parse.h>
#include <pcl/common/transforms.h>
#include <pcl/visualization/pcl_visualizer.h>
#include <pcl/filters/impl/filter.hpp>
#include <pcl/registration/icp.h>
#include <pcl/point_types.h>
#include <pcl/filters/voxel_grid.h>

using namespace std;
typedef pcl::PointXYZ PointT;
typedef pcl::PointCloud<PointT> PointCloudT;
typedef pcl::visualization::PCLVisualizer viz;
typedef pcl::visualization::PointCloudColorHandlerCustom < pcl::PointXYZ > CustomColour;
typedef pcl::IterativeClosestPoint < pcl::PointXYZ, pcl::PointXYZ > icp;

class  ICP{

private:        
    PointCloudT::Ptr cloud_one;
    PointCloudT::Ptr cloud_two;
    PointCloudT::Ptr cloud_filtered_one;
    PointCloudT::Ptr cloud_filtered_two;
    PointCloudT::Ptr cloud_icp;

public:
    ICP();
    ~ICP();	 
    int file_loader();
    void remove_nan(PointCloudT::Ptr cloud_in);
    int run_ICP_algorithm(PointCloudT::Ptr cloud_icp, PointCloudT::Ptr cloud_tr);
    void go_voxel(PointCloudT::Ptr cloud_a, PointCloudT::Ptr cloud_b);
    void colour_time(PointCloudT::Ptr cloud_a, PointCloudT::Ptr cloud_b, PointCloudT::Ptr cloud_c);
    
};

#endif
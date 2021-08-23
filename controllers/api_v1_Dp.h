#pragma once
#include <drogon/HttpController.h>
using namespace drogon;
namespace api
{
namespace v1
{
class Dp:public drogon::HttpController<Dp>
{
  public:
    METHOD_LIST_BEGIN
    //use METHOD_ADD to add your custom processing function here;
    //METHOD_ADD(Dp::get,"/{2}/{1}",Get);//path is /api/v1/Dp/{arg2}/{arg1}
    //METHOD_ADD(Dp::your_method_name,"/{1}/{2}/list",Get);//path is /api/v1/Dp/{arg1}/{arg2}/list
    //ADD_METHOD_TO(Dp::your_method_name,"/absolute/path/{1}/{2}/list",Get);//path is /absolute/path/{arg1}/{arg2}/list
    METHOD_ADD(Dp::lcs, "/lcs?first={first_str}&second={second_str}", Get);

    METHOD_LIST_END
    // your declaration of processing function maybe like this:
    // void get(const HttpRequestPtr& req,std::function<void (const HttpResponsePtr &)> &&callback,int p1,std::string p2);
    // void your_method_name(const HttpRequestPtr& req,std::function<void (const HttpResponsePtr &)> &&callback,double p1,int p2) const;
    void lcs(const HttpRequestPtr &req, std::function<void(const HttpResponsePtr &)> &&callback, std::string first_str, std::string second_str) const;
};
}
}

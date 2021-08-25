#pragma once
#include <drogon/HttpController.h>
using namespace drogon;
namespace api {
  namespace v1 {
    class String:public drogon::HttpController<String> {
      public:
        METHOD_LIST_BEGIN
        //use METHOD_ADD to add your custom processing function here;
        //METHOD_ADD(String::get,"/{2}/{1}",Get);//path is /api/v1/String/{arg2}/{arg1}
        //METHOD_ADD(String::your_method_name,"/{1}/{2}/list",Get);//path is /api/v1/String/{arg1}/{arg2}/list
        //ADD_METHOD_TO(String::your_method_name,"/absolute/path/{1}/{2}/list",Get);//path is /absolute/path/{arg1}/{arg2}/list
        METHOD_ADD(String::split_string, "/split?str={str}&delimiter={delimiter}", Get);

        METHOD_LIST_END
        // your declaration of processing function maybe like this:
        // void get(const HttpRequestPtr& req,std::function<void (const HttpResponsePtr &)> &&callback,int p1,std::string p2);
        // void your_method_name(const HttpRequestPtr& req,std::function<void (const HttpResponsePtr &)> &&callback,double p1,int p2) const;
        void split_string(const HttpRequestPtr& req, std::function<void (const HttpResponsePtr &)> &&callback, std::string str, std::string delimiter) const;
    };
  }
}

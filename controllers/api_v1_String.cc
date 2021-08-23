#include "api_v1_String.h"
using namespace api::v1;
using namespace std;
//add definition of your processing function here

void String::split_string(
  const HttpRequestPtr& req,
  function<void (const HttpResponsePtr &)> &&callback,
  string str,
  string delimiter
) const {
  size_t last = 0;
  size_t next = 0;
  Json::Value result_arr;
  while ((next = str.find(delimiter, last)) != string::npos) {
    result_arr.append(str.substr(last, next - last));
    last = next + delimiter.length();
  }
  result_arr.append(str.substr(last));
  Json::Value ret;
  ret["split_string"] = result_arr;
  auto resp = HttpResponse::newHttpJsonResponse(ret);
  callback(resp);
}

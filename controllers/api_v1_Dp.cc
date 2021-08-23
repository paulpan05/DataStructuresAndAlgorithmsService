#include "api_v1_Dp.h"
using namespace api::v1;
using namespace std;
//add definition of your processing function here

void Dp::lcs(
  const HttpRequestPtr &req,
  function<void (const HttpResponsePtr &)> &&callback,
  string first_str,
  string second_str
) const {
  size_t first_ln = first_str.length();
  size_t second_ln = second_str.length();
  vector<vector<int>> table (first_ln + 1, vector<int>(second_ln + 1, 0));
  for (size_t i = 0; i < table.size(); i += 1) {
    for (size_t j = 0; j < table[0].size(); j += 1) {
      if (i == 0 || j == 0) {
        table[i][j] = 0;
      } else if (first_str[i - 1] == second_str[j - 1]) {
        table[i][j] = table[i - 1][j - 1] + 1;
      } else {
        table[i][j] = max(table[i - 1][j], table[i][j - 1]);
      }
    }
  }
  Json::Value ret;
  ret["length"] = table[first_ln][second_ln];
  auto resp = HttpResponse::newHttpJsonResponse(ret);
  callback(resp);
}

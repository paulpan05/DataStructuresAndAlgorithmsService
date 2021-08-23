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
  for (size_t i = 1; i < table.size(); i += 1) {
    for (size_t j = 1; j < table[0].size(); j += 1) {
      if (first_str[i - 1] == second_str[j - 1]) {
        table[i][j] = table[i - 1][j - 1] + 1;
      } else {
        table[i][j] = max(table[i - 1][j], table[i][j - 1]);
      }
    }
  }

  int longest = table[first_ln][second_ln];
  string longest_str (longest, ' ');
  for (size_t i = first_ln, j = second_ln, k = longest - 1; i > 0 && j > 0;) {
    if (first_str[i - 1] == second_str[j - 1]) {
      longest_str[k] = first_str[i - 1];
      i -= 1;
      j -= 1;
      k -= 1;
    } else if (table[i - 1][j] > table[i][j - 1]) {
      i -= 1;
    } else {
      j -= 1;
    }
  }

  Json::Value ret;
  ret["length"] = longest;
  ret["common_string"] = longest_str;
  auto resp = HttpResponse::newHttpJsonResponse(ret);
  callback(resp);
}

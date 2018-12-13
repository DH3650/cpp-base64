#include <gtest/gtest.h>
#include <iostream>
#include <string>
#include "base64.h"

TEST(encode_decode_json, json_test) {
  std::string json_msg("{\"name\":\"Tom\",\n");
  json_msg += "\"age\":18\n";
  json_msg += "\"message\":\"hello\"}";

  std::vector<unsigned char> json_buf(json_msg.begin(), json_msg.end());
  auto encoded = base64_encode(json_buf.data(), json_buf.size());
  // utf-8, LF-eol
  std::string except_value(
      "eyJuYW1lIjoiVG9tIiwKImFnZSI6MTgKIm1lc3NhZ2UiOiJoZWxsbyJ9");
  ASSERT_EQ(encoded, except_value);

  auto decoded = base64_decode(encoded);
  std::string decoded_str(decoded.begin(), decoded.end());
  ASSERT_EQ(decoded_str, json_msg);
}

TEST(encode_decode_chinese_char, chinese_char_test) {
  std::string cc_msg("测试消息：message content!");
  std::vector<unsigned char> cc_buf(cc_msg.begin(), cc_msg.end());
  auto encoded = base64_encode(cc_buf.data(), cc_buf.size());
  std::string except_value("5rWL6K+V5raI5oGv77yabWVzc2FnZSBjb250ZW50IQ==");
  ASSERT_EQ(encoded, except_value);

  auto decoded = base64_decode(encoded);
  std::string decoded_str(decoded.begin(), decoded.end());
  ASSERT_EQ(decoded_str, cc_msg);
}

#include <iostream>
#include <string>
#include "sstream"

using namespace std;

int main() {
  ostringstream o_str1;
  ostringstream o_str2("abc");

  o_str1 << "o_str1 " << 2018 << endl;
  // 将缓冲区内容设置到string对象中
  cout << o_str1.str();

  long curPos = o_str2.tellp(); // 获取当前写入索引的位置
  cout << "curPos: " << curPos << endl;
  o_str2.seekp(2); // 手动设置put point 的值
  long curPos_set = o_str2.tellp();
  cout << "curPos after set: " << curPos_set << endl;

  o_str2.put('g'); // 在put pointer的位置写入 'g' , 并将put pointer的值指向下一个位置

  long curPos_write = o_str2.tellp();
  cout << "curPos after write: " << curPos_write << endl;

  cout << o_str2.str() << endl;

  // 重复使用一个 o_str 对象时建议：
  // 调用clear()清除当前错误控制状态
  // 调用str("")将缓冲区清零，清除脏数据
  o_str2.clear();
  o_str2.str("");
  cout << "after clear: " << o_str2.str() << endl;

  o_str2.str("_def");
  cout << "1: " << o_str2.str() << endl;

  o_str2.str("ggggggggh");
  cout << "2: " << o_str2.str() << endl;

  const char* buf = o_str2.str().c_str();
  cout << "危险操作: " << buf << endl;

  string ss = o_str2.str();
  const char *buffer = ss.c_str();
  cout << "正确操作: " << buffer << endl;
}

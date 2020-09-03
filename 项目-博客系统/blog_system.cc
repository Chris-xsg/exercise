#include"db.hpp"
#include"httplib.h"


void Test1()
{//局部功能测试--增删查改

  MYSQL *mysql = blog_system::MysqlInit();
  blog_system::TableUser table_user(mysql);
  Json::Value user;
  
  user["name"] = "张三";
  table_user.Insert(user);
  user.clear();
  user["name"] = "李四";
  table_user.Insert(user);
  //table_user.GetAll(&user);
  table_user.GetOne(1,&user);
  user["name"] = "zhangsan";
  table_user.Update(1,user);
  table_user.Delete(1);

  //json::vale转换为json字符串进行打印展示
  Json::Reader reader;//专门用于进行json反序列化
  //json::Writer writer;//专门用于进行json序列化---它是一个基类，不能直接使用
  Json::StyledWriter writer;
  std::cout<< writer.write(user) << std::endl;//json::Writer::write(Json::Vale &root)
  
  blog_system::MysqlRelease(mysql);
}

#define WWWROOT "./www"

blog_system::TableBlog *table_blog;
blog_system::TableTag * table_tag;
blog_system::TableUser *table_user;

void InsertUser(const httplib::Request &req,httplib::Response &rsp){
  //用户信息在req的body中，是一个json字符串
  //获取到json字符串
  std::string json_str = req.body;
  //将json字符串解析成为json::Value对象;
  Json::Reader reader;
  Json::Value root;
  bool ret = reader.parse(json_str,root);
  if(ret == false)
  {
    printf("json字符串解析失败！\n");
    rsp.status = 400;//400 Bad Request;
    return;
  }
  //调用table_user中的Insert接口向数据库插入数据
  ret = table_user->Insert(root);
  if(ret == false)
  {
    printf("插入数据失败！\n");
    rsp.status = 500;//500 服务器内部错误
    return;
  }
  //填充rsp响应信息
  rsp.status = 200;
  return;
}
void DeleteUser(const httplib::Request &req,httplib::Response &rsp){
  //获取删除用户id  /user/id  /user/(\d+)
  int user_id = std::stoi(req.matches[1]);//matches[0]放的是整个字符串，剩下的是捕捉到的字符串
  //执行数据库操作
  bool ret = table_user->Delete(user_id);
  if(ret == false)
  {
    printf("删除用户失败！\n");
    rsp.status = 500;
    return;
  }
  //填充响应
  rsp.status = 200;//默认响应状态码就是200---可以省略
  return;
}
void UpdateUser(const httplib::Request &req,httplib::Response &rsp){
  //获取用户id，解析json字符串
  int user_id = std::stoi(req.matches[1]);
  std::string json_str = req.body;
  Json::Reader reader;
  Json::Value root;
  bool ret = reader.parse(json_str,root);
  if(ret == false)
  {
    printf("解析失败！\n");
    rsp.status = 400;
    return;
  }
  //执行数据库操作进行修改
  ret = table_user->Update(user_id,root);
  if(ret == false)
  {
    printf("修改用户信息失败！\n");
    rsp.status = 500;
    return;
  }
  rsp.status = 200;
  return;
}
void GetAllUser(const httplib::Request &req,httplib::Response &rsp){
  //从数据库获取到所有用户信息的Json::Value;
  Json::Value root;
  bool ret = table_user->GetAll(&root);
  if(ret == false)
  {
    printf("获取用户信息失败！\n");
    rsp.status = 500;
    return;
  }
  //将Json::Value转换为json字符串，作为响应的正文，填充到rsp中
  Json::FastWriter writer;
  std::string body;
  body = writer.write(root);
  rsp.set_content(&body[0],body.size(),"application/json");
  return;
}
void GetOneUser(const httplib::Request &req,httplib::Response &rsp){
  int user_id = std::stoi(req.matches[1]);
  Json::Value root;
  bool ret = table_user->GetOne(user_id,&root);
  if(ret == false)
  {
    printf("获取单个用户信息失败！\n");
    rsp.status = 500;
    return;
  }
  Json::FastWriter writer;
  rsp.set_content(writer.write(root),"application/json");
  return;
}

void InsertTag(const httplib::Request &req,httplib::Response &rsp){
  //用户信息在req的body中，是一个json字符串
  //获取到json字符串
  std::string json_str = req.body;
  //将json字符串解析成为json::Value对象;
  Json::Reader reader;
  Json::Value root;
  bool ret = reader.parse(json_str,root);
  if(ret == false)
  {
    printf("json字符串解析失败！\n");
    rsp.status = 400;//400 Bad Request;
    return;
  }
  //调用table_tag中的Insert接口向数据库插入数据
  ret = table_tag->Insert(root);
  if(ret == false)
  {
    printf("插入数据失败！\n");
    rsp.status = 500;//500 服务器内部错误
    return;
  }
  //填充rsp响应信息
  rsp.status = 200;
  return;
}
void DeleteTag(const httplib::Request &req,httplib::Response &rsp){
  //获取删除标签id  /user/id  /user/(\d+)
  int tag_id = std::stoi(req.matches[1]);//matches[0]放的是整个字符串，剩下的是捕捉到的字符串
  //执行数据库操作
  bool ret = table_tag->Delete(tag_id);
  if(ret == false)
  {
    printf("删除用户标签失败！\n");
    rsp.status = 500;
    return;
  }
  //填充响应
  rsp.status = 200;//默认响应状态码就是200---可以省略
  return;
}
void UpdateTag(const httplib::Request &req,httplib::Response &rsp){
  //获取用户标签id，解析json字符串
  int tag_id = std::stoi(req.matches[1]);
  std::string json_str = req.body;
  Json::Reader reader;
  Json::Value root;
  bool ret = reader.parse(json_str,root);
  if(ret == false)
  {
    printf("解析失败！\n");
    rsp.status = 400;
    return;
  }
  //执行数据库操作进行修改
  ret = table_tag->Update(tag_id,root);
  if(ret == false)
  {
    printf("修改用户标签信息失败！\n");
    rsp.status = 500;
    return;
  }
  rsp.status = 200;
  return;
}
void GetAllTag(const httplib::Request &req,httplib::Response &rsp){
  //从数据库获取到所有用户标签信息的Json::Value;
  Json::Value root;
  bool ret = table_tag->GetAll(&root);
  if(ret == false)
  {
    printf("获取用户标签信息失败！\n");
    rsp.status = 500;
    return;
  }
  //将Json::Value转换为json字符串，作为响应的正文，填充到rsp中
  Json::FastWriter writer;
  rsp.set_content(writer.write(root),"application/json");
  return;
}
void GetOneTag(const httplib::Request &req,httplib::Response &rsp){
  int tag_id = std::stoi(req.matches[1]);
  Json::Value root;
  bool ret = table_tag->GetOne(tag_id,&root);
  if(ret == false)
  {
    printf("获取单个用户标签信息失败！\n");
    rsp.status = 500;
    return;
  }
  Json::FastWriter writer;
  rsp.set_content(writer.write(root),"application/json");
  return;
}
void InsertBlog(const httplib::Request &req,httplib::Response &rsp){
  //用户信息在req的body中，是一个json字符串
  //获取到json字符串
  std::string json_str = req.body;
  //将json字符串解析成为json::Value对象;
  Json::Reader reader;
  Json::Value root;
  bool ret = reader.parse(json_str,root);
  if(ret == false)
  {
    printf("json字符串解析失败！\n");
    rsp.status = 400;//400 Bad Request;
    return;
  }
  //调用table_blog中的Insert接口向数据库插入数据
  ret = table_blog->Insert(root);
  if(ret == false)
  {
    printf("插入数据失败！\n");
    rsp.status = 500;//500 服务器内部错误
    return;
  }
  //填充rsp响应信息
  rsp.status = 200;
  return;
}
void DeleteBlog(const httplib::Request &req,httplib::Response &rsp){
  //获取删除博客id  /user/id  /user/(\d+)
  int blog_id = std::stoi(req.matches[1]);//matches[0]放的是整个字符串，剩下的是捕捉到的字符串
  //执行数据库操作
  bool ret = table_blog->Delete(blog_id);
  if(ret == false)
  {
    printf("删除用户博客失败！\n");
    rsp.status = 500;
    return;
  }
  //填充响应
  rsp.status = 200;//默认响应状态码就是200---可以省略
  return;
}
void UpdateBlog(const httplib::Request &req,httplib::Response &rsp){
  //获取用户博客id，解析json字符串
  int blog_id = std::stoi(req.matches[1]);
  std::string json_str = req.body;
  Json::Reader reader;
  Json::Value root;
  bool ret = reader.parse(json_str,root);
  if(ret == false)
  {
    printf("解析失败！\n");
    rsp.status = 400;
    return;
  }
  //执行数据库操作进行修改
  ret = table_blog->Update(blog_id,root);
  if(ret == false)
  {
    printf("修改用户博客信息失败！\n");
    rsp.status = 500;
    return;
  }
  rsp.status = 200;
  return;
}
void GetAllBlog(const httplib::Request &req,httplib::Response &rsp){
  //从数据库获取到所有用户博客信息
  // /blog---获取所有博客   /blog?tag_id=id---获取标签博客 /blog?user_id=id--获取用户博客
  Json::Value root;
  if(req.has_param("tag_id"))
  {
    int tag_id = std::stoi(req.get_param_value("tag_id"));
    bool ret = table_blog->GetTag(tag_id,&root);
    if(ret == false)
    {
      printf("获取标签博客信息失败！\n");
      rsp.status = 500;
      return;
    }
  }
  else if(req.has_param("user_id"))
  {
      int user_id = std::stoi(req.get_param_value("user_id"));
      bool ret = table_blog->GetUser(user_id,&root);
      if(ret == false)
      {
        printf("获取用户博客信息失败！\n");
        rsp.status = 500;
        return;
      }
  }
  else
  {
      bool ret = table_blog->GetAll(&root);
      if(ret == false)
      {
        printf("获取所有博客信息失败！\n");
        rsp.status = 500;
        return;
      }  
  }
  Json::FastWriter writer;
  rsp.set_content(writer.write(root),"application/json");    
  return;
}
void GetOneBlog(const httplib::Request &req,httplib::Response &rsp){
  int blog_id = std::stoi(req.matches[1]);
  Json::Value root;
  bool ret = table_blog->GetONE(blog_id,&root);
  if(ret == false)
  {
    printf("获取单个用户博客信息失败！\n");
    rsp.status = 500;
    return;
  }
  Json::FastWriter writer;
  rsp.set_content(writer.write(root),"application/json");
  return;
}
int main(int argc,char *argv[])
{
  MYSQL *mysql = blog_system::MysqlInit();
  if(mysql == NULL)
  {
    return -1;
  }
  table_blog = new blog_system::TableBlog(mysql);
  table_tag = new blog_system::TableTag(mysql);
  table_user = new blog_system::TableUser(mysql);
  httplib::Server server;
  //httplib::Server::set_base_dir() 设置url中的资源路径的相对目录
  //好处：一些相对根目录下的静态文件资源，httplib会直接自动进行读取响应
  server.set_base_dir(WWWROOT);
  //R"()"---括号中的数据是原始数据，去除特殊字符的特殊含义
  //路由注册函数的第一个参数可以是一个正则表达式--用于匹配符合某种规则/特定格式的字符串
  //user/(\d+)  --直接捕捉括号括起来的数字 1  2  11 111
  server.Post("(/user)",InsertUser);
  server.Delete(R"(/user/(\d+))",DeleteUser);
  server.Put(R"(/user/(\d+))",UpdateUser);
  server.Get(R"(/user)",GetAllUser);
  server.Get(R"(/user/(\d+))",GetOneUser);
  
  server.Post("(/tag)",InsertTag);
  server.Delete(R"(/tag/(\d+))",DeleteTag);
  server.Put(R"(/tag/(\d+))",UpdateTag);
  server.Get(R"(/tag)",GetAllTag);
  server.Get(R"(/tag/(\d+))",GetOneTag);

  server.Post("(/blog)",InsertBlog);
  server.Delete(R"(/blog/(\d+))",DeleteBlog);
  server.Put(R"(/blog/(\d+))",UpdateBlog);
  server.Get(R"(/blog)",GetAllBlog);//get/blog-所有 /blog?tag_id=1 /blog?user_id=1
  server.Get(R"(/blog/(\d+))",GetOneBlog);

  server.listen("0.0.0.0,9000");
  blog_system::MysqlRelease(mysql);
  
  return 0;
}



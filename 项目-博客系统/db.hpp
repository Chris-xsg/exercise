#include<cstdio>
#include<iostream>
#include<cstdlib>
#include<string>
#include<mysql/mysql.h>
#include<jsoncpp/json/json.h>

#define MYSQL_HOST "127.0.0.1"//host地址
#define MYSQL_DB     "blog_system"//数据库名称
#define MYSQL_USER   "root"//用户
#define MYSQL_PASS   "000000"//密码

namespace blog_system{//数据库各接口实现
  static MYSQL *MysqlInit()//初始化
  {
      MYSQL *mysql = NULL;
      //初始化mysql句柄
      mysql = mysql_init(NULL);
      if(mysql == NULL)
      {
        printf("mysql init error\n");
        return NULL;
      }
      //连接MySQL服务器
     // MYSQL *mysql_real_connect(MYSQL *mysql(初始化完毕的句柄), const char *host(连接mysql服务器IP), const char *user(数据库的用户名), const char *passwd(数据库密码), const char *db(连接数据库的同时选择使用的数据库名称), unsigned int port(服务器端口，默认0表示3306), const char *unix_socket(套接字文件，通常为NULL), unsigned long client_flag(客户端标志，通常置0))
     if(mysql_real_connect(mysql,MYSQL_HOST,MYSQL_USER,MYSQL_PASS,MYSQL_DB,0,NULL,0) == NULL)
     {
       printf("connect mysql server failed:%s\n",mysql_error(mysql));
       mysql_close(mysql);
       return NULL;
     }
     //选择数据库 mysql_select_db
     //设置字符编码集   mysql_set_character_set(MYSQL *mysql,const char* csname)
     if(mysql_set_character_set(mysql,"utf8") != 0)
     {
       printf("set character failed : %s\n",mysql_error(mysql));
       mysql_close(mysql);
       return NULL;
     }
     return mysql;
      
  }
  static void MysqlRelease(MYSQL *mysql)//删除
  {
    if(mysql)
    {
      mysql_close(mysql);
      return;
    }
  }
  static bool MysqlQuery(MYSQL *mysql,const std::string &sql)//查询
  {
    int ret = mysql_query(mysql,sql.c_str());//执行sql语句
    if(ret != 0)
    {
      printf("query sql:[%s] error:%s\n",sql.c_str(),mysql_error(mysql));
      return false;
    }
    return true;
  }
/*******************************************标签表**********************************************/
    class TableTag
    {
        public:
          TableTag(MYSQL *mysql):_mysql(mysql){
          }
          
          bool Insert(const Json::Value &tag)//插入标签信息
          {
#define INSERT_TAG "insert table_tag values(null,'%s');"
            char tmp[4096] = {0};
            //Json::Value::asCString 返回c风格的字符串
            //sprintf 按照指定格式将多个数据对象组织成为一个字符串放到tmp中
            sprintf(tmp,INSERT_TAG,tag["name"].asCString());
            bool ret = MysqlQuery(_mysql,tmp);
            if(ret == false)
            {
              return false;
            }
              return true;
          }
          bool Delete(int tag_id)//删除标签信息
          {
#define DELETE_TAG "delete from table_tag where id=%d;"
            char tmp[4096] = {0};
            sprintf(tmp,DELETE_TAG,tag_id);
            bool ret = MysqlQuery(_mysql,tmp);
            if(ret == false)
            {
              return false;
            }
            return true;
          }
          bool Update(int tag_id,const Json::Value &tag)//修改标签信息
          {
#define UPDATE_TAG "update table_tag set name='%s' where id=%d;"
            char tmp[4096] = {0};
            sprintf(tmp,UPDATE_TAG,tag["name"].asCString(),tag_id);
            bool ret = MysqlQuery(_mysql,tmp);
            if(ret == false)
            {
              return false;
            }
            return true;
          }
          bool GetAll(Json::Value *tags)//获取所有标签信息
          {
#define SELECT_TAG_ALL "select * from table_tag"
            bool ret = MysqlQuery(_mysql,SELECT_TAG_ALL);
            if(ret == false)
            {
              return false;
            }
            MYSQL_RES * res = mysql_store_result(_mysql);//获取结果集
            int num_row = mysql_num_rows(res);//获取结果集中查询结果的条数
            if(num_row <= 0)
            {
              printf("No tag information\n");
              mysql_free_result(res);//释放结果集
              return false;
            }
            for(int i = 0;i<num_row;++i)
            {
              MYSQL_ROW row = mysql_fetch_row(res);//遍历结果集，获取每一行的数据
              Json::Value tag;
              tag["id"] = std::stoi(row[0]);
              tag["name"] = row[1];
              tags->append(tag);//将Json::Value对象->append，添加数组各个元素
            }
            mysql_free_result(res);
            return true;
          }
          bool GetOne(int tag_id,Json::Value *tag)//获取单个标签信息
          {
#define SELECT_TAG_ONE "select name from table_tag where id=%d;"
            char tmp[1024] = {0};
            sprintf(tmp,SELECT_TAG_ONE,tag_id);
            bool ret = MysqlQuery(_mysql,tmp);
            if(ret == false)
            {
              return false;
            }
            MYSQL_RES * res = mysql_store_result(_mysql);//获取结果集
            int num_row = mysql_num_rows(res);//获取结果集中查询结果的条数
            if(num_row != 1)
            {
              printf("tag count error\n");
              mysql_free_result(res);//释放结果集
              return false;
            }
            for(int i = 0;i<num_row;++i)
            {
              MYSQL_ROW row = mysql_fetch_row(res);//遍历结果集，获取每一行的数据
              (*tag)["id"] = tag_id;
              (*tag)["name"] = row[0];
            }
            mysql_free_result(res);
            return true;
          }
          ~TableTag()
          {

          }
        private:
          MYSQL *_mysql;
    };
/*******************************************用户表**********************************************/
    class TableUser
    {
        public:
          TableUser(MYSQL *mysql):_mysql(mysql){}
          
          bool Insert(const Json::Value &user)//插入标签信息
          {
#define INSERT_USER "insert table_user values(null,'%s');"
            char tmp[4096] = {0};
            sprintf(tmp,INSERT_USER,user["name"].asCString());
            bool ret = MysqlQuery(_mysql,tmp);
            if(ret == false)
            {
              return false;
            }
              return true;
          }
          bool Delete(int user_id)//删除标签信息
          {
#define DELETE_USER "delete from table_user where id=%d;"
            char tmp[4096] = {0};
            sprintf(tmp,DELETE_USER,user_id);
            bool ret = MysqlQuery(_mysql,tmp);
            if(ret == false)
            {
              return false;
            }
            return true;
          }
          bool Update(int user_id,const Json::Value &user)//修改标签信息
          {
#define UPDATE_USER "update table_user set name='%s' where id=%d;"
            char tmp[4096] = {0};
            sprintf(tmp,UPDATE_USER,user["name"].asCString(),user_id);
            bool ret = MysqlQuery(_mysql,tmp);
            if(ret == false)
            {
              return false;
            }
            return true;
          }
          bool GetAll(Json::Value *users)//获取所有标签信息
          {
#define SELECT_USER_ALL "select * from table_user"
            bool ret = MysqlQuery(_mysql,SELECT_USER_ALL);
            if(ret == false)
            {
              return false;
            }
            MYSQL_RES * res = mysql_store_result(_mysql);//获取结果集
            int num_row = mysql_num_rows(res);//获取结果集中查询结果的条数
            if(num_row <= 0)
            {
              printf("No user information\n");
              mysql_free_result(res);//释放结果集
              return false;
            }
            for(int i = 0;i<num_row;++i)
            {
              MYSQL_ROW row = mysql_fetch_row(res);//遍历结果集，获取每一行的数据
              Json::Value user;
              user["id"] = std::stoi(row[0]);
              user["name"] = row[1];
              users->append(user);//将Json::Value对象->append，添加数组各个元素
            }
            mysql_free_result(res);
            return true;
          }
          bool GetOne(int user_id,Json::Value *user)//获取单个标签信息
          {
#define SELECT_USER_ONE "select name from table_user where id=%d;"
            char tmp[1024] = {0};
            sprintf(tmp,SELECT_USER_ONE,user_id);
            bool ret = MysqlQuery(_mysql,tmp);
            if(ret == false)
            {
              return false;
            }
            MYSQL_RES * res = mysql_store_result(_mysql);//获取结果集
            int num_row = mysql_num_rows(res);//获取结果集中查询结果的条数
            if(num_row != 1)
            {
              printf("user count error\n");
              mysql_free_result(res);//释放结果集
              return false;
            }
            for(int i = 0;i<num_row;++i)
            {
              MYSQL_ROW row = mysql_fetch_row(res);//遍历结果集，获取每一行的数据
              (*user)["id"] = user_id;
              (*user)["name"] = row[0];
            }
            mysql_free_result(res);
            return true;
          }

          ~TableUser(){
          }
        private:
          MYSQL *_mysql;
    };
/*******************************************博客表**********************************************/
    class TableBlog
    {
        public:
          TableBlog(MYSQL *mysql):_mysql(mysql){
          }

          bool Insert(const Json::Value &blog)//插入标签信息
          {
            //id tag_id user_id title content ctime
#define INSERT_BLOG "insert table_blog values(null,%d,%d,'%s','%s',now());"
            char tmp[4096] = {0};
            sprintf(tmp,INSERT_BLOG,blog["tag_id"].asInt(),blog["user_id"].asInt(),blog["title"].asCString(),blog["content"].asCString());
            bool ret = MysqlQuery(_mysql,tmp);
            if(ret == false)
            {
              return false;
            }
              return true;
          }

          bool Delete(int blog_id)//删除博客信息
          {
#define DELETE_BLOG "delete from table_blog where id=%d;"
            char tmp[4096] = {0};
            sprintf(tmp,DELETE_BLOG,blog_id);
            bool ret = MysqlQuery(_mysql,tmp);
            if(ret == false)
            {
              return false;
            }
            return true;
          }
          
          bool Update(int blog_id,const Json::Value &blog)//修改博客信息
          {
            
#define UPDATE_BLOG "update table_blog set tag_id=%d,title='%s',content='%s' where id=%d;"
            char tmp[4096] = {0};
            sprintf(tmp,UPDATE_BLOG,blog["tag_id"].asInt(),blog["title"].asCString(),blog["content"].asCString(),blog_id);
            bool ret = MysqlQuery(_mysql,tmp);
            if(ret == false)
            {
              return false;
            }
              return true;
          }

          bool GetAll(Json::Value *blogs)//获取所有博客信息
          {
#define SELECT_BLOG_ALL "select * from table_blog"
            bool ret = MysqlQuery(_mysql,SELECT_BLOG_ALL);
            if(ret == false)
            {
              return false;
            }
            MYSQL_RES * res = mysql_store_result(_mysql);//获取结果集
            int num_row = mysql_num_rows(res);//获取结果集中查询结果的条数
            if(num_row <= 0)
            {
              printf("No blog information\n");
              mysql_free_result(res);//释放结果集
              return false;
            }
            for(int i = 0;i<num_row;++i)
            {
              MYSQL_ROW row = mysql_fetch_row(res);//遍历结果集，获取每一行的数据
              Json::Value blog;
              blog["id"] = std::stoi(row[0]);
              blog["tag_id"] = std::stoi(row[1]);
              blog["user_id"] = std::stoi(row[2]);
              blog["title"] = row[3];
              blog["content"] = row[4];
              blog["ctime"] = row[5];
              blogs->append(blog);
            }
            mysql_free_result(res);
            return true;
          }
          bool GetTag(int tag_id,Json::Value *blogs)//通过标签获取博客信息
          {
#define SELECT_BLOG_TAG "select * from table_blog where tag_id=%d"
            char tmp[4096] = {0};
            sprintf(tmp,SELECT_BLOG_TAG,tag_id);
            bool ret = MysqlQuery(_mysql,tmp);
            if(ret == false)
            {
              return false;
            }
            MYSQL_RES * res = mysql_store_result(_mysql);//获取结果集
            int num_row = mysql_num_rows(res);//获取结果集中查询结果的条数
            if(num_row <= 0)
            {
              printf("No blog information\n");
              mysql_free_result(res);//释放结果集
              return false;
            }
            for(int i = 0;i<num_row;++i)
            {
              MYSQL_ROW row = mysql_fetch_row(res);//遍历结果集，获取每一行的数据
              Json::Value blog;
              blog["id"] = std::stoi(row[0]);
              blog["tag_id"] = std::stoi(row[1]);
              blog["user_id"] = std::stoi(row[2]);
              blog["title"] = row[3];
              blog["content"] = row[4];
              blog["ctime"] = row[5];
              blogs->append(blog);
            }
            mysql_free_result(res);
            return true;
          }
          bool GetUser(int user_id,Json::Value *blogs)//通过用户获取博客信息
          {
#define SELECT_BLOG_USER "select * from table_blog where user_id=%d"
            char tmp[4096] = {0};
            sprintf(tmp,SELECT_BLOG_USER,user_id);
            bool ret = MysqlQuery(_mysql,tmp);
            if(ret == false)
            {
              return false;
            }
            MYSQL_RES * res = mysql_store_result(_mysql);//获取结果集
            int num_row = mysql_num_rows(res);//获取结果集中查询结果的条数
            if(num_row <= 0)
            {
              printf("No blog information\n");
              mysql_free_result(res);//释放结果集
              return false;
            }
            for(int i = 0;i<num_row;++i)
            {
              MYSQL_ROW row = mysql_fetch_row(res);//遍历结果集，获取每一行的数据
              Json::Value blog;
              blog["id"] = std::stoi(row[0]);
              blog["tag_id"] = std::stoi(row[1]);
              blog["user_id"] = std::stoi(row[2]);
              blog["title"] = row[3];
              blog["content"] = row[4];
              blog["ctime"] = row[5];
              blogs->append(blog);
            }
            mysql_free_result(res);
            return true;
          }
          bool GetONE(int blog_id,Json::Value *blog)//获取单个博客信息
          {
#define SELECT_BLOG_ONE "select * from table_blog where blog_id=%d"
            char tmp[4096] = {0};
            sprintf(tmp,SELECT_BLOG_ONE,blog_id);
            bool ret = MysqlQuery(_mysql,tmp);
            if(ret == false)
            {
              return false;
            }
            MYSQL_RES * res = mysql_store_result(_mysql);//获取结果集
            int num_row = mysql_num_rows(res);//获取结果集中查询结果的条数
            if(num_row <= 0)
            {
              printf("No blog information\n");
              mysql_free_result(res);//释放结果集
              return false;
            }
            for(int i = 0;i<num_row;++i)
            {
              MYSQL_ROW row = mysql_fetch_row(res);//遍历结果集，获取每一行的数据
              (*blog)["id"] = std::stoi(row[0]);
              (*blog)["tag_id"] = std::stoi(row[1]);
              (*blog)["user_id"] = std::stoi(row[2]);
              (*blog)["title"] = row[3];
              (*blog)["content"] = row[4];
              (*blog)["ctime"] = row[5];
            }
            mysql_free_result(res);
            return true;
          }
          ~TableBlog(){
          }
        private:
          MYSQL *_mysql;
    };

}


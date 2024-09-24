#include <iostream>
#include<vector>
#include<map>

#include "json.hpp"
using json=nlohmann::json;
using namespace std;

string fun1(){
    json js;
    js["msg_type"]=2;
    js["from"]="zhang san";
    js["to"]="Li si";
    js["msg"]="Hello!";
    cout << js << endl;
    string sendBuf=js.dump();
    return sendBuf;
}

void fun2(){
    json js;
    // 添加数组
    js["id"] = {1,2,3,4,5};
    // 添加key-value
    js["name"] = "zhang san";
    // 添加对象
    js["msg"]["zhang san"] = "hello world";
    js["msg"]["liu shuo"] = "hello china";
    // 上面等同于下面这句一次性添加数组对象
    js["msg"] = {{"zhang san", "hello world"}, {"liu shuo", "hello china"}};
    cout << js << endl;
    string sendBuf=js.dump();
    cout<<sendBuf<<endl;
}

int main(){
    string recvBuf=fun1();
    json jsbuf=json::parse(recvBuf);
    cout<<jsbuf["msg_type"]<< endl;
    cout<<jsbuf["from"]<< endl;
    cout<<jsbuf["to"]<< endl;
    cout<<jsbuf["msg"]<< endl;
    return 0;
}
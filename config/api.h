#ifndef API_H
#define API_H

namespace API
{
    namespace LOGIN
    {
        static const int NORMAL = 1;    // 常规登录
    }

    namespace BUCKET
    {
        static const int BASE = 100;
        static const int LIST = BASE + 1;   // 获取桶列表
        static const int PUT = BASE + 2;    // 创建桶
        static const int DELETE = BASE + 3;    // 删除桶
    }

    namespace OBJECT
    {
        static const int BASE = 200;
        static const int LIST = 200 + 1;    // 获取对象列表
        static const int GET = 200 + 10;    // 下载对象
        static const int PUT = 200 + 20;   // 上传对象
        static const int DELETE = 200 + 30;    // 删除对象
    }
}

#endif // API_H

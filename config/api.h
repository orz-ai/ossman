#ifndef API_H
#define API_H

namespace API
{
    namespace LOGIN
    {
        static const int NORMAL = 1;    // �����¼
    }

    namespace BUCKET
    {
        static const int BASE = 100;
        static const int LIST = BASE + 1;   // ��ȡͰ�б�
        static const int PUT = BASE + 2;    // ����Ͱ
        static const int DELETE = BASE + 3;    // ɾ��Ͱ
    }

    namespace OBJECT
    {
        static const int BASE = 200;
        static const int LIST = 200 + 1;    // ��ȡ�����б�
        static const int GET = 200 + 10;    // ���ض���
        static const int PUT = 200 + 20;   // �ϴ�����
        static const int DELETE = 200 + 30;    // ɾ������
    }
}

#endif // API_H

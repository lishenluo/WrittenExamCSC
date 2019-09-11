#include"IssueThree.h"

namespace csc
{
    IssueThree::IssueThree()
    {}

    void IssueThree::showCosGraphOfCPU()
    {
        calcCosValue();
        SYSTEM_INFO info;
        GetSystemInfo(&info);//�õ�cpu��Ŀ
        int num = info.dwNumberOfProcessors;
        cout << "������cpu����" << num << endl;

        HANDLE *handle;
        handle = new HANDLE[num];
        DWORD *threadId;
        threadId = new DWORD[num];
        for (int i = 0; i< num; ++i)
        {
            handle[i] = CreateThread(NULL, 0, startFunc, (LPVOID)this, 0, &threadId[i]);//�������߳�
            SetThreadAffinityMask(handle[i], i + 1);//�޶��߳��������ĸ�cpu��
            cout << "�߳�id:" << threadId[i] << endl;
        }
        cout << "����Դ���������رձ�������������ȣ��ۿ�cpuʹ��������" << endl;
        cout << "�۲����ֱ�ӹر�exe���򴰿�" << endl;
        WaitForSingleObject(handle[0], INFINITE);//�ȴ��߳̽���
        delete[] handle;
        delete[] threadId;
    }

    void IssueThree::calcCosValue()
    {
        double x = 0.0;
        for (int i = 0; i < COUNT; ++i, x += GAP)
        {
            m_cosValue[i] = (1 + cos(FACTOR * x)) / 2; //y=(1/2)*(1+cos(a*x))
        }
    }

    DWORD WINAPI IssueThree::startFunc(LPVOID p)
    {
        int count = 0;
        IssueThree* pIssueThree = (IssueThree*)p;
        if (pIssueThree == NULL)
        {
            cout << "ָ��Ϊ��" << endl;
            return -1;
        }
        while (1)
        {
            DWORD start = GetTickCount();
            if (count >= COUNT)
            {
                count = 0;
            }
            double r = pIssueThree->m_cosValue[count++];
            DWORD busy = DWORD(r * GAP);
            while (GetTickCount() - start < busy) {}
            Sleep(DWORD(GAP - busy));
        }
        return DWORD(0);
    }
}

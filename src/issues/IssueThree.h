/**
*  ����������дһ�����򣬸ó�������ʱ��CPU��ʹ����Ϊ����ͼ��
*
*  @author lishenluo
*  @since  2019-01-12
*/

#pragma once

#include "stdafx.h"
#include <Windows.h>
#include<tchar.h>

namespace csc
{
    static int PERIOD = 25 * 1000; //����ms
    const int COUNT = 300;  //һ�����ڼ������
    const double PI = 3.1415926535898; //PI
    const double GAP = (double)PERIOD / COUNT; //ʱ����
    const double FACTOR = 2 * PI / PERIOD;  //������ϵ��
    class IssueThree
    {
    public:
        IssueThree();
        void showCosGraphOfCPU();
    private:
        static DWORD WINAPI  startFunc(LPVOID);
        void                 calcCosValue();
        double               m_cosValue[COUNT];
    };
}
